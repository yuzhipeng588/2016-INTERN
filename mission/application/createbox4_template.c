

/*=============================================================================
   WARNING!!  This file is overwritten by the UIStyler each time the Styler 
   file is saved.
  
  
        Filename:  createbox4_template.c
  
        This file was generated by the NX User Interface Styler
        Created by: Administrator
        Version: NX 7.5
              Date: 12-22-2014
              Time: 16:06
  
   This template file is overwritten each time the UIStyler dialog is
   saved.  Any modifications to this file will be lost.
==============================================================================*/
 


/*==============================================================================
   Purpose:  This TEMPLATE file contains C source and static structures to      
   guide you in the construction of your NX Open application dialog.            
   The generation of your dialog file (.dlg extension) is the first step towards
   dialog construction within Unigraphics.  You must now create a UGOpen        
   application that utilizes this file (.dlg).                                  
                                                                                
   The information in this file provides you with the following:                
                                                                                
   1.  Help on the use of the functions, UF_MB_add_styler_actions and           
       UF_STYLER_create_dialog in your NX Open application.  These functions    
       will load and display your UIStyler dialog in Unigraphics.               
                                                                                
       An example of the function, UF_MB_add_styler_actions to associate your   
       dialog to the menubar is shown below (Search on Example 1).              
                                                                                
       An example of a invoking a dialog from a callback utilizing              
       UF_STYLER_create_dialog is also shown below (Search for Example 2).      
                                                                                
       An example of a user exit utilizing UF_STYLER_create_dialog is also      
       shown below (Search for Example 3).                                      
                                                                                
   2.  The callback structure: --- BLOCK_cbs ---               
       This structure is VERY important if you have callbacks associated with   
       your dialog.  It correlates the dialog items in your dialog with the     
       callback functions you must supply.  You should not modify this          
       structure since it MUST match up to the information stored in your       
       dialog file (.dlg).  Any attempt to do so will cause an error while      
       constructing your dialog.   If you wish to modify the association of     
       your callbacks to your dialog, please reload your dialog file (.dlg) into
       the UIStyler and regenerate your files.                                  
       You do not need to be concerned about this structure, simply pass it as  
       an argument to the function, UF_STYLER_create_dialog along with your     
       dialog file (.dlg).
       
       Example 1 displays the actual call you may make for this particular      
       dialog.                                                                  
                                                                                
   3.  The empty callback functions (stubs) associated with your dialog items   
       have also been placed in this file.  These empty functions have been     
       created simply to start you along with your coding requirements.         
       The function name, argument list and possible return values have already 
       been provided for you.                                                   
                                                                                
NOTE:  Each callback must be wrappered with the functions UF_initialize()       
       and UF_terminate().                                                      
                                                                                
==============================================================================*/



/* These include files are needed for the following template code.            */
#include <stdio.h> 
#include <uf.h>
#include <uf_defs.h>
#include <uf_exit.h>
#include <uf_ui.h>
#include <uf_styler.h>
#include <uf_mb.h> 
#include <uf_modl.h>
#include "createbox4.h"

/* The following definition defines the number of callback entries */
/* in the callback structure:                                      */
/* UF_STYLER_callback_info_t BLOCK_cbs */
#define BLOCK_CB_COUNT ( 3 + 1 ) /* Add 1 for the terminator */
 
/*--------------------------------------------------------------------------
The following structure defines the callback entries used by the       
styler file.  This structure MUST be passed into the user function,    
UF_STYLER_create_dialog along with BLOCK_CB_COUNT.                       
--------------------------------------------------------------------------*/
static UF_STYLER_callback_info_t BLOCK_cbs[BLOCK_CB_COUNT] = 
{
 {UF_STYLER_DIALOG_INDEX, UF_STYLER_OK_CB           , 0, BLOCK_ok_cb},
 {UF_STYLER_DIALOG_INDEX, UF_STYLER_APPLY_CB        , 0, BLOCK_apply_cb},
 {UF_STYLER_DIALOG_INDEX, UF_STYLER_CANCEL_CB       , 0, BLOCK_cancel_cb},
 {UF_STYLER_NULL_OBJECT, UF_STYLER_NO_CB, 0, 0 }
};



