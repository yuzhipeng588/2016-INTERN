/*=============================================================================
   WARNING!!  This file is overwritten by the UIStyler each time the Styler 
   file is saved.
  
  
        Filename:  select_feature.h
  
        This file was generated by the NX User Interface Styler
        Created by: Administrator
        Version: NX 7.5
              Date: 12-25-2014
              Time: 19:58
  
   This include file is overwritten each time the UIStyler dialog is
   saved.  Any modifications to this file will be lost.
==============================================================================*/
 
 
#ifndef SELECT_FEATURE_H_INCLUDED
#define SELECT_FEATURE_H_INCLUDED
 
#include <uf.h> 
#include <uf_defs.h>
#include <uf_styler.h> 


#ifdef __cplusplus
extern "C" {
#endif


/*------------------ UIStyler Dialog Definitions  ------------------- */
/* The following values are definitions into your UIStyler dialog.    */
/* These values will allow you to modify existing objects within your */
/* dialog.   They work directly with the NX Open API,                 */
/* UF_STYLER_ask_value, UF_STYLER_ask_values, and UF_STYLER_set_value.*/
/*------------------------------------------------------------------- */
 
#define SELECT_DIALOG_OBJECT_COUNT     ( 0 )
 

/*---------------- UIStyler Callback Prototypes --------------- */
/* The following function prototypes define the callbacks       */
/* specified in your UIStyler built dialog.  You are REQUIRED to*/
/* create the associated function for each prototype.  You must */
/* use the same function name and parameter list when creating  */
/* your callback function.                                      */
/*------------------------------------------------------------- */

int SELECT_construct_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);

int SELECT_ok_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);

int SELECT_apply_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);

int SELECT_cancel_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);




#ifdef __cplusplus
}
#endif



#endif /* SELECT_FEATURE_H_INCLUDED */
