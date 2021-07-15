#pragma once


// batch 对话框

class batch : public CDialogEx
{
	DECLARE_DYNAMIC(batch)

public:
	batch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~batch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BATCHTEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

protected:
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnInitDialog();
	void OnClose();
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonChange();
	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnEnChangeEditFrom();
	afx_msg void OnEnChangeEditTo();
	afx_msg void OnEnChangeEditpath();
	afx_msg void OnEnChangeEditexename();
	afx_msg void OnEnChangeEditioname();
	afx_msg void OnCbnEditchangeComboInputfilename();
	afx_msg void OnCbnEditchangeComboOutputfilename();
	afx_msg void OnCbnSelchangeComboAnswerfilename();
	afx_msg void OnEnChangeEditNumberchoose();
};
