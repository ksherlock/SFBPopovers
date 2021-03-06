/*
 * Copyright (C) 2011 - 2019 Stephen F. Booth <me@sbooth.org>
 * See https://github.com/sbooth/SFBPopovers/blob/master/LICENSE.txt for license information
 */

#import <Cocoa/Cocoa.h>

// ========================================
// Positioning constants
// ========================================
typedef NS_ENUM(NSUInteger, SFBPopoverPosition) {
	SFBPopoverPositionLeft          = NSMinXEdge,
	SFBPopoverPositionRight         = NSMaxXEdge,
	SFBPopoverPositionTop           = NSMaxYEdge,
	SFBPopoverPositionBottom        = NSMinYEdge,
	SFBPopoverPositionLeftTop       = 4,
	SFBPopoverPositionLeftBottom    = 5,
	SFBPopoverPositionRightTop      = 6,
	SFBPopoverPositionRightBottom   = 7,
	SFBPopoverPositionTopLeft       = 8,
	SFBPopoverPositionTopRight      = 9,
	SFBPopoverPositionBottomLeft    = 10,
	SFBPopoverPositionBottomRight   = 11
};

// ========================================
// A class that controls display of a popover
// ========================================
@interface SFBPopover : NSResponder

// ========================================
// Properties
@property (nonatomic, assign) BOOL animates;
@property (nonatomic, assign) BOOL closesWhenPopoverResignsKey;
@property (nonatomic, assign) BOOL closesWhenApplicationBecomesInactive;

// ========================================
// Creation
- (nullable instancetype) initWithContentView:(nonnull NSView *)contentView;
- (nullable instancetype) initWithContentViewController:(nonnull NSViewController *)contentViewController;

// ========================================
// Geometry determination
- (SFBPopoverPosition) bestPositionInWindow:(nonnull NSWindow *)window atPoint:(NSPoint)point;

// ========================================
// Show the popover- prefer these to showWindow:
- (void) displayPopoverInWindow:(nonnull NSWindow *)window atPoint:(NSPoint)point;
- (void) displayPopoverInWindow:(nonnull NSWindow *)window atPoint:(NSPoint)point chooseBestLocation:(BOOL)chooseBestLocation;
- (void) displayPopoverInWindow:(nonnull NSWindow *)window atPoint:(NSPoint)point chooseBestLocation:(BOOL)chooseBestLocation makeKey:(BOOL)makeKey;

// ========================================
// Move the popover to a new attachment point (should be currently displayed)
- (void) movePopoverToPoint:(NSPoint)point;

// ========================================
// Close the popover
- (IBAction) closePopover:(nullable id)sender;

// ========================================
// Returns the popover window
- (nonnull NSWindow *) popoverWindow;

// ========================================
// Returns YES if the popover is visible
- (BOOL) isVisible;

// ========================================
// Popover window properties

// The popover's position relative to its attachment point
- (SFBPopoverPosition) position;
- (void) setPosition:(SFBPopoverPosition)position;

// The distance between the attachment point and the popover window
- (CGFloat) distance;
- (void) setDistance:(CGFloat)distance;

// The popover's border color
- (nonnull NSColor *) borderColor;
- (void) setBorderColor:(nonnull NSColor *)borderColor;

// The width of the popover window's border
- (CGFloat) borderWidth;
- (void) setBorderWidth:(CGFloat)borderWidth;

// The radius of the popover window's border
- (CGFloat) cornerRadius;
- (void) setCornerRadius:(CGFloat)cornerRadius;

// Specifies if the popover window has an arrow pointing toward the attachment point
- (BOOL) drawsArrow;
- (void) setDrawsArrow:(BOOL)drawsArrow;

// The width of the arrow, if applicable
- (CGFloat) arrowWidth;
- (void) setArrowWidth:(CGFloat)arrowWidth;

// The height of the arrow, if applicable
- (CGFloat) arrowHeight;
- (void) setArrowHeight:(CGFloat)arrowHeight;

// If the arrow is drawn by a corner of the window, specifies whether that corner should be rounded
- (BOOL) drawRoundCornerBesideArrow;
- (void) setDrawRoundCornerBesideArrow:(BOOL)drawRoundCornerBesideArrow;

// The spacing between the edge of the popover's content view and its border
- (CGFloat) viewMargin;
- (void) setViewMargin:(CGFloat)viewMargin;

// The popover's background color
- (nonnull NSColor *) backgroundColor;
- (void) setBackgroundColor:(nonnull NSColor *)backgroundColor;

// Specifies whether the popover may be moved by dragging
- (BOOL) isMovable;
- (void) setMovable:(BOOL)movable;

// Specifies whether the popover may be resized
- (BOOL) isResizable;
- (void) setResizable:(BOOL)resizable;

@end
