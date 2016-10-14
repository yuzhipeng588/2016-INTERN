#include <stdio.h>
#include <stdarg.h>
#include <uf.h>
#include <uf_ui.h>
#include <uf_object_types.h>
#include <uf_disp.h>
#include <uf_obj.h>
#include <uf_part.h>
#include <uf_modl.h>
#include <uf_assem.h>
#include <afxdb.h>
#include <uf_csys.h>
#include <uf_mb.h>
#include <uf_drf.h>
#include <uf_xs.h>
#include <string.h>
#include <uf_draw.h>
#include <uf_view.h>
#include <uf_layout.h>
#include <uf_clone.h>


#define UF_CALL(X) (report( __FILE__, __LINE__, #X, (X)))

static int report( char *file, int line, char *call, int irc)
{
   
    if (irc)
    {
        char sfailmessage[133];
        //uf_get_fail_message(irc,sfailmessage);

        char swholemessage[256];
        sprintf(swholemessage,"file name:%s\nline:%d\nfunction:%s\nerror code:%d\nmessage:%s",file,line,call,irc,sfailmessage);
       // messagebox(null, swholemessage,"error in function", mb_ok|mb_iconwarning|mb_systemmodal);
        
    }
    return(irc);   

}


//static void error_return(char *msg)
//{
//    fprintf(stderr,"\n+++error : %s.\n\n",msg);
//    exit(1);
//}

//static void report_error(int result,char *alt_msg)
//{
//    char err_message[200];
//    int found = UF_get_fail_message(result,err_message);
//    if (found != 0)
//        error_return(alt_msg);
//    else
//        error_return(err_message);
//}

static void do_ugopen_api(void)
{
   //int response = 0; 
   //char title_string [ ] = "LITEON Training"; 
   //char sMessages[ 132 + 1 ] = "多按钮模态对话框"; 
   //char * p = sMessages ; 
   //UF_UI_MESSAGE_DIALOG_TYPE dialog_type = UF_UI_MESSAGE_INFORMATION ; 
   //UF_UI_message_buttons_t button ; 
   //button.button1 = true ; //控制按钮的数量
   //button.button2 = true ; 
   //button.button3 = true ;  

   //button.label1 = "是";   //按钮的标签
   //button.label2 = "否";
   //button.label3 = "取消"; 
   //
   //button.response1 = 1 ; // 按钮的返回值
   //button.response2 = 2 ;  
   //button.response3 = 3 ;

   //UF_UI_message_dialog( title_string, dialog_type, &p, 1, 0, &button , &response ) ; 
   //switch ( response ) 
   //{ case 1 :   uc1601( button.label1 , 1 ) ; break; // 显示所选按钮的标签 
   //  case 2 :   uc1601( button.label2 , 1 ) ; break ; 
   //  case 3 :   uc1601 ( button.label3 , 1 ) ; break ; 
   //  default : uc1601( "未知按钮", 1 ) ; break;
   //}
	char sCue[]="点构造器";
	UF_UI_POINT_base_method_t base_method = UF_UI_POINT_INFERRED;
	tag_t tPoint = NULL_TAG;
	double sBasepoint[]={0,0,0};
	int iResponse;
	UF_UI_point_construct(sCue,&base_method,&tPoint,sBasepoint,&iResponse);

}


/*ARGSUSED*/
void ufusr(char *param, int *retcode, int param_len)
{
    if (!UF_CALL(UF_initialize()))
    {
        do_ugopen_api();
        UF_CALL(UF_terminate());
		//UF_terminate();
   }
}

/*----------------------------------------------------------------------------*/

extern int ufusr_ask_unload (void)
{
    /* unload immediately after application exits*/
    return ( UF_UNLOAD_IMMEDIATELY );

}
