// batch.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "batch.h"
#include "afxdialogex.h"


// batch 对话框

IMPLEMENT_DYNAMIC(batch, CDialogEx)

batch::batch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BATCHTEST_DIALOG, pParent)
{

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
END_MESSAGE_MAP()


// batch 消息处理程序



void batch::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
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