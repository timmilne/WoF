
// WoFDlg.h : header file
//

#pragma once

#include "mmsystem.h"
#include "ocx2.h"
#include "afxwin.h"
#pragma comment(lib,"winmm.lib")


// CWoFDlg dialog
class CWoFDlg : public CDialogEx
{
// Construction
public:
	CWoFDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WOF_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	boolean m_sound;
	boolean m_themePaused;
	BSTR m_themeURL;
	BSTR m_voidURL;
	
	//Controls and Buttons
	CButton m_newRoundButton;
	CButton m_dingButton;
	CButton m_singleBuzzButton;
	CButton m_puzzleSolvedButton;
	CButton m_applauseButton;
	CButton m_finalSpinButton;
	CButton m_doubleBuzzButton;
	CButton m_themeButton;
	CButton m_aboutButton;
	CButton m_okButton;
	CToolTipCtrl m_toolTip;
	COcx2 m_WMPlayer;

	void playSound(UINT nID, DWORD dOpts=SND_RESOURCE | SND_ASYNC);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNewRound();
	afx_msg void OnBnClickedButtonDing();
	afx_msg void OnBnClickedButtonBuzz();
	afx_msg void OnBnClickedButtonPuzzleSolved();
	afx_msg void OnBnClickedButtonApplause();
	afx_msg void OnBnClickedButtonFinalSpin();
	afx_msg void OnBnClickedButtonDoubleBuzz();
	afx_msg void OnBnClickedButtonTheme();
	afx_msg void OnBnClickedButtonAbout();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
