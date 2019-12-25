// ReferenceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "PT.h"
#include "ReferenceDlg.h"
#include "afxdialogex.h"


// ReferenceDlg 对话框

IMPLEMENT_DYNAMIC(ReferenceDlg, CDialogEx)

ReferenceDlg::ReferenceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REQUIREMENTDLG, pParent)
	, m_Initiator(_T(""))
	, m_Receiver(_T(""))
	, m_Phenomenon(_T(""))
{

}

ReferenceDlg::~ReferenceDlg()
{
}

BOOL ReferenceDlg::OnInitDialog()
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

void ReferenceDlg::RFDlg_setreference()
{
	rf.set_initiator(inputInitiator);
	rf.set_receiver(inputReceiver);
}

Reference ReferenceDlg::showreference()
{
	return rf;
}

void ReferenceDlg::RFDlg_addphenomenon(CString str)
{
	rf.add_phenomenon(str);
}

void ReferenceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListBox1);
	DDX_Text(pDX, IDC_EDIT1, m_Initiator);
	DDX_Text(pDX, IDC_EDIT2, m_Receiver);
	DDX_Text(pDX, IDC_EDIT3, m_Phenomenon);
}


BEGIN_MESSAGE_MAP(ReferenceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO3, &ReferenceDlg::OnBnClickedRadio3)
	ON_EN_CHANGE(IDC_EDIT1, &ReferenceDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &ReferenceDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &ReferenceDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO1, &ReferenceDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &ReferenceDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &ReferenceDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ReferenceDlg 消息处理程序


void ReferenceDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	rf.set_type(value);
}


void ReferenceDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputInitiator = m_Initiator;
}


void ReferenceDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputReceiver = m_Receiver;
}


void ReferenceDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputPhenomenon = m_Phenomenon;
}


void ReferenceDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	rf.set_type(event);
}


void ReferenceDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	rf.set_type(state);
}





void ReferenceDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString t_str = inputInitiator + "!{" + inputPhenomenon + '}';
	RFDlg_setreference();
	rf.add_phenomenon(t_str);
	ListBox1.AddString(t_str);
}
