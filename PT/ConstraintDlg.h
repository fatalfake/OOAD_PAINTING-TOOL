#pragma once
#include"Constraint.h"

// ConstraintDlg 对话框

class ConstraintDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConstraintDlg)

public:
	ConstraintDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ConstraintDlg();
	BOOL OnInitDialog();
	void CDlg_setconstraint();
	Constraint showconstraint();
	void CDlg_addphenomenon(CString str);
private:
	CFont m_editFont;
	Constraint c;
	CString inputInitiator;
	CString inputReceiver;
	CString inputPhenomenon;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSTRAINTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox ListBox1;
	CString m_Initiator;
	CString m_Receiver;
	CString m_Phenomenon;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton1();
};
