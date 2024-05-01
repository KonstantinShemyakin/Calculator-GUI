/***************************************************************
 * Name:      MathCalculatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Konstantin & Stanislav Shemyakins (zdrastekostik@gmail.com)
 * Created:   2024-04-19
 * Copyright: Konstantin & Stanislav Shemyakins ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "MathCalculatorApp.h"

//(*AppHeaders
#include "MathCalculatorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MathCalculatorApp);

bool MathCalculatorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MathCalculatorFrame* Frame = new MathCalculatorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
