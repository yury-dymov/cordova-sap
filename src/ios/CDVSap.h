#import <Cordova/CDVPlugin.h>

@interface CDVSap : CDVPlugin


// License and pin should be provided
- (void)initialize:(CDVInvokedUrlCommand*)command;

// 5 arguments should be provided: service url, account hash, user name, user email and pin
- (void)requestCertificate:(CDVInvokedUrlCommand*)command;

// 2 arguments should be provided, 3d is optional: data, certificate, algorithm=SHA1
- (void)sign:(CDVInvokedUrlCommand*)command;

@end  