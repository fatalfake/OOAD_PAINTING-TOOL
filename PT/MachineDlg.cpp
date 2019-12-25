// MachineDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "PT.h"
#include "MachineDlg.h"
#include "afxdialogex.h"


// MachineDlg 对话框

IMPLEMENT_DYNAMIC(MachineDlg, CDialogEx)

MachineDlg::MachineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MACHINEDLG, pParent)
	, m_description(_T("Machine"))
	, m_shortname(_T("M"))
{
	Machine m = Machine();
	
}

MachineDlg::~MachineDlg()
{
}

BOOL MachineDlg::OnInitDialog()
{
	m_editFont.CreatePointFont(120, _T("Arial"));
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_STATIC1);	
	m_Edit->SetFont(&m_editFont);
	m_Edit = (CEdit *)GetDlgItem(IDC_STATIC2);
	m_Edit->SetFont(&m_editFont);

	UpdateData(false);
	return true;
}

void MachineDlg::Mdlg_setmachine()
{
	m.set_description(inputDescription);
	m.set_shortname(inputShortnmae);

}

Machine MachineDlg::showmachine()
{
	return m;
}



void MachineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_description);
	DDX_Text(pDX, IDC_EDIT2, m_shortname);
}


BEGIN_MESSAGE_MAP(MachineDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &MachineDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &MachineDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &MachineDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// MachineDlg 消息处理程序


void MachineDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputDescription = m_description;
}


void MachineDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Mdlg_setmachine();
	
	CDialogEx::OnOK();
}


void MachineDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	inputShortnmae = m_shortname;
}
