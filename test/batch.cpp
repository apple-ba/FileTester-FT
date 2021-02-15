// batch.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "batch.h"
#include "afxdialogex.h"
#include "testDlg.h"


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
    ON_BN_CLICKED(IDC_BUTTON_HELP, &batch::OnBnClickedButtonHelp)
END_MESSAGE_MAP()


// batch 消息处理程序
BOOL batch::OnInitDialog() {
    CDialogEx::OnInitDialog();
    SetIcon(m_hIcon, TRUE);			// 设置大图标
    SetIcon(m_hIcon, FALSE);		// 设置小图标
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_NUMBER_CHOOSE);
    pCombo->AddString(_T("x"));
    pCombo->AddString(_T("xx"));
    pCombo->AddString(_T("xxx"));
    pCombo->AddString(_T("xxxx"));
    pCombo->SetCurSel(0);
    pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_INPUTFILENAME);
    pCombo->AddString(_T(".in"));
    pCombo->SetCurSel(0);
    pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_ANSWERFILENAME);
    pCombo->AddString(_T(".ans"));
    pCombo->AddString(_T(".out"));
    pCombo->SetCurSel(0);
    CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
    pSpin->SetRange32(0, 10000);
    pSpin->SetBase(10);
    pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN2);
    pSpin->SetRange32(0, 10000);
    pSpin->SetBase(10);
    return TRUE;
}


void batch::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    exit(0);
	CDialogEx::OnClose();
}

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

void batch::OnBnClickedButtonChange()
{
    // TODO: 在此添加控件通知处理程序代码
    this->ShowWindow(SW_HIDE);//隐藏自己
    CtestDlg* pDlg = new CtestDlg();
    pDlg->Create(IDD_TEST_DIALOG); //创建一个非模态对话框  
    pDlg->ShowWindow(SW_SHOWNORMAL); //显示非模态对话框  
}




void batch::OnBnClickedButtonTest()
{
    // TODO: 在此添加控件通知处理程序代码
    CtestDlg* pDlg = new CtestDlg();
    pDlg->Create(IDD_TESTING_DIALOG); //创建一个非模态对话框  
    pDlg->ShowWindow(SW_SHOWNORMAL); //显示非模态对话框  
}


void batch::OnBnClickedButtonHelp()
{
    // TODO: 在此添加控件通知处理程序代码
    MessageBox(_T("\
第一个编辑框填写程序里写的输入输出文件名称(不带后缀名)\n\
第二个编辑框填写保留0的情况\n\
第三个编辑框填写输入文件后缀\n\
第四个编辑框填写答案文件后缀\n\
例：\n\
|apple|x|.in|.ans|\n\
则输入文件名为apple0.in,apple1.in,apple2.in~\n\
答案文件名为apple0.ans,apple1.ans,apple2.ans~\n\
"), _T("帮助..."), MB_OK);
}
