#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
{
	t = event;
	pvec.clear();
}


Interface::~Interface()
{
}

int Interface::pvec_size()
{
	return pvec.size();
}

void Interface::set_position(int a, int b, int c, int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}

void Interface::set_initiator(CString str)
{
	Initiator = str;
}

void Interface::set_type(Type i)
{
	t = i;
}

void Interface::add_phenomenon(CString p)
{
	pvec.push_back(p);
}

std::vector<CString> Interface::show_pvec()
{
	return pvec;
}

CString Interface::show_initiator()
{
	return Initiator;
}


