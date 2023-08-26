/***************************************************************
 * Name:      SlidesMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mark ()
 * Created:   2020-02-01
 * Copyright: Mark ()
 * License:
 **************************************************************/

#include "SlidesMain.h"
#include <wx/msgdlg.h>
#include "../VideoCrop/VideoCropMain.cpp"
//(*InternalHeaders(SlidesFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

using namespace std;
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

//(*IdInit(SlidesFrame)
const long SlidesFrame::ID_CREATEDATABASEBTN = wxNewId();
const long SlidesFrame::ID_SONGSLISTCTRL = wxNewId();
const long SlidesFrame::ID_REPORTSONGSBTN = wxNewId();
const long SlidesFrame::ID_CREATESLIDESBTN = wxNewId();
const long SlidesFrame::ID_VIDEORADIOBOX = wxNewId();
const long SlidesFrame::ID_FILERICHTEXTCTRL = wxNewId();
const long SlidesFrame::ID_VIDEOLISTBOX = wxNewId();
const long SlidesFrame::ID_BROWSEBTN = wxNewId();
const long SlidesFrame::ID_OPTIONSRADIOBOX = wxNewId();
const long SlidesFrame::ID_SEARCHTEXTCTRL = wxNewId();
const long SlidesFrame::ID_SEARCHCHKBOX = wxNewId();
const long SlidesFrame::ID_PLAYBTN = wxNewId();
const long SlidesFrame::ID_SEARCHTEXTCTRL2 = wxNewId();
const long SlidesFrame::ID_OVERWRITECHKBOX = wxNewId();
const long SlidesFrame::ID_URLBTN = wxNewId();
const long SlidesFrame::ID_SAVEBTN = wxNewId();
const long SlidesFrame::ID_TEMPLATELISTBOX = wxNewId();
const long SlidesFrame::ID_TEMPLATETEXTCTRL = wxNewId();
const long SlidesFrame::ID_IMPORTCREATEBTN = wxNewId();
const long SlidesFrame::ID_PLATFORMLISTCTRL = wxNewId();
const long SlidesFrame::ID_LICENSESPINCTRL = wxNewId();
const long SlidesFrame::ID_SEARCHSPINCTRL = wxNewId();
const long SlidesFrame::ID_CANCELBTN = wxNewId();
const long SlidesFrame::ID_LYRICSSPINCTRL = wxNewId();
const long SlidesFrame::ID_WEBPAGEPANEL = wxNewId();
const long SlidesFrame::ID_IMPORTBTN = wxNewId();
const long SlidesFrame::ID_DELETEBTN = wxNewId();
const long SlidesFrame::ID_FILELISTBOX = wxNewId();
const long SlidesFrame::ID_FUNCTIONSRADIOBOX = wxNewId();
const long SlidesFrame::idMenuQuit = wxNewId();
const long SlidesFrame::idMenuAbout = wxNewId();
const long SlidesFrame::idMenuDebug = wxNewId();
const long SlidesFrame::ID_MAINSTATUSBAR = wxNewId();
//*)

BEGIN_EVENT_TABLE(SlidesFrame,wxFrame)
    //(*EventTable(SlidesFrame)
    //*)
END_EVENT_TABLE()

