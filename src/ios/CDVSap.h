#import <Cordova/CDVPlugin.h>

@interface CDVSap : CDVPlugin


// License and pin should be provided
- (void)initialize:(CDVInvokedUrlCommand*)command;

// 5 arguments should be provided: service url, account hash, user name, user email and pin
- (void)requestCertificate:(CDVInvokedUrlCommand*)command;

// 1 argument should be provided, 2nd is optional: data, algorithm=SHA1
- (void)sign:(CDVInvokedUrlCommand*)command;

@end  