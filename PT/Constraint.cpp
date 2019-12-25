#include "stdafx.h"
#include "Constraint.h"


Constraint::Constraint()
{
	pvec.clear();
}


Constraint::~Constraint()
{
}
int Constraint::pvec_size()
{
	return pvec.size();
}

void Constraint::set_position(int a, int b, int c, int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}

void Constraint::set_initiator(CString str)
{
	Initiator = str;
}

void Constraint::set_receiver(CString str)
{
	Receriver = str;
}

void Constraint::set_type(Type i)
{
	t = i;
}

void Constraint::add_phenomenon(CString p)
{
	pvec.push_back(p);
}

std::vector<CString> Constraint::show_pvec()
{
	return pvec;
}

CString Constraint::show_initiator()
{
	return Initiator;
}

CString Constraint::show_receiver()
{
	return Receriver;
}



