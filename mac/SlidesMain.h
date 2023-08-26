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
#include "wx/button.h"
#include "wx/checkbox.h"
#include "wx/checklst.h"
#include "wx/dirdlg.h"
#include "wx/filedlg.h"
#include "wx/frame.h"
#include "wx/listbox.h"
#include "wx/listctrl.h"
#include "wx/menu.h"
#include "wx/panel.h"
#include "wx/radiobox.h"
#include "wx/richtext/richtextctrl.h"
#include "wx/spinctrl.h"
#include "wx/statusbr.h"
#include "wx/textctrl.h"
//*)

#include "wx/icon.h"
#include "wx/dir.h"
#include "wx/wfstream.h"
#include "wx/txtstrm.h"
#include "wx/tokenzr.h"
#include "wx/regex.h"
//#include <wx/filename.h>
//#include <wx/stdpaths.h>
#include "wx/webview.h"
#include "wx/dnd.h"
#include "wx/colour.h"
#include "wx/uri.h"
#include "wx/uiaction.h"

#include "numeric"
#include "list"
#include "unordered_map"
#include "wx/hashmap.h"

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
        void ShowSlides(wxString foldername, bool first = true);
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
        void SpecificSearch_NonVerbose(wxVector<wxString>fileNames);
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
        void OnSaveBtnClick(wxCommandEvent& event);
        void OnDeleteBtnClick(wxCommandEvent& event);
        void OnSearchChkBoxClick(wxCommandEvent& event);
        void OnBrowseBtnClick(wxCommandEvent& event);
        void OnImportBtnClick(wxCommandEvent& event);
        void OnFileListBoxSelect(wxCommandEvent& event);
        void OnFileListBoxToggled(wxCommandEvent& event);
        void OnFileListBoxDClick(wxCommandEvent& event);
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
        static const int ID_CREATEDATABASEBTN;
        static const int ID_SONGSLISTCTRL;
        static const int ID_REPORTSONGSBTN;
        static const int ID_CREATESLIDESBTN;
        static const int ID_VIDEORADIOBOX;
        static const int ID_FILERICHTEXTCTRL;
        static const int ID_FILELISTBOX;
        static const int ID_BROWSEBTN;
        static const int ID_RADIOBOX1;
        static const int ID_SEARCHTEXTCTRL;
        static const int ID_SEARCHCHKBOX;
        static const int ID_SEARCHTEXTCTRL2;
        static const int ID_OVERWRITECHKBOX;
        static const int ID_URLBTN;
        static const int ID_SAVEBTN;
        static const int ID_TEMPLATELISTBOX;
        static const int ID_TEMPLATETEXTCTRL;
        static const int ID_PLATFORMLISTCTRL;
        static const int ID_LICENSESPINCTRL;
        static const int ID_SEARCHSPINCTRL;
        static const int ID_CANCELBTN;
        static const int ID_LYRICSSPINCTRL;
        static const int ID_WEBPAGEPANEL;
        static const int ID_IMPORTBTN;
        static const int ID_DELETEBTN;
        static const int idMenuQuit;
        static const int idMenuAbout;
        static const int idMenuDebug;
        static const int ID_MAINSTATUSBAR;
        //*)

        //(*Declarations(SlidesFrame)
        wxButton* BrowseBtn;
        wxButton* CancelBtn;
        wxButton* CreateDatabaseBtn;
        wxButton* CreateSlidesBtn;
        wxButton* DeleteBtn;
        wxButton* ImportBtn;
        wxButton* PlayBtn;
        wxButton* ReportSongsBtn;
        wxButton* SaveBtn;
        wxButton* URLBtn;
        wxCheckBox* IncludeMacroChkBox;
        wxCheckBox* OverwriteChkBox;
        wxCheckBox* SearchChkBox;
        wxDirDialog* dirDialog;
        wxFileDialog* fileDialog;
        wxCheckListBox* FileListBox;
        wxListBox* TemplateListBox;
        wxListBox* VideoListBox;
        wxListCtrl* PlatformListCtrl;
        wxListCtrl* SongsListCtrl;
        wxMenu* Menu3;
        wxMenuItem* MenuItem3;
        wxPanel* WebPagePanel;
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

		int ID_WEBVIEW;
		int ID_CROPFRAME;
        wxString dirName, selected_platform, songfile_selected;
        wxString AZLyrics = "AZLyrics", Genius = "Genius", KLove = "KLove";
        wxString LyricsOnDemand = "LyricsOnDemand", WorshipTogether = "WorshipTogether", Lyrics = "Lyrics";
        wxString Musixmatch = "Musixmatch", UltimateGuitar = "UltimateGuitar";
		int webstate, curr_index, url_index, curr_platform, lyrics_index = 3, sizeMode = 0, hideMode = 1;
        bool skipCheck = false;
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
