/* 
 * Adium is the legal property of its developers, whose names are listed in the copyright file included
 * with this source distribution.
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#import <Adium/AIAccount.h>
#import "MGTwitterEngine/MGTwitterEngine.h"

typedef enum {
	AITwitterUnknownType = 0,
	AITwitterValidateCredentials,
	AITwitterDisconnect,
	AITwitterInitialUserInfo,
	AITwitterProfileUserInfo,
	AITwitterProfileStatusUpdates,
	AITwitterUserIconPull,
	AITwitterDirectMessageSend,
	AITwitterSendUpdate,
	AITwitterUpdateDirectMessage,
	AITwitterUpdateFollowedTimeline,
	AITwitterUpdateReplies,
	AITwitterRemoveFollow
} AITwitterRequestType;

#define TWITTER_UPDATE_INTERVAL_MINUTES		10
#define TWITTER_UPDATE_TIMELINE_COUNT		0 // get the default amount

#define TWITTER_INCORRECT_PASSWORD_MESSAGE	AILocalizedString(@"Incorrect username or password","Error message displayed when the server reports username or password as being incorrect.")

#define TWITTER_REMOTE_GROUP_NAME			@"Twitter"
#define TWITTER_TIMELINE_NAME				@"Twitter Timeline"
#define TWITTER_TIMELINE_UID				@"twitter-timeline"

#define TWITTER_PREFERENCE_DATE_DM			@"Direct Messages"
#define TWITTER_PREFERENCE_DATE_TIMELINE	@"Followed Timeline"
#define TWITTER_PREFERENCE_GROUP_UPDATES	@"Twitter Preferences"

// Status Updates
#define TWITTER_STATUS_CREATED				@"created_at"
#define TWITTER_STATUS_USER					@"user"
#define TWITTER_STATUS_UID					@"screen_name"
#define TWITTER_STATUS_TEXT					@"text"

// Direct Messages
#define TWITTER_DM_CREATED					@"created_at"
#define TWITTER_DM_SENDER_UID				@"sender_screen_name"
#define TWITTER_DM_TEXT						@"text"

// User Info
#define TWITTER_INFO_STATUS					@"status"
#define TWITTER_INFO_STATUS_TEXT			@"text"

#define TWITTER_INFO_DISPLAY_NAME			@"name"
#define TWITTER_INFO_UID					@"screen_name"
#define TWITTER_INFO_ICON					@"profile_image_url"

@interface AITwitterAccount : AIAccount <MGTwitterEngineDelegate> {
	MGTwitterEngine		*twitterEngine;
	NSTimer				*updateTimer;
	
	AIChat				*timelineChat;
	
	BOOL				followedTimelineCompleted;
	BOOL				repliesCompleted;
	NSMutableArray		*queuedUpdates;
	NSMutableArray		*queuedDM;
	
	NSMutableDictionary	*pendingRequests;
}

@end