/***************************************************************
 * Name:      SlidesMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mark ()
 * Created:   2020-02-01
 * Copyright: Mark ()
 * License:
 **************************************************************/

#include "SlidesMain.h"
#include "wx/msgdlg.h"
//(*InternalHeaders(SlidesFrame)
#include "wx/intl.h"
#include "wx/string.h"
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
const int SlidesFrame::ID_CREATEDATABASEBTN = wxNewId();
const int SlidesFrame::ID_SONGSLISTCTRL = wxNewId();
const int SlidesFrame::ID_REPORTSONGSBTN = wxNewId();
const int SlidesFrame::ID_CREATESLIDESBTN = wxNewId();
const int SlidesFrame::ID_VIDEORADIOBOX = wxNewId();
const int SlidesFrame::ID_FILERICHTEXTCTRL = wxNewId();
const int SlidesFrame::ID_FILELISTBOX = wxNewId();
const int SlidesFrame::ID_BROWSEBTN = wxNewId();
const int SlidesFrame::ID_RADIOBOX1 = wxNewId();
const int SlidesFrame::ID_SEARCHTEXTCTRL = wxNewId();
const int SlidesFrame::ID_SEARCHCHKBOX = wxNewId();
const int SlidesFrame::ID_SEARCHTEXTCTRL2 = wxNewId();
const int SlidesFrame::ID_OVERWRITECHKBOX = wxNewId();
const int SlidesFrame::ID_URLBTN = wxNewId();
const int SlidesFrame::ID_SAVEBTN = wxNewId();
const int SlidesFrame::ID_TEMPLATELISTBOX = wxNewId();
const int SlidesFrame::ID_TEMPLATETEXTCTRL = wxNewId();
const int SlidesFrame::ID_PLATFORMLISTCTRL = wxNewId();
const int SlidesFrame::ID_LICENSESPINCTRL = wxNewId();
const int SlidesFrame::ID_SEARCHSPINCTRL = wxNewId();
const int SlidesFrame::ID_CANCELBTN = wxNewId();
const int SlidesFrame::ID_LYRICSSPINCTRL = wxNewId();
const int SlidesFrame::ID_WEBPAGEPANEL = wxNewId();
const int SlidesFrame::ID_IMPORTBTN = wxNewId();
const int SlidesFrame::ID_DELETEBTN = wxNewId();
const int SlidesFrame::idMenuQuit = wxNewId();
const int SlidesFrame::idMenuAbout = wxNewId();
const int SlidesFrame::idMenuDebug = wxNewId();
const int SlidesFrame::ID_MAINSTATUSBAR = wxNewId();
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
    SetClientSize(wxSize(903,500));
    CreateDatabaseBtn = new wxButton(this, ID_CREATEDATABASEBTN, _("Find Songs"), wxPoint(0,224), wxSize(100,30), 0, wxDefaultValidator, _T("ID_CREATEDATABASEBTN"));
    CreateDatabaseBtn->SetToolTip(_("Extract lyrics from several sites\n(according to \'Search order\')"));
    SongsListCtrl = new wxListCtrl(this, ID_SONGSLISTCTRL, wxPoint(0,0), wxSize(228,224), wxLC_REPORT, wxDefaultValidator, _T("ID_SONGSLISTCTRL"));
    ReportSongsBtn = new wxButton(this, ID_REPORTSONGSBTN, _("Report Songs"), wxPoint(0,304), wxSize(100,30), 0, wxDefaultValidator, _T("ID_REPORTSONGSBTN"));
    ReportSongsBtn->SetToolTip(_("Report songs listed above through CCLI"));
    CreateSlidesBtn = new wxButton(this, ID_CREATESLIDESBTN, _("Create Slides"), wxPoint(0,336), wxSize(100,30), 0, wxDefaultValidator, _T("ID_CREATESLIDESBTN"));
    CreateSlidesBtn->SetToolTip(_("Construct slides consisting of songs listed above\n(with the template specified on the far right)"));
    wxString __wxRadioBoxChoices_1[1] =
    {
    	_("None"),
    };
    VideoRadioBox = new wxRadioBox(this, ID_VIDEORADIOBOX, _("Video"), wxPoint(104,328), wxSize(144,114), 1, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_VIDEORADIOBOX"));
    VideoRadioBox->SetSelection(0);
    FileRichTextCtrl = new wxRichTextCtrl(this, ID_FILERICHTEXTCTRL, wxEmptyString, wxPoint(234,40), wxSize(230,224), wxRE_MULTILINE, wxDefaultValidator, _T("ID_FILERICHTEXTCTRL"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    FileRichTextCtrl->SetToolTip(_("Displays song/ text file \n(selected in the box on its direct right)"));
    FileListBox = new wxCheckListBox(this, ID_FILELISTBOX, wxPoint(464,80), wxSize(216,184), 0, 0, 0, wxDefaultValidator, _T("ID_FILELISTBOX"));
    FileListBox->SetToolTip(_("Displays .txt files in \"Songs folder\""));
    BrowseBtn = new wxButton(this, ID_BROWSEBTN, _("Browse"), wxPoint(464,272), wxSize(100,30), 0, wxDefaultValidator, _T("ID_BROWSEBTN"));
    BrowseBtn->SetToolTip(_("Opens dialog to select the folder\n(specified in the \'Browse Options\' next to it)"));
    wxString __wxRadioBoxChoices_2[2] =
    {
    	_("Songs folder"),
    	_("Templates folder")
    };
    OptionsRadioBox = new wxRadioBox(this, ID_RADIOBOX1, _("Browse Options"), wxPoint(568,264), wxSize(140,96), 2, __wxRadioBoxChoices_2, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    SearchTextCtrl = new wxTextCtrl(this, ID_SEARCHTEXTCTRL, wxEmptyString, wxPoint(464,40), wxSize(216,21), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_SEARCHTEXTCTRL"));
    SearchChkBox = new wxCheckBox(this, ID_SEARCHCHKBOX, _("Search inside files"), wxPoint(464,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEARCHCHKBOX"));
    SearchChkBox->SetValue(false);
    SearchTextCtrl2 = new wxTextCtrl(this, ID_SEARCHTEXTCTRL2, wxEmptyString, wxPoint(0,256), wxSize(100,30), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_SEARCHTEXTCTRL2"));
    SearchTextCtrl2->SetToolTip(_("Type in query here\n(done through CCLI)"));
    OverwriteChkBox = new wxCheckBox(this, ID_OVERWRITECHKBOX, _("Overwrite files"), wxPoint(0,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_OVERWRITECHKBOX"));
    OverwriteChkBox->SetValue(false);
    URLBtn = new wxButton(this, ID_URLBTN, _("Go to URL"), wxPoint(464,332), wxSize(100,30), 0, wxDefaultValidator, _T("ID_URLBTN"));
    URLBtn->Hide();
    SaveBtn = new wxButton(this, ID_SAVEBTN, _("Save file"), wxPoint(256,272), wxSize(100,30), 0, wxDefaultValidator, _T("ID_SAVEBTN"));
    SaveBtn->SetToolTip(_("Saves song/ text file\n(when edits are made)"));
    TemplateListBox = new wxListBox(this, ID_TEMPLATELISTBOX, wxPoint(680,40), wxSize(168,192), 0, 0, 0, wxDefaultValidator, _T("ID_TEMPLATELISTBOX"));
    TemplateListBox->SetToolTip(_("Displays .ppt/.pptx files in \"Templates folder\""));
    TemplateTextCtrl = new wxTextCtrl(this, ID_TEMPLATETEXTCTRL, wxEmptyString, wxPoint(680,232), wxSize(168,30), 0, wxDefaultValidator, _T("ID_TEMPLATETEXTCTRL"));
    TemplateTextCtrl->Disable();
    TemplateTextCtrl->SetToolTip(_("Template selected for \'Create Slides\'"));
    PlatformListCtrl = new wxListCtrl(this, ID_PLATFORMLISTCTRL, wxPoint(148,224), wxSize(100,104), wxLC_REPORT|wxLC_NO_HEADER, wxDefaultValidator, _T("ID_PLATFORMLISTCTRL"));
    PlatformListCtrl->SetToolTip(_("Search order"));
    LicenseSpinCtrl = new wxSpinCtrl(this, ID_LICENSESPINCTRL, _T("3"), wxPoint(50,416), wxSize(50,21), 0, 1, 20, 3, _T("ID_LICENSESPINCTRL"));
    LicenseSpinCtrl->SetValue(_T("3"));
    LicenseSpinCtrl->SetToolTip(_("Maximum no. of lines for CCLI below slide\n(only applicable to \"Create Slides\", 1-20)"));
    SearchSpinCtrl = new wxSpinCtrl(this, ID_SEARCHSPINCTRL, _T("5"), wxPoint(101,235), wxSize(48,21), 0, 1, 25, 5, _T("ID_SEARCHSPINCTRL"));
    SearchSpinCtrl->SetValue(_T("5"));
    SearchSpinCtrl->SetToolTip(_("Number of songs to look for each query\n(1-25)"));
    CancelBtn = new wxButton(this, ID_CANCELBTN, _("Stop"), wxPoint(100,256), wxSize(48,30), 0, wxDefaultValidator, _T("ID_CANCELBTN"));
    CancelBtn->SetToolTip(_("Cancel \'Create database\' & \'Report Songs\'"));
    LyricsSpinCtrl = new wxSpinCtrl(this, ID_LYRICSSPINCTRL, _T("0"), wxPoint(0,416), wxSize(50,21), 0, 0, 20, 0, _T("ID_LYRICSSPINCTRL"));
    LyricsSpinCtrl->SetValue(_T("0"));
    LyricsSpinCtrl->SetToolTip(_("Maximum no. of lines for lyrics on each slide\n(0 implies no preference, 0-20)"));
    WebPagePanel = new wxPanel(this, ID_WEBPAGEPANEL, wxPoint(256,312), wxSize(200,128), wxTAB_TRAVERSAL, _T("ID_WEBPAGEPANEL"));
    WebPagePanel->Hide();
    ImportBtn = new wxButton(this, ID_IMPORTBTN, _("Import folder"), wxPoint(464,302), wxSize(100,30), 0, wxDefaultValidator, _T("ID_IMPORTBTN"));
    ImportBtn->SetToolTip(_("Choose a folder to convert all existing .ppt or .pptx\nto .txt"));
    DeleteBtn = new wxButton(this, ID_DELETEBTN, _("Delete file"), wxPoint(356,272), wxSize(100,30), 0, wxDefaultValidator, _T("ID_DELETEBTN"));
    DeleteBtn->Disable();
    DeleteBtn->SetToolTip(_("Delete file, can be enabled via Developer->Debug"));
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
    Connect(ID_FILELISTBOX,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&SlidesFrame::OnFileListBoxToggled);
    Connect(ID_FILELISTBOX,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&SlidesFrame::OnFileListBoxSelect);
    Connect(ID_FILELISTBOX,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&SlidesFrame::OnFileListBoxDClick);
    Connect(ID_BROWSEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnBrowseBtnClick);
    Connect(ID_SEARCHTEXTCTRL,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&SlidesFrame::FilterSearch);
    Connect(ID_SEARCHCHKBOX,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnSearchChkBoxClick);
    Connect(ID_SEARCHTEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&SlidesFrame::OnCreateDatabaseBtnClick);
    Connect(ID_URLBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnURLBtnClick);
    Connect(ID_SAVEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnSaveBtnClick);
    Connect(ID_TEMPLATELISTBOX,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&SlidesFrame::OnTemplateListBoxDClick);
    Connect(ID_PLATFORMLISTCTRL,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&SlidesFrame::OnPlatformListCtrlBeginDrag);
    Connect(ID_LICENSESPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SlidesFrame::OnLicenseSpinCtrlChange);
    Connect(ID_SEARCHSPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&SlidesFrame::OnSearchSpinCtrlChange);
    Connect(ID_CANCELBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnCancelBtnClick);
    WebPagePanel->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&SlidesFrame::OnWebPagePanelLeftDClick,0,this);
    WebPagePanel->Connect(wxEVT_RIGHT_DCLICK,(wxObjectEventFunction)&SlidesFrame::OnWebPagePanelRightDClick,0,this);
    Connect(ID_IMPORTBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnImportBtnClick);
    Connect(ID_DELETEBTN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SlidesFrame::OnDeleteBtnClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SlidesFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SlidesFrame::OnAbout);
    //*)
    Connect(idMenuDebug, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SlidesFrame::OnDebug);
    //ReportSongsBtn->Enable(false);
    FileListBox->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(SlidesFrame::OnFileListBoxRClick), NULL, this);
	ListCtrlDropTarget* dndSongsListCtrl = new ListCtrlDropTarget(SongsListCtrl);
    SongsListCtrl->SetDropTarget(dndSongsListCtrl);
    SongsListCtrl->InsertColumn(0, "Song Names", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(1, "", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(2, "CCLI", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(3, "Song Filename", wxLIST_FORMAT_LEFT);
    SongsListCtrl->InsertColumn(4, "", wxLIST_FORMAT_LEFT);
    SongsListCtrl->SetColumnWidth(0, 150);
    SongsListCtrl->SetColumnWidth(2, 0);
    SongsListCtrl->SetColumnWidth(3, 0);
    SongsListCtrl->SetColumnWidth(4, 0);
    ListCtrlDropTarget* dndPlatformListCtrl = new ListCtrlDropTarget(PlatformListCtrl);
    PlatformListCtrl->SetDropTarget(dndPlatformListCtrl);
    PlatformListCtrl->InsertColumn(0, "Search order", wxLIST_FORMAT_LEFT);

    webstate = -1;
    ori_pos = WebPagePanel->GetPosition();
    ori_size = WebPagePanel->GetSize();
    ID_WEBVIEW = NewControlId();
    webView = wxWebView::New(WebPagePanel, ID_WEBVIEW, "http://www.google.com", wxPoint(0, 0), wxSize(ori_size.GetWidth() - 20, ori_size.GetHeight()));
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
    wxDir dir(wxGetCwd());
    dirName = dir.GetName();

    wxString params[] = {"Default songs directory", "Template", "Default templates directory", "Search order", "Items per search", "Maximum lines for CCLI", "Username", "Password"};
    //Keys are specified here
    int num_params =  sizeof(params)/sizeof(wxString);
    for(int i = 0; i < num_params; i++)
    {
       configmap[params[i]] = "";
    }
    
    wxString filename;
    filename = dirName + "/Slides.app/Contents/Resources/config.txt";
    //config.txt should be in the same directory as the application
    wxFile wxofsFile;
    if (!wxofsFile.Exists(filename))
    {
        SetStatusText(wxT("Cannot find config.txt"), 0);
        SlidesFrame::InitSearchOrder();
        return;
    }
    wxFileInputStream input(filename);
    wxTextInputStream text(input, wxT("\x09"));
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
    
    //pre-signed in
    wxString URL = "https://profile.ccli.com/account/signin?appContext=OLR&returnUrl=https%3a%2f%2folr.ccli.com%3a443%2f";
    webstate = 3;
    webView -> LoadURL(URL);
    webView -> LoadURL(URL);
    if (hideMode == 1){
        WebPagePanel->Show();
        URLBtn->Show();
        DeleteBtn->Enable();
    }
    
    wxRichTextAttr attr = FileRichTextCtrl->GetBasicStyle();
    wxFont font = wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    attr.SetFont(font);
    FileRichTextCtrl->SetBasicStyle(attr);
}

void SlidesFrame::InitSearchOrder()
{
    vector<wxString> platforms = {Genius, AZLyrics, WorshipTogether, KLove, LyricsOnDemand, Lyrics, Musixmatch, UltimateGuitar};
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
    for (int i = 0; i < fileList.size(); i++)
    {
        FileListBox->Append(fileList[i]);
    }

    if (start) {
        wxFile wxofsFile;
        filename = configmap["Default templates directory"] + "/" + "favourites.txt";
        if (wxofsFile.Exists(filename))
        {
            wxFileInputStream input(filename);
            wxTextInputStream text(input, wxT("\x09"));
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
            while (filename.compare(*it) < 0)
            {
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

void SlidesFrame::ShowTemplates(wxString foldername)
{
    wxDir dir(foldername);
    if (!dir.IsOpened())
    //Check whether folder exists
    {
        wxMessageBox("does not exist");
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
    if (selectedFolder.compare("") == 0)
    {
        configmap["Default songs directory"] = dirName + "/Slides.app/Contents/Resources/Songs";
        selectedFolder = configmap["Default songs directory"];
    }
    SetStatusText(selectedFolder, 0);
    SlidesFrame::ShowSlides(selectedFolder);

    selectedFolder = configmap["Default templates directory"];
    if (selectedFolder.compare("") == 0)
    {
        configmap["Default templates directory"] = dirName + "/Slides.app/Contents/Resources/Templates";
        selectedFolder = configmap["Default templates directory"];
    }
    SetStatusText(selectedFolder, 0);
    SlidesFrame::ShowTemplates(selectedFolder);
}

void SlidesFrame::Save()
{
    wxString filename = dirName + "/Slides.app/Contents/Resources/config.txt";
    wxString search_order = "";
    int num_platforms = PlatformListCtrl->GetItemCount();
    for (int i = 0; i < num_platforms; i++)
    {
        search_order += PlatformListCtrl->GetItemText(i, 0) + ",";
    }
    configmap["Search order"] = search_order;
    if(configmap["Default songs directory"].EndsWith("/Slides.app/Contents/Resources/Songs"))
    {
        configmap["Default songs directory"] = "";
    }
    
    wxString templates_dir = configmap["Default templates directory"];
    if(configmap["Default templates directory"].EndsWith("/Slides.app/Contents/Resources/Templates"))
    {
        configmap["Default templates directory"] = "";
    }
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

    if(templates_dir.compare("") == 0)
    {
        return;
    }
    wxDir dir(templates_dir);
    if (!dir.IsOpened())
    //Check whether folder exists
    {
        return;
    }
    wxFile wxofsFile2(templates_dir + "/" + "favourites.txt", wxFile::write);
    list<wxString>::iterator it2;
    favourites.sort();
    for(it2 = favourites.begin(); it2 != favourites.end(); ++it2)
    {
        line = *it2 << "\n";
        wxofsFile2.Write(line, wxConvUTF8);
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
    wxVector<wxString> fileNames = wxVector<wxString>();
    for(unsigned int i = 0; i < songsDetails.size(); i++)
    {
        wxStringTokenizer tkz(songsDetails[i][0], wxT("\n"));
        title = tkz.GetNextToken();
        title.Replace("/", ",");
        if (songsDetails[i].size() == (unsigned int)lyrics_index)
        {
            wxString filename = configmap["Default songs directory"] + "/" + "missing.txt";
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
            wxString firstAuthor = tkz.GetNextToken();
            wxString ccli_no = tkz.GetString();
            if(ccli_no.compare("") == 0)
            {
                ccli_no = firstAuthor.substr(0, min(firstAuthor.find("/"), firstAuthor.find(",")));
            }
            wxString filename = configmap["Default songs directory"] + "/" + title \
                                + " (" + ccli_no + ").txt";
            fileNames.push_back(title + " (" + ccli_no + ").txt");
            wxFile wxofsFile;
            if (!OverwriteChkBox->GetValue() && wxofsFile.Exists(filename))
            {
                continue;
            }
            wxofsFile.Create(filename, true);
            wxString content, lyrics, line;
            bool twice = false;
            content = songsDetails[i][0];
            content << "\n\n" << songsDetails[i][1].Trim(false).Trim(true) << "\n";
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
            content << '\n' << lyrics.Trim(true).Trim(false);
            wxofsFile.Write(content);
            wxofsFile.Close();
        }
    }
    ReportSongsBtn->Enable(true);
    SetStatusText("Song files created", 0);
    SlidesFrame::SpecificSearch_NonVerbose(fileNames);
    //SlidesFrame::FilterSearch_NonVerbose();
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
        if (selected_platform.compare(KLove) == 0)
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
        else if (selected_platform.compare(WorshipTogether) == 0)
        {
            webView-> LoadURL("https://www.worshiptogether.com/search-results/");
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
                if (selected_platform.compare(KLove) == 0)
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
                else if (selected_platform.compare(WorshipTogether) == 0)
                {
                    webView-> LoadURL("https://www.worshiptogether.com/search-results/");
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
    
    if (lurl.find("https://profile.ccli.com/account/signin") == 0)
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
            output->Replace("\r", "\n");
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
            output2->Replace("\r", "\n");
            wxStringTokenizer tkz3(*output2, wxT("*"));
            for (int i = 0; i <cnt; i++)
            {
                songsDetails[i].push_back(wxString::Format("%s%s\n",tkz2.GetNextToken(), tkz3.GetNextToken()));
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
            output->Replace("\r", "\n");
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
            if(url_index == urlList.size())
            {
                if (selected_platform.compare(KLove) == 0)
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
                else if (selected_platform.compare(WorshipTogether) == 0)
                {
                    webView-> LoadURL("https://www.worshiptogether.com/search-results/");
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
    else if (url.compare("https://www.klove.com/music/songs#music-search-form") == 0 \
             || url.compare("https://www.lyrics.com/") == 0 \
             || url.compare("https://www.lyricsondemand.com/") == 0 \
             || url.compare("https://www.worshiptogether.com/search-results/") == 0 \
             || url.find("https://www.google.com/#spf") == 0 \
             || url.compare("https://www.google.com/") == 0)
    {
        SetStatusText(wxString::Format("Extracting lyrics of song %d from %s", curr_index+1, selected_platform), 0);
        wxStringTokenizer tkz(songsDetails[curr_index][0], wxT("\n"));
                
        if (selected_platform.compare(KLove) == 0)
        //Requires exact song name
        {
            webView-> RunScript(
            "\
            document.getElementById('musicSearchInput').value = \"" + tkz.GetNextToken() + "\";\
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
        else if (selected_platform.compare(WorshipTogether) == 0)
        {
            wxURI uri(tkz.GetNextToken() + " " + songsDetails[curr_index][2]);
            wxString encoded_uri = "https://www.worshiptogether.com/search-results/#?cludoquery=" + uri.BuildURI() + "&cludopage=1";
            webView->LoadURL(encoded_uri);
            webView->Reload();
        }
        else
        {
            if (webstate != -1)
            {
                webView-> RunScript(
                "\
                document.getElementsByName('q')[0].value = \"" + tkz.GetNextToken() + " " + selected_platform + " " + songsDetails[curr_index][2] + "\";\
                ");
                webView-> RunScript(
                "\
                setTimeout(() => {document.getElementsByTagName('form')[0].submit();}, Math.random()*1000);\
                ");
            }
        }
    }
    else if (url.find("https://www.klove.com/search?s=/music&q") == 0 \
             || url.find("https://www.worshiptogether.com/search-results/#?cludoquery=") == 0 \
             || url.find("https://www.lyrics.com/lyrics/") == 0 \
             || url.find("https://www.lyricsondemand.com/results.html?") == 0 \
             || url.find("https://www.google.com/search") == 0)
    {
        wxString* output = new wxString("");
                    
        if (selected_platform.compare(KLove) == 0)
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
        else if (selected_platform.compare(WorshipTogether) == 0)
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
        else
        {
            webView-> RunScript(
            "\
            var through = 0;\
            var elements = document.getElementsByClassName('BNeawe vvjwJb AP7Wnd');\
            if (elements.length != 0)\
            {\
                elements[0].click();\
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
                    output = elements[i + 7].innerText;\
                    break;\
                };\
            }\
            output;\
            ", lyrics);
        }
        else if (selected_platform.compare(Genius) == 0 && url.find("https://genius.com/") == 0)
        {
            webView-> RunScript(
            "\
            var output = '';\
            var elements = document.getElementsByClassName('SongPageGrid-sc-1vi6xda-0 DGVcp Lyrics__Root-sc-1ynbvzw-0 kkHBOZ');\
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
        else if (selected_platform.compare(LyricsOnDemand) == 0 && url.find("https://www.lyricsondemand.com/") == 0)
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
            //Lines are separated by white spaces which are also used to separate words
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
            webView-> RunScript(
            "\
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
        lyrics->Replace("\r", "\n");
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
        document.getElementById('EmailAddress').value = '" + configmap["Username"] + "';\
        document.getElementById('Password').value = '" + configmap["Password"] + "';\
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
                SetStatusText("Done reporting", 0);
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
            output->Replace("\r", "\n");
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
            output2->Replace("\r", "\n");
            wxStringTokenizer tkz3(*output2, wxT("*"));
            for (int i = 0; i <cnt; i++)
            {
                songsDetails[i].push_back(wxString::Format("%s%s\n",tkz2.GetNextToken(), tkz3.GetNextToken()));
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
            output->Replace("\r", "\n");
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
                wxStringTokenizer tkz3((*output).Trim(false).Trim(true), wxT("\r"));
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
            if(url_index == urlList.size())
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
    if (event.GetInt() != wxWEBVIEW_NAV_ERR_CONNECTION && event.GetInt() != wxWEBVIEW_NAV_ERR_NOT_FOUND)
    {
        //wxMessageBox(event.GetURL());
        //SlidesFrame::ScriptProgression();
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
    urlList.clear();
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
    wxTextInputStream text(input, wxT("\x09"));
    wxString line, segment;

    for (int i = 0; i < 3; i++)
    {
        info.push_back(text.ReadLine());
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
    SetStatusText("Creating slides", 0);
    if (SongsListCtrl->GetItemCount() == 0)
    {
        SetStatusText("At least a song has to be selected");
        return;
    }
    wxFile wxofsFile(dirName + "/Slides.app/Contents/Resources/values.txt", wxFile::write);
    wxString filename = configmap["Default templates directory"] + "/" + configmap["Template"];
    if(configmap["Default templates directory"].find("/") == -1)
    {
        filename = dirName + "/" + filename;
    }
    wxFile wxofsFile2;
    if (!wxofsFile2.Exists(filename))
    {
        SetStatusText(wxT("Cannot find template file"), 0);
        wxofsFile.Close();
        return;
    }
    else if (!filename.EndsWith(".ppt") && !filename.EndsWith(".pptx"))
    {
        SetStatusText(wxT("Template file must be .ppt/.pptx"), 0);
        wxofsFile.Close();
        return;
    }
    wxofsFile.Write("\n", 2);
    wxofsFile.Write(filename, wxMBConvUTF16LE());
    wxofsFile.Write("\n", 2);
    wxString resource_path = wxString::Format("%s/Slides.app/Contents/Resources", dirName);
    wxofsFile.Write(resource_path, wxMBConvUTF16LE());
    wxofsFile.Write("\n", 2);
    
    int num_lines = LyricsSpinCtrl->GetValue();
    wxofsFile.Write(wxString::Format("%i\n", num_lines), wxMBConvUTF16LE());
    wxVector <wxString> info;
    int cnt = 0;
    for (int i = 0; i < SongsListCtrl->GetItemCount(); i++)
    {
        bool success = ParseSlide(SongsListCtrl->GetItemText(i, 3), info);
        if (!success || info.size() <= 4)
        {
            SetStatusText("Cannot find/parse file properly", 0);
            continue;
        }
        else
        {
            wxFile wxofsFile3(wxString::Format("%s/Slides.app/Contents/Resources/song%i.txt", dirName, cnt), wxFile::write);
            for(int i = 0; i < info.size(); i++)
            {
                info[i].Replace("\n", "::");
                info[i].Replace("\v", "");
                //info[i] = info[i].ToAscii();
                //info[i].Replace("_", (char)39);
                wxofsFile3.Write(wxString::Format("%s\n", info[i]), wxMBConvUTF16LE());
            }
            wxofsFile3.Close();
            cnt++;
        }
    }
    int max_lines = LicenseSpinCtrl->GetValue();
    wxofsFile.Write(wxString::Format("%i\n", cnt), wxMBConvUTF16LE());
    wxofsFile.Write(wxString::Format("%i\n", max_lines), wxMBConvUTF16LE());
    wxofsFile.Close();
    wxExecute(wxString::Format("osascript '%s/Slides.app/Contents/Resources/CreateSlides.scpt'", dirName));
}

void SlidesFrame::OnSaveBtnClick(wxCommandEvent& event)
{
    wxFile wxofsFile;
    wxofsFile.Create(songfile_selected, true);
    wxofsFile.Write(FileRichTextCtrl->GetValue(), wxConvUTF8);
    wxofsFile.Close();
    wxStringTokenizer tkz(songfile_selected, wxT("/"));
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
    wxString filename = songfile_selected.substr(songfile_selected.rfind("/") + 1);
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
            wxFileInputStream input(configmap["Default songs directory"] + "/" + fileName);
            wxTextInputStream text(input, wxT("\x09"));
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
        int index = 0;
        list<wxString>::iterator it;
        filename = FileListBox->GetString(index);
        for (it = favourites.begin(); it != favourites.end(); it++)
        {
            while (filename.compare(*it) < 0)
            {
                index++;
                if (index == results.size())
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
            wxFileInputStream input(configmap["Default songs directory"] + "/" + fileName);
            wxTextInputStream text(input, wxT("\x09"));
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
        int index = 0;
        list<wxString>::iterator it;
        filename = FileListBox->GetString(index);
        for (it = favourites.begin(); it != favourites.end(); it++)
        {
            while (filename.compare(*it) < 0)
            {
                index++;
                if (index == results.size())
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
                                
                                
void SlidesFrame::SpecificSearch_NonVerbose(wxVector<wxString> fileNames)
{
    SlidesFrame::ShowSlides(configmap["Default songs directory"], false);
    int num_items = FileListBox->GetCount();
    for (int i = 0; i < num_items; i++)
    {
        FileListBox->Delete(0);
    }

    wxArrayString results;
    wxString fileName, line;
    int filesize = fileList.size();
    for (int i = 0; i < filesize; i++)
    {
        fileName = fileList[i];
        for (int ii = 0; ii < fileNames.size(); ii++){
            if (fileName.compare(fileNames[ii]) == 0)
            {
                results.Add(fileName,1);
                break;
            }
        }
    }
    if (!results.IsEmpty())
    {
        FileListBox->InsertItems(results, 0);
        wxString filename;
        int index = 0;
        list<wxString>::iterator it;
        filename = FileListBox->GetString(index);
        for (it = favourites.begin(); it != favourites.end(); it++)
        {
            while (filename.compare(*it) < 0)
            {
                index++;
                if (index == results.size())
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
        oriTitle.Replace("/", ",");
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
            wxString filename = configmap["Default songs directory"] + "/" + "missing.txt";
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
            wxString firstAuthor = tkz.GetNextToken();
            firstAuthor = firstAuthor.substr(0, min(firstAuthor.find("/"), firstAuthor.find(",")));
            
            wxString filename = configmap["Default songs directory"] + "/" + title \
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
            for (unsigned int ii = 2; ii < songsDetails2[i].size() - 1; ii++){
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
    SetStatusText("Setting up", 0);
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
        SetStatusText("Folder does not exist", 0);
        return;
    }
    wxArrayString* filenames =  new wxArrayString();
    wxString filename;
    wxString filespec = _T("*.ppt*");
    wxDir::GetAllFiles(dirname, filenames, filespec);
    wxFile wxofsFile(dirName + "/Slides.app/Contents/Resources/file.txt", wxFile::write);
    
    songsDetails2.clear();
    wxofsFile.Write(wxString::Format("%s\n", dirname), wxString::Format("%s\n", dirname).Len());
    for (unsigned int v = 0; v < filenames->GetCount(); v++){
        filename = filenames->Item(v);
        wxofsFile.Write(wxString::Format("\n%s", filename), wxMBConvUTF16LE());
    }
    wxofsFile.Close();
    delete filenames;
    wxArrayString output;
    wxExecute(wxString::Format("osascript '%s/Slides.app/Contents/Resources/ImportSlides.scpt'", dirName), output);
    
    wxFile wxofsFile2;
    int cnt = 0;
    while (true)
    {
        wxString filename = wxString::Format("%s/Slides.app/Contents/Resources/songinfo%i.txt", dirName, cnt);
        if (!wxofsFile2.Exists(filename))
        {
            break;
        }

        wxFileInputStream input(filename);
        wxTextInputStream text(input, wxT("\x09"));
        wxString line;
        wxVector<wxString> songDetails;
        while(!input.Eof())
        {
            line = text.ReadLine();
            //line = line.ToAscii();
            //line.Replace("_", (char)39);
            line.Replace("::", "\n");
            songDetails.push_back(line);
        }
        wxRemoveFile(filename);
        cnt++;
        songsDetails2.push_back(songDetails);
    }
    SlidesFrame::WriteSlides2();
    
    SlidesFrame::FilterSearch_NonVerbose();
}

void SlidesFrame::OnFileListBoxSelect(wxCommandEvent& event)
{
    wxArrayInt selections;
	FileListBox->GetSelections(selections);
    songfile_selected = configmap["Default songs directory"];
    songfile_selected += "/";
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
    wxTextInputStream text(input, wxT("\x09"));
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
        fileName = configmap["Default songs directory"] + "/" + item;
        wxFileInputStream input(fileName);
        wxTextInputStream text(input, wxT("\x09"));
        for (int i = 0; i < 3; i++)
        //Song file should contain at least 3 lines (Title, author/s & CCLI no. in this order)
        {
            if (!input.Eof())
            {
                line = text.ReadLine();
                if (i == 1)
                {
                    SongsListCtrl->SetItem(cnt, 1, line);
                }
                else if (i == 2)
                {
                    SongsListCtrl->SetItem(cnt, 2, line);
                }
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
        //The 3rd line is the CCLI no.
        SongsListCtrl->SetItem(cnt, 3, fileName);
    }
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
    wxString text = wxString::Format("%ld", event.GetIndex());
    wxTextDataObject tdo(text);
    wxDropSource tds(SongsListCtrl);
    tds.SetData(tdo);
    tds.DoDragDrop(wxDrag_CopyOnly);
}

void SlidesFrame::OnPlatformListCtrlBeginDrag(wxListEvent& event)
{
    wxString text = wxString::Format("%ld", event.GetIndex());
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
    //FileRichTextCtrl->Clear();
    //FileRichTextCtrl->AppendText(webView->GetPageSource());
    wxString content = webView->GetPageSource();
    wxFile wxofsFile(configmap["Default templates directory"] + "/" + "html.txt", wxFile::write);
    wxofsFile.Write(content, content.Len());
    wxofsFile.Close();
}
