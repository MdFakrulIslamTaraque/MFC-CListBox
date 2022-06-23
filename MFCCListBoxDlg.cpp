
// MFCCListBoxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCCListBox.h"
#include "MFCCListBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCListBoxDlg dialog



CMFCCListBoxDlg::CMFCCListBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CListBox, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Available_List, m_available_list);
	DDX_Control(pDX, IDC_Choosed_List, m_choosen_list);
}

BEGIN_MESSAGE_MAP(CMFCCListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Add, &CMFCCListBoxDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_Remove, &CMFCCListBoxDlg::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_Remove_all, &CMFCCListBoxDlg::OnBnClickedButtonRemoveall)
	ON_BN_CLICKED(IDC_BUTTON_Print_Choosen, &CMFCCListBoxDlg::OnBnClickedButtonPrintChoosen)
END_MESSAGE_MAP()


// CMFCCListBoxDlg message handlers

BOOL CMFCCListBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	//===================================================================//
	//first add find out the index of the enum of specific element
	//then add that item at specific index

	int addedIndex = m_available_list.AddString(monthToString.at(January)); 
	m_available_list.SetItemData(addedIndex, January);

	addedIndex = m_available_list.AddString(monthToString.at(February));
	m_available_list.SetItemData(addedIndex, February);

	addedIndex = m_available_list.AddString(monthToString.at(March));
	m_available_list.SetItemData(addedIndex, March);

	addedIndex = m_available_list.AddString(monthToString.at(April));
	m_available_list.SetItemData(addedIndex, April);

	addedIndex = m_available_list.AddString(monthToString.at(May));
	m_available_list.SetItemData(addedIndex, May);

	addedIndex = m_available_list.AddString(monthToString.at(June));
	m_available_list.SetItemData(addedIndex, June);

	addedIndex = m_available_list.AddString(monthToString.at(July));
	m_available_list.SetItemData(addedIndex, July);

	addedIndex = m_available_list.AddString(monthToString.at(August));
	m_available_list.SetItemData(addedIndex, August);

	addedIndex = m_available_list.AddString(monthToString.at(September));
	m_available_list.SetItemData(addedIndex, September);

	addedIndex = m_available_list.AddString(monthToString.at(October));
	m_available_list.SetItemData(addedIndex, October);

	addedIndex = m_available_list.AddString(monthToString.at(November));
	m_available_list.SetItemData(addedIndex, November);

	addedIndex = m_available_list.AddString(monthToString.at(December));
	m_available_list.SetItemData(addedIndex, December);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCCListBoxDlg::OnPaint()
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
HCURSOR CMFCCListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
} 


void CMFCCListBoxDlg::OnBnClickedButtonAdd()
{
	auto selectedMonthIndex = m_available_list.GetCurSel(); //get the selected month index
	if (selectedMonthIndex != LB_ERR)					   //if the selected month produces no error
	{
		//get the month at selected index from available_list and type-casting it to enum type
		Month selectedMonth = static_cast<Month>(m_available_list.GetItemData(selectedMonthIndex));
		
		//deleting the selected Month by index from the available list
		m_available_list.DeleteString(selectedMonthIndex);
		
		//getting the index at which we want to add the selected string in choosen list(usally it should be at the end)
		auto addedIndex = m_choosen_list.AddString(monthToString.at(selectedMonth));

		//add the string to the specific index of the choosen list
		m_choosen_list.SetItemData(addedIndex, selectedMonth);
	}
}


void CMFCCListBoxDlg::OnBnClickedButtonRemove()
{
	auto selectedMonthIndex = m_choosen_list.GetCurSel(); //get the selected month index
	if (selectedMonthIndex != LB_ERR)					   //if the selected month produces no error
	{
		//get the month at selected index from choosen_list and type-casting it to enum type
		Month selectedMonth = static_cast<Month>(m_choosen_list.GetItemData(selectedMonthIndex));

		//removing the selected item from the choosen table
		m_choosen_list.DeleteString(selectedMonthIndex); 

		//getting the index at which we want to add the selected string in availabe list(usally it should be at the end)
		auto addedIndex = m_available_list.AddString(monthToString.at(selectedMonth));

		//add the string to the specific index of the available  list
		m_available_list.SetItemData(addedIndex, selectedMonth);
	}
}


void CMFCCListBoxDlg::OnBnClickedButtonRemoveall()
{
	const int choosenListSize{ m_choosen_list.GetCount() };
	
	//prevent drawing what is happening in the list boxes
	m_available_list.SetRedraw(FALSE);
	m_choosen_list.SetRedraw(FALSE);



	//start removing from last to first
	//this way the indexes are valid, because if we delete items from the first,
	//all the ids will need to be shifted, whuch is cumbersome
	for (int i{ choosenListSize - 1 }; i >= 0; i--)
	{
		Month selectedMonth = static_cast<Month>(m_choosen_list.GetItemData(i));
		m_choosen_list.DeleteString(i);
		auto addedIndex = m_available_list.AddString(monthToString.at(selectedMonth));
		m_available_list.SetItemData(addedIndex, selectedMonth);

	}



	//set drawing what happens in the list boxes
	m_available_list.SetRedraw(TRUE);
	m_choosen_list.SetRedraw(TRUE);


	//draw both windows
	m_available_list.RedrawWindow();
	m_choosen_list.RedrawWindow();
}


void CMFCCListBoxDlg::OnBnClickedButtonPrintChoosen()
{
	CString message{ _T("You choose these months:\n") };
	const int chooosenCount{ m_choosen_list.GetCount() };

	for (int i(0); i < chooosenCount; i++)
	{
		 //get the selected item id from choosen list
		Month selectedMonth = static_cast<Month>(m_choosen_list.GetItemData(i));

		//use the ID(which is enum MOnth Type) to get the corresponding string using map
		message += monthToString.at(selectedMonth);

		if (i != chooosenCount - 1)
			message += _T("\n");
	}
	AfxMessageBox(message);
}
