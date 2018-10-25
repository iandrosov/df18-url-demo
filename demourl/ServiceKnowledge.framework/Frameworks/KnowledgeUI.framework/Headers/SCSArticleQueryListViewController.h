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

#import "SCSCategoryViewController.h"

NS_ASSUME_NONNULL_BEGIN

@class SCSArticleQueryListViewController, SCSArticleQuery;

/**
 Delegate protocol to allow the receiver to interact with, and control the experience of, a category view controller.
 */
@protocol SCSArticleQueryListViewControllerDelegate <SCSCategoryViewControllerDelegate>

@optional

/**
 Informs the delegate when a category is assigned and it begins to load.
 
 @param queryListViewController The SCSArticleQueryListViewController instance.
 @param newQuery The new query being set.
 @param oldQuery The old query that is being replaced.
 */
- (void)articleQueryListViewController:(SCSArticleQueryListViewController*)queryListViewController articleQueryDidChange:(nullable SCSArticleQuery*)newQuery fromOldQuery:(nullable SCSArticleQuery*)oldQuery;

@end

/**
 View controller capable of showing the list of articles that are the result of a query.
 */
@interface SCSArticleQueryListViewController : SCSCategoryViewController

/**
 Designated initializer.

 @param articleQuery Optional query to use when constructing the view controller.
 @return Initialized view controller.
 */
- (instancetype)initWithQuery:(nullable SCSArticleQuery *)articleQuery;

/**
 Delegate property to use to interact with the view controller.
 */
@property (nullable, nonatomic, weak) NSObject<SCSArticleQueryListViewControllerDelegate> *delegate;

/**
 Article query to use when showing articles.
 */
@property (nullable, nonatomic, copy) SCSArticleQuery *articleQuery;

@end

NS_ASSUME_NONNULL_END
