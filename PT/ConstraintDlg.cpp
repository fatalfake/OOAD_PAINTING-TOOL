// ConstraintDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "PT.h"
#include "ConstraintDlg.h"
#include "afxdialogex.h"


// ConstraintDlg 对话框

IMPLEMENT_DYNAMIC(ConstraintDlg, CDialogEx)

ConstraintDlg::ConstraintDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONSTRAINTDLG, pParent)
	, m_Initiator(_T(""))
	, m_Receiver(_T(""))
	, m_Phenomenon(_T(""))
{

}

ConstraintDlg::~ConstraintDlg()
{
}

BOOL ConstraintDlg::OnInitDialog()
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

void ConstraintDlg::CDlg_setconstraint()
{
	c.set_initiator(inputInitiator);
	c.set_receiver(inputReceiver);
}

Constraint ConstraintDlg::showconstraint()
{
	return c;
}

void ConstraintDlg::CDlg_addphenomenon(CString str)
{
	c.add_phenomenon(str);
}

void ConstraintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListBox1);
	DDX_Text(pDX, IDC_EDIT1, m_Initiator);
	DDX_Text(pDX, IDC_EDIT2, m_Receiver);
	DDX_Text(pDX, IDC_EDIT3, m_Phenomenon);
}


BEGIN_MESSAGE_MAP(ConstraintDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &ConstraintDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &ConstraintDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &ConstraintDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO1, &ConstraintDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &ConstraintDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &ConstraintDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &ConstraintDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ConstraintDlg 消息处理程序


void ConstraintDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputInitiator = m_Initiator;
}


void ConstraintDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputReceiver = m_Receiver;
}


void ConstraintDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputPhenomenon = m_Phenomenon;
}


void ConstraintDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	c.set_type(event);
}


void ConstraintDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	c.set_type(state);
}


void ConstraintDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	c.set_type(value);
}


void ConstraintDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString t_str = inputInitiator + "!{" + inputPhenomenon + '}';
	CDlg_setconstraint();
	c.add_phenomenon(t_str);
	ListBox1.AddString(t_str);
}
