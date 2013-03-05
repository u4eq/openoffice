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



#ifndef __FRAMEWORK_MACROS_REGISTRATION_HXX_
#define __FRAMEWORK_MACROS_REGISTRATION_HXX_

//_________________________________________________________________________________________________________________
//	my own includes
//_________________________________________________________________________________________________________________

#include <macros/debug.hxx>

//_________________________________________________________________________________________________________________
//	interface includes
//_________________________________________________________________________________________________________________
#include <com/sun/star/lang/XSingleServiceFactory.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>

//_________________________________________________________________________________________________________________
//	other includes
//_________________________________________________________________________________________________________________

//_________________________________________________________________________________________________________________
//	namespace
//_________________________________________________________________________________________________________________

//namespace framework{

/*_________________________________________________________________________________________________________________

	macros for registration of services
	Please use follow public macros only!

	IFFACTORY( CLASS )							=> use it as parameter for COMPONENT_GETFACTORY( IFFACTORIES )
	COMPONENTGETIMPLEMENTATIONENVIRONMENT		=> use it to define exported function component_getImplementationEnvironment()
	COMPONENTGETFACTORY( IFFACTORIES )			=> use it to define exported function component_getFactory()

_________________________________________________________________________________________________________________*/

//*****************************************************************************************************************
//	public
//	use it as parameter for COMPONENT_GETFACTORY( IFFACTORIES )
//*****************************************************************************************************************
#define	IFFACTORY( CLASS )																												\
	/* If searched name found ... */																									\
	/* You can't add some statements before follow line ... Here can be an ELSE-statement! */											\
	if ( CLASS::impl_getStaticImplementationName().equals( ::rtl::OUString::createFromAscii( pImplementationName ) ) )					\
	{																																	\
		LOG_REGISTRATION_GETFACTORY( "\t\tImplementationname found - try to create factory! ...\n" )									\
		/* ... then create right factory for this service.									*/											\
		/* xFactory and xServiceManager are local variables of method which use this macro.	*/											\
		xFactory = CLASS::impl_createFactory( xServiceManager );																		\
	}

//*****************************************************************************************************************
//	public
//	define helper to get information about service environment
//*****************************************************************************************************************
#define	COMPONENTGETIMPLEMENTATIONENVIRONMENT																							\
	extern "C" SAL_DLLPUBLIC_EXPORT void SAL_CALL component_getImplementationEnvironment( const	sal_Char**			ppEnvironmentTypeName	,				\
																	 		uno_Environment**	            			)				\
	{																																	\
		*ppEnvironmentTypeName = CPPU_CURRENT_LANGUAGE_BINDING_NAME ;																	\
	}

//*****************************************************************************************************************
//	public
//	define method to instanciate new services
//*****************************************************************************************************************
#define	COMPONENTGETFACTORY( IFFACTORIES )																								\
	extern "C" SAL_DLLPUBLIC_EXPORT void* SAL_CALL component_getFactory(	const	sal_Char*	pImplementationName	,											\
															void*		pServiceManager		,											\
															void*	  /*pRegistryKey*/		)											\
	{																																	\
		LOG_REGISTRATION_GETFACTORY( "\t[start]\n" )																					\
		/* Set default return value for this operation - if it failed. */																\
		void* pReturn = NULL ;																											\
		if	(																															\
				( pImplementationName	!=	NULL ) &&																					\
				( pServiceManager		!=	NULL )																						\
			)																															\
		{																																\
			LOG_REGISTRATION_GETFACTORY( "\t\tpImplementationName and pServiceManager are valid ...\n" )								\
			/* Define variables which are used in following macros. */																	\
			::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface >	xFactory			;					\
			::com::sun::star::uno::Reference< ::com::sun::star::lang::XMultiServiceFactory >	xServiceManager		;					\
			xServiceManager = reinterpret_cast< ::com::sun::star::lang::XMultiServiceFactory* >( pServiceManager )	;					\
			/* These parameter will expand to      */																					\
			/* "IF_NAME_CREATECOMPONENTFACTORY(a)  */																					\
			/*  else                               */																					\
			/*  ...                                */																					\
			/*  else                               */																					\
			/*  IF_NAME_CREATECOMPONENTFACTORY(z)" */																					\
			IFFACTORIES																													\
			/* Factory is valid, if service was found. */																				\
			if ( xFactory.is() == sal_True )																							\
			{																															\
				LOG_REGISTRATION_GETFACTORY( "\t\t\txFactory valid - service was found ...\n" )											\
				xFactory->acquire();																									\
				pReturn = xFactory.get();																								\
			}																															\
		}																																\
		LOG_REGISTRATION_GETFACTORY( "\t[end]\n" )																						\
		/* Return with result of this operation. */																						\
		return pReturn ;																												\
	}

//}		//	namespace framework

#endif	//	#ifndef __FRAMEWORK_MACROS_REGISTRATION_HXX_
