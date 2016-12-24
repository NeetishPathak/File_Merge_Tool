/***************************************************************
 * Name:      Bin_Merge_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    NePathak (Neetish.Pathak@harman.com)
 * Created:   2016-06-30
 * Copyright: NePathak (NA)
 * License:
 **************************************************************/

#include "Bin_Merge_GUIApp.h"

//(*AppHeaders
#include "Bin_Merge_GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Bin_Merge_GUIApp);

bool Bin_Merge_GUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Bin_Merge_GUIFrame* Frame = new Bin_Merge_GUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
