
// testDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// CtestDlg 对话框



CtestDlg::CtestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CtestDlg 消息处理程序

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static void UnicodeToAnsi(const wchar_t* srcStr, char* destStr, const UINT& nMaxBytesToConvert) {
	int nLen = WideCharToMultiByte(CP_ACP, 0, srcStr, -1, NULL, 0, NULL, NULL);
	if (nLen) {
		char* p = new char[nLen];
		WideCharToMultiByte(CP_ACP, 0, srcStr, -1, p, nLen, NULL, NULL);
		strcpy_s(destStr, nMaxBytesToConvert, p);
		free(p);
	}
}
static void AnsiToUnicode(const char* srcStr, wchar_t* destStr, const UINT& nMaxBytesToConvert) {
	int nLen = MultiByteToWideChar(CP_ACP, 0, srcStr, -1, NULL, 0);
	if (nLen) {
		wchar_t* pUnicode = new wchar_t[nLen];
		MultiByteToWideChar(CP_ACP, 0, srcStr, -1, pUnicode, nLen);
		wcscpy_s(destStr, nMaxBytesToConvert, pUnicode);
		free(pUnicode);
	}
}

void CtestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* pEdit;
	CString sss;

	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_path);
	pEdit->GetWindowText(sss);
	int lenpath = WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), NULL, 0, NULL, NULL);
	char* pCharPath = new char[(long long)lenpath + 2];
	WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), pCharPath, lenpath, NULL, NULL);
	pCharPath[(long long)lenpath + 1] = '\0';


	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_exename);
	pEdit->GetWindowText(sss);
	int lenexe = WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), NULL, 0, NULL, NULL);
	char* pCharExe = new char[(long long)lenexe + 2];
	WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), pCharExe, lenexe, NULL, NULL);
	pCharExe[(long long)lenexe + 1] = '\0';


	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ioname);
	pEdit->GetWindowText(sss);
	int lenioname = WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), NULL, 0, NULL, NULL);
	char* pCharIoname = new char[(long long)lenioname + 2];
	WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), pCharIoname, lenioname, NULL, NULL);
	pCharIoname[(long long)lenioname + 1] = '\0';

	char* pCharInputName = new char[(long long)lenioname + 6];
	for (int i = 0; i < lenioname; i++)pCharInputName[i] = pCharIoname[i];
	pCharInputName[lenioname] = '.';
	pCharInputName[lenioname + 1] = 'i';
	pCharInputName[lenioname + 2] = 'n';
	pCharInputName[lenioname + 3] = '\0';
	ofstream fout(pCharInputName);


	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_input);
	pEdit->GetWindowText(sss);
	int leninput = WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), NULL, 0, NULL, NULL);
	char* pCharInput = new char[(long long)leninput + 2];
	WideCharToMultiByte(CP_ACP, 0, sss, sss.GetLength(), pCharInput, leninput, NULL, NULL);
	pCharInput[(long long)leninput + 1] = '\0';

	fout << pCharInput;

	fout.close();
	char* pCharExeFull = new char[(long long)lenpath + lenexe + 20];
	pCharExeFull[0] = '\"';
	for (int i = 1; i <= lenpath; i++)pCharExeFull[i] = pCharPath[i - 1];
	for (int i = lenpath + 1; i <= lenpath + lenexe; i++)pCharExeFull[i] = pCharExe[i - lenpath - 1];
	pCharExeFull[lenpath + lenexe + 1] = '.';
	pCharExeFull[lenpath + lenexe + 2] = 'e';
	pCharExeFull[lenpath + lenexe + 3] = 'x';
	pCharExeFull[lenpath + lenexe + 4] = 'e';
	pCharExeFull[lenpath + lenexe + 5] = '\"';
	pCharExeFull[lenpath + lenexe + 6] = '\0';
	system(pCharExeFull);

	char* pCharOutput = new char[(long long)lenioname + 6];
	for (int i = 0; i < lenioname; i++)pCharOutput[i] = pCharIoname[i];
	pCharOutput[lenioname] = '.';
	pCharOutput[lenioname + 1] = 'o';
	pCharOutput[lenioname + 2] = 'u';
	pCharOutput[lenioname + 3] = 't';
	pCharOutput[lenioname + 4] = '\0';


	ifstream fin(pCharOutput);

	char ss[1024];
	sss = _T("");
	while (fin.getline(ss,1024)) {
		wchar_t t[1024];
		AnsiToUnicode(ss, t , 500);
		CString ssss=CString(t);
		ssss += _T("\r\n");
		sss += ssss;
	}
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_output);
	pEdit->SetWindowText(sss);

	fin.close();

	ofstream fout2("temp.bat");
	fout2 << "@echo off" << endl;
	fout2 << "del \"" << pCharInputName << "\"" << endl;
	fout2 << "del \"" << pCharOutput << "\"" << endl;
	fout2.close();
	system("temp.bat");
	system("del temp.bat");
	return;
}
