/*=============================================================================
   WARNING!!  This file is overwritten by the UIStyler each time the Styler 
   file is saved.
  
  
        Filename:  select_with_class.h
  
        This file was generated by the NX User Interface Styler
        Created by: Administrator
        Version: NX 7.5
              Date: 01-07-2015
              Time: 17:19
  
   This include file is overwritten each time the UIStyler dialog is
   saved.  Any modifications to this file will be lost.
==============================================================================*/
 
 
#ifndef SELECT_WITH_CLASS_H_INCLUDED
#define SELECT_WITH_CLASS_H_INCLUDED
 
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
 
#define CHANGE_DIALOG_OBJECT_COUNT     ( 0 )
 

/*---------------- UIStyler Callback Prototypes --------------- */
/* The following function prototypes define the callbacks       */
/* specified in your UIStyler built dialog.  You are REQUIRED to*/
/* create the associated function for each prototype.  You must */
/* use the same function name and parameter list when creating  */
/* your callback function.                                      */
/*------------------------------------------------------------- */

int CHANGE_apply_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);




#ifdef __cplusplus
}
#endif



#endif /* SELECT_WITH_CLASS_H_INCLUDED */