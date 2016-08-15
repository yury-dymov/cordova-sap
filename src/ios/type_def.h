//
//  type_def.h
//  O_All
//
//  Created by YXCD on 13-9-12.
//  Copyright (c) 2013年 YXCD. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

#define IN
#define OUT

#define itrus_vesion "0.0.0"
#define itrus_builder_id "itrus"

typedef unsigned char       uchar;
typedef unsigned short      ushort;
typedef unsigned int        uint;
typedef unsigned long       ulong;
typedef unsigned long long  ulonglong;

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
//typedef unsigned long       uint32;
typedef unsigned long long  uint64;



enum eErrorCode {
    EStateSuccess = 0,                  // 成功, success
    EStateErrorInitDB,                  // 初始化数据库失败, Failed to initialize the database
    EStateErrorInitPIN,                 // 初始化pin出错, Error to initialize pin
    EStateErrorUninitPIN,               // 初始化pin出错, Error to initialize pin
    EStateErrorMemLittle,               // 内存不足, Insufficient memory
    EStateErrorNoSlot,                  // 没有key, Not Found Key
    EStateErrorInvalidArg,              // 非法参数, Illegal parameter
    EStateErrorPIN,                     // pin码错误, Pin code error
    EStateErrorCert,                    // 证书错误, Certificate error
    EStateErrorNeedLogin,               // 需要登录, Need to log in
    EStateErrorGenPriKey,               // 生成私钥出错, Error generating private key
    EStateErrorSignData,                // 签名数据出错, Signature data error
    EStateErrorVerifySign,              // 验签出错, Verify signature error
    EStateErrorGenPubInfo,              // 生成公钥信息出错, Error in generating public key information
    EStateErrorGenCertReq,              // 生成证书请求出错, Generating a certificate request error
    EStateErrorCertNotExist,            // 证书不存在, Certificate does not exist
    EStateErrorNoCert,                  // 没有证书, No certificate
    EStateErrorNoPriKey,                // 没有私钥, No private key
    EStateErrorNoPubKey,                // 没有公钥, No public key
    EStateErrorEncrypt,                 // 加密出错, Encryption error
    EStateErrorDecrypt,                 // 解密出错, Decryption error
    EStateErrorHashData,                // 哈希出错, Hash error
    EStateErrorImportCert,              // 导入证书出错, Import certificate error
    EStateErrorKeyUsage,                // KEY用途不正确, KEY use is not correct
    EStateErrorCreateSignedData,        // 创建签名数据出错, Error creating signature data
    EStateErrorIncludeCertChain,        // 包含证书链出错, Error containing certificate chain
    EStateErrorEncodeItem,              // p7编码出错, P7 coding error
    EStateErrorDecodeItem,              // p7解码出错, P7 decoding error
    EStateErrorVerifyDetachedSignature, // p7Detach验签出错, P7 Detach verify signature error
    EStateErrorVerifySignature,         // p7Attach验签出错, P7 Attach verify signature error
    EStateErrorSetContent,              // p7设置原文出错, P7 set error in the original
    EStateErrorAddCertificate,          // 填加证书出错, Add certificate error
    EStateErrorNetwork,                 // 网络出错, Network error
    EStateErrorLicenseNotExist,         // LICENSE不存在, LICENSE does not exist
    EStateErrorLicenseVerify,           // LICENSE验证不通过, LICENSE validation does not pass
    EStateFailure = -1                  // 失败, Fail
};

enum Bool_approval_certificate
{
    EManualApprovalCertificate = 0,
    EAutoApprovalCertificate = 1,
};


enum SignTypeEnum
{
    ESignWithNO = 0,            //0表示裸签名,
    ESignWithP7Attach = 1,      //1表示P7 attach,
    ESignWithP7Detach = 2,      //2表示P7 detach
};



enum EncodedCertEnum
{
    ECertDer = 0,    //0 der
    ECertPem = 1,    //1 pem
    ECertBase64 = 2, //2 base64
};


enum CertificateDateTime
{
    ECertAll = 0,          //0表示所有证书
    ECertValid = 1,        //1表示处于有效期内的证书
    ECertShuldUpdate = 2,  //2表示待更新证书
    ECertInValid = 3,      //3表示未生效或已过期证书
};


enum Certificate_revocation_reason_code_standards //证书吊销标准理由码
{
    unspecified = 0,
    keyCompromise = 1,
    cACompromise = 2,
    affiliationChanged = 3,
    superseded = 4,
    cessationOfOperation = 5,
};

