// DomainDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "PT.h"
#include "DomainDlg.h"
#include "afxdialogex.h"


// DomainDlg 对话框

IMPLEMENT_DYNAMIC(DomainDlg, CDialogEx)

DomainDlg::DomainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DOMAINDLG, pParent)
	, m_description(_T("ProblemDomain"))
	, m_shortname(_T("PD"))
{
	d = Domain();
}

DomainDlg::~DomainDlg()
{
}

BOOL DomainDlg::OnInitDialog()
{
	m_editFont.CreatePointFont(120, _T("Arial"));
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_STATIC1);
	m_Edit->SetFont(&m_editFont);
	m_Edit = (CEdit *)GetDlgItem(IDC_STATIC2);
	m_Edit->SetFont(&m_editFont);
	m_Edit = (CEdit *)GetDlgItem(IDC_STATIC3);
	m_Edit->SetFont(&m_editFont);
	m_Edit = (CEdit *)GetDlgItem(IDC_STATIC4);
	m_Edit->SetFont(&m_editFont);

	UpdateData(false);
	return true;
}

void DomainDlg::Ddlg_setdomain()
{
	d.set_description(inputDescription);
	d.set_shortname(inputShortnmae);
	d.set_domaintype(inputDomainType);
	d.set_physicalproperty(inputPhysicalproperty);

}

Domain DomainDlg::showdomain()
{
	return d;
}

void DomainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_description);
	DDX_Text(pDX, IDC_EDIT2, m_shortname);

	
}


BEGIN_MESSAGE_MAP(DomainDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DomainDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &DomainDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &DomainDlg::OnEnChangeEdit2)
	
	
	ON_BN_CLICKED(IDC_CHECK2, &DomainDlg::OnBnClickedCheck2)
	
	ON_BN_CLICKED(IDC_CHECK1, &DomainDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK4, &DomainDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &DomainDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &DomainDlg::OnBnClickedCheck6)
END_MESSAGE_MAP()


// DomainDlg 消息处理程序


void DomainDlg::OnBnClickedOk()
{
	Ddlg_setdomain();
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void DomainDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputDescription = m_description;
}


void DomainDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputShortnmae = m_shortname;
}










void DomainDlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	inputPhysicalproperty = 1;
}





void DomainDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	inputPhysicalproperty = 0;
}


void DomainDlg::OnBnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
	inputDomainType = 0;
}


void DomainDlg::OnBnClickedCheck5()
{
	// TODO: 在此添加控件通知处理程序代码
	inputDomainType = 1;
}


void DomainDlg::OnBnClickedCheck6()
{
	// TODO: 在此添加控件通知处理程序代码
	inputDomainType = 2;
}
