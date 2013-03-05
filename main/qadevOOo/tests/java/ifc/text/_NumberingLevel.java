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



package ifc.text;

import com.sun.star.beans.PropertyValue;
import java.util.Enumeration;
import java.util.Hashtable;
import lib.StatusException;
import lib.TestParameters;
import share.LogWriter;


/**
* Testing <code>com.sun.star.text.NumberingLevel</code><p>
* This service is currently konwn as property value of 
* com.sun.star.text.ParagraphProperties.NumberingRules
* This test checks only for completnes of implemented properties.
* service properties :
* <ul>
*  <li><code> Adjust</code></li>
*  <li><code> ParentNumbering</code></li>
*  <li><code> Prefix</code></li>
*  <li><code> Suffix</code></li>
*  <li><code> CharStyleName</code></li>
*  <li><code> BulletId</code></li>
*  <li><code> BulletChar</code></li>
*  <li><code> BulletFontName</code></li>
*  <li><code> BulletFont</code></li>
*  <li><code> GraphicURL</code></li>
*  <li><code> GraphicBitmap</code></li>
*  <li><code> GraphicSize</code></li>
*  <li><code> VertOrient</code></li>
*  <li><code> StartWith</code></li>
*  <li><code> LeftMargin</code></li>
*  <li><code> SymbolTextDistance</code></li>
*  <li><code> FirstLineOffset</code></li>
*  <li><code> NumberingType</code></li>
*  <li><code> HeadingStyleName</code></li>
*  <li><code> BulletColor</code></li>
*  <li><code> BulletRelSize</code></li>
* </ul> <p>
*
* @see com.sun.star.text.NumberingLevel
* @see com.sun.star.test.ParagraphProperties
* @see ifc.text._ParagraphProperties
*/
public class _NumberingLevel {
    
    private static TestParameters tParam = null;
    private static Hashtable NumberingLevel = new Hashtable();
    private static PropertyValue[] PropertyArray = null;
    private static LogWriter log = null;
    
    
    /**
     * returns an instance of _NumberingLevel
     * @param log the log writer
     * @param tParam the test parameters
     * @param propertyValues a PropertyValue[] which should contain all properties of com.sun.star.text.NumberingLevel
     */
    public _NumberingLevel(LogWriter log, TestParameters tParam, PropertyValue[] propertyValues){
    
        this.tParam = tParam;
        this.PropertyArray = propertyValues;
        
        this.log = log;
        
        //key = PropertyName, value = Ooptional
        NumberingLevel.put("Adjust", new Boolean(false));
        NumberingLevel.put("ParentNumbering", new Boolean(true));
        NumberingLevel.put("Prefix", new Boolean(false));
        NumberingLevel.put("Suffix", new Boolean(false));
        NumberingLevel.put("CharStyleName", new Boolean(true));
        NumberingLevel.put("BulletId", new Boolean(true));
        NumberingLevel.put("BulletChar", new Boolean(false));
        NumberingLevel.put("BulletFontName", new Boolean(false));
        NumberingLevel.put("BulletFont", new Boolean(true));
        NumberingLevel.put("GraphicURL", new Boolean(false));
        NumberingLevel.put("GraphicBitmap", new Boolean(true));
        NumberingLevel.put("GraphicSize", new Boolean(true));
        NumberingLevel.put("VertOrient", new Boolean(true));
        NumberingLevel.put("StartWith", new Boolean(true));
        NumberingLevel.put("LeftMargin", new Boolean(false));
        NumberingLevel.put("SymbolTextDistance", new Boolean(true));
        NumberingLevel.put("FirstLineOffset", new Boolean(false));
        NumberingLevel.put("NumberingType", new Boolean(false));
        NumberingLevel.put("HeadingStyleName", new Boolean(false));
        NumberingLevel.put("BulletColor", new Boolean(true));
        NumberingLevel.put("BulletRelSize", new Boolean(true));
        
    }
    
    /**
     * This methods checks the PropertyValue for completnes. If one or more properties 
     * are missing the return value is FALSE, else TRUE
     * @return returns TRUE if PropertyValue[] is complete, else FALSE
     */
    public boolean testPropertieArray(){
        
        boolean status = true;
        try{
            
            // iterate over the given property array and remove it from the must list
            for (int i = 0; i < PropertyArray.length; i++){
                String propertyName=PropertyArray[i].Name;
                
                if ( NumberingLevel.containsKey(propertyName) ) {
                    NumberingLevel.remove(propertyName);
                } else {
                    status = false;
                        if ( status ) {
                            log.println("FAILED: com.sun.star.text.NumberingLevel -> " +
                                        "found not described property:");
                        }

                        status = false;
                        log.println("-> '" + propertyName + "'");
                }
                
            }
            
            // get rest of properties and check if they are optional
            if (! NumberingLevel.isEmpty()){
                for (Enumeration e = NumberingLevel.keys() ; e.hasMoreElements() ;) {
                    String property = (String) e.nextElement();
                    
                    // if some elements are not optional -> failed
                    if ( ! ((Boolean)NumberingLevel.get(property)).booleanValue() ){
                        
                        if ( status ) {
                            log.println("FAILED: com.sun.star.text.NumberingLevel -> " +
                                        "could not find not optional property:");
                        }

                        status = false;
                        log.println("-> '" + property + "'");
                    }
                }
            }

        }catch( Exception e ){
            throw new StatusException("ERROR: could not test all properties of com.sun.star.text.NumberingLevel",e);
        }
        
        return status;
    }
    
    
}  // finish class _NumberingLevel
