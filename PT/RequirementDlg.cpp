// RequirementDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "PT.h"
#include "RequirementDlg.h"
#include "afxdialogex.h"


// RequirementDlg 对话框

IMPLEMENT_DYNAMIC(RequirementDlg, CDialogEx)

RequirementDlg::RequirementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REFERENCEDLG, pParent)
	, m_description(_T(""))
{

}

RequirementDlg::~RequirementDlg()
{
}

BOOL RequirementDlg::OnInitDialog()
{
	m_editFont.CreatePointFont(120, _T("Arial"));
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_STATIC);
	m_Edit->SetFont(&m_editFont);
	
	//UpdateData(false);
	return true;
}

void RequirementDlg::RQDlg_setrequirement()
{
	rq.set_description(inputDescription);
}

Requirement RequirementDlg::showrequirement()
{
	return rq;
}

void RequirementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_description);
}


BEGIN_MESSAGE_MAP(RequirementDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &RequirementDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &RequirementDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// RequirementDlg 消息处理程序


void RequirementDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputDescription = m_description;
}


void RequirementDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	RQDlg_setrequirement();
	CDialogEx::OnOK();
}
