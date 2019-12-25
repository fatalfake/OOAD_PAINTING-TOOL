// InterfaceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "PT.h"
#include "InterfaceDlg.h"
#include "afxdialogex.h"


// InterfaceDlg 对话框

IMPLEMENT_DYNAMIC(InterfaceDlg, CDialogEx)

InterfaceDlg::InterfaceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INTERFACEDLG, pParent)
	, m_Initiator(_T(""))
	, m_phenomenon(_T(""))
{

}

InterfaceDlg::~InterfaceDlg()
{
}

BOOL InterfaceDlg::OnInitDialog()
{
	m_editFont.CreatePointFont(120, _T("Arial"));
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_STATIC1);
	m_Edit->SetFont(&m_editFont);
	m_Edit = (CEdit *)GetDlgItem(IDC_STATIC2);
	m_Edit->SetFont(&m_editFont);
	m_Edit = (CEdit *)GetDlgItem(IDC_STATIC3);
	m_Edit->SetFont(&m_editFont);
	UpdateData(false);
	return true;
}

void InterfaceDlg::IDlg_setinterface()
{
	i.set_initiator(inputInitiator);
}

Interface InterfaceDlg::showinterface()
{
	return i;
}

void InterfaceDlg::IDlg_addphenomenon(CString str)
{
	i.add_phenomenon(str);
}

void InterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Initiator);
	DDX_Text(pDX, IDC_EDIT3, m_phenomenon);
	DDX_Control(pDX, IDC_LIST1, ListBox1);
}


BEGIN_MESSAGE_MAP(InterfaceDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &InterfaceDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &InterfaceDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO1, &InterfaceDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &InterfaceDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &InterfaceDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &InterfaceDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// InterfaceDlg 消息处理程序


void InterfaceDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputInitiator = m_Initiator;
}


void InterfaceDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputPhenomenon = m_phenomenon;
}


void InterfaceDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	i.set_type(event);
}


void InterfaceDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	i.set_type(value);
}


void InterfaceDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	i.set_type(state);
}


void InterfaceDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString t_str = inputInitiator +"!{"+ inputPhenomenon +'}';
	IDlg_setinterface();
	i.add_phenomenon(t_str);
	ListBox1.AddString(t_str);
}
