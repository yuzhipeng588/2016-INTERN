﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block UI Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  Z:\01-项目文档\03-执行项目\P15S020-NX-CSS-船舶软件系统\02-Implementation\01-DetailDesign\CCS_CAD_UI\Application\CCS_HUST_HFHZ_CAD_3_5_CombineCabin.cpp
//
//        This file was generated by the NX Block UI Styler
//        Created by: chengdeng
//              Version: NX 10
//              Date: 02-27-2016  (Format: mm-dd-yyyy)
//              Time: 11:11 (Format: hh-mm)
//
//==============================================================================

//==============================================================================
//  Purpose:  This TEMPLATE file contains C++ source to guide you in the
//  construction of your Block application dialog. The generation of your
//  dialog file (.dlx extension) is the first step towards dialog construction
//  within NX.  You must now create a NX Open application that
//  utilizes this file (.dlx).
//
//  The information in this file provides you with the following:
//
//  1.  Help on how to load and display your Block UI Styler dialog in NX
//      using APIs provided in NXOpen.BlockStyler namespace
//  2.  The empty callback methods (stubs) associated with your dialog items
//      have also been placed in this file. These empty methods have been
//      created simply to start you along with your coding requirements.
//      The method name, argument list and possible return values have already
//      been provided for you.
//==============================================================================

//------------------------------------------------------------------------------
//These includes are needed for the following template code
//------------------------------------------------------------------------------
#include "CCS_HUST_HFHZ_CAD_3_5_CombineCabin.hpp"
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

//------------------------------------------------------------------------------
// Initialize static variables
//------------------------------------------------------------------------------
Session *(CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theSession) = NULL;
UI *(CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI) = NULL;
//------------------------------------------------------------------------------
// Constructor for NX Styler class
//------------------------------------------------------------------------------
CCS_HUST_HFHZ_CAD_3_5_CombineCabin::CCS_HUST_HFHZ_CAD_3_5_CombineCabin()
{
    try
    {
        // Initialize the NX Open C++ API environment
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theSession = NXOpen::Session::GetSession();
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI = UI::GetUI();
        theDlxFileName = "CCS_HUST_HFHZ_CAD_3_5_CombineCabin.dlx";
        theDialog = CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->CreateDialog(theDlxFileName);
        // Registration of callback functions
        theDialog->AddOkHandler(make_callback(this, &CCS_HUST_HFHZ_CAD_3_5_CombineCabin::ok_cb));
        theDialog->AddUpdateHandler(make_callback(this, &CCS_HUST_HFHZ_CAD_3_5_CombineCabin::update_cb));
        theDialog->AddInitializeHandler(make_callback(this, &CCS_HUST_HFHZ_CAD_3_5_CombineCabin::initialize_cb));
        theDialog->AddDialogShownHandler(make_callback(this, &CCS_HUST_HFHZ_CAD_3_5_CombineCabin::dialogShown_cb));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        throw;
    }
}

