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

typedef NS_ENUM(NSInteger, SCSCategoryDisplayMode) {
    SCSCategoryDisplayModeArticlesOnly,
    SCSCategoryDisplayModeArticlesAndCategories
};

typedef NS_ENUM(NSInteger, SCSCategoryHeaderType) {
    SCSCategoryHeaderTypeArticles = 1,
    SCSCategoryHeaderTypeChildCategories,
};

@class SCSCategory, SCSArticle, SCSCategoryViewController, SCSKnowledgeManager;

NS_ASSUME_NONNULL_BEGIN

/**
 Delegate protocol to allow the receiver to interact with, and control the experience of, a category view controller.
 */
@protocol SCSCategoryViewControllerDelegate <NSObject>

@optional

/**
 Informs the delegate when a category is assigned and it begins to load.

 @param controller The SCSCategoryViewController instance.
 @param category The category that was assigned to the controller.
 */
- (void)categoryController:(SCSCategoryViewController*)controller willLoadCategory:(SCSCategory*)category;

/**
 Informs the delegate when a category is assigned and it completes loading.

 @param controller The SCSCategoryViewController instance.
 @param category The category that was assigned to the controller.
 */
- (void)categoryController:(SCSCategoryViewController*)controller didLoadCategory:(SCSCategory*)category;

/**
 Informs the delegate when a category is selected.

 @param controller The SCSCategoryViewController instance.
 @param category The category that was selected.
 @return `YES` if the built-in default action should be performed, otherwise `NO` if no action should be performed.
 */
- (BOOL)categoryController:(SCSCategoryViewController*)controller childCategorySelected:(SCSCategory*)category;

/**
 Informs the delegate when an article is selected.

 @param controller The SCSCategoryViewController instance.
 @param article The article that was selected.
 @return `YES` if the built-in default action should be performed, otherwise `NO` if no action should be performed.
 */
- (BOOL)categoryController:(SCSCategoryViewController*)controller articleSelected:(SCSArticle*)article;

/**
 Informs the delegate when the "Show More Articles" row is tapped.
 
 This is only supported on controllers that have child categories, and whose display mode is `SCSCategoryDisplayModeArticlesAndCategories`.

 @param controller The SCSCategoryViewController instance.
 @param category The category being shown.
 @return `YES` if the built-in default action should be performed, otherwise `NO` if no action should be performed.
 */
- (BOOL)categoryController:(SCSCategoryViewController*)controller showMoreArticlesSelectedForCategory:(SCSCategory*)category;

/**
 Allows the delegate to customize the header view used for the indicated type.

 If `nil` is returned, then no header will be used for that section.
 
 If you want to use the default header view, don't implement this method.

 The `SCSCategoryHeaderTypeChildCategories` header type is only requested of the delegate when the selected category has child categories, and when the display mode is `SCSCategoryDisplayModeArticlesAndCategories`.

 @param controller The SCSCategoryViewController instance.
 @param headerType The type of header view being requested.
 @param category The category being shown.
 @return A UIView to show in the header section of the given type, or `nil` if no header should be shown.
 */
- (nullable __kindof UIView *)categoryController:(SCSCategoryViewController*)controller headerViewForType:(SCSCategoryHeaderType)headerType forCategory:(SCSCategory*)category;

/**
 Allows the delegate to customize the height of the header view used for the indicated type.
 
 If you want to use the default height, don't implement this method.

 @param controller The SCSCategoryViewController instance.
 @param headerType The type of header view being requested.
 @param category The category being shown.
 @return The desired height of the header.
 */
- (CGFloat)categoryController:(SCSCategoryViewController*)controller heightForHeaderType:(SCSCategoryHeaderType)headerType forCategory:(SCSCategory*)category;

@end

/**
 View controller capable of showing the contents of a category, whether it be child categories, articles, or both.  It can be controlled through assigning a containing category to the `category` property, and implementing the `SCSCategoryViewControllerDelegate` methods.
 */
@interface SCSCategoryViewController : UIViewController

/**
 The display mode used to create this category controller.  This value cannot be changed at runtime.
 */
@property (nonatomic, assign, readonly) SCSCategoryDisplayMode displayMode;

/**
 Indicates the knowledge manager instance that will be used within this controller.
 */
@property (null_resettable, nonatomic, strong) SCSKnowledgeManager *knowledgeManager;

/**
 The category this controller is displaying the contents of.
 */
@property (nullable, nonatomic, strong) SCSCategory *category;

/**
 Delegate property to use to interact with the category view controller.
 */
@property (nullable, nonatomic, weak) NSObject<SCSCategoryViewControllerDelegate> *delegate;

/**
 Indicates whether or not searching is allowed within this controller.
 */
@property (nonatomic, assign, getter=isSearchEnabled) BOOL searchEnabled;

/**
 Indicates whether or not the content of this controller is empty.
 
 @note This will return `true` if the content is still being loaded, since its unclear at that point whether or not the controller will be empty.
 */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/**
 Template to use when composing a search to show per-article.  This template object is used for the current category as the basis to find articles.

 @note The `categories` property is overwritten with the appropriate category being displayed, or will omit the category from the article query if the category property is `nil`.  Furthermore, it is advisable to avoid setting the `articleId` or `searchTerm` properties, as these may produce unexpected results.
 */
@property (null_resettable, nonatomic, copy) SCSArticleQuery *articleQueryTemplate;

/**
 Designated initializer.
 
 @param category Category to show.
 @param displayMode The type of contents to show within the category controller.
 @return Initialized view controller.
 */
- (instancetype)initWithCategory:(nullable SCSCategory *)category displayMode:(SCSCategoryDisplayMode)displayMode NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
