/***************************************************************
 * Name:      MathCalculatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Konstantin & Stanislav Shemyakins (zdrastekostik@gmail.com)
 * Created:   2024-04-19
 * Copyright: Konstantin & Stanislav Shemyakins ()
 * License:
 **************************************************************/

#ifndef MATHCALCULATORMAIN_H
#define MATHCALCULATORMAIN_H

//(*Headers(MathCalculatorFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class MathCalculatorFrame: public wxFrame
{
    public:

        MathCalculatorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MathCalculatorFrame();

    private:

        //(*Handlers(MathCalculatorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnEvalButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(MathCalculatorFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_GRID1;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long ID_PANEL2;
        static const long ID_NOTEBOOK1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        //(*Declarations(MathCalculatorFrame)
        wxButton* EvalButton;
        wxButton* HistoryButton;
        wxGrid* VariablesGrid;
        wxNotebook* Notebook1;
        wxPanel* CalculatorPage;
        wxPanel* GraphPage;
        wxStaticLine* StaticLine1;
        wxStaticText* EquasionLabel;
        wxStaticText* ResultLabel;
        wxStaticText* VariablesLabel;
        wxTextCtrl* EquasionCtrl;
        wxTextCtrl* ResultCtrl;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MATHCALCULATORMAIN_H