SlidesFrame::SlidesFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SlidesFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MainMenuBar;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxVSCROLL|wxHSCROLL, _T("wxID_ANY"));
    SetClientSize(wxSize(1003,515));
    CreateDatabaseBtn = new wxButton(this, ID_CREATEDATABASEBTN, _("Create Database"), wxPoint(0,224), wxSize(100,30), 0, wxDefaultValidator, _T("ID_CREATEDATABASEBTN"));
    CreateDatabaseBtn->SetToolTip(_("Extract lyrics from several sites\n(according to \'Search order\')"));
    SongsListCtrl = new wxListCtrl(this, ID_SONGSLISTCTRL, wxPoint(0,0), wxSize(248,224), wxLC_REPORT, wxDefaultValidator, _T("ID_SONGSLISTCTRL"));
    ReportSongsBtn = new wxButton(this, ID_REPORTSONGSBTN, _("Report Songs"), wxPoint(0,304), wxSize(100,30), 0, wxDefaultValidator, _T("ID_REPORTSONGSBTN"));
    ReportSongsBtn->SetToolTip(_("Report songs listed above through CCLI"));
    CreateSlidesBtn = new wxButton(this, ID_CREATESLIDESBTN, _("Create Slides"), wxPoint(0,336), wxSize(100,30), 0, wxDefaultValidator, _T("ID_CREATESLIDESBTN"));
    CreateSlidesBtn->SetToolTip(_("Construct slides consisting of songs listed above\n(with the template specified on the far right)"));
    wxString __wxRadioBoxChoices_1[4] =
    {
    	_("None"),
    	_("Background"),
    	_("Words"),
    	_("Mix")
    };
    VideoRadioBox = new wxRadioBox(this, ID_VIDEORADIOBOX, _("Video"), wxPoint(104,304), wxSize(144,114), 4, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_VIDEORADIOBOX"));
    VideoRadioBox->SetSelection(0);
    FileRichTextCtrl = new wxRichTextCtrl(this, ID_FILERICHTEXTCTRL, wxEmptyString, wxPoint(256,40), wxSize(208,224), wxRE_MULTILINE, wxDefaultValidator, _T("ID_FILERICHTEXTCTRL"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    FileRichTextCtrl->SetToolTip(_("Displays song/ text file \n(selected in the box on its direct right)"));
    VideoListBox = new wxListBox(this, ID_VIDEOLISTBOX, wxPoint(680,40), wxSize(168,192), 0, 0, 0, wxDefaultValidator, _T("ID_VIDEOLISTBOX"));
    VideoListBox->SetToolTip(_("Displays .mp4 files in \"Videos folder\""));
    BrowseBtn = new wxButton(this, ID_BROWSEBTN, _("Browse"), wxPoint(464,272), wxSize(100,30), 0, wxDefaultValidator, _T("ID_BROWSEBTN"));
    BrowseBtn->SetToolTip(_("Opens dialog to select the folder\n(specified in the \'Browse Options\' next to it)"));
    wxString __wxRadioBoxChoices_2[3] =
    {
    	_("Songs folder"),
    	_("Videos folder"),
    	_("Templates folder")
    };
    OptionsRadioBox = new wxRadioBox(this, ID_OPTIONSRADIOBOX, _("Browse Options"), wxPoint(568,264), wxSize(112,96), 3, __wxRadioBoxChoices_2, 1, 0, wxDefaultValidator, _T("ID_OPTIONSRADIOBOX"));
    SearchTextCtrl = new wxTextCtrl(this, ID_SEARCHTEXTCTRL, wxEmptyString, wxPoint(464,40), wxSize(216,21), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_SEARCHTEXTCTRL"));
    SearchChkBox = new wxCheckBox(this, ID_SEARCHCHKBOX, _("Search inside files"), wxPoint(464,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEARCHCHKBOX"));
    SearchChkBox->SetValue(false);
    PlayBtn = new wxButton(this, ID_PLAYBTN, _("Play video"), wxPoint(680,232), wxSize(100,30), 0, wxDefaultValidator, _T("ID_PLAYBTN"));
    PlayBtn->SetToolTip(_("Plays selected video above"));
    SearchTextCtrl2 = new wxTextCtrl(this, ID_SEARCHTEXTCTRL2, wxEmptyString, wxPoint(0,256), wxSize(100,30), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_SEARCHTEXTCTRL2"));
    SearchTextCtrl2->SetToolTip(_("Type in query here\n(done through CCLI)"));
    OverwriteChkBox = new wxCheckBox(this, ID_OVERWRITECHKBOX, _("Overwrite files"), wxPoint(0,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OVERWRITECHKBOX"));
    OverwriteChkBox->SetValue(false);
    URLBtn = new wxButton(this, ID_URLBTN, _("Go to URL"), wxPoint(464,332), wxSize(100,30), 0, wxDefaultValidator, _T("ID_URLBTN"));
    URLBtn->Hide();
    SaveBtn = new wxButton(this, ID_SAVEBTN, _("Save file"), wxPoint(256,272), wxSize(100,30), 0, wxDefaultValidator, _T("ID_SAVEBTN"));
    SaveBtn->SetToolTip(_("Saves song/ text file\n(when edits are made)"));
    TemplateListBox = new wxListBox(this, ID_TEMPLATELISTBOX, wxPoint(848,40), wxSize(152,192), 0, 0, 0, wxDefaultValidator, _T("ID_TEMPLATELISTBOX"));
    TemplateListBox->SetToolTip(_("Displays .ppt/.pptx files in \"Templates folder\""));
    TemplateTextCtrl = new wxTextCtrl(this, ID_TEMPLATETEXTCTRL, wxEmptyString, wxPoint(848,232), wxSize(152,30), 0, wxDefaultValidator, _T("ID_TEMPLATETEXTCTRL"));
    TemplateTextCtrl->Disable();
    TemplateTextCtrl->SetToolTip(_("Template selected for \'Create Slides\'"));
    ImportCreateBtn = new wxButton(this, ID_IMPORTCREATEBTN, _("Import + Create"), wxPoint(0,368), wxSize(100,30), 0, wxDefaultValidator, _T("ID_IMPORTCREATEBTN"));
    ImportCreateBtn->SetToolTip(_("Used to apply video to existing non-video slides\n(lyrics should have the largest font, title and/or author/s have the smallest font)"));
    PlatformListCtrl = new wxListCtrl(this, ID_PLATFORMLISTCTRL, wxPoint(148,224), wxSize(100,80), wxLC_REPORT|wxLC_NO_HEADER, wxDefaultValidator, _T("ID_PLATFORMLISTCTRL"));
    PlatformListCtrl->SetToolTip(_("Search order"));
    LicenseSpinCtrl = new wxSpinCtrl(this, ID_LICENSESPINCTRL, _T("3"), wxPoint(48,400), wxSize(50,21), 0, 1, 20, 3, _T("ID_LICENSESPINCTRL"));
    LicenseSpinCtrl->SetValue(_T("3"));
    LicenseSpinCtrl->SetToolTip(_("Maximum no. of lines for CCLI below slide\n(only applicable to \"Create Slides\", 1-20)"));
    SearchSpinCtrl = new wxSpinCtrl(this, ID_SEARCHSPINCTRL, _T("5"), wxPoint(101,235), wxSize(48,21), 0, 1, 25, 5, _T("ID_SEARCHSPINCTRL"));
    SearchSpinCtrl->SetValue(_T("5"));
    SearchSpinCtrl->SetToolTip(_("Number of songs to look for each query\n(1-25)"));
    CancelBtn = new wxButton(this, ID_CANCELBTN, _("Cancel"), wxPoint(100,256), wxSize(48,30), 0, wxDefaultValidator, _T("ID_CANCELBTN"));
    CancelBtn->SetToolTip(_("Cancel \'Create database\' & \'Report Songs\'"));
    LyricsSpinCtrl = new wxSpinCtrl(this, ID_LYRICSSPINCTRL, _T("0"), wxPoint(0,400), wxSize(50,21), 0, 0, 20, 0, _T("ID_LYRICSSPINCTRL"));
    LyricsSpinCtrl->SetValue(_T("0"));
    LyricsSpinCtrl->SetToolTip(_("Maximum no. of lines for lyrics on each slide\n(0 implies no preference, 0-20)"));
    WebPagePanel = new wxPanel(this, ID_WEBPAGEPANEL, wxPoint(256,312), wxSize(200,128), wxTAB_TRAVERSAL, _T("ID_WEBPAGEPANEL"));
    WebPagePanel->Hide();
    ImportBtn = new wxButton(this, ID_IMPORTBTN, _("Import folder"), wxPoint(464,302), wxSize(100,30), 0, wxDefaultValidator, _T("ID_IMPORTBTN"));
    ImportBtn->SetToolTip(_("Choose a folder to convert all existing .ppt or .pptx\nto .txt"));
    DeleteBtn = new wxButton(this, ID_DELETEBTN, _("Delete file"), wxPoint(356,272), wxSize(100,30), 0, wxDefaultValidator, _T("ID_DELETEBTN"));
    DeleteBtn->Disable();
    DeleteBtn->SetToolTip(_("Delete file, can be enabled via Developer->Debug"));
    FileListBox = new wxCheckListBox(this, ID_FILELISTBOX, wxPoint(464,88), wxSize(216,176), 0, 0, 0, wxDefaultValidator, _T("ID_FILELISTBOX"));
    wxString __wxRadioBoxChoices_3[3] =
    {
    	_("None"),
    	_("Include macro"),
    	_("Trim slides")
    };
    FunctionsRadioBox = new wxRadioBox(this, ID_FUNCTIONSRADIOBOX, _("Functions"), wxPoint(464,360), wxSize(104,96), 3, __wxRadioBoxChoices_3, 1, 0, wxDefaultValidator, _T("ID_FUNCTIONSRADIOBOX"));
    FunctionsRadioBox->SetToolTip(_("Include macro\nInclude code for slideshow (issue)\n\nTrim slides\nRemove slides in between\n\nBoth options only applicable to \'Background\' & \'Mix\'"));
    MainMenuBar = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MainMenuBar->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MainMenuBar->Append(Menu2, _("Help"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, idMenuDebug, _("Debug"), _("Displays hidden widgets"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MainMenuBar->Append(Menu3, _("Developer"));
    SetMenuBar(MainMenuBar);
    MainStatusBar = new wxStatusBar(this, ID_MAINSTATUSBAR, 0, _T("ID_MAINSTATUSBAR"));
    int __wxStatusBarWidths_1[2] = { -10, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    MainStatusBar->SetFieldsCount(2,__wxStatusBarWidths_1);
    MainStatusBar->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(MainStatusBar);
    dirDialog = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    fileDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_CREATEDATABASEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnCreateDatabaseBtnClick);
    Connect(ID_SONGSLISTCTRL,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&SlidesFrame::OnSongsListCtrlBeginDrag);
    Connect(ID_SONGSLISTCTRL,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&SlidesFrame::OnSongsListCtrlItemRClick);
    Connect(ID_REPORTSONGSBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnReportSongsBtnClick);
    Connect(ID_CREATESLIDESBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnCreateSlidesBtnClick);
    Connect(ID_VIDEOLISTBOX,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&SlidesFrame::OnVideoListBoxDClick);
    Connect(ID_BROWSEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnBrowseBtnClick);
    Connect(ID_SEARCHTEXTCTRL,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&SlidesFrame::FilterSearch);
    Connect(ID_SEARCHCHKBOX,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnSearchChkBoxClick);
    Connect(ID_PLAYBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnPlayBtnClick);
    Connect(ID_SEARCHTEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&SlidesFrame::OnCreateDatabaseBtnClick);
    Connect(ID_URLBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnURLBtnClick);
    Connect(ID_SAVEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnSaveBtnClick);
    Connect(ID_TEMPLATELISTBOX,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&SlidesFrame::OnTemplateListBoxDClick);
    Connect(ID_IMPORTCREATEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnImportCreateBtnClick);
    Connect(ID_PLATFORMLISTCTRL,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&SlidesFrame::OnPlatformListCtrlBeginDrag);
    Connect(ID_LICENSESPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SlidesFrame::OnLicenseSpinCtrlChange);
    Connect(ID_SEARCHSPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SlidesFrame::OnSearchSpinCtrlChange);
    Connect(ID_CANCELBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnCancelBtnClick);
    WebPagePanel->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&SlidesFrame::OnWebPagePanelLeftDClick,0,this);
    WebPagePanel->Connect(wxEVT_RIGHT_DCLICK,(wxObjectEventFunction)&SlidesFrame::OnWebPagePanelRightDClick,0,this);
    Connect(ID_IMPORTBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnImportBtnClick);
    Connect(ID_DELETEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnDeleteBtnClick);
    Connect(ID_FILELISTBOX,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&SlidesFrame::OnFileListBoxToggled);
    Connect(ID_FILELISTBOX,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&SlidesFrame::OnFileListBoxSelect);
    Connect(ID_FILELISTBOX,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&SlidesFrame::OnFileListBoxDClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SlidesFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SlidesFrame::OnAbout);
    //*)
    Connect(idMenuDebug, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SlidesFrame::OnDebug);
    //ReportSongsBtn->Enable(false);
    FileListBox->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(SlidesFrame::OnFileListBoxRClick), NULL, this);
    //wxLB_OWNERDRAW
    SetIcon(wxICON(app_logo));
	ListCtrlDropTarget* dndSongsListCtrl = new ListCtrlDropTarget(SongsListCtrl);
    SongsListCtrl->SetDropTarget(dndSongsListCtrl);
    SongsListCtrl->InsertColumn(0, "Song Names", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(1, "Video", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(2, "CCLI", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(3, "Song Filename", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(4, "Video Filename", wxLIST_FORMAT_LEFT);
    SongsListCtrl->SetColumnWidth(0, 150);
    SongsListCtrl->SetColumnWidth(2, 0);
    SongsListCtrl->SetColumnWidth(3, 0);
    SongsListCtrl->SetColumnWidth(4, 0);
    ListCtrlDropTarget* dndPlatformListCtrl = new ListCtrlDropTarget(PlatformListCtrl);
    PlatformListCtrl->SetDropTarget(dndPlatformListCtrl);
    PlatformListCtrl->InsertColumn(0, "Search order", wxLIST_FORMAT_LEFT);

    wxRegKey rk( wxT("HKEY_CURRENT_USER\\Software\\Microsoft\\Internet Explorer\\Main\\FeatureControl\\FEATURE_BROWSER_EMULATION"));
    //wxString strExe = wxFileName(wxStandardPaths::Get().GetExecutablePath()).GetFullName();
    rk.SetValue("Slides.exe", 11001);
    //11001 is the code to use Internet Explorer 11
    webstate = -1;
    ori_pos = WebPagePanel->GetPosition();
    ori_size = WebPagePanel->GetSize();
    ID_WEBVIEW = NewControlId();
    webView = wxWebView::New(WebPagePanel, ID_WEBVIEW, "google.com", wxPoint(0, 0), \
                             wxSize(ori_size.GetWidth() - 20, ori_size.GetHeight()));
    //webView->Hide();
    Connect(ID_WEBVIEW, wxEVT_WEBVIEW_ERROR, wxWebViewEventHandler(SlidesFrame::OnErrorWebView));
    Connect(ID_WEBVIEW, wxEVT_WEBVIEW_LOADED, wxWebViewEventHandler(SlidesFrame::ExecuteScript2));
    SlidesFrame::Initialise();
}

SlidesFrame::~SlidesFrame()
{
    SlidesFrame::Save();
    //(*Destroy(SlidesFrame)
    //*)
}

void SlidesFrame::Initialise()
{
    //ID_WEBVIEW = NewControlId();
    wxDir dir(wxGetCwd());
    dirName = dir.GetName();

    wxString params[] = {"Default songs directory", "Template", "Default templates directory", \
                        "Video", "Default videos directory", "Search order", "Items per search", \
                        "Maximum lines for CCLI"};
    //Keys are specified here
    int num_params =  sizeof(params)/sizeof(wxString);
    for(int i = 0; i < num_params; i++)
    {
       configmap[params[i]] = "";
    }

    wxString filename;
    filename = dirName + "\\config.txt";
    //config.txt should be in the same directory as the application
    wxFile wxofsFile;
    if (!wxofsFile.Exists(filename))
    {
        SetStatusText(wxT("Cannot find config.txt"), 0);
        SlidesFrame::InitSearchOrder();
        return;
    }
    wxFileInputStream input(filename);
    wxTextInputStream text(input, wxT("\x09"), wxConvUTF8);
    wxString line, key, value;
    while(!input.Eof())
    {
        line = text.ReadLine();
        wxStringTokenizer tkz(line, wxT(":"));
        key = tkz.GetNextToken().Trim(false).Trim(true);
        //Removes whitespace
        if (configmap.find(key) != configmap.end())
        //Include only known keys
        {
            value = tkz.GetString().Trim(false).Trim(true);
            //Removes whitespace
            configmap[key] = value;
        }
    }
    SlidesFrame::InitSearchOrder();
    SlidesFrame::InitSpinCtrls();
    SlidesFrame::DefaultFolderOpen();
    PlatformListCtrl->Hide();
}

void SlidesFrame::InitSearchOrder()
{
    vector<wxString> platforms = {AZLyrics, WorshipTogether, LyricsOnDemand, Lyrics, Musixmatch};
    //Available platforms and default order
    vector<wxString> choices;

    wxStringTokenizer tkz(configmap["Search order"], wxT(","));
    wxString platform;
    while (tkz.HasMoreTokens())
    {
        platform = tkz.GetNextToken().Trim(false).Trim(true);
        if(find(platforms.begin(), platforms.end(), platform) != platforms.end())
        {
            choices.push_back(platform);
        }
    }
    if (choices.size() > 0)
    //Ensures default order is given if there is no order provided
    {
        for (unsigned int i = 0; i < choices.size(); i++)
        {
            PlatformListCtrl->InsertItem(PlatformListCtrl->GetItemCount(), choices[i]);
        }
    }
    else
    {
        for (unsigned int i = 0; i < platforms.size(); i++)
        {
            PlatformListCtrl->InsertItem(PlatformListCtrl->GetItemCount(), platforms[i]);
        }
    }
}

void SlidesFrame::InitSpinCtrls()
{
    int val = atoi(configmap["Items per search"]);
    if (val <= 0)
    //Invalid value, set to default
    {
        //5 as an arbitrary default value
        SearchSpinCtrl->SetValue(5);
        configmap["Items per search"] = "5";
    }
    else
    {
        SearchSpinCtrl->SetValue(val);
    }

    val = atoi(configmap["Maximum lines for CCLI"]);
    if (val <= 0)
    {
        //3 as an arbitrary default value
        LicenseSpinCtrl->SetValue(3);
        configmap["Maximum lines for CCLI"] = "3";
    }
    else
    {
        LicenseSpinCtrl->SetValue(val);
    }
}

void SlidesFrame::ShowSlides(wxString foldername, bool start)
{
    wxDir dir(foldername);
    if (!dir.IsOpened())
    //Check whether folder exists
    {
        return;
    }
    int num_items = FileListBox->GetCount();
    for (int i = 0; i < num_items; i++)
    {
        FileListBox->Delete(0);
    }
    fileList.clear();
    wxString filename;
    wxString filespec = _T("*.txt");
    bool cont = dir.GetFirst(&filename, filespec, wxDIR_FILES);
    while (cont)
    {
        wxString filenamestr(filename);
        fileList.push_back(filenamestr);
        cont = dir.GetNext(&filename);
    }
    wxVectorSort(fileList);
    for (unsigned int i = 0; i < fileList.size(); i++)
    {
        FileListBox->Append(fileList[i]);
    }

    if (start)
    {
        wxFile wxofsFile;
        filename = configmap["Default templates directory"] + "\\" + "favourites.txt";
        if (wxofsFile.Exists(filename))
        {
            wxFileInputStream input(filename);
            wxTextInputStream text(input, wxT("\x09"), wxMBConvUTF16LE());
            wxString line = text.ReadLine();
            while(line.compare("") != 0)
            {
                favourites.push_back(line);
                line = text.ReadLine();
            }
        }

        int itemCount = FileListBox->GetCount();
        if(itemCount == 0)
        {
            return;
        }

        int index = 0;
        list<wxString>::iterator it;
        filename = FileListBox->GetString(index);
        for (it = favourites.begin(); it != favourites.end(); it++)
        {
            while (filename.compare(*it) < 0) {
                index++;
                if (index == itemCount)
                {
                    return;
                }
                filename = FileListBox->GetString(index);
            }
            if (filename.compare(*it) == 0)
            {
                FileListBox->Check(index);
            }
        }
    }
}

void SlidesFrame::ShowVideos(wxString foldername)
{
    wxDir dir(foldername);
    if (!dir.IsOpened())
    //Check whether folder exists
    {
        return;
    }
    int num_items = VideoListBox->GetCount();
    for (int i = 0; i < num_items; i++)
    {
        VideoListBox->Delete(0);
    }
    videoList.clear();
    wxString filename;
    wxString filespec = _T("*.mp4");
    bool cont = dir.GetFirst(&filename, filespec, wxDIR_FILES);
    while (cont)
    {
        wxString filenamestr(filename);
        VideoListBox->Append(filenamestr);
        videoList.push_back(filenamestr);
        cont = dir.GetNext(&filename);
    }
}

void SlidesFrame::ShowTemplates(wxString foldername)
{
    wxDir dir(foldername);
    if (!dir.IsOpened())
    //Check whether folder exists
    {
        return;
    }
    int num_items = TemplateListBox->GetCount();
    for (int i = 0; i < num_items; i++)
    {
        TemplateListBox->Delete(0);
    }
    wxString filename;
    wxString filespec = _T("*.ppt*");
    bool cont = dir.GetFirst(&filename, filespec, wxDIR_FILES);
    while (cont)
    {
        wxString filenamestr(filename);
        TemplateListBox->Append(filenamestr);
        cont = dir.GetNext(&filename);
    }
}

void SlidesFrame::DefaultFolderOpen()
{
    wxString selectedFolder = configmap["Default songs directory"];
    if (selectedFolder.compare("") != 0)
    {
        SetStatusText(selectedFolder, 0);
        SlidesFrame::ShowSlides(selectedFolder);
    }

    selectedFolder = configmap["Default videos directory"];
    if (selectedFolder.compare("") != 0)
    {
        SetStatusText(selectedFolder, 0);
        SlidesFrame::ShowVideos(selectedFolder);
    }

    selectedFolder = configmap["Default templates directory"];
    if (selectedFolder.compare("") != 0)
    {
        SetStatusText(selectedFolder, 0);
        SlidesFrame::ShowTemplates(selectedFolder);
    }
}

void SlidesFrame::Save()
{
    wxString filename = dirName + "\\config.txt";
    wxString search_order = "";
    int num_platforms = PlatformListCtrl->GetItemCount();
    for (int i = 0; i < num_platforms; i++)
    {
        search_order += PlatformListCtrl->GetItemText(i, 0) + ",";
    }
    configmap["Search order"] = search_order;
    wxFile wxofsFile(filename, wxFile::write);
    StringHashMap::iterator it;
    wxString line;
    for(it = configmap.begin(); it != configmap.end(); ++it )
    {
        line = it->first;
        line << ":" << it->second << "\n";
        wxofsFile.Write(line, line.Len());
    }
    wxofsFile.Close();

    wxDir dir(configmap["Default templates directory"]);
    if (!dir.IsOpened())
    //Check whether folder exists
    {
        return;
    }
    wxFile wxofsFile2(configmap["Default templates directory"] + "\\" + "favourites.txt", wxFile::write);
    list<wxString>::iterator it2;
    favourites.sort();
    for(it2 = favourites.begin(); it2 != favourites.end(); ++it2)
    {
        line = *it2 << "\n";
        wxofsFile2.Write(line, wxMBConvUTF16LE());
    }
    wxofsFile2.Close();
}

void SlidesFrame::OnSongsListCtrlItemRClick(wxListEvent& event)
{
    SongsListCtrl->DeleteItem(event.GetIndex());
}

void SlidesFrame::OnSearchSpinCtrlChange(wxSpinEvent& event)
{
    configmap["Items per search"] = to_string(SearchSpinCtrl->GetValue());
}

void SlidesFrame::WriteSlides()
{
    /*
    0
    Title
    Author/s
    CCLI no

    1
    CCLI

    2
    One line lyrics from CCLI

    3
    Lyrics
    */
    SetStatusText("Writing songs to files", 0);
    bool first = true;
    wxString title;
    for(unsigned int i = 0; i < songsDetails.size(); i++)
    {
        wxStringTokenizer tkz(songsDetails[i][0], wxT("\n"));
        title = tkz.GetNextToken();
        if (songsDetails[i].size() == (unsigned int)lyrics_index)
        {
            wxString filename = configmap["Default songs directory"] + "\\" + "missing.txt";
            wxFile wxofsFile(filename, wxFile::write_append);
            wxString content;
            if (first)
            {
                content = "\n--------\n" + title;
                first = false;
            }
            else
            {
                content = "\n" + title;
            }
            wxofsFile.Write(content, content.Len());
            wxofsFile.Close();
        }
        else
        {
            title.Replace((char)(-110), "'");
            wxString firstAuthor = tkz.GetNextToken();
            wxString ccli_no = tkz.GetString();
            if(ccli_no.compare("") == 0)
            {
                ccli_no = firstAuthor.substr(0, min(firstAuthor.find("/"),firstAuthor.find(",")));
            }
            wxString filename = configmap["Default songs directory"] + "\\" + title \
                                + " (" + ccli_no + ").txt";
            wxFile wxofsFile;
            if (!OverwriteChkBox->GetValue() && wxofsFile.Exists(filename))
            {
                continue;
            }
            wxofsFile.Create(filename, true);
            wxString content, lyrics, line;
            bool twice = false;
            content = songsDetails[i][0];
            content << "\n\n\n" << songsDetails[i][1].Trim(false).Trim(true) << "\n";
            wxStringTokenizer tkz(songsDetails[i][lyrics_index], wxT("\n"), wxTOKEN_RET_EMPTY);
            vector<int> line_counts;
            int line_count = 0;
            while (tkz.HasMoreTokens())
            {
                line = tkz.GetNextToken().Trim(false).Trim(true);
                int start_bracket, end_bracket;
                while(true)
                {
                    start_bracket = line.find("(");
                    end_bracket =  line.find(")");
                    if (start_bracket != wxNOT_FOUND && end_bracket != wxNOT_FOUND && start_bracket < end_bracket)
                    {
                        line = line.substr(0, start_bracket).Trim(true) + " " + line.substr(end_bracket + 1).Trim(false);
                    }
                    else
                    {
                        break;
                    }
                }
                if (line.compare("") == 0 || line.substr(0, 5).Lower().compare("intro") == 0 || line.substr(0, 6).Lower().compare("chorus") == 0 \
                     || line.substr(0, 5).Lower().compare("verse") == 0 || line.substr(0, 5).Lower().compare("instr") == 0 \
                     || line.substr(0, 5).Lower().compare("outro") == 0 || line.substr(0, 6).Lower().compare("bridge") == 0 \
                     || line.substr(0, 13).Lower().compare("repeat chorus") == 0 || line.substr(0, 13).Lower().compare("repeat bridge") == 0 \
                     || line.substr(0, 3).Lower().compare("tag") == 0 || line.substr(0, 10).Lower().compare("pre-chorus") == 0 \
                     || line.substr(0, 6).Lower().compare("ending") == 0 \
                     || line.substr(0, 9).Lower().compare("interlude") == 0 || line.at(0) == '[' || line.at(0) == '(' || line.at(0) == '|')
                {
                    //Assumes empty line before abovementioned text
                    if (line_count != 0)
                    {
                        line_counts.push_back(line_count);
                        line_count = 0;
                    }
                    if (!twice)
                    {
                        twice = true;
                        lyrics << '\n';
                    }
                }
                else if (line.substr(0, 9).Lower().compare("copyright") == 0 || line.substr(0, 7).Lower().compare("publish") == 0 \
                         || line.substr(0, 6).Lower().compare("writer") == 0 || line.substr(line.Len() - 1, 1).Lower().compare(":") == 0)
                {
                    break;
                }
                else
                {
                    if(twice)
                    {
                        line_count = 1;
                        twice = false;
                        lyrics << '\n' << line;
                    }
                    else
                    {
                        line_count++;
                        lyrics << '\n' << line;
                    }
                }
            }
            if (line_count != 0)
            {
                line_counts.push_back(line_count);
            }
            vector<vector<int>> line_splits = {{3, 3}, {3, 4}, {4, 4}, {5, 4}, \
                                            {4, 6}, {4, 4, 3}};
            //Ambiguities in number of lines = 7, 9, 10, 11
            vector<int> split_vector;
            vector<int> splits;
            int line_no = 0, multiples, remainder;
            for (unsigned int ii = 0; ii < line_counts.size(); ii++)
            {
                if (line_counts[ii] < 6)
                {
                    line_no += line_counts[ii];
                }
                else if (line_counts[ii] < 12)
                {
                    split_vector = line_splits[line_counts[ii] - 6];
                    for (unsigned int iii = 0; iii < split_vector.size() - 1; iii++)
                    {
                        line_no += split_vector[iii];
                        splits.push_back(line_no);
                    }
                    line_no += split_vector.back();
                }
                else
                {
                    //For any number more than 11, break for every 4, the last should be more than 4
                    multiples = line_counts[ii] / 4;
                    remainder = line_counts[ii] - (multiples*4);
                    if (remainder == 1)
                    {
                        multiples--;
                        remainder += 4;
                    }
                    for (int iii = 0; iii < multiples; iii++)
                    {
                        line_no += 4;
                        splits.push_back(line_no);
                    }
                    line_no += remainder;
                }
            }

            if (splits.size() != 0)
            {
                twice = true;
                wxStringTokenizer tkz2(lyrics, wxT("\n"), wxTOKEN_RET_EMPTY);
                line_count = 0;
                int step = 0;
                lyrics = "";
                while (tkz2.HasMoreTokens())
                {
                    line = tkz2.GetNextToken();
                    if (line.compare("") == 0)
                    {
                        if (!twice)
                        {
                            twice = true;
                            lyrics << "\n";
                        }
                    }
                    else
                    {
                        if (line_count == splits[step])
                        {
                            if (splits.size() != (unsigned int)(step + 1))
                            {
                                step++;
                            }
                            lyrics << "\n\n" <<line;
                        }
                        else
                        {
                            lyrics << "\n" <<line;
                        }
                        line_count++;
                        twice = false;
                    }
                }
            }
            content << '\n' << lyrics.Trim(false).Trim(true);
            wxofsFile.Write(content);
            wxofsFile.Close();
        }
    }
    ReportSongsBtn->Enable(true);
    SetStatusText("Song files created", 0);
    SlidesFrame::FilterSearch_NonVerbose();
}

void SlidesFrame::ScriptProgression()
{
    bool through = false;
    for (unsigned int i = curr_index + 1; i < songsDetails.size(); i++)
    {
        if (songsDetails[i].size() == (unsigned int)lyrics_index)
        //Check for songs without lyrics
        {
            curr_index = i;
            through = true;
            break;
        }
    }
    if (through)
    {
        if (selected_platform.compare(AZLyrics + "_removed") == 0)
        {
            webView-> LoadURL("https://www.azlyrics.com/");
        }
        else if (selected_platform.compare(Genius + "_removed") == 0)
        {
            webView-> LoadURL("https://genius.com/");
        }
        else if (selected_platform.compare(KLove) == 0)
        {
            webView-> LoadURL("https://www.klove.com/music/songs#music-search-form");
        }
        else if (selected_platform.compare(Lyrics) == 0)
        {
            webView-> LoadURL("https://www.lyrics.com/");
        }
        else if (selected_platform.compare(LyricsOnDemand) == 0)
        {
            webView-> LoadURL("https://www.lyricsondemand.com/");
        }
        else if (selected_platform.compare(WorshipTogether+ "_removed") == 0)
        {
            webView-> LoadURL("https://www.worshiptogether.com/search-results/");
        }
        else if (selected_platform.compare(UltimateGuitar + "_removed") == 0)
        {
            webView-> LoadURL("https://www.ultimate-guitar.com/");
        }
        else
        {
            webView-> LoadURL("https://www.google.com/");
        }
    }
    else
    {
        if (curr_platform != PlatformListCtrl->GetItemCount() - 1)
        {
            through = false;
            for (int i = 0; i < curr_index + 1; i++)
            {
                if (songsDetails[i].size() == (unsigned int)lyrics_index)
                //Check for songs without lyrics
                {
                    curr_platform++;
                    curr_index = i;
                    through = true;
                    break;
                }
            }
            if (through)
            {
                selected_platform = PlatformListCtrl->GetItemText(curr_platform);
                if (selected_platform.compare(AZLyrics + "_removed") == 0)
                {
                    webView-> LoadURL("https://www.azlyrics.com/");
                }
                else if (selected_platform.compare(Genius + "_removed") == 0)
                {
                    webView-> LoadURL("https://genius.com/");
                }
                else if (selected_platform.compare(KLove) == 0)
                {
                    webView-> LoadURL("https://www.klove.com/music/songs#music-search-form");
                }
                else if (selected_platform.compare(Lyrics) == 0)
                {
                    webView-> LoadURL("https://www.lyrics.com/");
                }
                else if (selected_platform.compare(LyricsOnDemand) == 0)
                {
                    webView-> LoadURL("https://www.lyricsondemand.com/");
                }
                else if (selected_platform.compare(WorshipTogether+ "_removed") == 0)
                {
                    webView-> LoadURL("https://www.worshiptogether.com/search-results/");
                }
                else if (selected_platform.compare(UltimateGuitar + "_removed") == 0)
                {
                    webView-> LoadURL("https://www.ultimate-guitar.com/");
                }
                else
                {
                    webView-> LoadURL("https://www.google.com/");
                }
            }
            else
            {
                SlidesFrame::WriteSlides();
                ReportSongsBtn->Enable(true);
                webstate = -1;
            }
        }
        else
        {
            SlidesFrame::WriteSlides();
            ReportSongsBtn->Enable(true);
            webstate = -1;
        }
    }
}

wxString SlidesFrame::EncodeURI(const wxString& uri)
{
    static unordered_map<int, wxString> sEncodeMap = {
        { (int)'!', "%21" }, { (int)'#', "%23" }, { (int)'$', "%24" }, { (int)'&', "%26" }, { (int)'\'', "%27" },
        { (int)'(', "%28" }, { (int)')', "%29" }, { (int)'*', "%2A" }, { (int)'+', "%2B" }, { (int)',', "%2C" },
        { (int)';', "%3B" }, { (int)'=', "%3D" }, { (int)'?', "%3F" }, { (int)'@', "%40" }, { (int)'[', "%5B" },
        { (int)']', "%5D" }, { (int)' ', "%20" }
    };

    wxString encoded;
    for(size_t i = 0; i < uri.length(); ++i) {
        wxChar ch = uri[i];
        unordered_map<int, wxString>::iterator iter = sEncodeMap.find((int)ch);
        if(iter != sEncodeMap.end()) {
            encoded << iter->second;
        } else {
            encoded << ch;
        }
    }
    return encoded;
}

void SlidesFrame::ExecuteScript(wxWebViewEvent& event)
{
    if (webstate == -1)
    {
        return;
    }
    wxString url = event.GetURL();
    //wxMessageBox(url);
    wxString lurl = url;
    lurl.MakeLower();
    if (url.compare("about:blank") == 0 || url.find("https://vars.hotjar.com") == 0)
    {
        return;
    }
    else if (lurl.find("https://profile.ccli.com/account/signin") == 0)
    {
        webView-> RunScript(
        "\
        document.getElementById('EmailAddress').value = 'markwong03121997@gmail.com';\
        document.getElementById('Password').value = 'markwongty1997';\
        document.getElementById('sign-in').click();\
        ");
    }
    else if (lurl.compare("https://reporting.ccli.com/") == 0)
    {
        if (webstate == 1)
        {
            webView->LoadURL("https://songselect.ccli.com");
        }
        else if (webstate == 2)
        {
            wxString query = SongsListCtrl->GetItemText(curr_index, 0) + " " + SongsListCtrl->GetItemText(curr_index, 1);
            query = EncodeURI(query);
            webView->LoadURL(wxString::Format("https://reporting.ccli.com/search?s=%s", query));
        }
    }
    else if (lurl.compare("https://reporting.ccli.com/search?") == 0)
    {
        if (webstate == 2)
        {
            curr_index++;
            if (curr_index == SongsListCtrl->GetItemCount()) {
                webstate = -1;
                CreateDatabaseBtn->Enable(true);
                return;
            }
            wxString query = SongsListCtrl->GetItemText(curr_index, 0) + " " + SongsListCtrl->GetItemText(curr_index, 1);
            query = EncodeURI(query);
            webView->LoadURL(wxString::Format("https://reporting.ccli.com/search?s=%s", query));
        }
    }
    else if (url.find("https://reporting.ccli.com/search?s=") == 0)
    {
        if (webstate == 2)
        {
            webView-> RunScript(
            "\
            function myFunc2() {\
                document.getElementById('cclDigital').value = \"" + wxString::Format("%d", 1) + "\";\
                var evt = document.createEvent('HTMLEvents');\
                evt.initEvent('change', false, true);\
                document.getElementById('cclDigital').dispatchEvent(evt);\
                document.getElementsByClassName('no-margin-bottom button primary margin-right-halfr')[0].click();\
                setTimeout(function(){document.getElementById('ModalReportSongForm').submit();}, 1000);\
            }\
            function myFunc() {\
                document.getElementsByClassName('button hollow primary small no-margin')[0].click();\
                setTimeout(myFunc2, 500);\
            }\
            setTimeout(myFunc, 4000);\
            ");
        }
    }
    else if (lurl.find("https://profile.ccli.com/account/selectorganization") == 0)
    {
        webView->LoadURL("https://songselect.ccli.com");
    }
    else if (url.compare("https://songselect.ccli.com/") == 0)
    {
        SetStatusText("Searching through CCLI", 0);
        if (webstate == 1)
        {
            webView-> RunScript(
            "\
            document.getElementById('SearchText').value = \"" + SearchTextCtrl2->GetLineText(0) + "\";\
            document.getElementById('searchForm').submit();\
            ");
        }
    }
    else if (url.find("https://songselect.ccli.com/search/results?SongContent=&PrimaryLanguage=&Keys=&Themes=&List=&Sort=&SearchText=") == 0)
    {
        if (webstate == 1)
        {
            SetStatusText("Extracting information from CCLI search", 0);
            wxString* output = new wxString("");
            wxString* output2 = new wxString("");
            webView-> RunScript(
            "\
                var cnt = document.getElementsByClassName('song-result').length;\
                cnt;\
            ", output);
            int cap = SearchSpinCtrl->GetValue();
            int cnt = min(atoi(*output), cap);
            if (cnt == 0)
            {
                ReportSongsBtn->Enable(true);
                webstate = -1;
                return;
            }
            curr_index = 0;
            songsDetails.resize(cnt);
            for (int i = 0; i <cnt; i++)
            {
                songsDetails[i].clear();
            }

            urlList.clear();
            webView-> RunScript(
            "\
                var output = [];\
                var elements = document.getElementsByClassName('song-result-title');\
                var cap = Math.min(elements.length, " + to_string(cap) + ");\
                for (var i = 0; i < cap; i++)\
                {\
                    output.push(elements[i].getElementsByTagName('a')[0].href);\
                }\
                var joined = output.join('*');\
                joined;\
            ", output);
            wxStringTokenizer tkz(*output, wxT("*"));
            while (tkz.HasMoreTokens())
            {
                urlList.push_back(tkz.GetNextToken());
            }

            webView-> RunScript(
            "\
                var output = [];\
                var elements = document.getElementsByClassName('song-result-title');\
                var cap = Math.min(elements.length, " + to_string(cap) + ");\
                for (var i = 0; i < cap; i++)\
                {\
                    output.push(elements[i].innerText);\
                }\
                var joined = output.join('*');\
                joined;\
            ", output);
            output->Replace("\r", "");
            wxStringTokenizer tkz2(*output, wxT("*"));

            webView-> RunScript(
            "\
                var output = [];\
                var elements = document.getElementsByClassName('song-result-subtitle');\
                var cap = Math.min(elements.length, " + to_string(cap) + ");\
                for (var i = 0; i < cap; i++)\
                {\
                    output.push(elements[i].innerText);\
                }\
                var joined = output.join('*');\
                joined;\
            ", output2);
            output2->Replace("\r", "");
            wxStringTokenizer tkz3(*output2, wxT("*"));
            for (int i = 0; i <cnt; i++)
            {
                songsDetails[i].push_back(wxString::Format("%s\n%s", tkz2.GetNextToken(), tkz3.GetNextToken()));
            }
            delete output;
            delete output2;

            url_index = 0;
            if(urlList.size() > 0)
            {
                webView->LoadURL(urlList[0]);
            }
        }
    }
    else if (url.find("https://songselect.ccli.com/Songs") == 0)
    {
        if (webstate == 1)
        {
            wxString* output = new wxString("");
            webView-> RunScript(
            "\
                var elements = document.getElementsByClassName('song-meta');\
                var text = elements[0].innerText;\
                var start1 = text.search('Copyrights');\
                var start2 = text.substring(start1 + 11).search('Catalogue');\
                text.substring(start1 + 11, start2 + start1 + 10);\
            ", output);
            output->Replace("\r", "");
            output = &(output->Trim(false).Trim(true));
            songsDetails[url_index].push_back(*output);

            webView-> RunScript(
            "\
                var elements = document.getElementsByClassName('large-4 columns');\
                elements[0].getElementsByTagName('p')[0].innerText;\
            ", output);
            wxString content = "";
            int max_lines = 4;//arbitrary
            if ((*output).Trim(false).Trim(true).compare("No lyrics are currently available") != 0)
            {
                wxStringTokenizer tkz3((*output).Trim(false).Trim(true), wxT("\n"));
                while (tkz3.HasMoreTokens() && max_lines > 0)
                {
                    content += '\n' + tkz3.GetNextToken();
                    max_lines--;
                }
            }
            songsDetails[url_index].push_back(content);
            delete output;

            url_index++;
            if(url_index == (int)urlList.size())
            {
                if (selected_platform.compare(AZLyrics + "_removed") == 0)
                {
                    webView-> LoadURL("https://www.azlyrics.com/");
                }
                else if (selected_platform.compare(Genius + "_removed") == 0)
                {
                    webView-> LoadURL("https://genius.com/");
                }
                else if (selected_platform.compare(KLove) == 0)
                {
                    webView-> LoadURL("https://www.klove.com/music/songs#music-search-form");
                }
                else if (selected_platform.compare(Lyrics) == 0)
                {
                    webView-> LoadURL("https://www.lyrics.com/");
                }
                else if (selected_platform.compare(LyricsOnDemand) == 0)
                {
                    webView-> LoadURL("https://www.lyricsondemand.com/");
                }
                else if (selected_platform.compare(WorshipTogether + "_removed") == 0)
                {
                    webView-> LoadURL("https://www.worshiptogether.com/search-results/");
                }
                else if (selected_platform.compare(UltimateGuitar + "_removed") == 0)
                {
                    webView-> LoadURL("https://www.ultimate-guitar.com/");
                }
                else
                {
                    webView-> LoadURL("https://www.google.com/");
                }
            }
            else
            {
                webView->LoadURL(urlList[url_index]);
            }
        }
    }
    else if (url.compare("https://www.azlyrics.com/_removed") == 0 \
             || url.compare("https://genius.com/_removed") == 0 \
             || url.compare("https://www.klove.com/music/songs#music-search-form") == 0 \
             || url.compare("https://www.lyrics.com/") == 0 \
             || url.compare("https://www.lyricsondemand.com/") == 0 \
             || url.compare("https://www.worshiptogether.com/search-results/_removed") == 0 \
             || url.compare("https://www.ultimate-guitar.com/_removed") == 0 \
             || url.find("https://www.google.com/#spf") == 0 \
             || url.compare("https://www.google.com/") == 0)
    {
        SetStatusText(wxString::Format("Extracting lyrics of song %d from %s", curr_index+1, selected_platform), 0);
        wxStringTokenizer tkz(songsDetails[curr_index][0], wxT("\n"));

        if (selected_platform.compare(AZLyrics + "_removed") == 0)
        {
            webView-> RunScript(
            "\
            document.getElementsByName('q')[0].value = \"" + tkz.GetNextToken() + " " + songsDetails[curr_index][2] + "\";\
            document.getElementsByClassName('btn btn-primary')[0].click();\
            ");
        }
        else if (selected_platform.compare(Genius + "_removed") == 0)
        {
            webView-> RunScript(
            "\
            document.getElementsByName('q')[0].value = \"" + tkz.GetNextToken() + " " + songsDetails[curr_index][2] + "\";\
            document.getElementsByClassName('PageHeaderSearchdesktop__Form-eom9vk-0 bxGFTc')[0].submit();\
            ");
        }
        else if (selected_platform.compare(KLove) == 0)
        //Requires exact song name
        {
            webView-> RunScript(
            "\
            document.getElementById('musicSearchInput').value = \"" + tkz.GetNextToken() + " " + songsDetails[curr_index][2] + "\";\
            document.getElementById('button-musicsearch').click();\
            ");
        }
        else if (selected_platform.compare(Lyrics) == 0)
        {
            webView-> RunScript(
            "\
            document.getElementById('search').value = \"" + tkz.GetNextToken() + " " + songsDetails[curr_index][2] + "\";\
            document.getElementById('search-frm').submit();\
            ");
        }
        else if (selected_platform.compare(LyricsOnDemand) == 0)
        {
            webView-> RunScript(
            "\
            document.getElementsByName('q')[0].value = \"" + tkz.GetNextToken() + " " + songsDetails[curr_index][2] + "\";\
            document.getElementsByName('sa')[0].click();\
            ");
        }
        else if (selected_platform.compare(WorshipTogether + "_removed") == 0)
        {
            wxURI uri(tkz.GetNextToken() + " " + songsDetails[curr_index][2]);
            wxString encoded_uri = "https://www.worshiptogether.com/search-results/#?cludoquery=" + uri.BuildURI();// + "&cludopage=1"
            webView->LoadURL(encoded_uri);
            webView->Reload(wxWEBVIEW_RELOAD_NO_CACHE);
        }
        else if (selected_platform.compare(UltimateGuitar + "_removed") == 0)
        {
            webView-> RunScript(
            "\
            document.getElementsByName('value')[0].value = \"" + tkz.GetNextToken() + " " + songsDetails[curr_index][2] + "\";\
            document.getElementsByClassName('_1dnQP AHe46')[0].submit();\
            ");
        }
        else
        {
            if (webstate != -1)
            {
                webView-> RunScript(
                "\
                document.getElementsByName('q')[0].value = \"" + selected_platform + " " + tkz.GetNextToken() + " " + songsDetails[curr_index][2] + "\";\
                ");
                webView-> RunScript(
                "\
                setTimeout(function(){document.getElementsByTagName('form')[0].submit();}, Math.random()*1000);\
                ");
            }
        }
    }
    else if (url.find("https://search.azlyrics.com/search.php?_removed") == 0 \
             || url.find("https://genius.com/search?_removed") == 0 \
             || url.find("https://www.klove.com/search?s=/music&q") == 0 \
             || url.find("https://www.worshiptogether.com/search-results/#?cludoquery=_removed") == 0 \
             || url.find("https://www.lyrics.com/lyrics/") == 0 \
             || url.find("https://www.lyricsondemand.com/results.html?") == 0 \
             || url.find("https://www.ultimate-guitar.com/search.php?_removed") == 0 \
             || url.find("https://www.google.com/search") == 0)
    {
        wxString* output = new wxString("");
        if (selected_platform.compare(AZLyrics + "_removed") == 0)
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('text-left visitedlyr');\
            if (elements.length != 0)\
            {\
                elements[0].click();\
                through = 1;\
            }\
            through;\
            ", output);
        }
        else if (selected_platform.compare(Genius + "_removed") == 0)
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('mini_card');\
            if (elements.length != 0)\
            {\
                elements[0].click();\
                through = 1;\
            }\
            through;\
            ", output);
        }
        else if (selected_platform.compare(KLove) == 0)
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('st-search-results')[0].getElementsByTagName('a');\
            if (elements.length != 0)\
            {\
                elements[0].click();\
                through = 1;\
            }\
            through;\
            ", output);
        }
        else if (selected_platform.compare(Lyrics) == 0)
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('lyric-body');\
            if (elements.length != 0)\
            {\
                elements[0].click();\
                through = 1;\
            }\
            through;\
            ", output);
        }
        else if (selected_platform.compare(LyricsOnDemand) == 0)
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('gs-title');\
            if (elements.length >= 2)\
            {\
                through = 1;\
            }\
            through;\
            ", output);
        }
        else if (selected_platform.compare(WorshipTogether + "_removed") == 0)
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('search-results-item');\
            if (elements.length != 0)\
            {\
                elements[0].getElementsByTagName('a')[0].click();\
                through = 1;\
            }\
            through;\
            ", output);
        }
        else if (selected_platform.compare(UltimateGuitar + "_removed") == 0)
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('_3DU-x JoRLr _3dYeW');\
            if (elements.length != 0)\
            {\
                elements[0].click();\
                through = 1;\
            }\
            through;\
            ", output);
        }
        else
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('yuRUbf');\
            if (elements.length != 0)\
            {\
                elements[0].getElementsByTagName('a')[0].click();\
                through = 1;\
            }\
            through;\
            ", output);
        }
        int cnt = atoi(*output);
        if (cnt == 0)
        {
            SlidesFrame::ScriptProgression();
        }
        else if (selected_platform.compare(LyricsOnDemand) == 0)
        {
            webView-> RunScript(
            "\
            var output = '';\
            var elements = document.getElementsByClassName('gs-title');\
            if (elements.length >= 2)\
            {\
                output = elements[1].href;\
            }\
            output;\
            ", output);
            webView->LoadURL(*output);
        }
        delete output;
    }
    else if (url.find("https://www.azlyrics.com/lyrics/") == 0 \
             || url.find("https://genius.com/") == 0 \
             || url.find("https://www.klove.com/music/artists") == 0 \
             || url.find("https://www.lyrics.com//lyric") == 0 \
             || url.find("http://www.lyricsondemand.com/") == 0 \
             || url.find("https://www.lyricsondemand.com/") == 0 \
             || url.find("https://www.musixmatch.com/lyrics/") == 0 \
             || url.find("https://tabs.ultimate-guitar.com/tab/") == 0 \
             || url.find("https://www.worshiptogether.com/songs") == 0)
    {
        wxString* lyrics = new wxString("");
        if (selected_platform.compare(AZLyrics) == 0 && url.find("https://www.azlyrics.com/lyrics/") == 0)
        {
            webView-> RunScript(
            "\
            var output = '';\
            var inner = document.getElementsByClassName('ringtone')[0].innerText;\
            var elements = document.getElementsByTagName('div');\
            for (var i = 0; i < elements.length; i++)\
            {\
                if (elements[i].innerText == inner)\
                {\
                    output = elements[i + 1].innerText;\
                    break;\
                };\
            }\
            output;\
            ", lyrics);
        }
        else if (selected_platform.compare(Genius) == 0 && url.find("https://genius.com/") == 0)
        {
            //Lyrics are shown briefly and then disappears
            webView-> RunScript(
            "\
            var output = '';\
            var elements = document.getElementsByClassName('Lyrics__Container-sc-1ynbvzw-2 jgQsqn');\
            if (elements.length != 0)\
            {\
                output = elements[0].innerText;\
            }\
            output;\
            ", lyrics);
        }
        else if (selected_platform.compare(KLove) == 0 && url.find("https://www.klove.com/music/artists") == 0)
        {
            webView-> RunScript(
            "\
            var output = '';\
            var elements = document.getElementsByClassName('text-article');\
            if (elements.length != 0)\
            {\
                output = elements[0].innerText;\
            }\
            output;\
            ", lyrics);
        }
        else if (selected_platform.compare(Lyrics) == 0 && url.find("https://www.lyrics.com//lyric") == 0)
        //"https://www.lyrics.com/no-lyrics.php" is the instance when there are no lyrics
        {
            webView-> RunScript(
            "\
            var output = '';\
            var element = document.getElementById('lyric-body-text');\
            output = element.innerText;\
            output;\
            ", lyrics);

        }
        else if (selected_platform.compare(LyricsOnDemand) == 0 && (url.find("http://www.lyricsondemand.com/") == 0 || url.find("https://www.lyricsondemand.com/") == 0))
        {
            webView-> RunScript(
            "\
            var output = '';\
            var elements = document.getElementsByClassName('lcontent');\
            if (elements.length != 0)\
            {\
                output = elements[0].innerText;\
            }\
            output;\
            ", lyrics);
        }
        else if (selected_platform.compare(Musixmatch) == 0 && url.find("https://www.musixmatch.com/lyrics/") == 0)
        {
            webView-> RunScript(
            "\
            var output = '';\
            var elements = document.getElementsByClassName('mxm-lyrics__content');\
            for (var i = 0; i < elements.length; i++)\
            {\
                output += elements[i].innerText;\
            }\
            output;\
            ", lyrics);
        }
        else if (selected_platform.compare(UltimateGuitar) == 0 && url.find("https://tabs.ultimate-guitar.com/tab/") == 0)
        {
            //Page on load is not fully loaded with lyrics but cannot delay with a sychronised output
            webView-> RunScript(
            "\
            function sleep(ms) {\
              return new Promise(function(resolve) {setTimeout(resolve, ms);});\
            }\
            sleep(3000).then(function(obj){});\
            var output = '';\
            var elements = document.getElementsByClassName('_3F2CP _3hukP');\
            var start = 0;\
            if (elements.length > 0)\
            {\
                var element = elements[0];\
                for (var i = 0; i < element.childElementCount; i++)\
                {\
                    if (element.children[i].className == '_2jIGi')\
                    {\
                        output += element.children[i].lastChild.innerText.trim() + '\\n';\
                        start = 1;\
                    }\
                    else\
                    {\
                        if (start == 1)\
                        {\
                            output += '\\n';\
                            start = 0;\
                        }\
                    }\
                }\
            }\
            output;\
            ", lyrics);
            //document.documentElement.innerHTML;
        }
        else if (selected_platform.compare(WorshipTogether) == 0 && url.find("https://www.worshiptogether.com/songs") == 0)
        {
            webView-> RunScript(
            "\
            var output = '';\
            var line = '';\
            var elements = document.getElementsByClassName('chord-pro-disp');\
            if (elements.length > 0)\
            {\
                var element = elements[0];\
                for (var i = 0; i < element.childElementCount; i++)\
                {\
                    if (element.children[i].className == 'chord-pro-line')\
                    {\
                        var elements2 = element.children[i].getElementsByClassName('chord-pro-lyric');\
                        for (var ii = 0; ii < elements2.length; ii++)\
                        {\
                            line += elements2[ii].innerText;\
                        }\
                        line += '\\n';\
                    }\
                    else if (element.children[i].className == 'chord-pro-br')\
                    {\
                        output += '\\n';\
                    }\
                    output += line;\
                    line = '';\
                }\
            }\
            output;\
            ", lyrics);
        }
        lyrics->Replace("\r", "");
        wxMessageBox(selected_platform + "\n" + *lyrics);
        if ((*lyrics).compare("") != 0)
        {
            //*lyrics = selected_platform + *lyrics;
            songsDetails[curr_index].push_back(*lyrics);
        }
        delete lyrics;
        SlidesFrame::ScriptProgression();
    }
    else if (url.find("google") == string::npos && \
             url.find("adnxs") == string::npos && \
             url.find("project") == string::npos)
    //There are intermediate webpages for google search & Lyrics
    {
        SlidesFrame::ScriptProgression();
    }
}

void SlidesFrame::ExecuteScript2(wxWebViewEvent& event)
{
    if (webstate == -1)
    {
        return;
    }
    wxString url = event.GetURL();
    wxString lurl = url;
    lurl.MakeLower();

    if (lurl.find("https://profile.ccli.com/account/signin") == 0)
    {
        webView-> RunScript(
        "\
        document.getElementById('EmailAddress').value = 'faithsanctuaryoffice@gmail.com';\
        document.getElementById('Password').value = 'BlackBox_1234';\
        document.getElementById('sign-in').click();\
        ");
    }
    else if (lurl.compare("https://reporting.ccli.com/") == 0)
    {
        if (webstate == 1)
        {
            webView->LoadURL("https://songselect.ccli.com");
        }
        else if (webstate == 2)
        {
            wxString filename = SongsListCtrl->GetItemText(curr_index, 3);
            int idx = filename.rfind("\\");
            wxString query = filename.substr(idx + 1, filename.Len() - 5 - idx);
            query.Replace("(", "");
            query.Replace(")", "");
            query = EncodeURI(query);
            webView->LoadURL(wxString::Format("https://reporting.ccli.com/search?s=%s", query));
        }
    }
    else if (lurl.compare("https://reporting.ccli.com/search?") == 0 || lurl.compare("https://reporting.ccli.com/search") == 0)
    {
        if (webstate == 2)
        {
            curr_index++;
            if (curr_index == SongsListCtrl->GetItemCount()) {
                webstate = -1;
                CreateDatabaseBtn->Enable(true);
                SetStatusText("Done reporting", 0);
                return;
            }
            wxString filename = SongsListCtrl->GetItemText(curr_index, 3);
            int idx = filename.rfind("\\");
            wxString query = filename.substr(idx + 1, filename.Len() - 5 - idx);
            query.Replace("(", "");
            query.Replace(")", "");
            query = EncodeURI(query);
            webView->LoadURL(wxString::Format("https://reporting.ccli.com/search?s=%s", query));
        }
    }
    else if (url.find("https://reporting.ccli.com/search?s=") == 0)
    {
        if (webstate == 2)
        {
            webView-> RunScript(
            "\
            function myFunc2() {\
                document.getElementById('cclDigital').value = \"" + wxString::Format("%d", 1) + "\";\
                var evt = document.createEvent('HTMLEvents');\
                evt.initEvent('change', false, true);\
                document.getElementById('cclDigital').dispatchEvent(evt);\
                document.getElementsByClassName('no-margin-bottom button primary margin-right-halfr')[0].click();\
                setTimeout(function(){document.getElementById('ModalReportSongForm').submit();}, 1000);\
            }\
            function myFunc() {\
                document.getElementsByClassName('button hollow primary small no-margin')[0].click();\
                setTimeout(myFunc2, 500);\
            }\
            setTimeout(myFunc, 4000);\
            ");
        }
    }
    else if (url.compare("https://songselect.ccli.com/") == 0)
    {
        SetStatusText("Searching through CCLI", 0);
        if (webstate == 1)
        {
            webView-> RunScript(
            "\
            document.getElementById('SearchText').value = \"" + SearchTextCtrl2->GetLineText(0) + "\";\
            document.getElementById('searchForm').submit();\
            ");
        }
    }
    else if (lurl.find("https://songselect.ccli.com/search/results?") == 0)
    {
        if (webstate == 1)
        {
            SetStatusText("Extracting information from CCLI search", 0);
            wxString* output = new wxString("");
            wxString* output2 = new wxString("");
            webView-> RunScript(
            "\
                var cnt = document.getElementsByClassName('song-result').length;\
                cnt;\
            ", output);
            int cap = SearchSpinCtrl->GetValue();
            int cnt = min(atoi(*output), cap);
            if (cnt == 0)
            {
                ReportSongsBtn->Enable(true);
                webstate = -1;
                return;
            }
            curr_index = 0;
            songsDetails.resize(cnt);
            for (int i = 0; i <cnt; i++)
            {
                songsDetails[i].clear();
            }

            urlList.clear();

            webView-> RunScript(
            "\
                var output = [];\
                var elements = document.getElementsByClassName('song-result-title');\
                var cap = Math.min(elements.length, " + to_string(cap) + ");\
                for (var i = 0; i < cap; i++)\
                {\
                    output.push(elements[i].getElementsByTagName('a')[0].href);\
                }\
                var joined = output.join('*');\
                joined;\
            ", output);
            wxStringTokenizer tkz(*output, wxT("*"));
            while (tkz.HasMoreTokens())
            {
                urlList.push_back(tkz.GetNextToken());
            }

            webView-> RunScript(
            "\
                var output = [];\
                var elements = document.getElementsByClassName('song-result-title');\
                var cap = Math.min(elements.length, " + to_string(cap) + ");\
                for (var i = 0; i < cap; i++)\
                {\
                    output.push(elements[i].innerText);\
                }\
                var joined = output.join('*');\
                joined;\
            ", output);
            output->Replace("\r", "");
            wxStringTokenizer tkz2(*output, wxT("*"));

            webView-> RunScript(
            "\
                var output = [];\
                var elements = document.getElementsByClassName('song-result-subtitle');\
                var cap = Math.min(elements.length, " + to_string(cap) + ");\
                for (var i = 0; i < cap; i++)\
                {\
                    output.push(elements[i].innerText);\
                }\
                var joined = output.join('*');\
                joined;\
            ", output2);
            output2->Replace("\r", "");
            wxStringTokenizer tkz3(*output2, wxT("*"));
            for (int i = 0; i <cnt; i++)
            {
                songsDetails[i].push_back(wxString::Format("%s\n%s", tkz2.GetNextToken(), tkz3.GetNextToken()));
            }
            delete output;
            delete output2;

            url_index = 0;
            if(urlList.size() > 0)
            {
                webView->LoadURL(urlList[0] + "/viewlyrics");
            }
        }
    }
    else if (url.find("https://songselect.ccli.com/Songs") == 0)
    {
        if (webstate == 1)
        {
            wxString* output = new wxString("");
            webView-> RunScript(
            "\
                var elements = document.getElementsByClassName('copyright');\
                elements[0].innerText;\
            ", output);
            output->Replace("\n\n", "\n");
            output = &(output->Trim(false).Trim(true));
            songsDetails[url_index].push_back(*output);

            webView-> RunScript(
            "\
                var elements = document.getElementsByClassName('song-viewer lyrics');\
                elements[0].innerText;\
            ", output);
            wxString content = "", token = "";
            if ((*output).Trim(false).Trim(true).compare("No lyrics are currently available") != 0)
            {
                wxStringTokenizer tkz3((*output).Trim(false).Trim(true), wxT("\n"));
                tkz3.GetNextToken();
                while (tkz3.HasMoreTokens())
                {
                    token = tkz3.GetNextToken();
                    if (token.find("CCLI") == 0) {
                        break;
                    }
                    content += '\n' + token;
                }
            }
            songsDetails[url_index].push_back("");
            songsDetails[url_index].push_back(content);
            delete output;

            url_index++;
            if(url_index == (int)urlList.size())
            {
                SlidesFrame::WriteSlides();
                webstate = -1;
            }
            else
            {
                webView->LoadURL(urlList[url_index] + "/viewlyrics");
            }
        }
    }
}

void SlidesFrame::OnErrorWebView(wxWebViewEvent& event)
{
    if (event.GetInt() != wxWEBVIEW_NAV_ERR_CONNECTION)
    {
        SlidesFrame::ScriptProgression();
        return;
    }
    SetStatusText("Internet connection fails.");
    FileRichTextCtrl->AppendText("\n" + event.GetURL());
    webstate = -1;
    CreateDatabaseBtn->Enable(true);
    ReportSongsBtn->Enable(true);
}

void SlidesFrame::OnCancelBtnClick(wxCommandEvent& event)
{
    SetStatusText("Canceled", 0);
    webstate = -1;
    CreateDatabaseBtn->Enable(true);
    ReportSongsBtn->Enable(true);
}

void SlidesFrame::OnCreateDatabaseBtnClick(wxCommandEvent& event)
{
    SetStatusText("Creating database...", 0);
    if (PlatformListCtrl->GetItemCount() == 0)
    {
        SetStatusText("No platform for use");
        return;
    }
    wxDir dir(configmap["Default songs directory"]);
    if (!dir.IsOpened())
    {
        SetStatusText("Songs directory specified is invalid");
        return;
    }
    ReportSongsBtn->Enable(false);
    selected_platform = PlatformListCtrl->GetItemText(0, 0);
    curr_platform = 0;
	wxString URL = "https://profile.ccli.com/account/signin?appContext=OLR&returnUrl=https%3a%2f%2folr.ccli.com%3a443%2f";
    webstate = 1;
    webView -> LoadURL(URL);
}

void SlidesFrame::OnReportSongsBtnClick(wxCommandEvent& event)
{
    SetStatusText("Reporting songs...", 0);
    if (SongsListCtrl->GetItemCount() == 0)
    {
        SetStatusText("No song to report");
        return;
    }
    CreateDatabaseBtn->Enable(false);
	wxString URL = "https://profile.ccli.com/account/signin?appContext=OLR&returnUrl=https%3a%2f%2folr.ccli.com%3a443%2f";
    webstate = 2;
    curr_index = 0;
    webView -> LoadURL(URL);
}

void SlidesFrame::OnLicenseSpinCtrlChange(wxSpinEvent& event)
{
    configmap["Maximum lines for CCLI"] = to_string(LicenseSpinCtrl->GetValue());
}

bool SlidesFrame::ParseSlide(wxString filename, wxVector <wxString>& info)
{
    info.clear();
    wxFile wxofsFile;
    if (!wxofsFile.Exists(filename))
    {
        SetStatusText("Cannot find" + filename, 0);
        return false;
    }
    wxFileInputStream input(filename);
    wxTextInputStream text(input, wxT("\x09"), wxConvUTF8);
    wxString line, segment;

    for (int i = 0; i < 3; i++)
    {
        line = text.ReadLine();
        /*
        while(line.compare("") == 0)
        //Removes blank lines
        {
            if (input.Eof())
            {
                return false;
            }
            line = text.ReadLine();
        }
        */
        info.push_back(line);
    }

    text.ReadLine();//consume blank line
    line = text.ReadLine();
    bool first = true;
    while (line.compare("") != 0){
        if(first){
            segment = line;
            first = false;
        }else{
            segment += "\n" + line;
        }
        line = text.ReadLine();
    }
    info.push_back(segment);
    segment = "";

    while(!input.Eof())
    {
        line = text.ReadLine();
        if (line.compare("") == 0 && segment.compare("") != 0)
        {
            info.push_back(segment);
            segment = "";
            continue;
        }
        if (segment.compare("") != 0)
        {
            segment += "\n";
        }
        segment += line;
    }
    if (segment.compare("") != 0)
    {
        info.push_back(segment);
    }
    return true;
}

void SlidesFrame::OnCreateSlidesBtnClick(wxCommandEvent& event)
{
	wxAutomationObject ppt, presentation, temp, customlayout, designs, design, shapes, textframe, textrange, textrange2, \
                       shp, slide, slides, textbox, range, videoslide, sequence, effect, component;
	wxVariant vpresentation, vtemp, vcustomlayout, vdesign, vshp, vslide, vname, vtextbox, vtextrange, vrange, \
              vvideoslide, vsequence, veffect, vcomponent;
	wxVector<wxString> groupNames, customNames;
    int cr, cnt, cnt2, width, height, count2;

    try
    {
        SetStatusText("Creating slides", 0);
        if (SongsListCtrl->GetItemCount() == 0)
        {
            SetStatusText("At least a song has to be selected");
            return;
        }
        wxString creation_mode = VideoRadioBox->GetString(VideoRadioBox->GetSelection());
        wxString option = FunctionsRadioBox->GetString(FunctionsRadioBox->GetSelection());
        ppt.CreateInstance("PowerPoint.Application");
        if (!ppt.IsOk())
        {
            SetStatusText("Failed to obtain PowerPoint.Application instance.");
            return;
        }

        wxString filename = configmap["Default templates directory"] + "\\" + configmap["Template"];
        if(configmap["Default templates directory"].find("\\") == (size_t)-1)
        {
            filename = dirName + "\\" + filename;
        }
        wxFile wxofsFile;
        if (!wxofsFile.Exists(filename))
        {
            SetStatusText(wxT("Cannot find template file"), 0);
            return;
        }
        else if (!filename.EndsWith(".ppt") && !filename.EndsWith(".pptx"))
        {
            SetStatusText(wxT("Template file must be .ppt/.pptx"), 0);
            return;
        }

        ppt.PutProperty("Visible", true);
        vtemp = ppt.CallMethod("Presentations.Open", filename);
        temp.SetDispatchPtr((IDispatch*)vtemp.GetVoidPtr());
        double w = temp.GetProperty("PageSetup.SlideWidth").GetDouble();
        double h = temp.GetProperty("PageSetup.SlideHeight").GetDouble();
        if (temp.GetProperty("Slides.Count").GetLong() == 0)
        {
            SetStatusText("Template contains no slide", 0);
            return;
        }
        vslide = temp.CallMethod("Slides.Item", 1);
        slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
        slide.GetObject(shapes, "Shapes");
        vrange = shapes.CallMethod("Range");
        range.SetDispatchPtr((IDispatch*)vrange.GetVoidPtr());
        range.CallMethod("Copy");
        temp.CallMethod("Close");

        vpresentation = ppt.CallMethod("Presentations.Add", true);
        presentation.SetDispatchPtr((IDispatch*)vpresentation.GetVoidPtr());
        presentation.PutProperty("PageSetup.SlideWidth", w);
        presentation.PutProperty("PageSetup.SlideHeight", h);
        ppt.PutProperty("Visible", true);
        presentation.GetObject(designs, "Designs");
        vdesign = designs.CallMethod("Item", 1);
        design.SetDispatchPtr((IDispatch*)vdesign.GetVoidPtr());
        vcustomlayout = design.CallMethod("SlideMaster.CustomLayouts.Add", 1);
        customlayout.SetDispatchPtr((IDispatch*)vcustomlayout.GetVoidPtr());
        customlayout.GetObject(shapes, "Shapes");
        cnt = shapes.GetProperty("Count").GetLong();
        for (int i = 1; i <= cnt; i++)
        //Delete all shapes in SlideMaster
        {
            vshp = shapes.CallMethod("Item", 1);
            shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
            shp.CallMethod("Delete");
        }

        cr = (long)wxColour(0, 0, 0).GetRGB();
        //Look into
        presentation.PutProperty("SlideMaster.Background.Fill.ForeColor.RGB", cr);
        width = presentation.GetProperty("PageSetup.SlideWidth").GetLong();
        height = presentation.GetProperty("PageSetup.SlideHeight").GetLong();
        bool loaded = false;
        if (creation_mode.compare(Words) == 0 || creation_mode.compare(Mix) == 0)
        {
            wxFile wxofsFile;
            wxString modulename = configmap["Default templates directory"] + "\\WordsModule.bas";
            if(configmap["Default templates directory"].find("\\") == (size_t)-1)
            {
                modulename = dirName + "\\" + modulename;
            }
            if (!wxofsFile.Exists(modulename))
            {
                SetStatusText(wxT("Cannot find WordsModule.bas"), 0);
            }
            else
            {
                try
                {
                    vcomponent = ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Import", modulename);
                    loaded = true;
                }
                catch(...)
                {
                    SetStatusText("File>Options>Trust Center>Trust Center Settings>Trust access to the VBA project object model", 0);
                }
            }
        }
        wxVector <wxString> info;
        bool first, has_picture = false;
        int start = 1;
        wxVector<int> videoSlidesNum;
        for (int i = 0; i < SongsListCtrl->GetItemCount(); i++)
        {
            bool success = ParseSlide(SongsListCtrl->GetItemText(i, 3), info);
            if (!success || info.size() <= 4)
            {
                SetStatusText("Cannot find/parse file properly", 0);
                continue;
            }
            int num_slides, num_lines = LyricsSpinCtrl->GetValue();
            if (num_lines == 0)
            {
                num_slides = info.size() - 4;
            }
            else
            {
                wxVector <wxString> info2 = info;
                info.erase(info.begin() + 4, info.end());
                wxString segment = "";
                int cnt = 0;
                bool through;
                for (unsigned int ii = 4; ii < info2.size(); ii++)
                {
                    wxStringTokenizer tkz(info2[ii], "\n");
                    through = false;
                    while(true)
                    {
                        while (cnt < num_lines)
                        {
                            if (tkz.HasMoreTokens())
                            {
                                if (cnt == 0)
                                {
                                    segment = tkz.GetNextToken();
                                }
                                else
                                {
                                    segment += "\n" + tkz.GetNextToken();
                                }
                                cnt++;
                            }
                            else
                            {
                                through= true;
                                break;
                            }
                        }
                        info.push_back(segment);
                        cnt = 0;
                        if (through)
                        {
                            break;
                        }
                    }
                }
                num_slides = info.size() - 4;
            }
            presentation.GetObject(slides, "Slides");
            if (start == 1)
            {
                vslide = presentation.CallMethod("Slides.Add", 1, 32);//ppLayoutCustom
                slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                slide.CallMethod("Select");
                ppt.CallMethod("CommandBars.ExecuteMso", "PasteSourceFormatting");
                start = 0;
            }
            vslide = slides.CallMethod("Item", 1);
            slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
            cnt = slides.GetProperty("Count").GetLong();

            for (int ii = 0; ii < num_slides; ii++)
            {
                slide.CallMethod("Copy");
                Sleep(500);
                presentation.CallMethod("Slides.Paste");
            }
            groupNames.clear();
            cnt2 = slides.GetProperty("Count").GetLong();
            wxString text, licensing, title = info[0] + "\n" + info[1];
            wxStringTokenizer tkz(info[3], "\n");
            int max_lines = LicenseSpinCtrl->GetValue();
            if (tkz.HasMoreTokens() && max_lines > 0)
            {
                licensing += tkz.GetNextToken();
                max_lines--;
            }
            while(tkz.HasMoreTokens() && max_lines > 0)
            {
                licensing += "\n" + tkz.GetNextToken();
                max_lines--;
            }
            first = true;
            for (int ii = cnt + 1; ii <= cnt2; ii++)
            {
                vslide = slides.CallMethod("Item", ii);
                slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                slide.GetObject(shapes,"Shapes");
                count2 = shapes.GetProperty("Count").GetLong();
                for (int iii = 1; iii <= count2; iii++)
                {
                    vshp = shapes.CallMethod("Item",iii);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.GetObject(textframe, "TextFrame");
                    textframe.GetObject(textrange, "TextRange");
                    if (textframe.GetProperty("HasText").GetBool())
                    {
                        text = textframe.GetProperty("TextRange.Text").GetString();
                        if ((int)text.Lower().find("title") != -1)
                        {
                            if ((int)text.Lower().find("cap") != -1)
                            {
                                textframe.PutProperty("TextRange.Text", info[0].Upper() + "\n" + info[1]);
                            }
                            else
                            {
                                textframe.PutProperty("TextRange.Text", title);
                            }
                            if (first)
                            {
                                customNames.push_back(shp.GetProperty("Name").GetString());
                            }
                        }
                        else if ((int)text.Lower().find("lyric") != -1 || (int)text.Lower().find("text") != -1)
                        {
                            wxString part = text.substr(text.rfind(" ") + 1, text.length() - text.rfind(" ") - 2);
                            if (text.rfind(" ") != string::npos && is_number(part))
                            {
                                int fontSize = textrange.GetProperty("Font.size").GetInteger();
                                int fontSize2 = atoi(part);

                                wxStringTokenizer tkz(info[3 + ii - cnt], wxT("\n"));
                                textrange.PutProperty("text", "");
                                int iiii = 0;
                                while (tkz.HasMoreTokens())
                                {
                                    vtextrange = textrange.CallMethod("InsertAfter", tkz.GetNextToken() + "\n");
                                    textrange2.SetDispatchPtr((IDispatch*)vtextrange.GetVoidPtr());
                                    if (iiii % 2 == 0)
                                    {
                                        textrange2.PutProperty("Font.size", fontSize);
                                    }
                                    else
                                    {
                                        textrange2.PutProperty("Font.size", fontSize2);
                                    }
                                    iiii++;
                                }
                            }
                            else
                            {
                                textrange.PutProperty("text", info[3 + ii - cnt]);
                            }
                            groupNames.push_back(shp.GetProperty("Name").GetString());
                        }
                        else if ((int)text.Lower().find("licen") != -1)
                        {
                            if(licensing.compare("") == 0){
                                textframe.PutProperty("TextRange.Text", "");
                            }else{
                                textframe.PutProperty("TextRange.Text", licensing + "\nUsed By Permission. CCL Licence No.306148");
                            }
                            if (first)
                            {
                                customNames.push_back(shp.GetProperty("Name").GetString());
                            }
                        }
                    }
                    else
                    {
                        has_picture = true;
                    }
                }
                first = false;
                if (creation_mode.compare(Words) == 0)
                {
                    if (!has_picture)
                    {
                        vshp = shapes.CallMethod("AddShape", 1, 0, 0, width, height);//msoShapeRectangle
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        cr = (long)wxColour(0,0,0).GetRGB();
                        shp.PutProperty("Fill.ForeColor.RGB", cr);
                        shp.PutProperty("Line.Visible", false);
                        shp.CallMethod("ZOrder", 1);//msoSendToBack
                    }
                    if (loaded)
                    {
                        ppt.CallMethod("Run", "DoMergeShapes", ii);
                    }
                    wxString videoName = SongsListCtrl->GetItemText(i, 4);
                    wxFile wxofsFile;
                    if (!wxofsFile.Exists(videoName))
                    {
                        SetStatusText(wxT("Cannot find video"), 0);
                    }
                    else
                    {
                        vshp = slide.CallMethod("Shapes.AddMediaObject2", videoName);
                        slide.GetObject(sequence, "TimeLine.MainSequence");
                        sequence.CallMethod("AddEffect", vshp, 83, 0, 2, 1);
                        //msoAnimEffectMediaPlay, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                        vshp = slide.CallMethod("Shapes.Item", slide.GetProperty("Shapes.Count").GetLong());
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        shp.PutProperty("Height", height);
                        //height is always shorter than width, aspect stretch
                        shp.PutProperty("AnimationSettings.PlaySettings.LoopUntilStopped", true);
                        shp.CallMethod("ZOrder", 1);//msoSendToBack
                    }
                }
                else if (creation_mode.compare(Mix) == 0)
                {
                    if (!has_picture)
                    {
                        vshp = shapes.CallMethod("AddShape", 1, 0, 0, width, height);//msoShapeRectangle
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        cr = (long)wxColour(0,0,0).GetRGB();
                        shp.PutProperty("Fill.ForeColor.RGB", cr);
                        shp.PutProperty("Line.Visible", false);
                        shp.CallMethod("ZOrder", 1);//msoSendToBack

                        slide.PutProperty("FollowMasterBackground", false);
                        cr = (long)wxColour(255, 255, 255).GetRGB();
                        slide.PutProperty("Background.Fill.ForeColor.RGB", cr);
                    }
                    if (loaded)
                    {
                        ppt.CallMethod("Run", "DoMergeShapes", ii);
                    }
                }
                slide.PutProperty("HeadersFooters.SlideNumber.Visible", false);
            }
            if (creation_mode.compare(Background) == 0)
            {
                int curr = 0, cnt3, left, top;
                bool through;
                wxString videoName = SongsListCtrl->GetItemText(i, 4);
                wxFile wxofsFile;
                videoSlidesNum.push_back(cnt + 1);
                vslide = presentation.CallMethod("Slides.Add", cnt + 1, 32);
                vvideoslide = slides.CallMethod("Item", cnt + 1 + start);
                videoslide.SetDispatchPtr((IDispatch*)vvideoslide.GetVoidPtr());

                for (int ii = cnt + 2; ii <= cnt2 + 1; ii++)
                {
                    vslide = slides.CallMethod("Item", ii);
                    slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                    through = false;
                    for (unsigned int iii = curr; iii < groupNames.size(); iii++)
                    {
                        cnt3 = slide.GetProperty("Shapes.Count").GetLong();
                        for (int iiii = 1; iiii <= cnt3; iiii++)
                        {
                            vshp = slide.CallMethod("Shapes.Item", iiii);
                            shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                            if (groupNames[iii].compare(shp.GetProperty("Name").GetString()) == 0)
                            {
                                curr = iii + 1;
                                through = true;
                                break;
                            }
                        }
                        if (through)
                        {
                            break;
                        }
                    }
                    shp.CallMethod("Copy");
                    Sleep(500);
                    left = shp.GetProperty("Left").GetLong();
                    top = shp.GetProperty("Top").GetLong();
                    vshp = videoslide.CallMethod("Shapes.Paste");
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.PutProperty("Left", left);
                    shp.PutProperty("Top", top);
                }

                videoslide.GetObject(shapes,"Shapes");
                count2 = shapes.GetProperty("Count").GetLong();
                videoslide.GetObject(sequence, "TimeLine.MainSequence");
                for (int ii = 1; ii <= count2; ii++)
                {
                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 2);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", false);

                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 1);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerOnPageClick
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", true);
                }
                if (1 <= count2)
                {
                    vshp = shapes.CallMethod("Item", 1);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.CallMethod("ZOrder", 0);
                }

                if (!wxofsFile.Exists(videoName))
                {
                    SetStatusText(wxT("Cannot find video"), 0);
                }
                else
                {
                    vshp = videoslide.CallMethod("Shapes.AddMediaObject2", videoName);
                    sequence.CallMethod("AddEffect", vshp, 83, 0, 2, 1);
                    //msoAnimEffectMediaPlay, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    vshp = shapes.CallMethod("Item", count2 + 1);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.PutProperty("Height", height);
                    //height is always shorter than width, aspect stretch;
                    shp.PutProperty("AnimationSettings.PlaySettings.LoopUntilStopped", true);
                    shp.CallMethod("ZOrder", 1);//msoSendToBack
                }

                vslide = slides.CallMethod("Item", cnt + 2);
                slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                through = false;
                for (unsigned int iii = 0; iii < customNames.size(); iii++)
                {
                    cnt3 = slide.GetProperty("Shapes.Count").GetLong();
                    for (int iiii = 1; iiii <= cnt3; iiii++)
                    {
                        vshp = slide.CallMethod("Shapes.Item", iiii);
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        if (customNames[iii].compare(shp.GetProperty("Name").GetString()) == 0)
                        {
                            shp.CallMethod("Copy");
                            left = shp.GetProperty("Left").GetLong();
                            top = shp.GetProperty("Top").GetLong();
                            vshp = videoslide.CallMethod("Shapes.Paste");
                            shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                            shp.PutProperty("Left", left);
                            shp.PutProperty("Top", top);
                        }
                    }
                }
            }
            else if (creation_mode.compare(Mix) == 0)
            {
                int left, top;
                wxString videoName = SongsListCtrl->GetItemText(i, 4);
                wxFile wxofsFile;
                videoSlidesNum.push_back(cnt + 1);
                vslide = presentation.CallMethod("Slides.Add", cnt + 1, 32);
                vvideoslide = slides.CallMethod("Item", cnt + 1);
                videoslide.SetDispatchPtr((IDispatch*)vvideoslide.GetVoidPtr());
                for (int ii = cnt + 2; ii <= cnt2 + 1; ii++)
                {
                    vslide = slides.CallMethod("Item", ii);
                    slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                    if (slide.GetProperty("Shapes.Count").GetLong() > 0)
                    {
                        vrange = slide.CallMethod("Shapes.Range");
                        range.SetDispatchPtr((IDispatch*)vrange.GetVoidPtr());
                        range.CallMethod("Copy");
                        Sleep(500);
                        left = range.GetProperty("Left").GetLong();
                        top = range.GetProperty("Top").GetLong();
                        vshp = videoslide.CallMethod("Shapes.Paste");
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        shp.PutProperty("Left", left);
                        shp.PutProperty("Top", top);
                    }
                }
                videoslide.GetObject(shapes,"Shapes");
                count2 = shapes.GetProperty("Count").GetLong();
                videoslide.GetObject(sequence, "TimeLine.MainSequence");
                for (int ii = 1; ii <= count2; ii++)
                {
                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 2);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", false);

                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 1);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerOnPageClick
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", true);
                }
                if (!wxofsFile.Exists(videoName))
                {
                    SetStatusText(wxT("Cannot find video"), 0);
                }
                else
                {
                    vshp = videoslide.CallMethod("Shapes.AddMediaObject2", videoName);
                    sequence.CallMethod("AddEffect", vshp, 83, 0, 2, 1);
                    //msoAnimEffectMediaPlay, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    vshp = shapes.CallMethod("Item", count2 + 1);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.PutProperty("Height", height);
                    //height is always shorter than width, aspect stretch
                    shp.PutProperty("AnimationSettings.PlaySettings.LoopUntilStopped", true);
                    shp.CallMethod("ZOrder", 1);//msoSendToBack
                }
            }
        }
        if (option.compare("Trim slides") == 0)
        {
            int slidesNum = presentation.GetProperty("Slides.Count").GetLong();
            for (int i = (int)videoSlidesNum.size() - 1; i >= 0; i--)
            {
                for (int ii = slidesNum; ii > videoSlidesNum[i]; ii--)
                {
                    vslide = presentation.CallMethod("Slides.Item", ii);
                    slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                    slide.CallMethod("Delete");
                }
                slidesNum = videoSlidesNum[i] - 1;
            }
        }
        vslide = presentation.CallMethod("Slides.Item", 1);
        slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
        slide.CallMethod("Delete");

        if (option.compare("Include macro") == 0 && \
            (creation_mode.compare(Background) == 0 || creation_mode.compare(Mix) == 0))
        {
            //temp.CallMethod("Close");//Ensures that VBA is loaded in correct presentation
            wxFile wxofsFile;
            wxString modulename = configmap["Default templates directory"] + "\\BackgroundModule.bas";
            wxString classname = configmap["Default templates directory"] + "\\BackgroundClass.cls";
            if(configmap["Default templates directory"].find("\\") == (size_t)-1)
            {
                modulename = dirName + "\\" + modulename;
                classname = dirName + "\\" + classname;
            }
            if (!wxofsFile.Exists(modulename))
            {
                SetStatusText(wxT("Cannot find BackgroundModule.bas"), 0);
            }
            else if (!wxofsFile.Exists(classname))
            {
                SetStatusText(wxT("Cannot find BackgroundClass.cls"), 0);
            }
            else
            {
                try
                {
                    ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Import", modulename);
                    ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Import", classname);
                    ppt.CallMethod("Run", "InitializeApp");
                }
                catch(...)
                {
                    SetStatusText("File>Options>Trust Center>Trust Center Settings>Trust access to the VBA project object model", 0);
                }
            }
        }

        if (loaded)
        {
            ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Remove", vcomponent);
            //vcomponent references to MergeShapes routine
        }
        SetStatusText("Slides created", 0);
    }
    catch(exception& e)
    {
        wxMessageBox(e.what());
        SetStatusText("Error creating slides", 0);
    }
}

void SlidesFrame::OnImportCreateBtnClick(wxCommandEvent& event)
{
    wxAutomationObject ppt, presentation, temp, customlayout, designs, design, shapes, textframe, textrange, \
                       shp, slide, slides, textbox, range, videoslide, sequence, effect, component;
	wxVariant vpresentation, vtemp, vcustomlayout, vdesign, vshp, vslide, vname, vtextbox, vrange, \
              vvideoslide, vsequence, veffect, vcomponent;
	wxVector<wxString> groupNames, customNames;
    int cr, cnt, width, height, count2;

    try
    {
        SetStatusText("Modifying slides", 0);
        wxString creation_mode = VideoRadioBox->GetString(VideoRadioBox->GetSelection());
        wxString option = FunctionsRadioBox->GetString(FunctionsRadioBox->GetSelection());
        if (creation_mode.compare("None") == 0)
        {
            SetStatusText("'None' option not applicable to this", 0);
            return;
        }
        ppt.CreateInstance("PowerPoint.Application");
        if (!ppt.IsOk())
        {
            SetStatusText("Failed to obtain PowerPoint.Application instance.", 0);
            return;
        }
        wxString filename;
        fileDialog->SetWildcard("PPT files (*.ppt;*.pptx)|*.ppt;*.pptx");
        if (fileDialog->ShowModal() == wxID_OK)
        {
            filename = fileDialog->GetPath();
        }
        else
        {
            SetStatusText("No file selected", 0);
            return;
        }
        wxFile wxofsFile;
        if (!wxofsFile.Exists(filename))
        {
            SetStatusText(wxT("Cannot find imported file"), 0);
            return;
        }
        else if (!filename.EndsWith(".ppt") && !filename.EndsWith(".pptx"))
        {
            SetStatusText(wxT("Imported file must be .ppt/.pptx"), 0);
            return;
        }
        vpresentation = ppt.CallMethod("Presentations.Open", filename);
        presentation.SetDispatchPtr((IDispatch*)vpresentation.GetVoidPtr());
        ppt.PutProperty("Visible", true);
        if (presentation.GetProperty("Slides.Count").GetLong() == 0)
        {
            SetStatusText(wxT("Presentation has no slide"), 0);
            return;
        }

        wxArrayInt selections;
        VideoListBox-> GetSelections(selections);
        int num_items = selections.GetCount();
        wxString videoName = "";
        if(num_items == 0)
        {
            SetStatusText(wxT("No video selected"), 0);
        }
        else
        {
            videoName = configmap["Default videos directory"] + "\\" + VideoListBox->GetString(selections.Item(0));
            if(configmap["Default videos directory"].find("\\") == (size_t)-1)
            {
                videoName = dirName + "\\" + videoName;
            }
        }
        width = presentation.GetProperty("PageSetup.SlideWidth").GetLong();
        height = presentation.GetProperty("PageSetup.SlideHeight").GetLong();
        bool loaded = false;
        if (creation_mode.compare(Words) == 0 || creation_mode.compare(Mix) == 0)
        {
            wxFile wxofsFile;
            wxString modulename = configmap["Default templates directory"] + "\\WordsModule.bas";
            if(configmap["Default templates directory"].find("\\") == (size_t)-1)
            {
                modulename = dirName + "\\" + modulename;
            }
            if (!wxofsFile.Exists(modulename))
            {
                SetStatusText(wxT("Cannot find WordsModule.bas"), 0);
            }
            else
            {
                try
                {
                    vcomponent = ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Import", modulename);
                    loaded = true;
                }
                catch(...)
                {
                    SetStatusText("File>Options>Trust Center>Trust Center Settings>Trust access to the VBA project object model", 0);
                }
            }
        }

        presentation.GetObject(designs, "Designs");
        vdesign = designs.CallMethod("Item", 1);
        design.SetDispatchPtr((IDispatch*)vdesign.GetVoidPtr());
        vcustomlayout = design.CallMethod("SlideMaster.CustomLayouts.Add", 1);
        customlayout.SetDispatchPtr((IDispatch*)vcustomlayout.GetVoidPtr());
        customlayout.GetObject(shapes, "Shapes");
        cnt = shapes.GetProperty("Count").GetLong();
        for (int i = 1; i <= cnt; i++)
        //Delete all shapes in SlideMaster
        {
            vshp = shapes.CallMethod("Item", 1);
            shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
            shp.CallMethod("Delete");
        }
        cr = (long)wxColour(0, 0, 0).GetRGB();//Look into
        presentation.PutProperty("SlideMaster.Background.Fill.ForeColor.RGB", cr);

        wxVector<int>start_indices, videoSlidesNum;
        wxString title_reference = "abcdefghijk";
        presentation.GetObject(slides, "Slides");
        cnt = slides.GetProperty("Count").GetLong();
        groupNames.clear();

        bool has_picture;
        for (int i = 1; i <= cnt; i++)
        {
            vslide = slides.CallMethod("Item", i);
            slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
            slide.GetObject(shapes,"Shapes");
            slide.CallMethod("Select");
            if (creation_mode.compare(Words) == 0)
            {
                has_picture = false;
                int c = shapes.GetProperty("Count").GetLong();
                for (int ii = 1; ii <= c; ii++)
                {
                    vshp = shapes.CallMethod("Item", ii);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.GetObject(textframe, "TextFrame");
                    if (!textframe.GetProperty("HasText").GetBool())
                    {
                        has_picture = true;
                        break;
                    }
                }
                if (!has_picture)
                {
                    vshp = shapes.CallMethod("AddShape", 1, 0, 0, width, height);//msoShapeRectangle
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    cr = (long)wxColour(0,0,0).GetRGB();
                    shp.PutProperty("Fill.ForeColor.RGB", cr);
                    shp.PutProperty("Line.Visible", false);
                    shp.CallMethod("ZOrder", 1);//msoSendToBack
                }
                if (loaded)
                {
                    ppt.CallMethod("Run", "DoMergeShapes", i);
                }
                wxFile wxofsFile;
                if (!wxofsFile.Exists(videoName))
                {
                    SetStatusText(wxT("Cannot find video"), 0);
                }
                else
                {
                    vshp = slide.CallMethod("Shapes.AddMediaObject2", videoName);
                    slide.GetObject(sequence, "TimeLine.MainSequence");
                    sequence.CallMethod("AddEffect", vshp, 83, 0, 2, 1);
                    //msoAnimEffectMediaPlay, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    vshp = slide.CallMethod("Shapes.Item", slide.GetProperty("Shapes.Count").GetLong());
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.PutProperty("Height", height);
                    //height is always shorter than width, aspect stretch
                    shp.PutProperty("AnimationSettings.PlaySettings.LoopUntilStopped", true);
                    shp.CallMethod("ZOrder", 1);//msoSendToBack
                }
            }
            else if (creation_mode.compare(Background) == 0)
            {
                int fontSize, maxSize = 0, minSize = 200;
                wxString shpName, text, text2 = "";
                count2 = shapes.GetProperty("Count").GetLong();
                for (int iii = 1; iii <= count2; iii++)
                {
                    vshp = shapes.CallMethod("Item",iii);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.GetObject(textframe, "TextFrame");
                    if (textframe.GetProperty("HasText").GetBool())
                    {
                        text = textframe.GetProperty("TextRange.Text").GetString();
                        if ((int)text.Lower().find("licen") == -1)
                        {
                            fontSize = textframe.GetProperty("TextRange.Font.Size").GetLong();
                            if (maxSize < fontSize)
                            {
                                shpName = shp.GetProperty("Name").GetString();
                                maxSize = fontSize;
                            }
                            if (minSize > fontSize)
                            {
                                text2 = text;
                                minSize = fontSize;
                            }
                        }
                    }
                }
                if (maxSize == 0)
                {
                    SetStatusText("Must have at least one textbox that does not contain 'licen'", 0);
                    return;
                }
                groupNames.push_back(shpName);

                text2 = text2.substr(0, min(min(text2.find("\n"), text2.find("\v")), text2.find("\r")));
                text2 = text2.substr(0, min(text2.find("-"), text2.find((char)(-106)))).Trim(true);
                if (minSize != maxSize && title_reference.compare(text2) != 0)
                //Assumes title has smallest font, title is used as the point for comparison
                {
                    title_reference = text2;
                    start_indices.push_back(i);
                    for (int iii = 1; iii <= count2; iii++)
                    {
                        vshp = shapes.CallMethod("Item",iii);
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        text = shp.GetProperty("Name").GetString();
                        if (shpName.compare(text) != 0 && shp.GetProperty("TextFrame.HasText").GetBool())
                        {
                            customNames.push_back(text);
                        }
                    }
                }
            }
            else if (creation_mode.compare(Mix) == 0)
            {
                int fontSize, ini_minSize = 200;
                int minSize = ini_minSize;
                wxString shpName, text, text2 = "";
                count2 = shapes.GetProperty("Count").GetLong();
                has_picture = false;
                for (int iii = 1; iii <= count2; iii++)
                {
                    vshp = shapes.CallMethod("Item",iii);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.GetObject(textframe, "TextFrame");
                    if (textframe.GetProperty("HasText").GetBool())
                    {
                        text = textframe.GetProperty("TextRange.Text").GetString();
                        if ((int)text.Lower().find("licen") == -1)
                        {
                            fontSize = textframe.GetProperty("TextRange.Font.Size").GetLong();
                            if (minSize > fontSize)
                            {
                                text2 = text;
                                minSize = fontSize;
                            }
                        }
                    }
                    else
                    {
                        has_picture = true;
                    }
                }
                if (minSize == ini_minSize)
                {
                    SetStatusText("Must have at least one textbox that does not contain 'licen'", 0);
                    return;
                }

                text2 = text2.substr(0, min(min(text2.find("\n"), text2.find("\v")), text2.find("\r")));
                text2 = text2.substr(0, min(text2.find("-"), text2.find((char)(-106)))).Trim(true);
                if (title_reference.compare(text2) != 0)
                //Assumes title has smallest font
                {
                    title_reference = text2;
                    start_indices.push_back(i);
                }
                if (!has_picture)
                {
                    vshp = shapes.CallMethod("AddShape", 1, 0, 0, width, height);//msoShapeRectangle
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    cr = (long)wxColour(0,0,0).GetRGB();
                    shp.PutProperty("Fill.ForeColor.RGB", cr);
                    shp.PutProperty("Line.Visible", false);
                    shp.CallMethod("ZOrder", 1);//msoSendToBack
                    cr = (long)wxColour(255,255,255).GetRGB();
                    slide.PutProperty("FollowMasterBackground", false);
                    slide.PutProperty("Background.Fill.ForeColor.RGB", cr);
                }
                if (loaded)
                {
                    ppt.CallMethod("Run", "DoMergeShapes", i);
                }
            }
            slide.PutProperty("HeadersFooters.SlideNumber.Visible", false);
        }
        if (creation_mode.compare(Background) == 0)
        {
            start_indices.push_back(slides.GetProperty("Count").GetLong() + 1);
            int offset = 0, curr = 0, cnt3, left, top;
            bool through;
            wxFile wxofsFile;
            for (unsigned int i = 0; i < start_indices.size() - 1; i++)
            {
                videoSlidesNum.push_back(start_indices[i] + offset);
                vslide = presentation.CallMethod("Slides.Add", start_indices[i] + offset, 32);
                vvideoslide = slides.CallMethod("Item", start_indices[i] + offset);
                videoslide.SetDispatchPtr((IDispatch*)vvideoslide.GetVoidPtr());
                for (int ii = start_indices[i] + offset + 1; ii <= start_indices[i + 1] + offset; ii++)
                {
                    vslide = slides.CallMethod("Item", ii);
                    slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                    through = false;
                    for (unsigned int iii = curr; iii < groupNames.size(); iii++)
                    {
                        cnt3 = slide.GetProperty("Shapes.Count").GetLong();
                        for (int iiii = 1; iiii <= cnt3; iiii++)
                        {
                            vshp = slide.CallMethod("Shapes.Item", iiii);
                            shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                            if (groupNames[iii].compare(shp.GetProperty("Name").GetString()) == 0)
                            {
                                curr = iii + 1;
                                through = true;
                                break;
                            }
                        }
                        if (through)
                        {
                            break;
                        }
                    }
                    shp.CallMethod("Copy");
                    Sleep(500);
                    left = shp.GetProperty("Left").GetLong();
                    top = shp.GetProperty("Top").GetLong();
                    vshp = videoslide.CallMethod("Shapes.Paste");
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.PutProperty("Left", left);
                    shp.PutProperty("Top", top);
                }
                videoslide.GetObject(shapes,"Shapes");
                count2 = shapes.GetProperty("Count").GetLong();
                videoslide.GetObject(sequence, "TimeLine.MainSequence");

                for (int ii = 1; ii <= count2; ii++)
                {
                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 2);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", false);

                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 1);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerOnPageClick
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", true);
                }
                if (!wxofsFile.Exists(videoName))
                {
                    SetStatusText(wxT("Cannot find video"), 0);
                }
                else
                {
                    vshp = videoslide.CallMethod("Shapes.AddMediaObject2", videoName);
                    sequence.CallMethod("AddEffect", vshp, 83, 0, 2, 1);
                    //msoAnimEffectMediaPlay, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    vshp = shapes.CallMethod("Item", count2 + 1);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.PutProperty("Height", height);
                    //height is always shorter than width, aspect stretch
                    shp.PutProperty("AnimationSettings.PlaySettings.LoopUntilStopped", true);
                    shp.CallMethod("ZOrder", 1);//msoSendToBack
                }

                vslide = slides.CallMethod("Item", start_indices[i] + offset + 1);
                slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                for (unsigned int iii = 0; iii < customNames.size(); iii++)
                {
                    cnt3 = slide.GetProperty("Shapes.Count").GetLong();
                    for (int iiii = 1; iiii <= cnt3; iiii++)
                    {
                        vshp = slide.CallMethod("Shapes.Item", iiii);
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        if (customNames[iii].compare(shp.GetProperty("Name").GetString()) == 0)
                        {
                            shp.CallMethod("Copy");
                            left = shp.GetProperty("Left").GetLong();
                            top = shp.GetProperty("Top").GetLong();
                            vshp = videoslide.CallMethod("Shapes.Paste");
                            shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                            shp.PutProperty("Left", left);
                            shp.PutProperty("Top", top);
                        }
                    }
                }
                offset++;
            }
        }
        else if (creation_mode.compare(Mix) == 0)
        {
            start_indices.push_back(slides.GetProperty("Count").GetLong() + 1);
            int offset = 0, left, top;
            wxFile wxofsFile;
            for (unsigned int i = 0; i < start_indices.size() - 1; i++)
            {
                videoSlidesNum.push_back(start_indices[i] + offset);
                vslide = presentation.CallMethod("Slides.Add", start_indices[i] + offset, 32);
                vvideoslide = slides.CallMethod("Item", start_indices[i] + offset);
                videoslide.SetDispatchPtr((IDispatch*)vvideoslide.GetVoidPtr());
                for (int ii = start_indices[i] + offset + 1; ii <= start_indices[i + 1] + offset; ii++)
                {
                    vslide = slides.CallMethod("Item", ii);
                    slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                    if (slide.GetProperty("Shapes.Count").GetLong() > 0)
                    {
                        vrange = slide.CallMethod("Shapes.Range");
                        range.SetDispatchPtr((IDispatch*)vrange.GetVoidPtr());
                        range.CallMethod("Copy");
                        Sleep(500);
                        left = range.GetProperty("Left").GetLong();
                        top = range.GetProperty("Top").GetLong();
                        vshp = videoslide.CallMethod("Shapes.Paste");
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        shp.PutProperty("Left", left);
                        shp.PutProperty("Top", top);
                    }
                }
                videoslide.GetObject(shapes,"Shapes");
                count2 = shapes.GetProperty("Count").GetLong();
                videoslide.GetObject(sequence, "TimeLine.MainSequence");
                for (int ii = 1; ii <= count2; ii++)
                {
                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 2);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", false);

                    vshp = shapes.CallMethod("Item", ii);
                    veffect = sequence.CallMethod("AddEffect", vshp, 1, 0, 1);
                    //msoAnimEffectAppear, msoAnimateLevelNone, msoAnimTriggerOnPageClick
                    effect.SetDispatchPtr((IDispatch*)veffect.GetVoidPtr());
                    effect.PutProperty("Exit", true);
                }
                if (!wxofsFile.Exists(videoName))
                {
                    SetStatusText(wxT("Cannot find video"), 0);
                }
                else
                {
                    vshp = videoslide.CallMethod("Shapes.AddMediaObject2", videoName);
                    sequence.CallMethod("AddEffect", vshp, 83, 0, 2, 1);
                    //msoAnimEffectMediaPlay, msoAnimateLevelNone, msoAnimTriggerWithPrevious
                    vshp = shapes.CallMethod("Item", count2 + 1);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.PutProperty("Height", height);
                    //height is always shorter than width, aspect stretch
                    shp.PutProperty("AnimationSettings.PlaySettings.LoopUntilStopped", true);
                    shp.CallMethod("ZOrder", 1);//msoSendToBack
                }
                offset++;
            }
        }
        if (option.compare("Trim slides") == 0)
        {
            int slidesNum = presentation.GetProperty("Slides.Count").GetLong();
            for (int i = (int)videoSlidesNum.size() - 1; i >= 0; i--)
            {
                for (int ii = slidesNum; ii > videoSlidesNum[i]; ii--)
                {
                    vslide = presentation.CallMethod("Slides.Item", ii);
                    slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                    slide.CallMethod("Delete");
                }
                slidesNum = videoSlidesNum[i] - 1;
            }
        }
        if (option.compare("Include macro") == 0 && \
           (creation_mode.compare(Background) == 0 || creation_mode.compare(Mix) == 0))
        {
            //Loading takes time & thus cause subsequent modifications to be prone to errors
            wxFile wxofsFile;
            wxString modulename = configmap["Default templates directory"] + "\\BackgroundModule.bas";
            wxString classname = configmap["Default templates directory"] + "\\BackgroundClass.cls";
            if(configmap["Default templates directory"].find("\\") == (size_t)-1)
            {
                modulename = dirName + "\\" + modulename;
                classname = dirName + "\\" + classname;
            }
            if (!wxofsFile.Exists(modulename))
            {
                SetStatusText(wxT("Cannot find BackgroundModule.bas"), 0);
            }
            else if (!wxofsFile.Exists(classname))
            {
                SetStatusText(wxT("Cannot find BackgroundClass.cls"), 0);
            }
            else
            {
                try
                {
                    ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Import", modulename);
                    ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Import", classname);
                    ppt.CallMethod("Run", "InitializeApp");
                }
                catch(...)
                {
                    SetStatusText("File>Options>Trust Center>Trust Center Settings>Trust access to the VBA project object model", 0);
                }
            }
        }

        if (loaded)
        {
            ppt.CallMethod("VBE.ActiveVBProject.VBComponents.Remove", vcomponent);
            //vcomponent references to MergeShapes routine
        }
        SetStatusText("Slides modified", 0);
    }
    catch(exception& e)
    {
        wxMessageBox(e.what());
        SetStatusText("Error modifying slides", 0);
    }
}

