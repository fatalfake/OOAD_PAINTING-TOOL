#pragma once
#include"Domain.h"

// DomainDlg 对话框

class DomainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DomainDlg)

public:
	DomainDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DomainDlg();
	BOOL OnInitDialog();
	void Ddlg_setdomain();
	Domain showdomain();
private:
	CFont m_editFont;
	Domain d;
	CString inputDescription;
	CString inputShortnmae;
	int inputPhysicalproperty;
	int inputDomainType;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOMAINDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_description;
	CString m_shortname;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	
	
	
	afx_msg void OnBnClickedCheck2();
	
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
};
