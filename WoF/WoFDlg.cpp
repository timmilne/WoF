
// WoFDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WoF.h"
#include "WoFDlg.h"
#include "afxdialogex.h"
#include "windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWoFDlg dialog



CWoFDlg::CWoFDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWoFDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sound = TRUE;
	m_themePaused = TRUE;
	m_themeURL = SysAllocString(L"res/WoF_Theme.wav");
	m_voidURL = SysAllocString(L"res/WoF_Void.wav");
}

void CWoFDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NEW_ROUND, m_newRoundButton);
	DDX_Control(pDX, IDC_BUTTON_DING, m_dingButton);
	DDX_Control(pDX, IDC_BUTTON_BUZZ, m_singleBuzzButton);
	DDX_Control(pDX, IDC_BUTTON_PUZZLE_SOLVED, m_puzzleSolvedButton);
	DDX_Control(pDX, IDC_BUTTON_APPLAUSE, m_applauseButton);
	DDX_Control(pDX, IDC_BUTTON_FINAL_SPIN, m_finalSpinButton);
	DDX_Control(pDX, IDC_BUTTON_DOUBLE_BUZZ, m_doubleBuzzButton);
	DDX_Control(pDX, IDC_BUTTON_THEME, m_themeButton);
	DDX_Control(pDX, IDC_BUTTON_ABOUT, m_aboutButton);
	DDX_Control(pDX, IDC_OCX2_WMPLAYER, m_WMPlayer);
	DDX_Control(pDX, IDOK, m_okButton);
}

BEGIN_MESSAGE_MAP(CWoFDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NEW_ROUND, &CWoFDlg::OnBnClickedButtonNewRound)
	ON_BN_CLICKED(IDC_BUTTON_DING, &CWoFDlg::OnBnClickedButtonDing)
	ON_BN_CLICKED(IDC_BUTTON_BUZZ, &CWoFDlg::OnBnClickedButtonBuzz)
	ON_BN_CLICKED(IDC_BUTTON_PUZZLE_SOLVED, &CWoFDlg::OnBnClickedButtonPuzzleSolved)
	ON_BN_CLICKED(IDC_BUTTON_APPLAUSE, &CWoFDlg::OnBnClickedButtonApplause)
	ON_BN_CLICKED(IDC_BUTTON_FINAL_SPIN, &CWoFDlg::OnBnClickedButtonFinalSpin)
	ON_BN_CLICKED(IDC_BUTTON_DOUBLE_BUZZ, &CWoFDlg::OnBnClickedButtonDoubleBuzz)
	ON_BN_CLICKED(IDC_BUTTON_THEME, &CWoFDlg::OnBnClickedButtonTheme)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, &CWoFDlg::OnBnClickedButtonAbout)
END_MESSAGE_MAP()


// CWoFDlg message handlers

BOOL CWoFDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Setup the tool tips
	//Create the ToolTip control
	if( !m_toolTip.Create(this))
	{
		TRACE0("Unable to create the ToolTip!");
	}
	else
	{
		// Add tool tips to the controls, either by hard coded string 
		// or using the string table resource
		m_toolTip.AddTool( &m_newRoundButton, IDS_NEW_ROUND );
		m_toolTip.AddTool( &m_dingButton, IDS_DING );
		m_toolTip.AddTool( &m_singleBuzzButton, IDS_SINGLE_BUZZ );
		m_toolTip.AddTool( &m_puzzleSolvedButton, IDS_PUZZLE_SOLVED );
		m_toolTip.AddTool( &m_applauseButton, IDS_APPLAUSE );
		m_toolTip.AddTool( &m_finalSpinButton, IDS_FINAL_SPIN );
		m_toolTip.AddTool( &m_doubleBuzzButton, IDS_DOUBLE_BUZZ );
		m_toolTip.AddTool( &m_themeButton, IDS_THEME );
		m_toolTip.AddTool( &m_aboutButton, IDS_ABOUTBOX );
		m_toolTip.AddTool( &m_okButton, IDS_OK );

		m_toolTip.Activate(TRUE);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWoFDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWoFDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWoFDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CWoFDlg::OnBnClickedButtonNewRound()
{
	// Do a single applause
	OnBnClickedButtonApplause();

	// Stop theme
	m_themePaused = FALSE;
	OnBnClickedButtonTheme();
}


void CWoFDlg::OnBnClickedButtonDing()
{
	playSound(IDR_WAVE_DING);
}


void CWoFDlg::OnBnClickedButtonBuzz()
{
	playSound(IDR_WAVE_BUZZ);
}


void CWoFDlg::OnBnClickedButtonPuzzleSolved()
{
	// Do a winning ring tone (wait to finish)
	OnBnClickedButtonFinalSpin();

	//Wait just a second
	Sleep(1000);

	// Start the theme music
	m_themePaused = TRUE;
	OnBnClickedButtonTheme();

	// Do a single applause
	OnBnClickedButtonApplause();
}


void CWoFDlg::OnBnClickedButtonApplause()
{
	playSound(IDR_WAVE_APPLAUSE);
}


void CWoFDlg::OnBnClickedButtonFinalSpin()
{
	playSound(IDR_WAVE_FINAL_SPIN);
}


void CWoFDlg::OnBnClickedButtonDoubleBuzz()
{
	playSound(IDR_WAVE_DOUBLE_BUZZ);
}


void CWoFDlg::OnBnClickedButtonTheme()
{
	m_themePaused = !m_themePaused;
	m_WMPlayer.SetProperty(m_WMPlayer.mpPaused, VT_BOOL, m_themePaused);
	m_WMPlayer.SetProperty(m_WMPlayer.mpClipURL, VT_BSTR, (m_themePaused)?m_voidURL:m_themeURL);
}


void CWoFDlg::OnBnClickedButtonAbout()
{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
}


void CWoFDlg::playSound(UINT nID, DWORD dOpts)
{
	// Issue the new sound
	if(m_sound)
	{
		if (!(::PlaySound(MAKEINTRESOURCE(nID), NULL, dOpts)))
		{
			AfxMessageBox(_T("Can't play sound"));
		}
	}
}


BOOL CWoFDlg::PreTranslateMessage(MSG* pMsg)
{
	// First time through, get some music going
	static boolean firstTime = TRUE;
	if (firstTime)
	{
		m_themePaused = TRUE;
		OnBnClickedButtonTheme();
		firstTime = FALSE;
	}

	// Process any tool tips
	m_toolTip.RelayEvent(pMsg);

	// Intercept any key strokes we are interested in
    if(pMsg->message==WM_KEYDOWN)
    {
		switch (pMsg->wParam)
		{
		// Number 1
		case 49:
			OnBnClickedButtonNewRound();
			return true;
			break;

		// Number 2
		case 50:
			OnBnClickedButtonDing();
			return true;
			break;

		// Number 3
		case 51:
			OnBnClickedButtonBuzz();
			return true;
			break;

		// Number 4
		case 52:
			OnBnClickedButtonPuzzleSolved();
			return true;
			break;

		// Number 5
		case 53:
			OnBnClickedButtonApplause();
			return true;
			break;

		// Number 6
		case 54:
			OnBnClickedButtonFinalSpin();
			return true;
			break;

		// Number 7
		case 55:
			OnBnClickedButtonDoubleBuzz();
			return true;
			break;

		// Number 8
		case 56:
			OnBnClickedButtonTheme();
			return true;
			break;
		}
    }

	return CDialogEx::PreTranslateMessage(pMsg);
}
