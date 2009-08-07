//
//  SessionManager.h
//  Recon
//
//  Created by Sumanth Peddamatham on 7/8/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class Profile;
@class Session;
@class SessionController;

@interface SessionManager : NSObject
{
	NSMutableDictionary *sessionControllers;   
   BOOL processingQueue;

   NSArrayController *sessionsArrayController;
}

+ (SessionManager *)sharedSessionManager;
@property (readonly) NSManagedObjectContext *context;
@property (readwrite, retain)NSArrayController *sessionsArrayController;

- (void)setContext:(NSManagedObjectContext *)c;

- (Session *)queueSessionWithProfile:(Profile *)profile withTarget:(NSString *)target;
- (Session *)queueExistingSession:(Session *)session withGrowl:(BOOL)notify;
- (void)queueExistingSessions:(NSArray *)sessions;

- (void)deleteSession:(Session *)session;
- (void)abortSession:(Session *)session;
- (void)launchSession:(Session *)session;
- (void)launchNextSession;
- (void)updateQueueFlag;
- (void)processQueue;

- (void)registerNotificationsFromSessionController:(SessionController *)sc;

@end


