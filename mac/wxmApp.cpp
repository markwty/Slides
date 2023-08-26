#include "wxmApp.h"

//(*AppHeaders
#include "SlidesMain.h"
#include "wx/image.h"
//*)

bool wxmApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SlidesFrame* Frame = new SlidesFrame(0);
    	Frame->Show(true);
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
