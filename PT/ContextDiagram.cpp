#include "stdafx.h"
#include "ContextDiagram.h"


ContextDiagram::ContextDiagram()
{
	mlist.clear();
	dvec.clear();
	ilist.clear();
}


ContextDiagram::~ContextDiagram()
{
}

bool ContextDiagram::add_machine(Machine * mptr)
{
	if (mptr != NULL)
	{
		mlist.push_back(*mptr);
		return true;
	}
	else
		return false;
}

bool ContextDiagram::add_domain(Domain * dptr)
{
	if (dptr != NULL)
	{
		dvec.push_back(*dptr);
		return true;
	}
	else
		return false;
}

bool ContextDiagram::add_interface(Interface * iptr)
{
	if (iptr != NULL)
	{
		ilist.push_back(*iptr);
		return true;
	}
	else
		return false;
}

bool ContextDiagram::check_conDgm()
{
	if (mlist.size() > 1)
		return false;
	if (dvec.size() == 0)
		return false;
	std::vector<Interface>::iterator iter;
	for (iter = ilist.begin(); iter != ilist.end(); ++iter)
	{
		if (iter->pvec_size() == 0)
			return false;
	}
	return true;
}

std::list<Machine> ContextDiagram::show_mlist()
{
	return mlist;
}

std::vector<Domain> ContextDiagram::show_dvec()
{
	return dvec;
}
