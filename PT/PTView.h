
// PTView.h: CPTView 类的接口
//

#pragma once
#include"Constraint.h"
#include"ContextDiagram.h"
#include"Domain.h"
#include"Interface.h"
#include"Machine.h"
#include"MachineDlg.h"
#include"ProblemDiagram.h"
#include"Reference.h"
#include"Requirement.h"


class CPTView : public CFormView
{
protected: // 仅从序列化创建
	CPTView() noexcept;
	DECLARE_DYNCREATE(CPTView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PT_FORM };
#endif

// 特性
public:
	CPTDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	void DrawMachine(Machine &m);
	void DrawDomain(Domain &d);
	void DrawRequirement(Requirement &rq);
	void DrawInterface(Interface &i);
	void DrawReference(Reference &rf);
	void DrawConstraint(Constraint &c);

private:
	ContextDiagram cd;
	ProblemDiagram pd;


public:
	afx_msg void OnFileNew();
	CListBox Details;
};

#ifndef _DEBUG  // PTView.cpp 中的调试版本
inline CPTDoc* CPTView::GetDocument() const
   { return reinterpret_cast<CPTDoc*>(m_pDocument); }
#endif