void SlidesFrame::OnSaveBtnClick(wxCommandEvent& event)
{
    wxFile wxofsFile;
    wxofsFile.Create(songfile_selected, true);
    wxofsFile.Write(FileRichTextCtrl->GetValue(), wxConvUTF8);
    wxofsFile.Close();
    wxStringTokenizer tkz(songfile_selected, wxT("\\"));
    wxString token;
    while (tkz.HasMoreTokens())
    {
        token = tkz.GetNextToken();
    }
    SetStatusText("Saved '" + token + "'", 0);
}

void SlidesFrame::OnDeleteBtnClick(wxCommandEvent& event)
{
    wxFile wxofsFile;
    bool success = wxRemoveFile(songfile_selected);
    wxString filename = songfile_selected.substr(songfile_selected.rfind("\\") + 1);
    if (success)
    {
        SetStatusText("Deleted '" + filename + "'", 0);
        int index = FileListBox->GetSelection();
        if (index != wxNOT_FOUND && FileListBox->IsChecked(index))
        {
            list<wxString>::iterator it;
            for (it = favourites.begin(); it != favourites.end(); it++)
            {
                if ((*it).compare(filename) == 0)
                {
                    favourites.erase(it);
                    break;
                }
            }
        }
        FileListBox->Delete(index);
    }
    else
    {
        SetStatusText("Unable to delete '" + filename + "'", 0);
    }
}

