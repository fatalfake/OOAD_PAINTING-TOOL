
// PTView.cpp: CPTView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PT.h"
#endif

#include "PTDoc.h"
#include "PTView.h"
#include"Constraint.h"
#include"ContextDiagram.h"
#include"Domain.h"
#include"Interface.h"
#include"Machine.h"
#include"MachineDlg.h"
#include"DomainDlg.h"
#include"ProblemDiagram.h"
#include"Reference.h"
#include"Requirement.h"
#include"RequirementDlg.h"
#include"InterfaceDlg.h"
#include"ReferenceDlg.h"
#include"ConstraintDlg.h"
#include<list>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _UNICODE
typedef const wchar_t* LPCTSTR;
#else
typedef const char* LPCTSTR;
#endif

// CPTView
CPen SolidPen(BS_SOLID, 1, RGB(0, 0, 0));
CPen DotPen(PS_DASH, 1, RGB(0, 0, 0));

CPoint m_ptOrigin, m_ptEnd;

int d_gap = 0;
int rq_gap = 0;
int i_gap = 0;
int rf_gap = 0;
int c_gap = 0;


IMPLEMENT_DYNCREATE(CPTView, CFormView)

BEGIN_MESSAGE_MAP(CPTView, CFormView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CPTView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPTView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPTView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPTView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPTView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPTView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CPTView::OnBnClickedButton7)
	ON_COMMAND(ID_FILE_NEW, &CPTView::OnFileNew)
END_MESSAGE_MAP()

// CPTView 构造/析构

CPTView::CPTView() noexcept
	: CFormView(IDD_PT_FORM)
{
	// TODO: 在此处添加构造代码
	cd = ContextDiagram();
	pd = ProblemDiagram();
}

CPTView::~CPTView()
{
}

void CPTView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Details);
}

BOOL CPTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CPTView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CPTView 打印

BOOL CPTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CPTView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 在此处添加自定义打印代码
}


// CPTView 诊断

#ifdef _DEBUG
void CPTView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPTView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPTDoc* CPTView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPTDoc)));
	return (CPTDoc*)m_pDocument;
}
#endif //_DEBUG


// CPTView 消息处理程序


void CPTView::OnBnClickedButton1()
{
	MachineDlg mdlg;
	// TODO: 在此添加控件通知处理程序代码
	mdlg.DoModal();
	Machine t = mdlg.showmachine();
	DrawMachine(t);
	cd.add_machine(&t);
}


void CPTView::OnBnClickedButton2()
{
	DomainDlg ddlg;
	// TODO: 在此添加控件通知处理程序代码
	ddlg.DoModal();
	Domain t = ddlg.showdomain();
	DrawDomain(t);
	cd.add_domain(&t);
}


void CPTView::OnBnClickedButton3()
{
	RequirementDlg rqdlg;
	rqdlg.DoModal();
	Requirement t = rqdlg.showrequirement();
	// TODO: 在此添加控件通知处理程序代码
	DrawRequirement(t);
	pd.add_requirement(&t);
}


void CPTView::OnBnClickedButton4()
{
	InterfaceDlg idlg;
	idlg.DoModal();
	Interface t = idlg.showinterface();
	
	DrawInterface(t);
	cd.add_interface(&t);
	

	std::vector<CString> t_vec = t.show_pvec();
	int n = t_vec.size();
	for (int i = 0; i < n; i++)
	{
		Details.AddString(t_vec[i]);
	}
}


void CPTView::OnBnClickedButton5()
{
	ReferenceDlg rfdlg;
	rfdlg.DoModal();
	Reference t = rfdlg.showreference();

	DrawReference(t);
	pd.add_reference(&t);
	

	std::vector<CString> t_vec = t.show_pvec();
	int n = t_vec.size();
	for (int i = 0; i < n; i++)
	{
		Details.AddString(t_vec[i]);
	}
}


void CPTView::OnBnClickedButton6()
{
	ConstraintDlg cdlg;
	cdlg.DoModal();
	Constraint t = cdlg.showconstraint();
	
	DrawConstraint(t);
	pd.add_constraint(&t);
	

	std::vector<CString> t_vec = t.show_pvec();
	int n = t_vec.size();
	for (int i = 0; i < n; i++)
	{
		Details.AddString(t_vec[i]);
	}
}


void CPTView::OnBnClickedButton7()
{
	CString str("1234");
	if (pd.check_pblDgm() && cd.check_conDgm())
		str = "The diagram is correct.";
	else if (pd.check_pblDgm())
		str = "The context diagram is wrong.";
	else if (cd.check_conDgm())
		str = "The problem diagram is wrong.";
	else
		str = "Both the context diagram and the problem diagram are wrong.";
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(str);
}

