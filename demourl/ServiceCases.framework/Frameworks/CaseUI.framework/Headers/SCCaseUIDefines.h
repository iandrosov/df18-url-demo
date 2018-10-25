/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import <Foundation/Foundation.h>

#ifndef SC_EXTERN
#ifdef __cplusplus
#define SC_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

#ifndef SCSAppearanceImageToken
typedef NSString * SCSAppearanceImageToken NS_STRING_ENUM;
#endif

SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenCaseSubmitSuccess;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenPicklistDropdown;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenCompose;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenActionCasePublisher;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenEmptyIcon;

SC_EXTERN NSString * const SCSCaseUILogIdentifier;

// Deprecated mappings
#define SCS_API_DEPRECATED_WITH_REPLACEMENT(__name) __API_DEPRECATED_WITH_REPLACEMENT(__name, ios(1.0,1.0))

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenCaseSubmitSuccess")
SC_EXTERN NSString * const kSCAppearanceCaseSubmitSuccess;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenPicklistDropdown")
SC_EXTERN NSString * const kSCAppearancePicklistDropdown;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenCompose")
SC_EXTERN NSString * const kSCAppearanceCompose;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenActionCasePublisher")
SC_EXTERN NSString * const kSCAppearanceActionCasePublisher;

__attribute__((deprecated("kSCAppearanceActionCaseList is no longer used")))
SC_EXTERN NSString * const kSCAppearanceActionCaseList;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenEmptyIcon")
SC_EXTERN NSString * const kSCAppearanceEmptyIcon;