void SlidesFrame::OnSearchChkBoxClick(wxCommandEvent& event)
{
    if (SearchChkBox->GetValue())
    {
	   SlidesFrame::FilterSearch(event);
    }
}

void SlidesFrame::FilterSearch(wxCommandEvent& event)
{
    SetStatusText("Searching through files...");
    SlidesFrame::ShowSlides(configmap["Default songs directory"], false);
	int num_items = FileListBox->GetCount();
	for (int i = 0; i < num_items; i++)
	{
        FileListBox->Delete(0);
    }
    wxRegEx rgx(SearchTextCtrl->GetLineText(0).Lower(), wxRE_BASIC);
    wxArrayString results;
    wxString fileName, line;
    int filesize = fileList.size();
    for (int i = 0; i < filesize; i++)
	{
        if (SearchChkBox->GetValue())
        {
            fileName = fileList[i];
            if (rgx.Matches(fileName.Lower()))
            {
                results.Add(fileName,1);
                continue;
            }
            wxFileInputStream input(configmap["Default songs directory"] + "\\" + fileName);
            wxTextInputStream text(input, wxT("\x09"), wxConvUTF8);
            while(!input.Eof())
            {
                line = text.ReadLine().Lower();
                if (rgx.Matches(line))
                {
                    results.Add(fileName,1);
                    break;
                }
            }
        }
        else
        {
            fileName =  fileList[i];
            if (rgx.Matches(fileName.Lower()))
            {
                results.Add(fileName,1);
            }
        }
    }
    if (!results.IsEmpty())
    {
        FileListBox->InsertItems(results, 0);
        wxString filename;
        unsigned int index = 0;
        list<wxString>::iterator it;
        filename = FileListBox->GetString(index);
        for (it = favourites.begin(); it != favourites.end(); it++)
        {
            while (filename.compare(*it) < 0) {
                index++;
                if(index == results.size())
                {
                    return;
                }
                filename = FileListBox->GetString(index);
            }
            if (filename.compare(*it) == 0)
            {
                FileListBox->Check(index);
            }
        }
    }
    SetStatusText("Search done");
}

