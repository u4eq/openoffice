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



#ifndef SD_FRAMEWORK_CHANGE_OPERATION_QUEUE_HXX
#define SD_FRAMEWORK_CHANGE_OPERATION_QUEUE_HXX

#include <com/sun/star/drawing/framework/XConfigurationChangeRequest.hpp>

#include <list>

namespace sd { namespace framework {


/** The ChangeRequestQueue stores the pending requests for changes to the
    requested configuration.  It is the task of the
    ChangeRequestQueueProcessor to process these requests.
*/
class ChangeRequestQueue
    : public ::std::list<com::sun::star::uno::Reference<
        ::com::sun::star::drawing::framework::XConfigurationChangeRequest> >
{
public:
    /** Create an empty queue.
    */
    ChangeRequestQueue (void);
};


} } // end of namespace sd::framework

#endif