//------------------------------------------------------------------------------
// Destructor for NX Styler class
//------------------------------------------------------------------------------
CCS_HUST_HFHZ_CAD_3_5_CombineCabin::~CCS_HUST_HFHZ_CAD_3_5_CombineCabin()
{
    if (theDialog != NULL)
    {
        delete theDialog;
        theDialog = NULL;
    }
}
//------------------------------- DIALOG LAUNCHING ---------------------------------
//
//    Before invoking this application one needs to open any part/empty part in NX
//    because of the behavior of the blocks.
//
//    Make sure the dlx file is in one of the following locations:
//        1.) From where NX session is launched
//        2.) $UGII_USER_DIR/application
//        3.) For released applications, using UGII_CUSTOM_DIRECTORY_FILE is highly
//            recommended. This variable is set to a full directory path to a file 
//            containing a list of root directories for all custom applications.
//            e.g., UGII_CUSTOM_DIRECTORY_FILE=$UGII_ROOT_DIR\menus\custom_dirs.dat
//
//    You can create the dialog using one of the following way:
//
//    1. USER EXIT
//
//        1) Create the Shared Library -- Refer "Block UI Styler programmer's guide"
//        2) Invoke the Shared Library through File->Execute->NX Open menu.
//
//------------------------------------------------------------------------------
extern "C" DllExport void  ufusr(char *param, int *retcod, int param_len)
{
    CCS_HUST_HFHZ_CAD_3_5_CombineCabin *theCCS_HUST_HFHZ_CAD_3_5_CombineCabin = NULL;
    try
    {
        theCCS_HUST_HFHZ_CAD_3_5_CombineCabin = new CCS_HUST_HFHZ_CAD_3_5_CombineCabin();
        // The following method shows the dialog immediately
        theCCS_HUST_HFHZ_CAD_3_5_CombineCabin->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    if(theCCS_HUST_HFHZ_CAD_3_5_CombineCabin != NULL)
    {
        delete theCCS_HUST_HFHZ_CAD_3_5_CombineCabin;
        theCCS_HUST_HFHZ_CAD_3_5_CombineCabin = NULL;
    }
}

//------------------------------------------------------------------------------
// This method specifies how a shared image is unloaded from memory
// within NX. This method gives you the capability to unload an
// internal NX Open application or user  exit from NX. Specify any
// one of the three constants as a return value to determine the type
// of unload to perform:
//
//
//    Immediately : unload the library as soon as the automation program has completed
//    Explicitly  : unload the library from the "Unload Shared Image" dialog
//    AtTermination : unload the library when the NX session terminates
//
//
// NOTE:  A program which associates NX Open applications with the menubar
// MUST NOT use this option since it will UNLOAD your NX Open application image
// from the menubar.
//------------------------------------------------------------------------------
extern "C" DllExport int ufusr_ask_unload()
{
    //return (int)Session::LibraryUnloadOptionExplicitly;
    return (int)Session::LibraryUnloadOptionImmediately;
    //return (int)Session::LibraryUnloadOptionAtTermination;
}

//------------------------------------------------------------------------------
// Following method cleanup any housekeeping chores that may be needed.
// This method is automatically called by NX.
//------------------------------------------------------------------------------
extern "C" DllExport void ufusr_cleanup(void)
{
    try
    {
        //---- Enter your callback code here -----
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

int CCS_HUST_HFHZ_CAD_3_5_CombineCabin::Show()
{
    try
    {
        theDialog->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//---------------------Block UI Styler Callback Functions--------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Callback Name: initialize_cb
//------------------------------------------------------------------------------
void CCS_HUST_HFHZ_CAD_3_5_CombineCabin::initialize_cb()
{
    try
    {
        group = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group"));
        targetSelect = dynamic_cast<NXOpen::BlockStyler::BodyCollector*>(theDialog->TopBlock()->FindBlock("targetSelect"));
        group1 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group1"));
        waitSelect = dynamic_cast<NXOpen::BlockStyler::BodyCollector*>(theDialog->TopBlock()->FindBlock("waitSelect"));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Callback Name: dialogShown_cb
//This callback is executed just before the dialog launch. Thus any value set 
//here will take precedence and dialog will be launched showing that value. 
//------------------------------------------------------------------------------
void CCS_HUST_HFHZ_CAD_3_5_CombineCabin::dialogShown_cb()
{
    try
    {
        //---- Enter your callback code here -----
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Callback Name: update_cb
//------------------------------------------------------------------------------
int CCS_HUST_HFHZ_CAD_3_5_CombineCabin::update_cb(NXOpen::BlockStyler::UIBlock* block)
{
    try
    {
        if(block == targetSelect)
        {
        //---------Enter your code here-----------
        }
        else if(block == waitSelect)
        {
        //---------Enter your code here-----------
        }
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//Callback Name: ok_cb
//------------------------------------------------------------------------------
int CCS_HUST_HFHZ_CAD_3_5_CombineCabin::ok_cb()
{
    int errorCode = 0;
    try
    {
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        errorCode = 1;
        CCS_HUST_HFHZ_CAD_3_5_CombineCabin::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Function Name: GetBlockProperties
//Description: Returns the propertylist of the specified BlockID
//------------------------------------------------------------------------------
PropertyList* CCS_HUST_HFHZ_CAD_3_5_CombineCabin::GetBlockProperties(const char *blockID)
{
    return theDialog->GetBlockProperties(blockID);
}
