/*
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
   MAP_FortranBinding.h
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  	     
   Copyright Sept. 2013
   
   Author: Marco D. Masciola, 
   National Renewable Energy Laboratory, Golden, Colorado, USA
   
   This file is part of the Mooring Analysis Program (MAP).
   
   Licensed to the Apache Software Foundation (ASF) under one
   or more contributor license agreements.  See the NOTICE file
   distributed with this work for additional information
   regarding copyright ownership.  The ASF licenses this file
   to you under the Apache License, Version 2.0 (the
   "License"); you may not use this file except in compliance
   with the License.  You may obtain a copy of the License at
   
   http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing,
   software distributed under the License is distributed on an
   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
   KIND, either express or implied.  See the License for the
   specific language governing permissions and limitations
   under the License.
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*/


#include "MAP_OtherStateType.h" /**
                                 * Preprocessor Defitions in MAP_OtherStateType_class.h
                                 *
                                 * #include "Python.h"
                                 * #include <assert.h>
                                 * #include <sstream>
                                 * #include <ostream>
                                 * #include <iostream>
                                 * #include <fstream>
                                 * #include <time.h>
                                 *
                                 * #include "MAP_InitInputType_class.h" 
                                 *     #include <boost/lexical_cast.hpp>
                                 *     #include <boost/algorithm/string.hpp>
                                 *     #include <string>
                                 *     #include <vector>
                                 *     #include <iomanip>
                                 *
                                 * #include "UserData.h"
                                 *     #include "MAP_BaseType.h"
                                 *         #include "Python.h"
                                 *         #include <boost/python.hpp>
                                 *         #include <boost/python/suite/indexing/vector_indexing_suite.hpp>
                                 *         #include "VarType.h" 
                                 *             #include <boost/lexical_cast.hpp>
                                 *             #include <boost/algorithm/string.hpp>
                                 *             #include <string>
                                 *             #include <iomanip>
                                 *             #include "MAP_Message_class.h" 
                                 *             #include "MAP_ErrStat_class.h"
                                 *     
                                 *     #include "Element.h" 
                                 *         #include "Node.h"  
                                 *             #include "VarType.h"
                                 *                 #include <boost/lexical_cast.hpp>
                                 *                 #include <boost/algorithm/string.hpp>
                                 *                 #include <string>
                                 *                 #include <iomanip>
                                 *                 #include "MAP_Message_class.h" 
                                 *                 #include "MAP_ErrStat_class.h" 
                                 *     
                                 *     #include <petscsnes.h>
                                 */

#include "NWTCFunctions.h"

#ifdef _WIN64
#include <windows.h>
#define CALL __declspec( dllexport ) //define something for Windows (64-bit)
#elif _WIN32
#include <windows.h>
#define CALL __declspec( dllexport ) //define something for Windows (32-bit)
#elif __APPLE__ // Unsupported platform
  
#elif __linux
#define CALL //__attribute__((dllexport) )
#elif __unix // all unices not caught above
#define CALL //__attribute__((dllexport) )
#elif __posix
    // POSIX
#endif


void 
MAPSetInputArray( MAP_InputType            *input , 
                  MAP_InputType_class      *u     ,
                  MAP_OtherStateType       *other ,
                  MAP_OtherStateType_class *o );

void 
MAPSetParameterArray( MAP_ParameterType        *param , 
                      MAP_ParameterType_class  *p     ,
                      MAP_OtherStateType       *other ,
                      MAP_OtherStateType_class *o );

void 
MAPSetConstraintArray( MAP_ConstraintStateType       *constr , 
                       MAP_ConstraintStateType_class *z      ,
                       MAP_OtherStateType            *other  ,
                       MAP_OtherStateType_class      *o );

void 
MAPSetOtherArray( void*                    NULL_A,
                  void*                    NULL_B,
                  MAP_OtherStateType       *other  ,
                  MAP_OtherStateType_class *o );

//void 
//MAPSetInitOutputString( MAP_InitOutputType       *initOut ,
//                        MAP_InitOutputType_class *io      ,
//                        MAP_OtherStateType       *other   ,
//                        MAP_OtherStateType_class *o       );

void 
MAPSetOutputArray( MAP_OutputType           *output , 
                   MAP_OutputType_class     *y      ,
                   MAP_OtherStateType       *other  ,
                   MAP_OtherStateType_class *o );

void 
MAPUnpackConstraint( MAP_ConstraintStateType       *constrData ,
                     MAP_ConstraintStateType_class *z          ,
                     MAP_OtherStateType            *otherState );

void 
MAPUnpackInput( MAP_InputType       *inputData ,
                MAP_InputType_class *u         ,
                MAP_OtherStateType  *otherState );