/*--------------------------------------------------------------------------
UF_MB_styler_actions_t contains 4 fields.  These are defined as follows:
 
Field 1 : the name of your dialog that you wish to display.
Field 2 : any client data you wish to pass to your callbacks.
Field 3 : your callback structure.
Field 4 : flag to inform menubar of your dialog location.  This flag MUST  
          match the resource set in your dialog!  Do NOT ASSUME that changing 
          this field will update the location of your dialog.  Please use the 
          UIStyler to indicate the position of your dialog.
--------------------------------------------------------------------------*/
static UF_MB_styler_actions_t actions[] = {
    { "createbox4.dlg",  NULL,   BLOCK_cbs,  UF_MB_STYLER_IS_NOT_TOP },
    { NULL,  NULL,  NULL,  0 } /* This is a NULL terminated list */
};








/*---------------- MENUBAR HOOKUP HELP Example -------------------
To launch this dialog from a Unigraphics menubar, you must follow 
the steps below.
1)  Add the following lines to your MenuScript file in order to 
    associate a menu bar button with your dialog.  In this     
    example, a cascade menu will be created and will be        
    located just before the Help button on the main menubar.   
    The button, CREATEBOX4_BTN is set up to launch your dialog and 
    will be positioned as the first button on your pulldown menu.
    If you wish to add the button to an existing cascade, simply 
    add the 3 lines between MENU LAUNCH_CASCADE and END_OF_MENU  
    to your menuscript file.  
    
    The MenuScript file requires an extension of ".men".
    Make sure that you add the extension to the file and place  
    the file in your startup directory:
      $UGII_USER_DIR/startup or 
      $UGII_SITE_DIR/startup or 
      $UGII_VENDOR_DIR/startup directory


    Move the contents between the dashed lines to your Menuscript file.
!   ----------------------------------------------------------------
    VERSION 120

    EDIT UG_GATEWAY_MAIN_MENUBAR

    BEFORE UG_HELP
      CASCADE_BUTTON UISTYLER_DLG_CASCADE_BTN
      LABEL Dialog Launcher
    END_OF_BEFORE
 
    MENU UISTYLER_DLG_CASCADE_BTN
      BUTTON CREATEBOX4_BTN
      LABEL Display createbox4 dialog
      ACTIONS createbox4.dlg
    END_OF_MENU
!   ---------------------------------------------------------------


2) Issue a call to the function, UF_MB_add_styler_actions from the ufsta
   user exit as shown below.  To use this call, remove the conditional 
   definitions:  #ifdef MENUBAR_COMMENTED_OUT 
                 #endif MENUBAR_COMMENTED_OUT 
   
   The static structure, actions, will allow you to associate ALL of your
   dialogs and callback functions to the  menubar at once.  For example, if you 
   wish to have 10 dialogs associated to 10 different buttons on the menubar,
   you may enter each dialog and callback list into the actions structure. Make
   sure that you have created a corresponding button in your MenuScript file.
   
   You may also have separate shared libraries, each with a ufsta user exit
   for each individual dialog.


3) Place your compiled and linked ufsta user function in 
   $UGII_USER_DIR/startup or   
   $UGII_SITE_DIR/startup or 
   $UGII_VENDOR_DIR/startup directory.     
 
   NOTE:  The user function must contain the proper extension .so, .sl or .dll 
   to make ensure that it is recognized by the MenuScript.  If it does not
   have the proper extension, it will NOT be recognized by MenuScript.    


   The action name you have provided in your MenuScript must correspond to
   to the dialog name provided in the action structure.  This MUST match inorder
   to bind your dlg file to your MenuScript button.                            


4) Copy your UIStyler dialog file to the proper directory.
   All dialog files (.dlg) must be located in 
      $UGII_USER_DIR/application or 
      $UGII_SITE_DIR/application or 
      $UGII_VENDOR_DIR/application directory




------------------------------------------------------------*/
#ifdef MENUBAR_COMMENTED_OUT
extern void ufsta (char *param, int *retcode, int rlen)
{
    int  error_code;
 
    if ( (UF_initialize()) != 0) 
          return;
                                                 
    if ( (error_code = UF_MB_add_styler_actions ( actions ) ) != 0 )
    {
          char fail_message[133];
          
          UF_get_fail_message(error_code, fail_message);
          printf ( "%s\n", fail_message ); 
    }
                                                 
    UF_terminate();                             
    return;
}
#endif /*MENUBAR_COMMENTED_OUT*/





