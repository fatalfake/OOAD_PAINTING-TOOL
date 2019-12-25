#include "stdafx.h"
#include "Domain.h"


Domain::Domain()
{
	
	//CString str;
	//str.Format(_T("%d"), no);
	Description = CString("problemDomain");//+str;
	ShortName = CString("PD");//+str;
	pp = GivenDomain;
	dt = Casual;
}


Domain::~Domain()
{
}

void Domain::set_description(CString str)
{
	Description = str;
}

void Domain::set_shortname(CString str)
{
	ShortName = str;
}

void Domain::set_physicalproperty(int v)
{
	pp = (PhysicalProperty)v;
}

void Domain::set_domaintype(int v)
{
	dt = (DomainType)v;
}

CString Domain::show_shortname()
{
	return ShortName;
}

void Domain::set_position(int a, int b, int c, int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}

int Domain::show_type()
{
	if (dt == Casual)
		return 1;
	else if (dt == Biddable)
		return 2;
	else if (dt == Lexical)
		return 3;
}

int Domain::show_property()
{
	if (pp == GivenDomain)
		return 1;
	if (pp == DesignDomain)
		return 2;
}

int Domain::left_link_point_x()
{
	return x1;
}

int Domain::left_link_point_y()
{
	return (y1+y2)/2;
}

int Domain::right_link_point_x()
{
	return x2;
}

int Domain::right_link_point_y()
{
	return (y1+y2)/2;
}
