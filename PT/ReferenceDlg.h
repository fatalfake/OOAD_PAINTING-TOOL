#pragma once
#include"Reference.h"

// ReferenceDlg 对话框

class ReferenceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReferenceDlg)

public:
	ReferenceDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ReferenceDlg();
	BOOL OnInitDialog();
	void RFDlg_setreference();
	Reference showreference();
	void RFDlg_addphenomenon(CString str);
private:
	CFont m_editFont;
	Reference rf;
	CString inputInitiator;
	CString inputReceiver;
	CString inputPhenomenon;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REQUIREMENTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio3();
	CListBox ListBox1;
	CString m_Initiator;
	CString m_Receiver;
	CString m_Phenomenon;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
};