/*-------DIALOG CREATION FROM A CALLBACK HELP Example ----------
If you wish to have this dialog displayed from the callback of 
another UIStyler dialog, you should:                           

1) Make sure that the callback of your UIStyler dialog is 
   designated as a dialog building callback.              
2) Remove the conditional definitions:
   #ifdef DISPLAY_FROM_CALLBACK 
   #endif DISPLAY_FROM_CALLBACK
3) Your callback should issue a call to this function.
4) You should also add the funcitonal prototype to your header file 
   (createbox4.h) and ensure that the file is properly included.

All dialog files must be located in 
      $UGII_USER_DIR/application or 
      $UGII_SITE_DIR/application or 
      $UGII_VENDOR_DIR/application directory
--------------------------------------------------------------*/


#ifdef DISPLAY_FROM_CALLBACK
extern int <enter the name of your function> ( int *response )
{
    int  error_code = 0;
 
    if ( ( error_code = UF_initialize() ) != 0 ) 
           return (0) ;

    if ( ( error_code = UF_STYLER_create_dialog ( "createbox4.dlg",
           BLOCK_cbs,      /* Callbacks from dialog */
           BLOCK_CB_COUNT, /* number of callbacks*/
           NULL,        /* This is your client data */
           response ) ) != 0 )
    {
          char fail_message[133];

          /* Get the user function fail message based on the fail code.*/
          UF_get_fail_message(error_code, fail_message);
          UF_UI_set_status (fail_message);
          printf ( "%s\n", fail_message ); 
    }


    UF_terminate();                             
    return (error_code);
}
#endif /* DISPLAY_FROM_CALLBACK */ 




/*-------DIALOG CREATION FROM A USER EXIT HELP Example --------
To create this dialog from a user exit, you must invoke a     
call to the NX Open API, UF_STYLER_create_dialog.  An example 
is shown below.                                               

All dialog files must be located in 
      $UGII_USER_DIR/application or 
      $UGII_SITE_DIR/application or 
      $UGII_VENDOR_DIR/application directory

1) Remove the conditional definitions:
   #ifdef DISPLAY_FROM_USER_EXIT 
   #endif DISPLAY_FROM_USER_EXIT 
2) Add a user exit to the function name below, for example, ufusr.
3) Consider how your shared library will be unloaded.  Take a look
   at the generated function ufusr_ask_unload.
--------------------------------------------------------------*/
static void get_real_data(int dialog_id,char *item_id,int *value)
{
	UF_STYLER_item_value_type_t   Option;
	Option.item_attr = UF_STYLER_VALUE;
	Option.item_id = item_id;
	UF_STYLER_ask_value ( dialog_id, &Option );
	*value = Option.value.integer;
}


