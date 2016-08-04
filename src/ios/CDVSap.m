#import "CDVSap.h"

@implementation CDVSap

- (void)sapHelloWorld:(CDVInvokedUrlCommand*)command {
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Hello World"];

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end