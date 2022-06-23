
// MFCCListBoxDlg.h : header file
//

#pragma once
#include<map>

//without enum, we can't initialize CListbox's key element with hidden id
enum Month {
	January = 8, February, March, April, May, June, July,
	August, September, October, November, December
};

//to get the corresponding string to set in the CList Box, we need map

const std::map<Month, CString> monthToString{
	{January,_T("January")},
	{February,_T("February")},
	{March,_T("March")},
	{April,_T("April")},
	{May,_T("May")},
	{June,_T("June")},
	{July,_T("July")},
	{August,_T("August")},
	{September,_T("September")},
	{October,_T("October")},
	{November,_T("November")},
	{December,_T("December")}
};



// CMFCCListBoxDlg dialog
class CMFCCListBoxDlg : public CDialogEx
{
// Construction
public:
	CMFCCListBoxDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CListBox};
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
private:
	CListBox m_available_list;
	CListBox m_choosen_list;
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonRemoveall();
	afx_msg void OnBnClickedButtonPrintChoosen();
};
