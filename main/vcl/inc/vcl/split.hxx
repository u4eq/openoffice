/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/

#ifndef _SV_SPLIT_HXX
#define _SV_SPLIT_HXX

#include <vcl/sv.h>
#include <vcl/dllapi.h>
#include <vcl/window.hxx>

#define SPLITTER_DEFAULTSTEPSIZE 0xFFFF

// ------------
// - Splitter -
// ------------

class VCL_DLLPUBLIC Splitter : public Window
{
private:
    Window*             mpRefWin;
    long                mnSplitPos;
    long                mnLastSplitPos;
    long                mnStartSplitPos;
    Point               maDragPos;
    Rectangle           maDragRect;
    sal_Bool                mbHorzSplit;
    sal_Bool                mbDragFull;
    sal_Bool                mbKbdSplitting;
    long                mbInKeyEvent;
    long                mnKeyboardStepSize;
    Link                maStartSplitHdl;
    Link                maSplitHdl;
	Link                maEndSplitHdl;

	SAL_DLLPRIVATE void 	 ImplInitSplitterData();
	SAL_DLLPRIVATE void 	 ImplDrawSplitter();
    SAL_DLLPRIVATE void      ImplSplitMousePos( Point& rPos );
    SAL_DLLPRIVATE void      ImplStartKbdSplitting();
    SAL_DLLPRIVATE void      ImplKbdTracking( KeyCode aKeyCode );
    SAL_DLLPRIVATE sal_Bool      ImplSplitterActive();
    SAL_DLLPRIVATE Splitter* ImplFindSibling();
    SAL_DLLPRIVATE void      ImplRestoreSplitter();
    SAL_DLLPRIVATE void      ImplInitHorVer(bool bNew);

    // Copy assignment is forbidden and not implemented.
	SAL_DLLPRIVATE           Splitter (const Splitter &);
    SAL_DLLPRIVATE           Splitter& operator= (const Splitter &);

protected:
    using Window::ImplInit;
	SAL_DLLPRIVATE void 	 ImplInit( Window* pParent, WinBits nWinStyle );

public:
    explicit            Splitter( Window* pParent, WinBits nStyle = WB_VSCROLL );
    explicit            Splitter( Window* pParent, const ResId& );
    virtual             ~Splitter();

    virtual void        StartSplit();
	virtual void        EndSplit();
    virtual void        Split();
    virtual void        Splitting( Point& rSplitPos );

    virtual void        MouseButtonDown( const MouseEvent& rMEvt );
    virtual void        Tracking( const TrackingEvent& rTEvt );

    virtual long        Notify( NotifyEvent& rNEvt );

	virtual void        GetFocus();
	virtual void        LoseFocus();
	virtual void        KeyInput( const KeyEvent& rKEvt );
	virtual void        Paint( const Rectangle& rPaintRect );

    virtual void        DataChanged( const DataChangedEvent& rDCEvt );

    void                StartDrag();

    void                SetDragRectPixel( const Rectangle& rDragRect,
                                          Window* pRefWin = NULL );
    const Rectangle&    GetDragRectPixel() const { return maDragRect; }
    Window*             GetDragWindow() const { return mpRefWin; }

    virtual void        SetSplitPosPixel( long nPos );
    long                GetSplitPosPixel() const { return mnSplitPos; }

    void                SetLastSplitPosPixel( long nNewPos );
    long                GetLastSplitPosPixel() const { return mnLastSplitPos; }

    sal_Bool            IsHorizontal() const { return mbHorzSplit; }
    void                SetHorizontal(bool bNew);

    // set the stepsize of the splitter for cursor movement
    // the default is 10% of the reference window's width/height
    void                SetKeyboardStepSize( long nStepSize );
    long                GetKeyboardStepSize() const;

    void                SetStartSplitHdl( const Link& rLink ) { maStartSplitHdl = rLink; }
    const Link&         GetStartSplitHdl() const { return maStartSplitHdl; }
    void                SetSplitHdl( const Link& rLink ) { maSplitHdl = rLink; }
	void                SetEndSplitHdl( const Link& rLink ) { maEndSplitHdl = rLink; }
    const Link&         GetEndSplitHdl() const { return maEndSplitHdl; }
    const Link&         GetSplitHdl() const { return maSplitHdl; }
};

#endif  // _SV_SPLIT_HXX

