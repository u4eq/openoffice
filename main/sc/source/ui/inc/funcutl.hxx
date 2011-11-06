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



#ifndef SC_FUNCUTL_HXX
#define SC_FUNCUTL_HXX

#ifndef _SCRBAR_HXX //autogen
#include <vcl/scrbar.hxx>
#endif
#ifndef _FIXED_HXX //autogen
#include <vcl/fixed.hxx>
#endif
#include <svtools/svmedit.hxx>
#include "anyrefdg.hxx"		// formula::RefButton


//============================================================================
// class ValWnd

class ValWnd : public Window
{
public:
			ValWnd( Window* pParent, const ResId& rId );

	void	SetValue( const String& rStrVal );

protected:
	virtual void	Paint( const Rectangle& rRect );

private:
	String		aStrValue;
	Rectangle	aRectOut;
};


//============================================================================
// class ScEditBox

class ScEditBox : public Control
{
private:

	MultiLineEdit*	pMEdit;
	Link			aSelChangedLink;
	Selection		aOldSel;
	sal_Bool			bMouseFlag;
					DECL_LINK( ChangedHdl, ScEditBox* );

protected:

	virtual long	PreNotify( NotifyEvent& rNEvt );
	virtual void	SelectionChanged();
	virtual void	Resize();
	virtual void	GetFocus();


public:
					ScEditBox( Window* pParent, const ResId& rResId );

					~ScEditBox();

	MultiLineEdit*	GetEdit() {return pMEdit;}

	void            SetSelChangedHdl( const Link& rLink ) { aSelChangedLink = rLink; }
	const Link&     GetSelChangedHdl() const { return aSelChangedLink; }

	void			UpdateOldSel();
};



//============================================================================
// class ArgEdit

class ArgEdit : public formula::RefEdit
{
public:
			ArgEdit( Window* pParent, const ResId& rResId );

	void	Init( ArgEdit* pPrevEdit, ArgEdit* pNextEdit,
				  ScrollBar& rArgSlider, sal_uInt16 nArgCount );

protected:
	virtual void	KeyInput( const KeyEvent& rKEvt );

private:
	ArgEdit*	pEdPrev;
	ArgEdit*	pEdNext;
	ScrollBar*	pSlider;
	sal_uInt16		nArgs;
};


//============================================================================
// class ArgInput

class ArgInput
{
private:

	Link			aFxClickLink;
	Link			aRefClickLink;
	Link			aFxFocusLink;
	Link			aRefFocusLink;
	Link			aEdFocusLink;
	Link			aEdModifyLink;

	FixedText*		pFtArg;
	ImageButton*	pBtnFx;
	ArgEdit*		pEdArg;
	formula::RefButton*	pRefBtn;

	DECL_LINK(	FxBtnClickHdl, ImageButton* );
	DECL_LINK(	RefBtnClickHdl,formula::RefButton* );
	DECL_LINK(	FxBtnFocusHdl, ImageButton* );
	DECL_LINK(	RefBtnFocusHdl,formula::RefButton* );
	DECL_LINK(	EdFocusHdl, ArgEdit* );
	DECL_LINK(	EdModifyHdl,ArgEdit* );

protected:

	virtual void	FxClick();
	virtual void	RefClick();
	virtual void	FxFocus();
	virtual void	RefFocus();
	virtual void	EdFocus();
	virtual void	EdModify();

public:

	ArgInput();

	void		InitArgInput (	FixedText*		pftArg,
								ImageButton*	pbtnFx,
								ArgEdit*		pedArg,
								formula::RefButton*	prefBtn);

	void		SetArgName(const String &aArg);
	String		GetArgName();
	void		SetArgNameFont(const Font&);

	void		SetArgVal(const String &aVal);
	String		GetArgVal();

	void		SetArgSelection	(const Selection& rSel );

	ArgEdit*	GetArgEdPtr() {return pEdArg;}


	void            SetFxClickHdl( const Link& rLink ) { aFxClickLink = rLink; }
	const Link&     GetFxClickHdl() const { return aFxClickLink; }

	void            SetRefClickHdl( const Link& rLink ) { aRefClickLink = rLink; }
	const Link&     GetRefClickHdl() const { return aRefClickLink; }

	void            SetFxFocusHdl( const Link& rLink ) { aFxFocusLink = rLink; }
	const Link&     GetFxFocusHdl() const { return aFxFocusLink; }

	void            SetRefFocusHdl( const Link& rLink ) { aRefFocusLink = rLink; }
	const Link&     GetRefFocusHdl() const { return aRefFocusLink; }

	void            SetEdFocusHdl( const Link& rLink ) { aEdFocusLink = rLink; }
	const Link&     GetEdFocusHdl() const { return aEdFocusLink; }

	void            SetEdModifyHdl( const Link& rLink ) { aEdModifyLink = rLink; }
	const Link&     GetEdModifyHdl() const { return aEdModifyLink; }

	void Hide();
	void Show();

};


#endif
