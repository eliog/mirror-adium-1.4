//
//  AIFacebookXMPPAccountViewController.h
//  Adium
//
//  Created by Colin Barrett on 11/18/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "PurpleAccountViewController.h"
#import <WebKit/WebKit.h>

@interface AIFacebookXMPPAccountViewController : PurpleAccountViewController {
	NSTextField *label_instructions;
	AILocalizationButton *button_OAuthStart;
	NSTextField *textField_OAuthStatus;
	NSProgressIndicator *spinner;
	
	NSButton *button_help;
}

@property (assign) IBOutlet NSTextField *label_instructions;
@property (assign) IBOutlet NSProgressIndicator *spinner;
@property (assign) IBOutlet NSTextField *textField_OAuthStatus;
@property (assign) IBOutlet AILocalizationButton *button_OAuthStart;
@property (assign) IBOutlet NSButton *button_help;

- (IBAction)showHelp:(id)sender;

@end