static void create_block(int dialog_id)
{
	int length =0;
	int width = 0;
	int height = 0;
	int x=0,y=0,z=0;
	double  corner_pt[3] = {0.0,0.0,0.0};

	char *edge_len[3] = {NULL};
	tag_t block_tag = NULL_TAG;
	int error = 0;

	//取得用户输入的长、宽、高以及x,y,z坐标。
	
	get_real_data( dialog_id, BLOCK_LENGTH, &length );
	get_real_data( dialog_id, BLOCK_WIDTH, &width );
	get_real_data( dialog_id, BLOCK_HEIGHT, &height );
	get_real_data( dialog_id, BLOCK_X, &x);
	get_real_data( dialog_id, BLOCK_Y, &y);
	get_real_data( dialog_id, BLOCK_Z, &z);
	//参数类型转换
	edge_len[0] = (char *)UF_allocate_memory( 256 * sizeof(char), &error );
	edge_len[1] = (char *)UF_allocate_memory( 256 * sizeof(char), &error );
	edge_len[2] = (char *)UF_allocate_memory( 256 * sizeof(char), &error );

	switch(length)
	{
	case 0:sprintf( edge_len[0], "%d", 100 );break;
	case 1:sprintf( edge_len[0], "%d", 200 );break;
	case 2:sprintf( edge_len[0], "%d", 300 );
	}
	switch(width)
	{
	case 0:sprintf( edge_len[1], "%d", 100 );break;
	case 1:sprintf( edge_len[1], "%d", 200 );break;
	case 2:sprintf( edge_len[1], "%d", 300 );
	}
	switch(height)
	{
	case 0:sprintf( edge_len[2], "%d", 100 );break;
	case 1:sprintf( edge_len[2], "%d", 200 );break;
	case 2:sprintf( edge_len[2], "%d", 300 );
	}
	switch(x)
	{
	case 0:corner_pt[0]=0;break;
	case 1:corner_pt[0]=100;break;
	case 2:corner_pt[0]=200;
	}
	switch(y)
	{
	case 0:corner_pt[1]=0;break;
	case 1:corner_pt[1]=100;break;
	case 2:corner_pt[1]=200;
	}
	switch(z)
	{
	case 0:corner_pt[2]=0;break;
	case 1:corner_pt[2]=100;break;
	case 2:corner_pt[2]=200;
	}
	
	//调用UF函数，生成BLock
	error = UF_MODL_create_block1( UF_NULLSIGN, corner_pt, edge_len, &block_tag );

	UF_free( edge_len[0] );
	UF_free( edge_len[1] );
	UF_free( edge_len[2] );
}
//#ifdef DISPLAY_FROM_USER_EXIT
extern void ufsta (char *param, int *retcode, int rlen)
{
    int  response   = 0;
    int  error_code = 0;
 
    if ( ( UF_initialize() ) != 0 ) 
           return;

    if ( ( error_code = UF_STYLER_create_dialog ( "createbox4.dlg",
           BLOCK_cbs,      /* Callbacks from dialog */
           BLOCK_CB_COUNT, /* number of callbacks*/
           NULL,        /* This is your client data */
           &response ) ) != 0 )
    {
          char fail_message[133];

          /* Get the user function fail message based on the fail code.*/
          UF_get_fail_message(error_code, fail_message);
          UF_UI_set_status (fail_message);
          printf ( "%s\n", fail_message ); 
    }


    UF_terminate();                             
    return;
}




/*--------------------------------------------------------------------------
This function specifies how a shared image is unloaded from memory          
within Unigraphics. This function gives you the capability to unload an     
internal NX Open application or user  exit from Unigraphics.  You can       
specify any one of the three constants as a return value to determine       
the type of unload to perform:  immediately after user function             
execution, via an unload selection dialog, or when Unigraphics terminates   
terminates.  If you choose UF_UNLOAD_SEL_DIALOG, then you have the          
option to unload your image by selecting  File->Utilities->Unload Shared    
Image. 

NOTE:  A program which associates NX Open applications with the menubar     
MUST NOT use this option since it will UNLOAD your NX Open application image
--------
from the menubar.
--------------------------------------------------------------------------*/

extern int ufusr_ask_unload (void)
{
     /* unload immediately after application exits*/
     return ( UF_UNLOAD_IMMEDIATELY );

     /*via the unload selection dialog... */
     /*return ( UF_UNLOAD_SEL_DIALOG );   */
     /*when UG terminates...              */
     /*return ( UF_UNLOAD_UG_TERMINATE ); */
}



/*--------------------------------------------------------------------------
You have the option of coding the cleanup routine to perform any housekeeping
chores that may need to be performed.  If you code the cleanup routine, it is
automatically called by Unigraphics.
--------------------------------------------------------------------------*/
extern void ufusr_cleanup (void)
{
    return;
}
//#endif /* DISPLAY_FROM_USER_EXIT */ 






