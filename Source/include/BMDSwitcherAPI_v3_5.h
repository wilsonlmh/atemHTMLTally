/* -LICENSE-START-
** Copyright (c) 2012 Blackmagic Design
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

#ifndef BMD_BMDSWITCHERAPI_V3_5_H
#define BMD_BMDSWITCHERAPI_V3_5_H

#include "BMDSwitcherAPI.h"

// Interface ID Declarations

BMD_CONST REFIID IID_IBMDSwitcherKeyFlyParameters_v3_5                 = /* C522E970-DDB1-4027-B492-F52C1DFA5D09 */ {0xC5,0x22,0xE9,0x70,0xDD,0xB1,0x40,0x27,0xB4,0x92,0xF5,0x2C,0x1D,0xFA,0x5D,0x09};

/* Interface IBMDSwitcherKeyFlyParameters - Key Fly Parameters */

class IBMDSwitcherKeyFlyParameters_v3_5 : public IUnknown
{
public:
    virtual HRESULT GetFly (/* out */ bool* isFlyKey) = 0;
    virtual HRESULT SetFly (/* in */ bool isFlyKey) = 0;
    virtual HRESULT GetCanFly (/* out */ bool* canFly) = 0;
    virtual HRESULT GetRate (/* out */ uint32_t* frames) = 0;
    virtual HRESULT SetRate (/* in */ uint32_t frames) = 0;
    virtual HRESULT GetSizeX (/* out */ double* multiplierX) = 0;
    virtual HRESULT SetSizeX (/* in */ double multiplierX) = 0;
    virtual HRESULT GetSizeY (/* out */ double* multiplierY) = 0;
    virtual HRESULT SetSizeY (/* in */ double multiplierY) = 0;
    virtual HRESULT GetPositionX (/* out */ double* offsetX) = 0;
    virtual HRESULT SetPositionX (/* in */ double offsetX) = 0;
    virtual HRESULT GetPositionY (/* out */ double* offsetY) = 0;
    virtual HRESULT SetPositionY (/* in */ double offsetY) = 0;
    virtual HRESULT GetRotation (/* out */ double* degrees) = 0;
    virtual HRESULT SetRotation (/* in */ double degrees) = 0;
    virtual HRESULT ResetRotation (void) = 0;
    virtual HRESULT ResetDVE (void) = 0; // Resets all DVE parameters, excluding mask
    virtual HRESULT ResetDVEFull (void) = 0; // Resets all DVE parameters to full screen, excluding mask
    virtual HRESULT IsKeyFrameStored (/* in */ BMDSwitcherFlyKeyFrame keyFrame, /* out */ bool* stored) = 0;
    virtual HRESULT StoreAsKeyFrame (/* in */ BMDSwitcherFlyKeyFrame keyFrame) = 0; // Stores current state into the specified Key Frame, only Key Frame A and/or B can be specified.
    virtual HRESULT RunToKeyFrame (/* in */ BMDSwitcherFlyKeyFrame destination) = 0; // Can only specify 1 Key Frame destination
    virtual HRESULT IsAtKeyFrames (/* out */ BMDSwitcherFlyKeyFrame* keyFrames) = 0;
    virtual HRESULT IsRunning (/* out */ bool* isRunning, /* out */ BMDSwitcherFlyKeyFrame* destination) = 0;
    virtual HRESULT AddCallback (/* in */ IBMDSwitcherKeyFlyParametersCallback* callback) = 0;
    virtual HRESULT RemoveCallback (/* in */ IBMDSwitcherKeyFlyParametersCallback* callback) = 0;

protected:
    virtual ~IBMDSwitcherKeyFlyParameters_v3_5 () {}; // call Release method to drop reference count
};

#endif /* defined(BMD_BMDSWITCHERAPI_V3_5_H) */
