#include "stdafx.h"
#include "Machine.h"


Machine::Machine()
{
	Description = CString("machine");
	ShortName = CString("M");
}


Machine::~Machine()
{
}

void Machine::set_description(CString str)
{
	Description = str;
}

void Machine::set_shortname(CString str)
{
	ShortName = str;
}

CString Machine::show_shortname()
{
	return ShortName;
}

void Machine::set_position(int a, int b, int c, int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}

int Machine::link_point_x()
{
	return x2;
}

int Machine::link_point_y()
{
	return (y1+y2)/2;
}
