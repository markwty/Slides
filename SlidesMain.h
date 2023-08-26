/***************************************************************
 * Name:      SlidesMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mark ()
 * Created:   2020-02-01
 * Copyright: Mark ()
 * License:
 **************************************************************/

#ifndef SLIDESMAIN_H
#define SLIDESMAIN_H

//(*Headers(SlidesFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/checklst.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/spinctrl.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include <wx/icon.h>
#include <wx/dir.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/tokenzr.h>
#include <wx/msw/registry.h>
#include <wx/regex.h>
//#include <wx/filename.h>
//#include <wx/stdpaths.h>
#include <wx/webview.h>
#include <wx/msw/ole/automtn.h>
#include <wx/msw/ole/oleutils.h>
#include <wx/dnd.h>
#include <wx/colour.h>

#include <numeric>
#include <list>
#include <unordered_map>
#include <wx/hashmap.h>
#include "../VideoCrop/VideoCropMain.h"

WX_DECLARE_STRING_HASH_MAP(wxString, StringHashMap);
WX_DECLARE_STRING_HASH_MAP(double, DoubleHashMap);

class SlidesFrame: public wxFrame
{
    public:

        SlidesFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SlidesFrame();
        void Initialise();
        void InitSearchOrder();
        void InitSpinCtrls();
        void ShowSlides(wxString foldername, bool start = true);
        void ShowVideos(wxString foldername);
        void ShowTemplates(wxString foldername);
        void DefaultFolderOpen();
        void Save();
        void CropVideo(wxCommandEvent& event);
        void WriteSlides();
        void ScriptProgression();
        wxString EncodeURI(const wxString& uri);
        void ExecuteScript(wxWebViewEvent& event);
        void ExecuteScript2(wxWebViewEvent& event);
        void OnErrorWebView(wxWebViewEvent& event);
        void FilterSearch_NonVerbose();
		bool ParseSlide(wxString songname, wxVector <wxString>& info);
		bool is_number(wxString& s);
		void WriteSlides2();

    private:

        //WX_DECLARE_STRING_HASH_MAP(Temp, TempHashMap);
        //(*Handlers(SlidesFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnDebug(wxCommandEvent& event);
        void OnSongsListCtrlItemRClick(wxListEvent& event);
        void OnSearchSpinCtrlChange(wxSpinEvent& event);
        void OnCancelBtnClick(wxCommandEvent& event);
        void OnCreateDatabaseBtnClick(wxCommandEvent& event);
        void OnReportSongsBtnClick(wxCommandEvent& event);
        void OnLicenseSpinCtrlChange(wxSpinEvent& event);
        void OnCreateSlidesBtnClick(wxCommandEvent& event);
        void OnImportCreateBtnClick(wxCommandEvent& event);
        void OnSaveBtnClick(wxCommandEvent& event);
        void OnDeleteBtnClick(wxCommandEvent& event);
        void OnSearchChkBoxClick(wxCommandEvent& event);
        void OnBrowseBtnClick(wxCommandEvent& event);
        void OnImportBtnClick(wxCommandEvent& event);
        void OnPlayBtnClick(wxCommandEvent& event);
        void OnFileListBoxSelect(wxCommandEvent& event);
        void OnFileListBoxToggled(wxCommandEvent& event);
        void OnFileListBoxDClick(wxCommandEvent& event);
        void OnVideoListBoxDClick(wxCommandEvent& event);
        void FilterSearch(wxCommandEvent& event);
        void OnSongsListCtrlBeginDrag(wxListEvent& event);
        void OnTemplateListBoxDClick(wxCommandEvent& event);
        void OnPlatformListCtrlBeginDrag(wxListEvent& event);
        void OnURLBtnClick(wxCommandEvent& event);
        void OnWebPagePanelLeftDClick(wxMouseEvent& event);
        void OnWebPagePanelRightDClick(wxMouseEvent& event);
        //*)
        void OnFileListBoxRClick(wxMouseEvent& event);

