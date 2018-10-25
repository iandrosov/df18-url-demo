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

NS_ASSUME_NONNULL_BEGIN

@protocol SCSArticleViewControllerDelegate;
@class SCArticleHeaderView, SCSCategory, SCSCategoryGroup, SCSArticle;

/**
 View controller capable of displaying the contents of an article.  When used in
 conjunction with a navigation controller, the `title` property of the view will
 automatically be set to the title of the article, or `nil` if no article is assigned.
 
 Article content is automatically rendered into content capable of being displayed within this view controller.  The articles data is laid out as HTML and rendered within a WKWebView instance.
 
 HTML content is rendered using a structure like the following:
 
     <html>
      <head>
        <meta name="viewport" content="initial-scale=1"/>
        <link rel="stylesheet" href="/style.css" type="text/css" media="all"/>
        <link rel="stylesheet" href="/article/{{article.id}}/style.css" type="text/css" media="all"/>
      </head>
      <body>
        <header>
          {{article.title}}
        </header>
        <main>
          <field name="{{field.name}}" type="{{field.type}}">
            <field-title>{{field.title}}</field-title>
            <field-value>{{field.value}}</field-value>
          </field>
          ...
        </main>
        <script src="/script.js"></script>
        <script src="/article/{{article.id}}/script.js"></script>
      </body>
    </html>

 Each article field is separated into its own block which can be independently formatted, hidden, or otherwise styled using custom CSS.  The default global CSS is automatically populated based on the fonts and colors defined in `SCAppearanceConfiguration`.  Furthermore, if any custom styles need to be changed,  `SCAppearanceConfiguration.globalArticleCSS` property can be used to add default syles that are applied to all articles.  Likewise, the `SCAppearanceConfiguration.globalArticleJavascript` property can be used to supply common javascript to be injected to all articles when they're loaded.
 
 The `-[SCSArticleViewControllerDelegate articleController:additionalCSSForArticle:]` and `-[SCSArticleViewControllerDelegate articleController:additionalJavascriptForArticle:]` delegate methods can be used to provide more granular per-article control over both CSS and javascript.

 */
@interface SCSArticleViewController : UIViewController

/**
 The category information to use when displaying empty content.  If `nil` is assigned, the value
 will automatically reset to the root data category.
 */
@property (null_resettable, nonatomic, strong) SCSCategory *category;

/**
 The article to display.  If the article is not yet cached, its content will automatically
 be downloaded on-demand when the view is loaded.  If `nil` is assigned, an empty view will
 automatically be shown to display information about the data category.
 */
@property (nullable, nonatomic, copy) SCSArticle *article;

/**
 Delegate property to use to interact with the article view controller.
 */
@property (nullable, nonatomic, weak) NSObject<SCSArticleViewControllerDelegate> *delegate;

@end

NS_ASSUME_NONNULL_END
