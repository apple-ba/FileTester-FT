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
    ON_WM_CREATE()
END_MESSAGE_MAP()


// batch 消息处理程序



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


int batch::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialogEx::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  在此添加您专用的创建代码
    AfxGetMainWnd() - SendMessage(WM_SETICON, TRUE, (LPARAM)m_hIcon);

    return 0;
}