        //(*Identifiers(SlidesFrame)
        static const long ID_CREATEDATABASEBTN;
        static const long ID_SONGSLISTCTRL;
        static const long ID_REPORTSONGSBTN;
        static const long ID_CREATESLIDESBTN;
        static const long ID_VIDEORADIOBOX;
        static const long ID_FILERICHTEXTCTRL;
        static const long ID_VIDEOLISTBOX;
        static const long ID_BROWSEBTN;
        static const long ID_OPTIONSRADIOBOX;
        static const long ID_SEARCHTEXTCTRL;
        static const long ID_SEARCHCHKBOX;
        static const long ID_PLAYBTN;
        static const long ID_SEARCHTEXTCTRL2;
        static const long ID_OVERWRITECHKBOX;
        static const long ID_URLBTN;
        static const long ID_SAVEBTN;
        static const long ID_TEMPLATELISTBOX;
        static const long ID_TEMPLATETEXTCTRL;
        static const long ID_IMPORTCREATEBTN;
        static const long ID_PLATFORMLISTCTRL;
        static const long ID_LICENSESPINCTRL;
        static const long ID_SEARCHSPINCTRL;
        static const long ID_CANCELBTN;
        static const long ID_LYRICSSPINCTRL;
        static const long ID_WEBPAGEPANEL;
        static const long ID_IMPORTBTN;
        static const long ID_DELETEBTN;
        static const long ID_FILELISTBOX;
        static const long ID_FUNCTIONSRADIOBOX;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long idMenuDebug;
        static const long ID_MAINSTATUSBAR;
        //*)

        //(*Declarations(SlidesFrame)
        wxButton* BrowseBtn;
        wxButton* CancelBtn;
        wxButton* CreateDatabaseBtn;
        wxButton* CreateSlidesBtn;
        wxButton* DeleteBtn;
        wxButton* ImportBtn;
        wxButton* ImportCreateBtn;
        wxButton* PlayBtn;
        wxButton* ReportSongsBtn;
        wxButton* SaveBtn;
        wxButton* URLBtn;
        wxCheckBox* OverwriteChkBox;
        wxCheckBox* SearchChkBox;
        wxCheckListBox* FileListBox;
        wxDirDialog* dirDialog;
        wxFileDialog* fileDialog;
        wxListBox* TemplateListBox;
        wxListBox* VideoListBox;
        wxListCtrl* PlatformListCtrl;
        wxListCtrl* SongsListCtrl;
        wxMenu* Menu3;
        wxMenuItem* MenuItem3;
        wxPanel* WebPagePanel;
        wxRadioBox* FunctionsRadioBox;
        wxRadioBox* OptionsRadioBox;
        wxRadioBox* VideoRadioBox;
        wxRichTextCtrl* FileRichTextCtrl;
        wxSpinCtrl* LicenseSpinCtrl;
        wxSpinCtrl* LyricsSpinCtrl;
        wxSpinCtrl* SearchSpinCtrl;
        wxStatusBar* MainStatusBar;
        wxTextCtrl* SearchTextCtrl2;
        wxTextCtrl* SearchTextCtrl;
        wxTextCtrl* TemplateTextCtrl;
        //*)
        wxWebView* webView;

		long ID_WEBVIEW;
		long ID_CROPFRAME;
        wxString dirName, selected_platform, songfile_selected;
        wxString Background = "Background", Words = "Words", Mix = "Mix";
        wxString AZLyrics = "AZLyrics", Genius = "Genius (issue)", KLove = "KLove (issue)";
        wxString LyricsOnDemand = "LyricsOnDemand", WorshipTogether = "WorshipTogether", Lyrics = "Lyrics";
        wxString Musixmatch = "Musixmatch", UltimateGuitar = "UltimateGuitar (issue)";
		int webstate, curr_index, url_index, curr_platform, lyrics_index = 3, sizeMode = 0, hideMode = 0;
		wxPoint ori_pos;
		wxSize ori_size;
		wxVector <wxString> videoList;
		wxVector <wxString> fileList;
		std::list <wxString> favourites;
		wxVector <wxString> urlList;
		wxVector <wxVector<wxString>> songsDetails, songsDetails2;
		StringHashMap configmap;

        DECLARE_EVENT_TABLE()
};

class ListCtrlDropTarget : public wxTextDropTarget
{
    public:
        wxListCtrl *m_owner;
        ListCtrlDropTarget(wxListCtrl *owner);
        virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& data);
};
#endif // SLIDESMAIN_H
