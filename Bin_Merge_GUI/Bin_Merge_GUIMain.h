/***************************************************************
 * Name:      Bin_Merge_GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    NePathak (Neetish.Pathak@harman.com)
 * Created:   2016-06-30
 * Copyright: NePathak (NA)
 * License:
 **************************************************************/

#ifndef BIN_MERGE_GUIMAIN_H
#define BIN_MERGE_GUIMAIN_H

//(*Headers(Bin_Merge_GUIFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define FLASH_SIZE  (4 * 1024 * 1024)
#define BOOTLOADER_SIZE (128 * 1024)
#define FIRM_UPGRADE_SIZE (128 * 1024)
#define BIOS_SIZE (256 * 1024)
#define APP_SIZE (FLASH_SIZE - BOOTLOADER_SIZE - FIRM_UPGRADE_SIZE - BIOS_SIZE

using namespace std;

class Bin_Merge_GUIFrame: public wxFrame
{
    public:

        Bin_Merge_GUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Bin_Merge_GUIFrame();

    private:

        //(*Handlers(Bin_Merge_GUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnMergeButtonClick(wxCommandEvent& event);
        void OnResetButtonClick(wxCommandEvent& event);
        void OnExitButtonClick(wxCommandEvent& event);
        void OnBootLoaderButtonClick(wxCommandEvent& event);
        void OnFirmUpgradeButtonClick(wxCommandEvent& event);
        void OnApplicationButtonClick(wxCommandEvent& event);
        void OnBiosButtonClick(wxCommandEvent& event);
        void OnMergeDirButtonClick(wxCommandEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        void OnTextCtrl4Text(wxCommandEvent& event);
        void OnMergeButtonClick1(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnBootLoaderBtnClick(wxCommandEvent& event);
        void OnFirmUpgradeBtnClick(wxCommandEvent& event);
        void OnApplicationBtnClick(wxCommandEvent& event);
        void OnBiosBtnClick(wxCommandEvent& event);
        void OnMergeDirBtnClick(wxCommandEvent& event);
        void OnResetButtonClick1(wxCommandEvent& event);
        void OnExitButtonClick1(wxCommandEvent& event);
        //*)

        bool MergeFiles();
        void fillNull(ofstream& outFile, long startPt, long fileSize);

        //(*Identifiers(Bin_Merge_GUIFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON0;
        static const long ID_BUTTON1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON7;
        static const long ID_CHECKBOX1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Bin_Merge_GUIFrame)
        wxTextCtrl* TextCtrl4;
        wxButton* MergeDirBtn;
        wxButton* ResetButton;
        wxStaticText* StaticText1;
        wxFileDialog* FileDialog1;
        wxButton* ExitButton;
        wxCheckBox* CheckBox1;
        wxButton* BootLoaderBtn;
        wxButton* MergeButton;
        wxButton* FirmUpgradeBtn;
        wxStatusBar* StatusBar1;
        wxButton* BiosBtn;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl3;
        wxButton* ApplicationBtn;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BIN_MERGE_GUIMAIN_H
