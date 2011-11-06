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



#ifndef SC_FUCONSTR_HXX
#define SC_FUCONSTR_HXX

#include "fudraw.hxx"


/************************************************************************/

#define MIN_FREEHAND_DISTANCE	10


/*************************************************************************
|*
|* Rechteck zeichnen
|*
\************************************************************************/

class FuConstruct : public FuDraw
{
 public:
	FuConstruct(ScTabViewShell* pViewSh, Window* pWin, ScDrawView* pView,
				   SdrModel* pDoc, SfxRequest& rReq);

	virtual ~FuConstruct();
									   // Mouse- & Key-Events
	virtual sal_Bool KeyInput(const KeyEvent& rKEvt);
	virtual sal_Bool MouseMove(const MouseEvent& rMEvt);
	virtual sal_Bool MouseButtonUp(const MouseEvent& rMEvt);
	virtual sal_Bool MouseButtonDown(const MouseEvent& rMEvt);
	virtual sal_uInt8 Command(const CommandEvent& rCEvt);

			sal_Bool SimpleMouseButtonUp(const MouseEvent& rMEvt);

	virtual void Activate();		   // Function aktivieren
	virtual void Deactivate();		   // Function deaktivieren
};



#endif		// _SD_FUCONSTR_HXX