void SlidesFrame::FilterSearch_NonVerbose()
{
    SlidesFrame::ShowSlides(configmap["Default songs directory"], false);
	int num_items = FileListBox->GetCount();
	for (int i = 0; i < num_items; i++)
	{
        FileListBox->Delete(0);
    }
    wxRegEx rgx(SearchTextCtrl->GetLineText(0).Lower(), wxRE_BASIC);
    wxArrayString results;
    wxString fileName, line;
    int filesize = fileList.size();
    for (int i = 0; i < filesize; i++)
	{
        if (SearchChkBox->GetValue())
        {
            fileName = fileList[i];
            if (rgx.Matches(fileName.Lower()))
            {
                results.Add(fileName,1);
                continue;
            }
            wxFileInputStream input(configmap["Default songs directory"] + "\\" + fileName);
            wxTextInputStream text(input, wxT("\x09"), wxConvUTF8);
            while(!input.Eof())
            {
                line = text.ReadLine().Lower();
                if (rgx.Matches(line))
                {
                    results.Add(fileName,1);
                    break;
                }
            }
        }
        else
        {
            fileName =  fileList[i];
            if (rgx.Matches(fileName.Lower()))
            {
                results.Add(fileName,1);
            }
        }
    }
    if (!results.IsEmpty())
    {
        FileListBox->InsertItems(results, 0);
        wxString filename;
        unsigned int index = 0;
        list<wxString>::iterator it;
        filename = FileListBox->GetString(index);
        for (it = favourites.begin(); it != favourites.end(); it++)
        {
            while (filename.compare(*it) < 0) {
                index++;
                if(index == results.size())
                {
                    return;
                }
                filename = FileListBox->GetString(index);
            }
            if (filename.compare(*it) == 0)
            {
                FileListBox->Check(index);
            }
        }
    }
}

