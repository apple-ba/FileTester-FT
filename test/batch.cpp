// batch.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "batch.h"
#include "afxdialogex.h"
#include "testDlg.h"
#include "testing.h"
#include "variables.h"


// batch 对话框

IMPLEMENT_DYNAMIC(batch, CDialogEx)

batch::batch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BATCHTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

batch::~batch()
{
}

void batch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(batch, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &batch::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_TEST, &batch::OnBnClickedButtonTest)
	ON_EN_CHANGE(IDC_EDIT_FROM, &batch::OnEnChangeEditFrom)
	ON_EN_CHANGE(IDC_EDIT_TO, &batch::OnEnChangeEditTo)
	ON_EN_CHANGE(IDC_EDIT_path, &batch::OnEnChangeEditpath)
	ON_EN_CHANGE(IDC_EDIT_exename, &batch::OnEnChangeEditexename)
	ON_EN_CHANGE(IDC_EDIT_ioname, &batch::OnEnChangeEditioname)
	ON_CBN_EDITCHANGE(IDC_COMBO_INPUTFILENAME, &batch::OnCbnEditchangeComboInputfilename)
	ON_CBN_EDITCHANGE(IDC_COMBO_OUTPUTFILENAME, &batch::OnCbnEditchangeComboOutputfilename)
	ON_CBN_SELCHANGE(IDC_COMBO_ANSWERFILENAME, &batch::OnCbnSelchangeComboAnswerfilename)
	ON_EN_CHANGE(IDC_EDIT_NUMBERCHOOSE, &batch::OnEnChangeEditNumberchoose)
END_MESSAGE_MAP()


// batch 消息处理程序

//初始化对话框
BOOL batch::OnInitDialog() {
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//读入文件数据
	_read();

	//初始化控件(只设置范围,不包括初始值)
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_INPUTFILENAME);
	pCombo->AddString(_T(".in"));
	pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_OUTPUTFILENAME);
	pCombo->AddString(_T(".out"));
	pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_ANSWERFILENAME);
	pCombo->AddString(_T(".ans"));
	pCombo->AddString(_T(".out"));
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_FROM);
	pSpin->SetRange32(0, 1);
	pSpin->SetBase(10);
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_TO);
	pSpin->SetRange32(1, 10000);
	pSpin->SetBase(10);
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_NUMBERC);
	pSpin->SetRange32(0, 5);
	pSpin->SetBase(10);

	//调出变量表中的值(定义在varibles.h)
	CString ss;
	CEdit* pEdit;
	ss = AnsiToUnicode(sPath.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_path);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sExename.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_exename);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sIoname.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ioname);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sInputFileName.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_COMBO_INPUTFILENAME);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sOutputFileName.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_COMBO_OUTPUTFILENAME);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sAnswerFileName.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_COMBO_ANSWERFILENAME);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sFrom.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_FROM);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sTo.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TO);
	pEdit->SetWindowText(ss);
	ss = AnsiToUnicode(sNumberChoose.c_str());
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_NUMBERCHOOSE);
	pEdit->SetWindowText(ss);


	return TRUE;
}

//关闭对话框
void batch::OnClose()
{
	//在退出时保存数据
	//_save();
	//执行基类函数
	CDialogEx::OnClose();
	//强制结束程序,这个语句避免只关闭对话框而不结束程序的情况
	exit(0);
}

//重载消息处理函数,防止ESC键退出程序
BOOL batch::PreTranslateMessage(MSG* pMsg)
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

//切换对话框
void batch::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);//隐藏自己
	CtestDlg* pDlg = new CtestDlg();
	pDlg->Create(IDD_TEST_DIALOG); //创建一个非模态对话框  
	pDlg->ShowWindow(SW_SHOWNORMAL); //显示非模态对话框  
}

//测试(启动"正在测试"对话框)
void batch::OnBnClickedButtonTest()
{
	// TODO: 在此添加控件通知处理程序代码
	testing* pDlg = new testing();
	pDlg->Create(IDD_TESTING_DIALOG); //创建一个非模态对话框  
	pDlg->ShowWindow(SW_SHOWNORMAL); //显示非模态对话框  
}

//当控件被更改,储存到全局变量
void batch::OnEnChangeEditFrom()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_FROM);
	CString ss;
	pEdit->GetWindowText(ss);
	int x = atoi(UnicodeToAnsi(ss));
	if (x != 0) {
		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_TO);
		pSpin->SetRange32(x, 10000);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TO);
		pEdit->GetWindowText(ss);
		if (atoi(UnicodeToAnsi(ss)) < x) {
			ss.Format(_T("%d"), x);
			pEdit->SetWindowText(ss);
		}
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_FROM);
		pEdit->GetWindowText(ss);
		sFrom = UnicodeToAnsi(ss);
	}
	
}

void batch::OnEnChangeEditTo()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TO);
	CString ss;
	pEdit->GetWindowText(ss);
	int x = atoi(UnicodeToAnsi(ss));
	if (x != 0) {
		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_FROM);
		pSpin->SetRange32(0, x);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_FROM);
		pEdit->GetWindowText(ss);
		if (atoi(UnicodeToAnsi(ss)) > x) {
			ss.Format(_T("%d"), x);
			pEdit->SetWindowText(ss);
		}
		if (atoi(UnicodeToAnsi(ss)) != x) {
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TO);
			pEdit->GetWindowText(ss);
			sTo = UnicodeToAnsi(ss);
		}
	}
}

void batch::OnEnChangeEditpath()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_path);
	pEdit->GetWindowText(ss);
	sPath = UnicodeToAnsi(ss);
}

void batch::OnEnChangeEditexename()
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

void batch::OnEnChangeEditioname()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ioname);
	pEdit->GetWindowText(ss);
	sIoname = UnicodeToAnsi(ss);
}

void batch::OnCbnEditchangeComboInputfilename()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_COMBO_INPUTFILENAME);
	pEdit->GetWindowText(ss);
	if (ss != _T(".in"))sInputFileName = UnicodeToAnsi(ss);
}

void batch::OnCbnEditchangeComboOutputfilename()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_COMBO_OUTPUTFILENAME);
	pEdit->GetWindowText(ss);
	if (ss != _T(".out"))sOutputFileName = UnicodeToAnsi(ss);
}

void batch::OnCbnSelchangeComboAnswerfilename()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_COMBO_ANSWERFILENAME);
	pEdit->GetWindowText(ss);
	if (ss != _T(".ans"))sAnswerFileName = UnicodeToAnsi(ss);
}

void batch::OnEnChangeEditNumberchoose()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_NUMBERCHOOSE);
	CString ss;
	pEdit->GetWindowText(ss);
	if (ss != _T("0"))sNumberChoose = UnicodeToAnsi(ss);
}
