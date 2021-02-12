// testing.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "testing.h"
#include "afxdialogex.h"


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
