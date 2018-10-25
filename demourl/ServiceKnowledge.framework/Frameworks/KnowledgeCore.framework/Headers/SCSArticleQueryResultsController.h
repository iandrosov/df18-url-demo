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

NS_ASSUME_NONNULL_BEGIN

@class SCSArticleQueryResultsController;
@class SCSArticle, SCSArticleQuery, SCSKnowledgeManager;

/**
 Delegate protocol for interacting with a SCSArticleQueryResultsController.
 */
@protocol SCSArticleQueryResultsControllerDelegate <NSObject>

@optional

/**
 Message sent to the delegate when content changes will be made.
 
 @param controller The article query results controller.
 */
- (void)articleQueryWillChangeContent:(SCSArticleQueryResultsController*)controller;

/**
 Message sent to the delegate when content changes have been completed.

 @param controller The article query results controller.
 */
- (void)articleQueryDidChangeContent:(SCSArticleQueryResultsController*)controller;

/**
 Indicates that the controller reloaded its contents entirely.  If the error property is nonnull, then it indicates that an error occurred in the process.

 @param controller The article query results controller.
 @param error The error that occurred, or `nil` if no error was received.
 */
- (void)articleQuery:(SCSArticleQueryResultsController*)controller didReloadWithError:(nullable NSError*)error;

/**
 Sent to the delegate when an article is inserted.
 
 An article may be inserted at an index when it is first found, or when a reload occurs and new articles are found.

 @param controller The article query results controller.
 @param article The article that was inserted.
 @param index The index where the article was inserted.
 */
- (void)articleQuery:(SCSArticleQueryResultsController*)controller article:(SCSArticle*)article insertedAtIndex:(NSUInteger)index;

/**
 Sent to the delegate when an article is deleted.

 Note that the article itself may not have been deleted; this merely means that the article was removed from the fetched list.

 @param controller The article query results controller.
 @param article The article that was deleted.
 @param index The index where the article was deleted.
 */
- (void)articleQuery:(SCSArticleQueryResultsController*)controller article:(SCSArticle*)article deletedAtIndex:(NSUInteger)index;

/**
 Sent to the delegate when an article is updated.

 @param controller The article query results controller.
 @param article The article that was updated.
 @param index The index of the article.
 */
- (void)articleQuery:(SCSArticleQueryResultsController*)controller article:(SCSArticle*)article updatedAtIndex:(NSUInteger)index;

/**
 Sent to the delegate when an article is moved.

 An article may be moved if something influencing its sort criteria changes after a reload.

 @param controller The article query results controller.
 @param article The article that was moved.
 @param oldIndex The index where the article existed prior to this update.
 @param newIndex The new index of the article.
 */
- (void)articleQuery:(SCSArticleQueryResultsController*)controller article:(SCSArticle*)article movedFromIndex:(NSUInteger)oldIndex toIndex:(NSUInteger)newIndex;

/**
 Sent to the delegate when a given page of articles beings loading.
 
 @param controller The article query results controller.
 @param page The page number being loaded.
 */
- (void)articleQuery:(SCSArticleQueryResultsController*)controller willBeginLoadingPage:(NSUInteger)page;

/**
 Sent to the delegate when a given page of articles finishes loading.

 @param controller The article query results controller.
 @param page The page number being loaded.
 @param error The error that occurred, or `nil` if no error was received.
 */
- (void)articleQuery:(SCSArticleQueryResultsController*)controller didFinishLoadingPage:(NSUInteger)page error:(nullable NSError*)error;

@end

/**
 This class is intended to efficiently manage the results of an article query to return an indexed list of articles to the caller.
 
 You configure an instance of this controller with a specific query, and the fetches and pagination will automatically be handled for you.
 Any changes to the set of articles will be communicated through the use of the SCSArticleQueryResultsControllerDelegate, allowing UI
 state to be updated as needed.
 */
@interface SCSArticleQueryResultsController : NSObject

/**
 The query to be performed.  If a `nil` value is supplied, this indicates that no articles should be returned from this controller.  Assigning new values to this property will result in the set of articles returned being changed, with the appropriate delegate calls made to update the caller's state.
 
 @note When this property is changed, no network calls will be automatically made, only the locally-cached article information already stored will be returned immediately.  If you wish for new information to be loaded that matches the supplied query, you must invoke `loadNextPage:` manually.
 
 Assigning a new query will result in the page loading to reset back to the first page of results.
 
 Any in-flight network actions being performed to load new articles will immediately be cancelled when a new query is assigned.
 
 @warning Whenever the query is assigned, the result set must reside within the same knowledgeManager instance, including categories and all other properties.  The behavior is undefined when this condition is not met.
 */
@property (nullable, nonatomic, copy) SCSArticleQuery *query;

/**
 The SCSKnowledgeManager instance this query controller will observe.  All queries assigned to this controller must be scoped by the same knowledge manager.
 */
@property (nonatomic, strong, readonly) SCSKnowledgeManager *knowledgeManager;

/**
 Indicates whether or not this controller is performing a network operation to load more content.
 */
@property (nonatomic, assign, readonly, getter=isLoadingMore) BOOL loadingMore;

/**
 Indicates if there is any more content that can be loaded.
 */
@property (nonatomic, assign, readonly) BOOL canLoadMore;

/**
 When the device is offline and no previously-cached results for the exact search criteria is available, this property will cause the controller to attempt to approximate the search results based on the articles already cached in the database.
 */
@property (nonatomic, assign, getter=shouldApproximateResultsOffline) BOOL approxmiateResultsOffline;

/**
 Delegate to receive updates about changes to the data set.
 */
@property (nullable, nonatomic, weak) NSObject<SCSArticleQueryResultsControllerDelegate> *delegate;

/**
 Initializes a new query controller with the given query and knowledge manager.  The query may be nil, see the `query` property for more information.
 
 @param query The query to perform, or `nil` if no query should be executed.
 @param manager The knowledge manager to scope the query searches within.

 @return Initialized instance.
 */
- (instancetype)initWithQuery:(nullable SCSArticleQuery*)query knowledgeManager:(SCSKnowledgeManager*)manager;

/**
 The number of articles currently available from this controller.
 */
- (NSUInteger)numberOfArticles;

/**
 Returns the article at the given index, or `nil` if the index is out-of-bounds.
 */
- (nullable SCSArticle*)articleAtIndex:(NSUInteger)index;

/**
 Returns the index within this controller where the supplied article can be found, or `NSNotFound` is returned if the article cannot be found within this query controller.
 */
- (NSUInteger)indexForArticle:(SCSArticle*)article;

/**
 Requests that a network operation be performed to load the next page, if available.
 */
- (void)loadNextPage:(nullable void(^)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
