#pragma once
#include"Interface.h"

// InterfaceDlg 对话框

class InterfaceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InterfaceDlg)

public:
	InterfaceDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~InterfaceDlg();
	BOOL OnInitDialog();
	void IDlg_setinterface();
	Interface showinterface();
	void IDlg_addphenomenon(CString str);
private:
	CFont m_editFont;
	Interface i;
	CString inputInitiator;
	CString inputPhenomenon;
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTERFACEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_Initiator;
	afx_msg void OnEnChangeEdit2();
	CString m_phenomenon;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton1();
	CListBox ListBox1;
};
