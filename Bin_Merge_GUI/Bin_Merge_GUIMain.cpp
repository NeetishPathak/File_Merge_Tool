/***************************************************************
 * Name:      Bin_Merge_GUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    NePathak (Neetish.Pathak@harman.com)
 * Created:   2016-06-30
 * Copyright: NePathak (NA)
 * License:
 **************************************************************/

#include "Bin_Merge_GUIMain.h"
#include <wx/msgdlg.h>
#include <wx/filepicker.h>
#include <wx/wx.h>

//(*InternalHeaders(Bin_Merge_GUIFrame)
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

//(*IdInit(Bin_Merge_GUIFrame)
const long Bin_Merge_GUIFrame::ID_TEXTCTRL1 = wxNewId();
const long Bin_Merge_GUIFrame::ID_TEXTCTRL2 = wxNewId();
const long Bin_Merge_GUIFrame::ID_TEXTCTRL3 = wxNewId();
const long Bin_Merge_GUIFrame::ID_TEXTCTRL4 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON0 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON1 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON3 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON4 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON5 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON6 = wxNewId();
const long Bin_Merge_GUIFrame::ID_STATICTEXT1 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON2 = wxNewId();
const long Bin_Merge_GUIFrame::ID_TEXTCTRL5 = wxNewId();
const long Bin_Merge_GUIFrame::ID_BUTTON7 = wxNewId();
const long Bin_Merge_GUIFrame::ID_CHECKBOX1 = wxNewId();
const long Bin_Merge_GUIFrame::ID_MENUITEM1 = wxNewId();
const long Bin_Merge_GUIFrame::idMenuAbout = wxNewId();
const long Bin_Merge_GUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Bin_Merge_GUIFrame,wxFrame)
    //(*EventTable(Bin_Merge_GUIFrame)
    //*)
END_EVENT_TABLE()

