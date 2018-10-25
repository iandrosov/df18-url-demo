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

#ifndef SCS_EXTERN
#ifdef __cplusplus
#define SCS_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SCS_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

#if DEBUG
    #define SCU_UNIT_TESTS_AVAILABLE NS_CLASS_AVAILABLE(10_10, 8_0)
    #define SCU_UNIT_TESTS_EXTERN SCS_EXTERN
#else
    #define SCU_UNIT_TESTS_AVAILABLE NS_CLASS_AVAILABLE(10_10, 8_0)
    #define SCU_UNIT_TESTS_EXTERN SCS_EXTERN
#endif

#ifndef SCSAppearanceImageToken
typedef NSString * SCSAppearanceImageToken NS_STRING_ENUM;
#endif

/* Default appearance styling will be applied */
SCS_EXTERN NSString * const SCUAppearanceStyleDefault;

SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenCategoryHeaderArrow;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenEmptyArticle;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenEmptySection;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSubCategoryIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenActionSearch;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenNoSearchResult;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSearchPlaceholder;

// Deprecated mappings
#define SCS_API_DEPRECATED_WITH_REPLACEMENT(__name) __API_DEPRECATED_WITH_REPLACEMENT(__name, ios(1.0,1.0))

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenCategoryHeaderArrow")
SCS_EXTERN NSString * const kSCAppearanceCategoryHeaderArrow;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenEmptyArticle")
SCS_EXTERN NSString * const kSCAppearanceEmptyArticle;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenEmptySection")
SCS_EXTERN NSString * const kSCAppearanceEmptySection;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSubCategoryIcon")
SCS_EXTERN NSString * const kSCAppearanceSubCategoryIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenActionSearch")
SCS_EXTERN NSString * const kSCAppearanceActionSearch;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenNoSearchResult")
SCS_EXTERN NSString * const kSCAppearanceNoSearchResult;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSearchPlaceholder")
SCS_EXTERN NSString * const kSCAppearanceSearchPlaceholder;
