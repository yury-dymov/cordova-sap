#import <Cordova/CDVPlugin.h>

@interface CDVSap : CDVPlugin


// License should be provided
- (void)initialize:(CDVInvokedUrlCommand*)command;

// 4 arguments should be provided: service url, account hash, user name and user email
- (void)requestCertificate:(CDVInvokedUrlCommand*)command;

@end  