void SlidesFrame::OnBrowseBtnClick(wxCommandEvent& event)
{
    if (OptionsRadioBox->GetString(OptionsRadioBox->GetSelection()).compare("Songs folder") == 0)
    {
        dirDialog = new wxDirDialog(this);
        if (dirDialog->ShowModal() == wxID_OK)
        {
            wxString selectedFolder = dirDialog->GetPath();
            SetStatusText(selectedFolder, 0);
            configmap["Default songs directory"] = selectedFolder;
            SlidesFrame::ShowSlides(selectedFolder);
        }
    }
    else if (OptionsRadioBox->GetString(OptionsRadioBox->GetSelection()).compare("Templates folder") == 0)
    {
        //templates.clear();
        dirDialog = new wxDirDialog(this);
        if (dirDialog->ShowModal() == wxID_OK)
        {
            wxString selectedFolder = dirDialog->GetPath();
            SetStatusText(selectedFolder, 0);
            configmap["Default templates directory"] = selectedFolder;
            SlidesFrame::ShowTemplates(selectedFolder);
        }
    }
    else if (OptionsRadioBox->GetString(OptionsRadioBox->GetSelection()).compare("Videos folder") == 0)
    {
        dirDialog = new wxDirDialog(this);
        if (dirDialog->ShowModal() == wxID_OK)
        {
            wxString selectedFolder = dirDialog->GetPath();
            SetStatusText(selectedFolder, 0);
            configmap["Default videos directory"] = selectedFolder;
            SlidesFrame::ShowVideos(selectedFolder);
        }
    }
}