void CPTView::DrawMachine(Machine &m)
{
	CRect rect;
	CWnd *pDraw = GetDlgItem(IDC_DRAW);
	pDraw->GetClientRect(rect);
	int m_Points[4];

	CDC *pDC = pDraw->GetDC();

	CRect t_rect;
	CString str;

	pDC->SelectStockObject(NULL_BRUSH);
	pDC->SelectObject(&SolidPen);
	srand((unsigned)time(NULL));
	m_Points[0] = (rand() % 21) + 70;
	m_Points[1] = (rand() % 21) + 290;
	m_Points[2] = m_Points[0] + 100;
	m_Points[3] = m_Points[1] + 50;
	pDC->Rectangle(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	pDC->Rectangle(m_Points[0] - 8, m_Points[1], m_Points[2] - 100, m_Points[3]);
	pDC->Rectangle(m_Points[0] - 16, m_Points[1], m_Points[2] - 108, m_Points[3]);
	t_rect = CRect(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	m.set_position(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	str = m.show_shortname();
	pDC->DrawText(str, -1, t_rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
}

void CPTView::DrawDomain(Domain &d)
{
	CRect rect;
	CWnd *pDraw = GetDlgItem(IDC_DRAW);
	pDraw->GetClientRect(rect);
	int m_Points[4];


	CDC *pDC = pDraw->GetDC();

	CRect t_rect;
	CString str;

	pDC->SelectStockObject(NULL_BRUSH);
	pDC->SelectObject(&SolidPen);
	srand((unsigned)time(NULL));
	m_Points[0] = (rand() % 21) + 470;
	m_Points[1] = (rand() % 21) + 60 + d_gap * 160;
	m_Points[2] = m_Points[0] + 100;
	m_Points[3] = m_Points[1] + 50;
	pDC->Rectangle(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	t_rect = CRect(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);

	int pp = d.show_property();
	if (pp == 2)
		pDC->Rectangle(m_Points[0] - 8, m_Points[1], m_Points[2] - 100, m_Points[3]);

	int t_g;
	for (t_g = 0; t_g < d_gap; ++t_g);
	d_gap++;
	str = d.show_shortname();
	d.set_position(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	pDC->DrawText(str, -1, t_rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

	CString str1;
	int dt = d.show_type();
	if (dt == 1)
		str1 = _T('C');
	if (dt == 2)
		str1 = _T('B');
	if (dt == 3)
		str1 = _T('X');
	CRect t_rect1;
	t_rect1 = CRect(m_Points[0] + 80, m_Points[1] + 30, m_Points[2], m_Points[3]);
	pDC->DrawText(str1, -1, t_rect1, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
}

void CPTView::DrawRequirement(Requirement &rq)
{
	CRect rect;
	CWnd *pDraw = GetDlgItem(IDC_DRAW);
	pDraw->GetClientRect(rect);
	int m_Points[4];


	CDC *pDC = pDraw->GetDC();

	CRect t_rect;
	CString str;

	pDC->SelectStockObject(NULL_BRUSH);
	pDC->SelectObject(&DotPen);
	srand((unsigned)time(NULL));
	m_Points[0] = (rand() % 21) + 870;
	m_Points[1] = (rand() % 21) + 60 + rq_gap * 160;
	m_Points[2] = m_Points[0] + 100;
	m_Points[3] = m_Points[1] + 50;
	pDC->Ellipse(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	t_rect = CRect(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	int t_g1;
	for (t_g1 = 0; t_g1 < rq_gap; ++t_g1);
	rq_gap++;
	rq.set_position(m_Points[0], m_Points[1], m_Points[2], m_Points[3]);
	str = rq.show_description();
	pDC->DrawText(str, -1, t_rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
}


void CPTView::DrawInterface(Interface &i)
{
	CRect rect;
	CWnd *pDraw = GetDlgItem(IDC_DRAW);
	pDraw->GetClientRect(rect);

	CDC *pDC = pDraw->GetDC();
	pDC->SelectObject(&SolidPen);

	CString str = i.show_initiator();

	int id ;
	std::vector<Domain> t_vd;
	t_vd = cd.show_dvec();
	id = 0;
	CString str1 = t_vd[id].show_shortname();
	for (; str1 != str;)
	{
		id++;
		if (id == t_vd.size() - 1) break;
		str1 = t_vd[id].show_shortname();
	}
	int xx = t_vd[id].left_link_point_x();
	int yy = t_vd[id].left_link_point_y();

	int s_x, s_y;
	Machine t_m = *(cd.show_mlist().begin());
	s_x = t_m.link_point_x();
	s_y = t_m.link_point_y();

	
	pDC->MoveTo(s_x, s_y);
	pDC->LineTo(xx, yy);

	
	CRect t_rect;
	t_rect = CRect(s_x, s_y, xx+100, yy+50);
	
	char t_ch = 'a' + i_gap;
	CString str2(t_ch);

	str2 = str2 + ':';
	i_gap++;

	int k = i.show_pvec().size();
	for (int l = 0; k!=0; k--)
	{
		str2 = str2 + i.show_pvec()[l];
		l++;
	}
	pDC->DrawText(str2, -1, t_rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
	
}

void CPTView::DrawReference(Reference &rf)
{
	CRect rect;
	CWnd *pDraw = GetDlgItem(IDC_DRAW);
	pDraw->GetClientRect(rect);

	CDC *pDC = pDraw->GetDC();
	pDC->SelectObject(&DotPen);

	CString str = rf.show_initiator();
	CString str0 = rf.show_receiver();

	int d_id = 0;
	std::vector<Domain> t_vd;
	t_vd = cd.show_dvec();
	CString str1 = t_vd[d_id].show_shortname();
	for (; str1 != str; )
	{
		d_id++;
		if (d_id == t_vd.size() - 1) break;
		str1 = t_vd[d_id].show_shortname();
	}
	int s_x = t_vd[d_id].right_link_point_x();
	int s_y = t_vd[d_id].right_link_point_y();

	int rq_id = 0;
	std::vector<Requirement> t_vrq;
	t_vrq = pd.show_rqvec();
	CString str3 = t_vrq[rq_id].show_description();
	for (; str3 != str0; )
	{
		rq_id++;
		if (rq_id == t_vrq.size() - 1)break;
		str3 = t_vrq[rq_id].show_description();
	}
	int xx = t_vrq[rq_id].link_point_x();
	int yy = t_vrq[rq_id].link_point_y();


	pDC->MoveTo(s_x, s_y);
	pDC->LineTo(xx, yy);


	CRect t_rect;
	t_rect = CRect(s_x, s_y, xx + 100, yy + 50);

	char t_ch = 'a' + i_gap + rf_gap;
	CString str4(t_ch);

	str4 = str4 + ':';
	rf_gap++;

	int k = rf.show_pvec().size();
	for (int l = 0; k != 0; k--)
	{
		str4 = str4 + rf.show_pvec()[l];
		l++;
	}
	pDC->DrawText(str4, -1, t_rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
}

void CPTView::DrawConstraint(Constraint & c)
{
	CRect rect;
	CWnd *pDraw = GetDlgItem(IDC_DRAW);
	pDraw->GetClientRect(rect);

	CDC *pDC = pDraw->GetDC();
	pDC->SelectObject(&DotPen);

	CString str = c.show_initiator();
	CString str0 = c.show_receiver();

	int d_id = 0;
	std::vector<Domain> t_vd;
	t_vd = cd.show_dvec();
	CString str1 = t_vd[d_id].show_shortname();
	for (; str1 != str; )
	{
		d_id++;
		if (d_id == t_vd.size() - 1) break;
		str1 = t_vd[d_id].show_shortname();
	}
	int s_x = t_vd[d_id].right_link_point_x();
	int s_y = t_vd[d_id].right_link_point_y();

	int rq_id = 0;
	std::vector<Requirement> t_vrq;
	t_vrq = pd.show_rqvec();
	CString str3 = t_vrq[rq_id].show_description();
	for (; str3 != str0; )
	{
		rq_id++;
		if (rq_id == t_vrq.size() - 1)break;
		str3 = t_vrq[rq_id].show_description();
	}
	int xx = t_vrq[rq_id].link_point_x();
	int yy = t_vrq[rq_id].link_point_y();


	pDC->MoveTo(s_x, s_y);
	pDC->LineTo(xx, yy);

	pDC->SelectObject(SolidPen);

	

	double theta = 5* (3.1415926 / 6);//转换为弧度
	double Px, Py, P1x, P1y, P2x, P2y;
	//以P2为原点得到向量P2P1（P）
	Px = abs(s_x - xx);
	Py = abs(s_y - yy);
	//向量P旋转theta角得到向量P1
	P1x = Px * cos(theta) - Py * sin(theta);
	P1y = Px * sin(theta) + Py * cos(theta);
	//向量P旋转-theta角得到向量P2
	P2x = Px * cos(-theta) - Py * sin(-theta);
	P2y = Px * sin(-theta) + Py * cos(-theta);
	double x1, x2;
	x1 = sqrt(P1x*P1x + P1y * P1y);
	P1x = P1x * 15 / x1;
	P1y = P1y * 15 / x1;
	x2 = sqrt(P2x*P2x + P2y * P2y);
	P2x = P2x * 15 / x2;
	P2y = P2y * 15 / x2;
	P1x = P1x + xx;
	P1y = P1y + yy;
	P2x = P2x + xx;
	P2y = P2y + yy;

	pDC->MoveTo(xx, yy);
	pDC->LineTo(P1x, P1y);
	pDC->MoveTo(xx, yy);
	pDC->LineTo(P2x, P2y);


	CRect t_rect;
	t_rect = CRect(s_x, s_y, xx + 100, yy + 50);

	char t_ch = 'a' + i_gap + rf_gap + c_gap;
	CString str4(t_ch);

	str4 = str4 + ':';
	c_gap++;

	int k = c.show_pvec().size();
	for (int l = 0; k != 0; k--)
	{
		str4 = str4 + c.show_pvec()[l];
		l++;
	}
	pDC->DrawText(str4, -1, t_rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
}





void CPTView::OnFileNew()
{
	// TODO: 在此添加命令处理程序代码
	d_gap = 0;
	rq_gap = 0;
	i_gap = 0;
	rf_gap = 0;
	c_gap = 0;
	CPTView::CPTView();
	Invalidate();
}