@interface userInfo : NSObject
{
    NSString * cerReqBuffer;
    NSString * userName;
    NSString * userEmail;
    NSString * certReqChallenge;
    NSString * certReqOverrideValidity;
    NSString * certReqComment;
    NSString * certKmcReq2;
    NSString * userOrganization;
    NSString * userOrgunit;
    NSString * keyMode;
    NSString * passcode;
    NSString * userId;
    NSNumber * accountId;
    NSString * userIdRandom;
    NSString * userSurname;
    NSString * userCountry;
    NSString * userState;
    NSString * userLocality;
    NSString * userStreet;
    NSString * userDns;
    NSString * userIp;
    NSString * userTitle;
    NSString * userDescription;
    NSString * userAdditionalField1;
    NSString * userAdditionalField2;
    NSString * userAdditionalField3;
    NSString * userAdditionalField4;
    NSString * userAdditionalField5;
    NSString * userAdditionalField6;
    NSString * userAdditionalField7;
    NSString * userAdditionalField8;
    NSString * userAdditionalField9;
    NSString * userAdditionalField10;
};

@property(atomic,strong)NSString * cerReqBuffer;
@property(atomic,strong)NSString * userName;
@property(atomic,strong)NSString * userEmail;
@property(atomic,strong)NSString * certReqChallenge;
@property(atomic,strong)NSString * certReqOverrideValidity;
@property(atomic,strong)NSString * certReqComment;
@property(atomic,strong)NSString * certKmcReq2;
@property(atomic,strong)NSString * userOrganization;
@property(atomic,strong)NSString * userOrgunit;
@property(atomic,strong)NSString * keyMode;
@property(atomic,strong)NSString * passcode;
@property(atomic,strong)NSString * userId;
@property(atomic,strong)NSNumber * accountId;
@property(atomic,strong)NSString * userIdRandom;
@property(atomic,strong)NSString * userSurname;
@property(atomic,strong)NSString * userCountry;
@property(atomic,strong)NSString * userState;
@property(atomic,strong)NSString * userLocality;
@property(atomic,strong)NSString * userStreet;
@property(atomic,strong)NSString * userDns;
@property(atomic,strong)NSString * userIp;
@property(atomic,strong)NSString * userTitle;
@property(atomic,strong)NSString * userDescription;
@property(atomic,strong)NSString * userAdditionalField1;
@property(atomic,strong)NSString * userAdditionalField2;
@property(atomic,strong)NSString * userAdditionalField3;
@property(atomic,strong)NSString * userAdditionalField4;
@property(atomic,strong)NSString * userAdditionalField5;
@property(atomic,strong)NSString * userAdditionalField6;
@property(atomic,strong)NSString * userAdditionalField7;
@property(atomic,strong)NSString * userAdditionalField8;
@property(atomic,strong)NSString * userAdditionalField9;
@property(atomic,strong)NSString * userAdditionalField10;

@end


@interface renewInfo : NSObject
{
    NSString * origCertSerialNumber;
    NSString * origCert;
    NSString * pkcsInformation;
    NSString * certReqBuf;
    NSString * certReqBufType;
    NSString * certReqChallenge;
    NSString * certReqChallengeOld;
    NSString * certReqComment;
    NSString * certReqOverrideValidity;
    NSString * renewMode;
    NSString * passcode;
};

@property(atomic,strong)NSString * origCertSerialNumber;
@property(atomic,strong)NSString * origCert;
@property(atomic,strong)NSString * pkcsInformation;
@property(atomic,strong)NSString * certReqBuf;
@property(atomic,strong)NSString * certReqBufType;
@property(atomic,strong)NSString * certReqChallenge;
@property(atomic,strong)NSString * certReqChallengeOld;
@property(atomic,strong)NSString * certReqComment;
@property(atomic,strong)NSString * certReqOverrideValidity;
@property(atomic,strong)NSString * renewMode;
@property(atomic,strong)NSString * passcode;

@end


@interface certInfo : NSObject
{
    NSString * CommonName;
    NSString * Subject;
    NSString * Issuer;
    NSString * CSP;
    NSString * KeyContainer;
    NSString * SerialNumber;
    NSString * ValidFrom;
    NSString * ValidTo;
    NSString * KeyUsage;
    NSString * GetEncodedCert;
    NSString * Verify;
    NSString * PublicKey;
};

@property(atomic,strong)NSString * CommonName;
@property(atomic,strong)NSString * Subject;
@property(atomic,strong)NSString * Issuer;
@property(atomic,strong)NSString * CSP;
@property(atomic,strong)NSString * KeyContainer;
@property(atomic,strong)NSString * SerialNumber;
@property(atomic,strong)NSString * ValidFrom;
@property(atomic,strong)NSString * ValidTo;
@property(atomic,strong)NSString * KeyUsage;
@property(atomic,strong)NSString * GetEncodedCert;
@property(atomic,strong)NSString * Verify;
@property(atomic,strong)NSString * PublicKey;

@end

#endif