void SlidesFrame::WriteSlides2()
{
    /*
    0
    Title
    Author/s (May be blank)
    CCLI no (Blank line)

    1
    CCLI (If blank it will be inputted as "")

    2
    Lyrics
    */
    SetStatusText("Writing songs to files", 0);
    bool first = true, space_before;
    wxString oriTitle, title;
    for(unsigned int i = 0; i < songsDetails2.size(); i++)
    {
        wxStringTokenizer tkz(songsDetails2[i][0], wxT("\n"));
        oriTitle = tkz.GetNextToken();
        title = "";
        space_before = true;
        for(wchar_t c: oriTitle){
            if(space_before){
                if(c >= 97 && c <= 122){
                    title += (wchar_t)(c - 32);
                }else{
                    title += c;
                }
                space_before = false;
            }else{
                if(c >= 65 && c <= 90){
                    title += (wchar_t)(c + 32);
                }else{
                    title += c;
                }
                if(c == 32){
                    space_before = true;
                }
            }
        }
        songsDetails2[i][0].Replace(oriTitle, title);
        if (songsDetails2[i].size() == 2)
        {
            wxString filename = configmap["Default songs directory"] + "\\" + "missing.txt";
            wxFile wxofsFile(filename, wxFile::write_append);
            wxString content;
            if (first)
            {
                content = "\n--------\n" + title;
                first = false;
            }
            else
            {
                content = "\n" + title;
            }
            wxofsFile.Write(content, content.Len());
            wxofsFile.Close();
        }
        else
        {
            title.Replace((char)(-110), "'");
            wxString firstAuthor = tkz.GetNextToken();
            firstAuthor = firstAuthor.substr(0, min(firstAuthor.find("/"),firstAuthor.find(",")));

            wxString filename = configmap["Default songs directory"] + "\\" + title \
                                + " (" + firstAuthor + ").txt";
            wxFile wxofsFile;
            if (!OverwriteChkBox->GetValue() && wxofsFile.Exists(filename))
            {
                continue;
            }
            wxofsFile.Create(filename, true);
            wxString content, lyrics, line;
            content = songsDetails2[i][0];
            content << "\n\n\n" << songsDetails2[i][1];
            for(unsigned int ii = 2; ii < songsDetails2[i].size(); ii++){
                content << "\n\n" << songsDetails2[i][ii];
            }
            wxofsFile.Write(content, wxConvUTF8);
            wxofsFile.Close();
        }
    }
    SetStatusText("Song files created", 0);
}

