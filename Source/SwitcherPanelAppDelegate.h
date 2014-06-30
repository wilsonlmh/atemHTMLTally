/* -LICENSE-START-
** Copyright (c) 2011 Blackmagic Design
**
** Permission is hereby granted, free of charge, to any person or organization
** obtaining a copy of the software and accompanying documentation covered by
** this license (the "Software") to use, reproduce, display, distribute,
** execute, and transmit the Software, and to prepare derivative works of the
** Software, and to permit third-parties to whom the Software is furnished to
** do so, all subject to the following:
** 
** The copyright notices in the Software and this entire statement, including
** the above license grant, this restriction and the following disclaimer,
** must be included in all copies of the Software, in whole or in part, and
** all derivative works of the Software, unless such copies or derivative
** works are solely in the form of machine-executable object code generated by
** a source language processor.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
** -LICENSE-END-
*/


#import "BMDSwitcherAPI.h"


#import <list>

#import <Cocoa/Cocoa.h>

class MixEffectBlockMonitor;
class SwitcherMonitor;
class InputMonitor;
@class   HTTPServer;

@interface SwitcherPanelAppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow *window;
	
	IBOutlet NSTextField*		mAddressTextField;
	IBOutlet NSButton*			mConnectButton;
	IBOutlet NSTextField*		mSwitcherNameLabel;
	IBOutlet NSBox*				mMixEffectBlockBox;
	IBOutlet NSPopUpButton*		mProgramInputsPopup;
	IBOutlet NSPopUpButton*		mPreviewInputsPopup;
    
	IBOutlet NSButton*			mCutButton;
	IBOutlet NSButton*			mAutoButton;
	IBOutlet NSButton*			mFTBButton;
	IBOutlet NSSlider*			mSlider;
	IBOutlet NSTextField*		mTransitionFramesTextField;
	IBOutlet NSTextField*		mFTBFramesTextField;
	IBOutlet NSLevelIndicator*	mLevelIndicator;

    IBOutlet NSPopUpButton*     wInputPopup;
    IBOutlet NSTextField*       wMappingNo;
    IBOutlet NSTextField*       wServerPathText;
    IBOutlet NSTextField*       wConnectionStatus;
    IBOutlet NSTextView*        wHTTPServerLog;
    IBOutlet NSTextField*       wHTTPServerStatus;
    IBOutlet NSButton*          wHTTPServerButton;
    IBOutlet NSTextField*       wHTTPServerPortField;
    
	IBMDSwitcherDiscovery*		mSwitcherDiscovery;
	IBMDSwitcher*				mSwitcher;
	IBMDSwitcherMixEffectBlock*	mMixEffectBlock;
	MixEffectBlockMonitor*		mMixEffectBlockMonitor;
	SwitcherMonitor*			mSwitcherMonitor;
	std::list<InputMonitor*>	mInputMonitors;
	bool						mMoveSliderDownwards;
	bool						mCurrentTransitionReachedHalfway;
    
    //************************************************************************
    NSString*                   wServerPath;
    int                         tally[11000];
    BMDSwitcherInputId          lastPreviewId;
    BMDSwitcherInputId          lastProgramId;
    HTTPServer*                 wHTTPServerHandle;
    bool                        wHTTPServerIsRunning;
}

@property (assign) IBOutlet NSWindow *window;

- (void)wUpdateTallyPreview;
- (void)wUpdateTallyProgram;
- (void)writeToServer;
- (void)changeConnectionStatus:(int)statusCode; //0:Disconnected, 1:Connected
- (void)connectBMD;
- (IBAction)wMappingNoChanged:(id)sender;
- (IBAction)wInputPopupChanged:(id)sender;
- (IBAction)wUpdateServerPath:(id)sender;
- (IBAction)wHTTPServerButtonClicked:(id)sender;


- (IBAction)cutButtonPressed:(id)sender;
- (IBAction)autoButtonPressed:(id)sender;
- (IBAction)FTBButtonPressed:(id)sender;
- (IBAction)programPopupChanged:(id)sender;
- (IBAction)previewPopupChanged:(id)sender;
- (IBAction)sliderChanged:(id)sender;

- (void)switcherConnected;
- (void)switcherDisconnected;

- (void)updatePopupButtonItems;
- (void)updateProgramButtonSelection;
- (void)updatePreviewButtonSelection;
- (void)updateInTransitionState;
- (void)updateSliderPosition;
- (void)updateTransitionFramesTextField;
- (void)updateFTBFramesTextField;
- (void)mixEffectBlockBoxSetEnabled:(bool)enabled;

@end
