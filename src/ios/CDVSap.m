#import "CDVSap.h"
#import "func_def.h"
#import "type_def.h"


static CDVSap *_instance;

@interface CDVSap() {
  BOOL _initialized;
}

@end

@implementation CDVSap

- (id)init {
  if (!_instance) {
    self = [super init];
        
    _instance = self;
  }
  
  return _instance;
}

- (void)initialize:(CDVInvokedUrlCommand*)command {
  if (command.arguments.count == 0) {
    [self _returnError:command];
    return;
  }
  
  setLicense([command.arguments objectAtIndex: 0]);
  
  _initialized = YES;
  
  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];

  [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];  
}

+ (id)allocWithZone:(NSZone*)zone {
  if (!_instance) {
    return [super allocWithZone:zone];
  }
  
  return _instance;
}

- (void)_returnError:(CDVInvokedUrlCommand*)command {
  [self _returnError:command andMessage:@"No license provided"];
}

- (void)_returnError:(CDVInvokedUrlCommand*)command andMessage:(NSString*)message {
  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:message];    
  
  [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];  
}


- (void)_returnCommandError:(CDVInvokedUrlCommand*)command {
  NSString *outPUT = nil;  
  
  getLastErrInfo(&outPUT);
  
  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:outPUT];    
  
  [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];    
}
  

- (void)requestCertificate:(CDVInvokedUrlCommand*)command {
  if (!_initialized) {
    [self _returnError:command];
    return;
  }
  
  if (command.arguments.count != 5) {
    [self _returnError:command andMessage:@"5 arguments should be provided: service url, account hash, user name, user email and global customer PIN"];
  }
  
  NSString *outPUT = nil;
  NSString *outPUTcertReq = nil;
  
  int ret = EStateFailure;
  
  userInfo *user = [[userInfo alloc]init];
  user.userName = [command.arguments objectAtIndex:2];
  user.userEmail = [command.arguments objectAtIndex:3];

  ret = initWebsiteAndAccountHash([command.arguments objectAtIndex:0], [command.arguments objectAtIndex:1]);
  
  if (ret != EStateSuccess) {
    [self _returnCommandError:command];
    return;
  }
  
  NSString *globalCustomerPin = [command.arguments objectAtIndex:4];
  
  ret = verifyPIN(nil, globalCustomerPin, globalCustomerPin.length);

  if (ret != EStateSuccess) {
    [self _returnCommandError:command];
    return;
  }
  
  ret = genCSR(&outPUT, @"", user.userName, user.userEmail, nil, nil, 2048, @"RSA");  
  
  if (ret != EStateSuccess || !outPUT) {
    [self _returnCommandError:command];
    return;
  }
  
  outPUTcertReq = [[NSString alloc] initWithString: outPUT];
  outPUTcertReq = [outPUTcertReq stringByReplacingOccurrencesOfString:@"\r\n" withString:@""];
        
  ret = enrollCert(&outPUT, outPUTcertReq, user, @"itrusyes", @"itrusyes", EAutoApprovalCertificate);
  
  if (ret != EStateSuccess) {
    [self _returnCommandError:command];
    return;
  }
  
  ret = importCert(nil, outPUT);
                  
  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:outPUT];    
  
  [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];                                          
}

@end