// testing.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "testing.h"
#include "afxdialogex.h"
#include "variables.h"


// testing 对话框

IMPLEMENT_DYNAMIC(testing, CDialogEx)

testing::testing(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTING_DIALOG, pParent)
{

}

testing::~testing()
{
}

void testing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(testing, CDialogEx)
END_MESSAGE_MAP()


// testing 消息处理程序


BOOL testing::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