bool SlidesFrame::is_number(wxString& s)
{
    wxString::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)){
        ++it;
    }
    return !s.empty() && it == s.end();
}

void SlidesFrame::OnImportBtnClick(wxCommandEvent& event)
{
    wxAutomationObject ppt, presentation, slides, slide, shapes, shp, textframe;
	wxVariant vpresentation, vshp, vslide;
	wxVector<wxString> customNames;
    int cnt, count2;

    try
    {
        SetStatusText("Setting up", 0);
        ppt.CreateInstance("PowerPoint.Application");
        if (!ppt.IsOk())
        {
            SetStatusText("Failed to obtain PowerPoint.Application instance.", 0);
            return;
        }

        wxString dirname;
        if (dirDialog->ShowModal() == wxID_OK)
        {
            dirname = dirDialog->GetPath();
        }
        else
        {
            SetStatusText("No folder selected", 0);
            return;
        }
        wxDir dir(dirname);
        if (!dir.IsOpened())
        //Check whether folder exists
        {
            return;
        }

        wxArrayString* filenames =  new wxArrayString();
        wxString filename;
        wxString filespec = _T("*.ppt*");
        wxDir::GetAllFiles(dirname, filenames, filespec);

        songsDetails2.clear();
        for (unsigned int v = 0; v < filenames->GetCount(); v++){
            filename = filenames->Item(v);
            vpresentation = ppt.CallMethod("Presentations.Open", filename);
            presentation.SetDispatchPtr((IDispatch*)vpresentation.GetVoidPtr());
            ppt.PutProperty("Visible", true);
            if (presentation.GetProperty("Slides.Count").GetLong() == 0)
            {
                SetStatusText(wxT("Presentation has no slide"), 0);
                continue;
            }

            wxVector<wxString> songDetails;
            wxString title_reference = "abcdefghijk"; //random
            presentation.GetObject(slides, "Slides");
            cnt = slides.GetProperty("Count").GetLong();
            for (int i = 1; i <= cnt; i++)
            {
                vslide = slides.CallMethod("Item", i);
                slide.SetDispatchPtr((IDispatch*)vslide.GetVoidPtr());
                slide.GetObject(shapes,"Shapes");
                slide.CallMethod("Select");
                int fontSize, maxSize = 0, minSize = 200;
                wxString shpName, shpName2 = "", text, text2 = "";
                count2 = shapes.GetProperty("Count").GetLong();
                for (int iii = 1; iii <= count2; iii++)
                {
                    vshp = shapes.CallMethod("Item",iii);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    shp.GetObject(textframe, "TextFrame");
                    if (textframe.GetProperty("HasText").GetBool())
                    {
                        text = textframe.GetProperty("TextRange.Text").GetString();
                        if ((int)text.Lower().find("licen") == -1)
                        {
                            if(SlidesFrame::is_number(text)){
                                continue;
                            }
                            fontSize = textframe.GetProperty("TextRange.Font.Size").GetLong();
                            if (maxSize < fontSize)
                            {
                                shpName = shp.GetProperty("Name").GetString();
                                maxSize = fontSize;
                            }
                            if (minSize > fontSize)
                            {
                                text2 = text;
                                minSize = fontSize;
                            }
                        }else{
                            shpName2 = shp.GetProperty("Name").GetString();
                        }
                    }
                }
                if (maxSize == 0)
                {
                    SetStatusText("Must have at least one textbox that does not contain 'licen':" + filename, 0);
                    continue;
                }

                text2 = text2.Trim(true).Trim(false);
                text2 = text2.substr(0, min(min(text2.find("\n"), text2.find("\v")), text2.find("\r")));
                text2 = text2.substr(0, min(text2.find("-"), text2.find((char)(-106)))).Trim(true);
                if (minSize != maxSize && title_reference.compare(text2) != 0)
                //Assumes title has smallest font, title is used as the point for comparison
                {
                    if(songDetails.size() > 0){
                        songsDetails2.push_back(songDetails);
                    }
                    songDetails.clear();
                    title_reference = text2;
                    for (int iii = 1; iii <= count2; iii++)
                    {
                        vshp = shapes.CallMethod("Item",iii);
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        text = shp.GetProperty("Name").GetString();
                        if (shpName.compare(text) != 0 && shpName2.compare(text) != 0 && shp.GetProperty("TextFrame.HasText").GetBool())
                        {
                            shp.GetObject(textframe, "TextFrame");
                            text = textframe.GetProperty("TextRange.Text").GetString();
                            if(!SlidesFrame::is_number(text)){
                                text.Replace("\v", "\n");
                                text.Replace("\r", "\n");
                                text = text.Trim(true).Trim(false);
                                if (text.find("\n") != string::npos){
                                    songDetails.push_back(text.substr(0, min(text.find("\n"), min(text.find("-"), text.find((char)(-106))))).Trim()
                                                          + text.substr(text.find("\n")).Trim());
                                }else{
                                    songDetails.push_back(text.substr(0, min(text.find("\n"), min(text.find("-"), text.find((char)(-106))))).Trim() + "\n");
                                }
                                break;
                            }
                        }
                    }
                    bool through = false;
                    for (int iii = 1; iii <= count2; iii++)
                    {
                        vshp = shapes.CallMethod("Item",iii);
                        shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                        text = shp.GetProperty("Name").GetString();
                        if (shpName2.compare(text) == 0)
                        {
                            shp.GetObject(textframe, "TextFrame");
                            text = textframe.GetProperty("TextRange.Text").GetString();
                            text.Replace("\v", "\n");
                            text.Replace("\r", "\n");
                            unsigned int pos = text.Lower().find("used by permission");
                            if(pos != string::npos){
                                if(pos > 0){
                                    text = text.substr(0, pos - 1);
                                }else{
                                    text = text.substr(0, pos);
                                }
                            }
                            songDetails.push_back(text);
                            through = true;
                            break;
                        }
                    }
                    if(!through){
                        songDetails.push_back("");
                    }
                }
                for (int iii = 1; iii <= count2; iii++)
                {
                    vshp = shapes.CallMethod("Item",iii);
                    shp.SetDispatchPtr((IDispatch*)vshp.GetVoidPtr());
                    text = shp.GetProperty("Name").GetString();
                    if (shpName.compare(text) == 0)
                    {
                        shp.GetObject(textframe, "TextFrame");
                        text = textframe.GetProperty("TextRange.Text").GetString();
                        text.Replace("\v", "\n");
                        text.Replace("\r", "\n");
                        songDetails.push_back(text.Trim());
                        break;
                    }
                }
            }
            if(songDetails.size() > 0){
                songsDetails2.push_back(songDetails);
            }
            presentation.CallMethod("Close");
        }
        SlidesFrame::WriteSlides2();
        delete filenames;
    }
    catch(exception& e)
    {
        wxMessageBox(e.what());
    }
    SlidesFrame::FilterSearch_NonVerbose();
}

void SlidesFrame::OnFileListBoxSelect(wxCommandEvent& event)
{
    wxArrayInt selections;
	FileListBox->GetSelections(selections);
    songfile_selected = configmap["Default songs directory"];
    songfile_selected += "\\";
    songfile_selected += FileListBox->GetString(selections.Item(0));
    wxFile wxofsFile;
    if (!wxofsFile.Exists(songfile_selected))
    {
        SetStatusText(wxT("Cannot find song file"), 0);
        int scrollPosition = FileListBox->GetScrollPos(wxVERTICAL);
        SlidesFrame::FilterSearch_NonVerbose();
        FileListBox->ScrollLines(scrollPosition);
        return;
    }
    wxFileInputStream input(songfile_selected);
    FileRichTextCtrl->Clear();
    wxTextInputStream text(input, wxT("\x09"), wxConvUTF8);
    FileRichTextCtrl->AppendText(text.ReadLine());
    while (!input.Eof())
    {
        FileRichTextCtrl->AppendText("\n" + text.ReadLine());
    }
}

void SlidesFrame::OnFileListBoxRClick(wxMouseEvent& event)
{
    int item_no = FileListBox->HitTest(event.GetPosition());
    if (item_no != wxNOT_FOUND)
    {
        if(FileListBox->IsChecked(item_no))
        {
            FileListBox->Check(item_no, false);
            list<wxString>::iterator it;
            wxString content = FileListBox->GetString(item_no);

            for (it = favourites.begin(); it != favourites.end(); it++)
            {
                if ((*it).compare(content) == 0)
                {
                    favourites.erase(it);
                    break;
                }
            }
        }
        else
        {
            FileListBox->Check(item_no);
            favourites.push_back(FileListBox->GetString(item_no));
        }
    }
    event.Skip();
}

void SlidesFrame::OnFileListBoxToggled(wxCommandEvent& event)
{
    int item_no = event.GetSelection();
    if (item_no != wxNOT_FOUND)
    {
        if(!FileListBox->IsChecked(item_no))
        {
            list<wxString>::iterator it;
            wxString content = FileListBox->GetString(item_no);

            for (it = favourites.begin(); it != favourites.end(); it++)
            {
                if ((*it).compare(content) == 0)
                {
                    favourites.erase(it);
                    break;
                }
            }
        }
        else
        {
            favourites.push_back(FileListBox->GetString(item_no));
        }
    }
}

void SlidesFrame::OnFileListBoxDClick(wxCommandEvent& event)
{
    wxArrayInt selections;
	FileListBox->GetSelections(selections);
	int num_items = selections.GetCount();
	int cnt = SongsListCtrl->GetItemCount();
	wxString item, songTitle, fileName, line;
	for (int i = 0; i < num_items; i++)
    {
        item = FileListBox->GetString(selections.Item(i));
        if (item.rfind('(') != string::npos)
        {
            songTitle = item.substr(0, item.rfind('(') - 1);
        }
        else if (item.compare("missing.txt") == 0)
        {
            SetStatusText("'missing.txt' is not a song", 0);
            return;
        }
        else
        {
            songTitle = item;
        }
        SongsListCtrl->InsertItem(cnt + i, songTitle);
        fileName = configmap["Default songs directory"] + "\\" + item;
        wxFileInputStream input(fileName);
        wxTextInputStream text(input, wxT("\x09"), wxConvUTF8);
        for (int i = 0; i < 3; i++)
        //Song file should contain at least 3 lines (Title, author/s & CCLI no. in this order)
        {
            if (!input.Eof())
            {
                line = text.ReadLine();
            }
            else
            {
                SongsListCtrl->DeleteItem(cnt + i);
                SetStatusText("Failed to add song", 0);
                return;
            }
            if (line.find("----") == 0)
            //Second condition to prevent missing.txt to be added
            {
                SongsListCtrl->DeleteItem(cnt + i);
                SetStatusText("Failed to add song", 0);
                return;
            }
        }
        SongsListCtrl->SetItem(cnt, 2, line);
        //The 3rd line is the CCLI no.
        SongsListCtrl->SetItem(cnt, 3, fileName);
    }
}

void SlidesFrame::OnVideoListBoxDClick(wxCommandEvent& event)
{
    wxArrayInt selections;
	VideoListBox-> GetSelections(selections);
	int num_items = selections.GetCount();
	wxString item;
	int curr = 0;
	int cnt = SongsListCtrl->GetItemCount();
	wxString videoDir = configmap["Default videos directory"];
    if(videoDir.find("\\") == (size_t)-1)
    {
        videoDir = dirName + "\\" + videoDir;
    }
	for (int i = 0; i < num_items; i++)
    {
        item = VideoListBox->GetString(selections.Item(i));
        while (curr < cnt)
        {
            if (SongsListCtrl->GetItemText(curr, 1).compare("") == 0)
            {
                SongsListCtrl->SetItem(curr, 1, item);
                SongsListCtrl->SetItem(curr, 4, videoDir + "\\" + item);
                curr++;
                break;
            }
            else
            {
                curr++;
            }
        }
    }
}

void SlidesFrame::OnPlayBtnClick(wxCommandEvent& event)
{
    wxArrayInt selections;
	VideoListBox->GetSelections(selections);
	if (selections.size() == 0)
    {
        SetStatusText("No video is selected", 0);
        return;
    }
    wxString item = configmap["Default videos directory"] + "\\" + VideoListBox->GetString(selections.Item(0));
    ID_CROPFRAME = NewControlId();
    VideoCropFrame* cropFrame = new VideoCropFrame(this, ID_CROPFRAME);
    cropFrame->Show();
    cropFrame->LoadVideo(item);
}

void SlidesFrame::OnTemplateListBoxDClick(wxCommandEvent& event)
{
    wxArrayInt selections;
    wxString selected_file;
	TemplateListBox->GetSelections(selections);
	int num_items = selections.GetCount();
	if (num_items > 0)
    {
        TemplateTextCtrl->Clear();
        selected_file = TemplateListBox->GetString(selections.Item(0));
        TemplateTextCtrl->AppendText(selected_file);
        configmap["Template"] = selected_file;
    }
}

void SlidesFrame::OnSongsListCtrlBeginDrag(wxListEvent& event)
{
    wxString text = wxString::Format("%d", event.GetIndex());
    wxTextDataObject tdo(text);
    wxDropSource tds(SongsListCtrl);
    tds.SetData(tdo);
    tds.DoDragDrop(wxDrag_CopyOnly);
}

void SlidesFrame::OnPlatformListCtrlBeginDrag(wxListEvent& event)
{
    wxString text = wxString::Format("%d", event.GetIndex());
    wxTextDataObject tdo(text);
    wxDropSource tds(PlatformListCtrl);
    tds.SetData(tdo);
    tds.DoDragDrop(wxDrag_CopyOnly);
}


ListCtrlDropTarget::ListCtrlDropTarget(wxListCtrl *owner)
{
    m_owner = owner;
    SetDataObject(new wxTextDataObject);
}

bool ListCtrlDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& data)
{
    wxPoint point;
    int end_index = 0, dist, min_dist = 100000;
    int cnt = m_owner->GetItemCount();
    bool last = false;
    for (int i = 0; i < cnt; i++)
    {
        m_owner->GetItemPosition(i, point);
        dist = abs(y - point.y);
        if (dist < min_dist)
        {
            min_dist = dist;
            end_index = i;
            if (i == cnt - 1 && point.y < y)
            {
                last = true;
            }
        }
    }
    int start_index = atoi(data);
    if (start_index == end_index)
    {
        return true;
    }
    if (last)
    {
        end_index++;
    }
    m_owner->InsertItem(end_index, m_owner->GetItemText(start_index, 0));
    if (start_index > end_index)
    {
        start_index++;
    }
    for (int i = 0; i < m_owner->GetColumnCount(); i++)
    {
        m_owner->SetItem(end_index, i, m_owner->GetItemText(start_index, i));
    }
    m_owner->DeleteItem(start_index);
    return true;
}

void SlidesFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SlidesFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SlidesFrame::OnDebug(wxCommandEvent& event)
{
    if (hideMode == 0)
    {
        WebPagePanel->Show();
        URLBtn->Show();
        DeleteBtn->Enable();
        hideMode = 1;
    }
    else
    {
        WebPagePanel->Hide();
        URLBtn->Hide();
        DeleteBtn->Disable();
        hideMode = 0;
    }
    this->Layout();
}

void SlidesFrame::OnURLBtnClick(wxCommandEvent& event)
{
    webstate = -1;
    webView->LoadURL(SearchTextCtrl2->GetLineText(0));
}

void SlidesFrame::OnWebPagePanelLeftDClick(wxMouseEvent& event)
{
    if (sizeMode == 0)
    {
        int new_y = 10;
        int new_width = this->GetSize().GetX() - ori_pos.x - 40;
        int new_height = ori_pos.y + ori_size.GetY() - new_y;
        WebPagePanel->SetPosition(wxPoint(ori_pos.x, new_y));
        WebPagePanel->SetSize(new_width, new_height);
        webView->SetSize(wxSize(new_width - 20, new_height));
        sizeMode = 1;
    }
    else
    {
        WebPagePanel->SetPosition(ori_pos);
        WebPagePanel->SetSize(ori_size);
        webView->SetSize(wxSize(ori_size.GetWidth() - 20, ori_size.GetHeight()));
        sizeMode = 0;
    }
}

void SlidesFrame::OnWebPagePanelRightDClick(wxMouseEvent& event)
{
    FileRichTextCtrl->Clear();
    FileRichTextCtrl->AppendText(webView->GetPageSource());
}
