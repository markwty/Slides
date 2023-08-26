/***************************************************************
 * Name:      SlidesApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mark ()
 * Created:   2020-02-01
 * Copyright: Mark ()
 * License:
 **************************************************************/

#include "SlidesApp.h"

//(*AppHeaders
#include "SlidesMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SlidesApp);

bool SlidesApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SlidesFrame* Frame = new SlidesFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
