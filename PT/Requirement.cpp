#include "stdafx.h"
#include "Requirement.h"


Requirement::Requirement()
{
}


Requirement::~Requirement()
{
}

void Requirement::set_description(CString str)
{
	Description = str;
}

CString Requirement::show_description()
{
	return Description;
}

void Requirement::set_position(int a, int b, int c, int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}

int Requirement::link_point_x()
{
	return x1;
}

int Requirement::link_point_y()
{
	return (y1+y2)/2;
}