void 
MAPUnpackOther( MAP_OtherStateType       *otherState ,
                MAP_OtherStateType_class *o);

void 
MAPUnpackParameter( MAP_ParameterType       *paramData ,
                    MAP_ParameterType_class *p         ,
                    MAP_OtherStateType      *otherState );
void 
MAPPackOutput( MAP_OutputType           *output     ,
               MAP_OutputType_class     *y          ,
               MAP_OtherStateType       *otherState ,
               MAP_OtherStateType_class *o          );

void 
MAPPackParameter( MAP_ParameterType       *paramData ,
                  MAP_ParameterType_class *p         ,
                  MAP_OtherStateType      *otherState );

void 
MAPPackConstraint( MAP_ConstraintStateType       *constrData ,
                   MAP_ConstraintStateType_class *z         ,
                   MAP_OtherStateType             *otherState );
void 
MAPPackInput( MAP_InputType       *input ,
              MAP_InputType_class *u     ,
              MAP_OtherStateType  *otherState );


template <class Type> void
MAPPack( Type   *ptr     ,
         int    *index   ,
         int    len      ,
         double *array   ,
         int    *counter )
{
  for(int k=0 ; k<len ; k++ ){                      
    array[k] = ptr->GetVar( index[*counter] );                   
    (*counter)++;                                                    
  };
};


// =================================================================
// These function set the indexing number for the Input, Outputs, 
// Constraints, ect. vectors that are inside MAP. To change a variables 
// in MAP, Object->SetVar( index , value ) is called. These function 
// set index. This is called by the FAST glue code 
// =================================================================
template <class Type> void 
MAPSetArrayIndex( const std::string   &argStr , 
                  int                 &len    , 
                  Type                *Ptr    ,                       
                  std::vector<int>    &index  , 
                  std::vector<double> &value )
{                           
  len = 0;
  value.clear();
  for ( int i=0 ; i<Ptr->size() ; i++ ) {
    if ( argStr == Ptr->GetElementName(i) ) {
      index.push_back(i);
      value.push_back( Ptr->GetVar(i) );
      len++;
    }
  }
};


template <class Type> void
MAPUnpack( Type   *ptr     ,
           int    *index   ,
           int    len      ,
           double *array   ,
           int    *counter )
{
  for(int k=0 ; k<len ; k++ ){         
    ptr->SetVar( index[*counter], array[k] );
    (*counter)++;
  }                                            
};


// =================================================================
// Used in the CALLMAP_MSQS_End routine to clean up allocated 
// arrays. These functions are called once.                   
// =================================================================
void                                                          
MAPDeleteOutputArray( MAP_OutputType *OutData )               
{                                                             
  delete[] OutData->FX;                                       
  delete[] OutData->FY;                                       
  delete[] OutData->FZ;     
  delete[] OutData->writeOutput;
};                                                            
                                                              

void                                                          
MAPDeleteInputArray( MAP_InputType *InputData )               
{                                                             
  delete[] InputData->X;                                      
  delete[] InputData->Y;                                      
  delete[] InputData->Z;                                      
};                                                            
                                                              

void                                                          
MAPDeleteConstraintArray( MAP_ConstraintStateType *ConstrData )
{
  delete[] ConstrData->X;                                    
  delete[] ConstrData->Y;                                    
  delete[] ConstrData->Z;                                    
  delete[] ConstrData->H;                                    
  delete[] ConstrData->V;                                    
};                                                           
                                                             

void                                                         
MAPDeleteParameterArray( MAP_ParameterType *ParamData )      
{                                                            
  delete[] ParamData->Diam;                                  
  delete[] ParamData->MassDenInAir;                          
  delete[] ParamData->EA;                                    
  delete[] ParamData->CB;                                    
  delete[] ParamData->Lu;                                    
  delete[] ParamData->X;                                     
  delete[] ParamData->Y;                                     
  delete[] ParamData->Z;                                     
  delete[] ParamData->FX;                                    
  delete[] ParamData->FY;                                    
  delete[] ParamData->FZ;                                    
  delete[] ParamData->M;                                     
  delete[] ParamData->B;                                     
};                                                           
                                                             
void                                                         
MAPDeleteOtherArray( MAP_OtherStateType *OtherData )         
{
  // Other States                                                                                                        
  delete[] OtherData->FX;                                    
  delete[] OtherData->FY;                                    
  delete[] OtherData->FZ;                                    
  delete[] OtherData->o_index;                               

  // Inputs                                                  
  delete[] OtherData->u_index;                               
                                                             
  // Output                                                  
  delete[] OtherData->y_index;                               
                                                             
  // Constraint                                              
  delete[] OtherData->z_index;                               
                                                             
  // Parameters                                              
  delete[] OtherData->p_index;            
};                                                           