Bin_Merge_GUIFrame::Bin_Merge_GUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Bin_Merge_GUIFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("BinMerge"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER, _T("wxID_ANY"));
    SetClientSize(wxSize(627,373));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,72), wxSize(368,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(136,112), wxSize(368,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(136,152), wxSize(368,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(136,192), wxSize(368,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    MergeButton = new wxButton(this, ID_BUTTON0, _("Merge"), wxPoint(80,288), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON0"));
    ResetButton = new wxButton(this, ID_BUTTON1, _("Reset"), wxPoint(224,288), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BootLoaderBtn = new wxButton(this, ID_BUTTON3, _("Boot Loader"), wxPoint(24,72), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FirmUpgradeBtn = new wxButton(this, ID_BUTTON4, _("Firm Upgrade"), wxPoint(24,112), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    ApplicationBtn = new wxButton(this, ID_BUTTON5, _("Application"), wxPoint(24,152), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BiosBtn = new wxButton(this, ID_BUTTON6, _("Bios"), wxPoint(24,192), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("BINARY MERGE TOOL"), wxPoint(112,16), wxSize(112,30), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(20,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Georgia"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    ExitButton = new wxButton(this, ID_BUTTON2, _("Exit"), wxPoint(368,288), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(136,232), wxSize(368,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    MergeDirBtn = new wxButton(this, ID_BUTTON7, _("Merged File Path"), wxPoint(24,232), wxSize(96,24), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Enable"), wxPoint(528,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), _("C:\\"), wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Center();

    Connect(ID_BUTTON0,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnMergeButtonClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnResetButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnBootLoaderButtonClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnFirmUpgradeButtonClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnApplicationButtonClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnBiosButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnExitButtonClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnMergeDirButtonClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnCheckBox1Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Bin_Merge_GUIFrame::OnClose);
    //*)

    BiosBtn->Disable();
    TextCtrl4->Disable();
    SetIcon(wxICON(bbb));
}

Bin_Merge_GUIFrame::~Bin_Merge_GUIFrame()
{
    //(*Destroy(Bin_Merge_GUIFrame)
    //*)
}

void Bin_Merge_GUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Bin_Merge_GUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}



void Bin_Merge_GUIFrame::OnClose(wxCloseEvent& event)
{
    Destroy();
}


void Bin_Merge_GUIFrame::OnMergeButtonClick(wxCommandEvent& event)
{
    if(MergeFiles()){
      wxMessageDialog *dial = new wxMessageDialog(NULL,
      wxT("Merge Successful"), wxT("Merge Info"), wxOK);
      dial->ShowModal();
    }
}

void Bin_Merge_GUIFrame::OnResetButtonClick(wxCommandEvent& event)
{
    TextCtrl1->Clear();
    TextCtrl2->Clear();
    TextCtrl3->Clear();
    TextCtrl4->Clear();
    TextCtrl5->Clear();
}

void Bin_Merge_GUIFrame::OnExitButtonClick(wxCommandEvent& event)
{
    Close();
}

void Bin_Merge_GUIFrame::OnBootLoaderButtonClick(wxCommandEvent& event)
{
    wxFileDialog * openFileDialog = new wxFileDialog(this);
    if (openFileDialog->ShowModal() == wxID_OK){
      wxString fileName = openFileDialog->GetPath();
      TextCtrl1->SetValue(fileName);
    }
}

void Bin_Merge_GUIFrame::OnFirmUpgradeButtonClick(wxCommandEvent& event)
{
    wxFileDialog * openFileDialog = new wxFileDialog(this);
    if (openFileDialog->ShowModal() == wxID_OK){
      wxString fileName = openFileDialog->GetPath();
      TextCtrl2->SetValue(fileName);
    }
}

void Bin_Merge_GUIFrame::OnApplicationButtonClick(wxCommandEvent& event)
{
    wxFileDialog * openFileDialog = new wxFileDialog(this);
    if (openFileDialog->ShowModal() == wxID_OK){
      wxString fileName = openFileDialog->GetPath();
      TextCtrl3->SetValue(fileName);
    }
}

void Bin_Merge_GUIFrame::OnBiosButtonClick(wxCommandEvent& event)
{
    wxFileDialog * openFileDialog = new wxFileDialog(this);
    if (openFileDialog->ShowModal() == wxID_OK){
      wxString fileName = openFileDialog->GetPath();
      TextCtrl4->SetValue(fileName);
    }
}

void Bin_Merge_GUIFrame::OnMergeDirButtonClick(wxCommandEvent& event)
{
     wxDirDialog * openDirDialog = new wxDirDialog(this);
     if (openDirDialog->ShowModal() == wxID_OK){
          wxString dirName = openDirDialog->GetPath();
          TextCtrl5->SetValue(dirName);
     }
}




void Bin_Merge_GUIFrame::fillNull(ofstream& outFile, long startPt, long fileSize){

    char a = 255;
    for(long stPt = startPt; stPt < fileSize; ++stPt )
    outFile << a;
}

bool Bin_Merge_GUIFrame::MergeFiles(){

    ifstream fileBl;
    ifstream fileFu;
    ifstream fileApp;
    ifstream fileBios;
    ofstream fileOut;

    fileBl.open(TextCtrl1->GetValue(), ios::in | ios::binary);
    fileFu.open(TextCtrl2->GetValue(), ios::in | ios::binary);
    fileApp.open(TextCtrl3->GetValue(), ios::in | ios::binary);

    if(CheckBox1->IsChecked())
    {
         fileBios.open(TextCtrl4->GetValue(), ios::in | ios::binary);
    }
    // fileBl.open("sh726b_spibsc_loader_prog.bin", ios::in | ios::binary);
    //fileFu.open("firm_upgrade.bin", ios::in | ios::binary);
    //fileApp.open("connectivity_radio.bin", ios::in | ios::binary);
    //fileBios.open("SH726B_L090-4010-30KF_bios_uimage.bin", ios::in | ios::binary);

    if(fileBl == NULL || fileFu == NULL || fileApp == NULL || (CheckBox1->IsChecked() && fileBios == NULL)){
       wxMessageDialog *dial = new wxMessageDialog(NULL,
         wxT("Error in File Path"), wxT("Error"), wxOK | wxICON_ERROR);
        dial->ShowModal();
        cout<<"Press any key to exit...\n";
		//getch();
		//exit(EXIT_FAILURE);
		return false;
    }
    fileOut.open(TextCtrl5->GetValue() + "\\mergedSwdl.bin", ios::out | ios::binary);

    if(!fileOut)
	{
		perror("Error Message ");
		cout<<"Press any key to exit...\n";
		//getch();
		//exit(EXIT_FAILURE);
	}

    //Writing the boot loader File
     if(fileBl){
        fileOut << fileBl.rdbuf();
        long sizeBl = fileBl.tellg();
        fillNull(fileOut, sizeBl, BOOTLOADER_SIZE);
     }

	//Writing the FirmUpgrade File
	 if(fileFu){
        fileOut << fileFu.rdbuf();
        long sizeFu = fileFu.tellg();
        fillNull(fileOut, sizeFu, FIRM_UPGRADE_SIZE);
	 }

	//Writing Application File
	 if(fileApp){
        fileOut << fileApp.rdbuf();

        if(CheckBox1->IsChecked())
        {
            long sizeApp = fileApp.tellg();
            fillNull(fileOut,sizeApp,APP_SIZE));
        }

	 }

    if(CheckBox1->IsChecked()){
         //Writing Bios File
        if(fileBios){

            fileOut << fileBios.rdbuf();
            long sizeBios = fileBios.tellg();
            fillNull(fileOut, sizeBios, BIOS_SIZE);
            fileBios.close();
        }
    }


    fileBl.close();
	fileFu.close();
	fileApp.close();
	fileOut.close();
	return true;
}


void Bin_Merge_GUIFrame::OnCheckBox1Click(wxCommandEvent& event)
{
    if(!CheckBox1->IsChecked())
    {
        BiosBtn->Disable();
        TextCtrl4->Disable();

    }
    else
    {
        BiosBtn->Enable();
        TextCtrl4->Enable();
    }

}

