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

#import <UIKit/UIKit.h>

@class SCSCategory, SCSArticle, SCSArticleQuery, SCSKnowledgeHomeViewController;

NS_ASSUME_NONNULL_BEGIN

/**
 Delegate protocol for events related to the SCSKnowledgeHomeViewController.
 */
@protocol SCSKnowledgeHomeViewControllerDelegate <NSObject>

@optional

/**
 Informs the delegate when the set of expanded indexes will change.

 @param controller The SCSKnowledgeHomeViewController instance.
 @param newIndexes The new expanded indexes being set.
 */
- (void)knowledgeHome:(SCSKnowledgeHomeViewController*)controller willExpandIndexes:(NSIndexSet*)newIndexes;

/**
 Informs the delegate when the set of expanded indexes has changed.

 @param controller The SCSKnowledgeHomeViewController instance.
 @param newIndexes The new expanded indexes being set.
 */
- (void)knowledgeHome:(SCSKnowledgeHomeViewController*)controller didExpandIndexes:(NSIndexSet*)newIndexes;

/**
 Informs the delegate when an article is selected.

 @param controller The SCSKnowledgeHomeViewController instance.
 @param article The article that was selected.
 @return `YES` if the built-in default action should be performed, otherwise `NO` if no action should be performed.
 */
- (BOOL)knowledgeHome:(SCSKnowledgeHomeViewController*)controller articleSelected:(SCSArticle*)article;

/**
 Informs the delegate when the "Show More Articles" row is tapped for a particular category.

 @param controller The SCSKnowledgeHomeViewController instance.
 @param category The category in which the Show More button was selected.
 @return `YES` if the built-in default action should be performed, otherwise `NO` if no action should be performed.
 */
- (BOOL)knowledgeHome:(SCSKnowledgeHomeViewController*)controller showMoreArticlesSelectedForCategory:(SCSCategory*)category;

@end

/**
 View controller that implements the built-in "Support Home" experience.  This class is not meant to be used when using SCServiceInterface.
 */
@interface SCSKnowledgeHomeViewController : UIViewController

/**
 The parent category this view controller is showing.
 */
@property (nonatomic, strong, readonly) SCSCategory *parentCategory;

/**
 The currently expanded section index set.  Changes from the user will cause KVO events on this property to fire.
 
 The expanded index values represent the childCategory objects within the `parentCategory` object.
 */
@property (null_resettable, nonatomic, copy) NSIndexSet *expandedIndexes;

/**
 Delegate property to use to interact with the knowledge home view controller.
 */
@property (nullable, nonatomic, weak) NSObject<SCSKnowledgeHomeViewControllerDelegate> *delegate;

/**
 Indicates whether or not searching is allowed within this controller.
 */
@property (nonatomic, assign, getter=isSearchEnabled) BOOL searchEnabled;

/**
 Template to use when composing a search to show per-article.  This template object is used for each category within the knowledge home view controller as the basis to find the top articles.
 
 @note The `categories` property is overwritten with the appropriate category being displayed.  Furthermore, it is advisable to avoid setting the `articleId` or `searchTerm` properties, as these may produce unexpected results.
 */
@property (null_resettable, nonatomic, copy) SCSArticleQuery *articleQueryTemplate;

/**
 Designated initializer
 
 @param parentCategory Parent category to use when displaying the interface.
 @return View controller
 */
- (instancetype)initWithParentCategory:(SCSCategory*)parentCategory NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
