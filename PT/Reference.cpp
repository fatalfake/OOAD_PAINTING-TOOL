#include "stdafx.h"
#include "Reference.h"


Reference::Reference()
{
	pvec.clear();
}


Reference::~Reference()
{
}

int Reference::pvec_size()
{
	return pvec.size();
}

void Reference::set_position(int a, int b, int c, int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}

void Reference::set_initiator(CString str)
{
	Initiator = str;
}

void Reference::set_receiver(CString str)
{
	Receriver = str;
}

void Reference::set_type(Type i)
{
	t = i;
}

void Reference::add_phenomenon(CString p)
{
	pvec.push_back(p);
}

std::vector<CString> Reference::show_pvec()
{
	return pvec;
}

CString Reference::show_initiator()
{
	return Initiator;
}

CString Reference::show_receiver()
{
	return Receriver;
}

