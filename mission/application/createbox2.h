/*=============================================================================
   WARNING!!  This file is overwritten by the UIStyler each time the Styler 
   file is saved.
  
  
        Filename:  createbox2.h
  
        This file was generated by the NX User Interface Styler
        Created by: Administrator
        Version: NX 7.5
              Date: 12-10-2014
              Time: 16:43
  
   This include file is overwritten each time the UIStyler dialog is
   saved.  Any modifications to this file will be lost.
==============================================================================*/
 
 
#ifndef CREATEBOX2_H_INCLUDED
#define CREATEBOX2_H_INCLUDED
 
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
 
#define MY_REAL_0                      ("REAL_0")
#define MY_REAL_1                      ("REAL_1")
#define MY_REAL_2                      ("REAL_2")
#define MY_REAL_3                      ("REAL_3")
#define MY_REAL_4                      ("REAL_4")
#define MY_REAL_5                      ("REAL_5")
#define MY_DIALOG_OBJECT_COUNT         ( 6 )
 

/*---------------- UIStyler Callback Prototypes --------------- */
/* The following function prototypes define the callbacks       */
/* specified in your UIStyler built dialog.  You are REQUIRED to*/
/* create the associated function for each prototype.  You must */
/* use the same function name and parameter list when creating  */
/* your callback function.                                      */
/*------------------------------------------------------------- */

int MY_ok_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);

int MY_apply_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);

int MY_cancel_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data);




#ifdef __cplusplus
}
#endif



#endif /* CREATEBOX2_H_INCLUDED */
