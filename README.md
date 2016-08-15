# cordova-sap
Cordova plugin, which provides JS interface for Tianwei SDK to enable digital signature and encryption/decryption.
Currently implemented only for iOS devices.

# Installation
```
cordova plugin add https://github.com/yury-dymov/cordova-sap.git
```
# Methods

## initialize
This method should be called prior the execution of any other methods
#### Arguments
- license : string - MANDATORY, your Tianwei license
- pin-code : string - MANDATORY, some pin-code. I am not aware, what it is used for but it is required

#### Returns
Nothing or error

## requestCertificate
Requests certificate from Tianwei and stores it in the application

#### Arguments
- URL : string - MANDATORY, Tianwei service URL
- Account Hash : string - MANDATORY,your account hash. Was provided to me within demo. I have no clue, how to generate one myself.
- User Name : string - MANDATORY, self-descriptive
- User e-mail : string - MANDATORY, self-descriptive
- pin-code : string, see 'pin-code' for initialize method

#### Returns
Certificate provided by Tianwei SDK or error

#### sign
Signs data with digital signature

#### Arguments
- data : string - MANDATORY, data, which you want to sign
- algorithm : string - OPTIONAL, default value: "SHA1". Algorithm for signing data.

#### Returns
Signed data or error

# ToDo
1. Implement verifyDigitalSignature, encrypt and decrypt methods
2. Add Android and Windows Desktop platforms support
