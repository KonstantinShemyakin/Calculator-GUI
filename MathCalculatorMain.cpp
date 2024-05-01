/***************************************************************
 * Name:      MathCalculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Konstantin & Stanislav Shemyakins (zdrastekostik@gmail.com)
 * Created:   2024-04-19
 * Copyright: Konstantin & Stanislav Shemyakins ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "MathCalculatorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MathCalculatorFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MathCalculatorFrame)
const long MathCalculatorFrame::ID_TEXTCTRL1 = wxNewId();
const long MathCalculatorFrame::ID_STATICTEXT1 = wxNewId();
const long MathCalculatorFrame::ID_STATICLINE1 = wxNewId();
const long MathCalculatorFrame::ID_STATICTEXT2 = wxNewId();
const long MathCalculatorFrame::ID_TEXTCTRL2 = wxNewId();
const long MathCalculatorFrame::ID_BUTTON1 = wxNewId();
const long MathCalculatorFrame::ID_GRID1 = wxNewId();
const long MathCalculatorFrame::ID_STATICTEXT3 = wxNewId();
const long MathCalculatorFrame::ID_BUTTON2 = wxNewId();
const long MathCalculatorFrame::ID_PANEL1 = wxNewId();
const long MathCalculatorFrame::ID_PANEL2 = wxNewId();
const long MathCalculatorFrame::ID_NOTEBOOK1 = wxNewId();
const long MathCalculatorFrame::idMenuQuit = wxNewId();
const long MathCalculatorFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(MathCalculatorFrame,wxFrame)
    //(*EventTable(MathCalculatorFrame)
    //*)
END_EVENT_TABLE()

MathCalculatorFrame::MathCalculatorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MathCalculatorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,400));
    SetMinSize(wxSize(550,420));
    SetMaxSize(wxSize(550,420));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    CalculatorPage = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    EquasionCtrl = new wxTextCtrl(CalculatorPage, ID_TEXTCTRL1, _("Enter equasion here"), wxPoint(8,32), wxSize(376,136), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    EquasionLabel = new wxStaticText(CalculatorPage, ID_STATICTEXT1, _("Equasion:"), wxPoint(8,8), wxSize(360,22), 0, _T("ID_STATICTEXT1"));
    wxFont EquasionLabelFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    EquasionLabel->SetFont(EquasionLabelFont);
    StaticLine1 = new wxStaticLine(CalculatorPage, ID_STATICLINE1, wxPoint(8,174), wxSize(376,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    ResultLabel = new wxStaticText(CalculatorPage, ID_STATICTEXT2, _("Result:"), wxPoint(8,176), wxSize(376,24), 0, _T("ID_STATICTEXT2"));
    wxFont ResultLabelFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    ResultLabel->SetFont(ResultLabelFont);
    ResultCtrl = new wxTextCtrl(CalculatorPage, ID_TEXTCTRL2, _("Result here"), wxPoint(8,200), wxSize(376,104), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    EvalButton = new wxButton(CalculatorPage, ID_BUTTON1, _("Evaluate"), wxPoint(272,312), wxSize(107,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    VariablesGrid = new wxGrid(CalculatorPage, ID_GRID1, wxPoint(392,32), wxSize(136,312), 0, _T("ID_GRID1"));
    VariablesGrid->CreateGrid(1,2);
    VariablesGrid->EnableEditing(true);
    VariablesGrid->EnableGridLines(true);
    VariablesGrid->SetColLabelSize(20);
    VariablesGrid->SetRowLabelSize(36);
    VariablesGrid->SetDefaultColSize(50, true);
    wxFont GridLabelFont_1(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("System"),wxFONTENCODING_DEFAULT);
    VariablesGrid->SetLabelFont(GridLabelFont_1);
    VariablesGrid->SetColLabelValue(0, _("Name"));
    VariablesGrid->SetColLabelValue(1, _("Value"));
    VariablesGrid->SetRowLabelValue(0, wxEmptyString);
    VariablesGrid->SetDefaultCellFont( VariablesGrid->GetFont() );
    VariablesGrid->SetDefaultCellTextColour( VariablesGrid->GetForegroundColour() );
    VariablesLabel = new wxStaticText(CalculatorPage, ID_STATICTEXT3, _("Variables"), wxPoint(392,8), wxSize(136,24), 0, _T("ID_STATICTEXT3"));
    wxFont VariablesLabelFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    VariablesLabel->SetFont(VariablesLabelFont);
    HistoryButton = new wxButton(CalculatorPage, ID_BUTTON2, _("History"), wxPoint(8,312), wxSize(112,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    GraphPage = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Notebook1->AddPage(CalculatorPage, _("Calculator"), true);
    Notebook1->AddPage(GraphPage, _("Graph"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MathCalculatorFrame::OnEvalButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MathCalculatorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MathCalculatorFrame::OnAbout);
    //*)
}

MathCalculatorFrame::~MathCalculatorFrame()
{
    //(*Destroy(MathCalculatorFrame)
    //*)
}

void MathCalculatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MathCalculatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void MathCalculatorFrame::OnEvalButtonClick(wxCommandEvent& event)
{

}
