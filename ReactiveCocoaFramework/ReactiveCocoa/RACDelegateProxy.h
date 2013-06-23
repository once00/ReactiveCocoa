//
//  RACDelegateProxy.h
//  ReactiveCocoa
//
//  Created by Cody Krieger on 5/19/12.
//  Copyright (c) 2012 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RACSignal;

// A delegate object suitable for using -rac_signalForSelector:fromProtocol:
// upon.
@interface RACDelegateProxy : NSObject

// The delegate to which messages should be forwarded if not handled by
// any -signalForSelector: applications.
@property (nonatomic, weak) id rac_proxiedDelegate;

// The KVC key determining the delegator's delegate property.
// Defaults to @"delegate".
@property (nonatomic, copy) NSString *delegateKey;

// Creates a delegate proxy for the delegator, which will respond to selectors
// from `protocol`.
- (instancetype)initWithDelegator:(NSObject *)delegator protocol:(Protocol *)protocol;

// Calls -rac_signalForSelector:fromProtocol: using the `protocol` specified
// during initialization, and scopes the signal to the lifetime of the delegator.
- (RACSignal *)signalForSelector:(SEL)selector;

@end
