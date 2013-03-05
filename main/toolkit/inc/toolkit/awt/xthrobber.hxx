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


#ifndef TOOLKIT_AWT_XTHROBBER_HXX
#define TOOLKIT_AWT_XTHROBBER_HXX

#include <toolkit/awt/vclxwindow.hxx>
#include <toolkit/helper/listenermultiplexer.hxx>
#include <cppuhelper/implbase1.hxx>
#include <comphelper/uno3.hxx>
#include <com/sun/star/awt/XThrobber.hpp>

#include <boost/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>

//........................................................................
namespace toolkit
{
//........................................................................

    //====================================================================
	//= XThrobber
	//====================================================================
    typedef ::cppu::ImplInheritanceHelper1  <   VCLXWindow
                                            ,   ::com::sun::star::awt::XThrobber
                                            >   XThrobber_Base;

    class XThrobber :public XThrobber_Base
                    ,public ::boost::noncopyable
	{
    private:
        void SAL_CALL InitImageList() throw(::com::sun::star::uno::RuntimeException);

    public:
        XThrobber();

    protected:
        ~XThrobber();

        // XThrobber
        virtual void SAL_CALL start() throw (::com::sun::star::uno::RuntimeException);
        virtual void SAL_CALL stop() throw (::com::sun::star::uno::RuntimeException);

        // VCLXWindow
	    virtual void	SetWindow( Window* pWindow );

    private:
        XThrobber( const XThrobber& );            // never implemented
        XThrobber& operator=( const XThrobber& ); // never implemented
	};

//........................................................................
} // namespacetoolkit
//........................................................................

#endif // TOOLKIT_AWT_XTHROBBER_HXX

