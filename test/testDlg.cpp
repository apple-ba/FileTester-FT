
// testDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include "batch.h"
#include "variables.h"
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
	ON_BN_CLICKED(IDC_CLEAROUTPUT, &CtestDlg::OnBnClickedClearoutput)
	ON_BN_CLICKED(IDC_CLEARINPUT, &CtestDlg::OnBnClickedClearinput)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CtestDlg::OnBnClickedButtonChange)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT_path, &CtestDlg::OnEnChangeEditpath)
	ON_EN_CHANGE(IDC_EDIT_exename, &CtestDlg::OnEnChangeEditexename)
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

	CString ss=AnsiToUnicode(sPath.c_str());
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_path);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sPath.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_exename);
	pEdit->SetWindowText(ss);

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


void CtestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CButton* ok = (CButton*)GetDlgItem(IDOK);
	ok->EnableWindow(FALSE);//禁止再次启动测试
	//控件指针
	CEdit* pEdit;

	//读入路径控件值
	CString pCharPath;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_path);
	pEdit->GetWindowText(pCharPath);

	//读入程序名称控件值
	CString pCharExe;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_exename);
	pEdit->GetWindowText(pCharExe);

	//读入输入输出文件名称控件值
	CString pCharIoname;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ioname);
	pEdit->GetWindowText(pCharIoname);

	//生成输入文件
	ofstream fout(UnicodeToAnsi(pCharIoname + _T(".in")));//文件流
	CString pCharInput;//文件内容
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_input);
	pEdit->GetWindowText(pCharInput);//读入输入控件值
	fout << UnicodeToAnsi(pCharInput) << endl;//转为ANSI文件
	fout.close();//保存关闭文件
	
	//运行被测试文件
	CString pCharExeFull;
	pCharExeFull = pCharPath;
	if (UnicodeToAnsi(pCharPath)[pCharPath.GetLength() - 1] != '\\')pCharExeFull += _T("\\");//补全路径末尾反斜杠
	pCharExeFull += pCharExe;
	system(UnicodeToAnsi(pCharExeFull));//执行程序
	
	//读入输出文件
	ifstream fin(UnicodeToAnsi(pCharIoname+_T(".out")));//文件流
	CString pCharOutput;
	char ss[1024];
	pCharOutput = _T("");
	while (fin.getline(ss,1024)) {
		CString ssss = AnsiToUnicode(ss);
		ssss += _T("\r\n");
		pCharOutput += ssss;
	}//读入
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_output);
	pEdit->SetWindowText(pCharOutput);//设置输出控件值
	fin.close();//关闭文件

	//生成删除临时文件脚本
	ofstream fout2("temp.bat");
	fout2 << "@echo off" << endl;
	fout2 << "del \"" << UnicodeToAnsi(pCharIoname + _T(".in")) << "\"" << endl;
	fout2 << "del \"" << UnicodeToAnsi(pCharIoname + _T(".out")) << "\"" << endl;
	fout2.close();
	system("temp.bat");//执行
	system("del temp.bat");//删除脚本

	ok->EnableWindow(TRUE);//允许测试
	return;
}


void CtestDlg::OnBnClickedClearoutput()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_output);
	pEdit->SetWindowText(_T(""));
	return;
}


void CtestDlg::OnBnClickedClearinput()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_input);
	pEdit->SetWindowText(_T(""));
	return;
}


void CtestDlg::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);//隐藏自己
	batch* pDlg = new batch();
	pDlg->Create(IDD_BATCHTEST_DIALOG); //创建一个非模态对话框  
	pDlg->ShowWindow(SW_SHOWNORMAL); //显示非模态对话框  
}

BOOL CtestDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			return TRUE;

		case VK_ESCAPE:
			return TRUE;

		default:
			break;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}


void CtestDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
	exit(0);
}


void CtestDlg::OnEnChangeEditpath()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_path);
	pEdit->GetWindowText(ss);
	string sPath = UnicodeToAnsi(ss);
}


void CtestDlg::OnEnChangeEditexename()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_exename);
	pEdit->GetWindowText(ss);
	sExename = UnicodeToAnsi(ss);
}
