#pragma once
#include"Requirement.h"


// RequirementDlg 对话框

class RequirementDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RequirementDlg)

public:
	RequirementDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RequirementDlg();
	BOOL OnInitDialog();
	void RQDlg_setrequirement();
	Requirement showrequirement();
private:
	CFont m_editFont;
	Requirement rq;
	CString inputDescription = _T("Requirement");

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REFERENCEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
public:
	CString m_description;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
};