/*-------------------------------------------------------------------------*/
/*---------------------- UIStyler Callback Functions ----------------------*/
/*-------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------
 * Callback Name: BLOCK_ok_cb
 * This is a callback function associated with an action taken from a
 * UIStyler object. 
 *
 * Input: dialog_id   -   The dialog id indicate which dialog this callback
 *                        is associated with.  The dialog id is a dynamic,
 *                        unique id and should not be stored.  It is
 *                        strictly for the use in the NX Open API:
 *                               UF_STYLER_ask_value(s) 
 *                               UF_STYLER_set_value   
 *        client_data -   Client data is user defined data associated
 *                        with your dialog.  Client data may be bound
 *                        to your dialog with UF_MB_add_styler_actions
 *                        or UF_STYLER_create_dialog.                 
 *        callback_data - This structure pointer contains information
 *                        specific to the UIStyler Object type that  
 *                        invoked this callback and the callback type.
 * -----------------------------------------------------------------------*/
int BLOCK_ok_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data)
{
     /* Make sure User Function is available. */  
     if ( UF_initialize() != 0) 
          return ( UF_UI_CB_CONTINUE_DIALOG );

     /* ---- Enter your callback code here ----- */
	 create_block(dialog_id);
     UF_terminate ();

    /* Callback acknowledged, terminate dialog             */
    /* It is STRONGLY recommended that you exit your       */
    /* callback with UF_UI_CB_EXIT_DIALOG in a ok callback.*/
    /* return ( UF_UI_CB_EXIT_DIALOG );                    */
    return (UF_UI_CB_EXIT_DIALOG);                           

}


/* -------------------------------------------------------------------------
 * Callback Name: BLOCK_apply_cb
 * This is a callback function associated with an action taken from a
 * UIStyler object. 
 *
 * Input: dialog_id   -   The dialog id indicate which dialog this callback
 *                        is associated with.  The dialog id is a dynamic,
 *                        unique id and should not be stored.  It is
 *                        strictly for the use in the NX Open API:
 *                               UF_STYLER_ask_value(s) 
 *                               UF_STYLER_set_value   
 *        client_data -   Client data is user defined data associated
 *                        with your dialog.  Client data may be bound
 *                        to your dialog with UF_MB_add_styler_actions
 *                        or UF_STYLER_create_dialog.                 
 *        callback_data - This structure pointer contains information
 *                        specific to the UIStyler Object type that  
 *                        invoked this callback and the callback type.
 * -----------------------------------------------------------------------*/
int BLOCK_apply_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data)
{
     /* Make sure User Function is available. */  
     if ( UF_initialize() != 0) 
          return ( UF_UI_CB_CONTINUE_DIALOG );

     /* ---- Enter your callback code here ----- */
	 create_block(dialog_id);
     UF_terminate ();

    /* Callback acknowledged, do not terminate dialog                 */
    /* A return value of UF_UI_CB_EXIT_DIALOG will not be accepted    */
    /* for this callback type.  You must respond to your apply button.*/
    return (UF_UI_CB_CONTINUE_DIALOG); 

}


/* -------------------------------------------------------------------------
 * Callback Name: BLOCK_cancel_cb
 * This is a callback function associated with an action taken from a
 * UIStyler object. 
 *
 * Input: dialog_id   -   The dialog id indicate which dialog this callback
 *                        is associated with.  The dialog id is a dynamic,
 *                        unique id and should not be stored.  It is
 *                        strictly for the use in the NX Open API:
 *                               UF_STYLER_ask_value(s) 
 *                               UF_STYLER_set_value   
 *        client_data -   Client data is user defined data associated
 *                        with your dialog.  Client data may be bound
 *                        to your dialog with UF_MB_add_styler_actions
 *                        or UF_STYLER_create_dialog.                 
 *        callback_data - This structure pointer contains information
 *                        specific to the UIStyler Object type that  
 *                        invoked this callback and the callback type.
 * -----------------------------------------------------------------------*/
int BLOCK_cancel_cb ( int dialog_id,
             void * client_data,
             UF_STYLER_item_value_type_p_t callback_data)
{
     /* Make sure User Function is available. */  
     if ( UF_initialize() != 0) 
          return ( UF_UI_CB_CONTINUE_DIALOG );

     /* ---- Enter your callback code here ----- */

     UF_terminate ();

    /* Callback acknowledged, terminate dialog             */
    /* It is STRONGLY recommended that you exit your       */
    /* callback with UF_UI_CB_EXIT_DIALOG in a cancel call */
    /* back rather than UF_UI_CB_CONTINUE_DIALOG.          */
    return ( UF_UI_CB_EXIT_DIALOG );                       

}


