#pragma once
#include"Machine.h"

// MachineDlg 对话框

class MachineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MachineDlg)

public:
	MachineDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MachineDlg();
	BOOL OnInitDialog();
	void Mdlg_setmachine();
	Machine showmachine();
private:
	CFont m_editFont;
	Machine m;
	CString inputDescription = _T("Machine");
	CString inputShortnmae = _T("M");

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MACHINEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CString m_description;
	CString m_shortname;
	afx_msg void OnEnChangeEdit2();
};
