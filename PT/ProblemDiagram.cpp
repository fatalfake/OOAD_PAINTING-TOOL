#include "stdafx.h"
#include "ProblemDiagram.h"


ProblemDiagram::ProblemDiagram()
{
	rqvec.clear();
	rfvec.clear();
	cvec.clear();
}


ProblemDiagram::~ProblemDiagram()
{
}

bool ProblemDiagram::add_requirement(Requirement* rqptr)
{
	if (rqptr != NULL)
	{
		rqvec.push_back(*rqptr);
		return true;
	}
	else
		return false;
}

bool ProblemDiagram::add_reference(Reference * rfptr)
{
	if (rfptr != NULL)
	{
		rfvec.push_back(*rfptr);
		return true;
	}
	else
		return false;
}

bool ProblemDiagram::add_constraint(Constraint * cptr)
{
	if (cptr != NULL)
	{
		cvec.push_back(*cptr);
		return true;
	}
	else
		return false;
}

bool ProblemDiagram::check_pblDgm()
{
	if (rqvec.size() == 0)
		return false;
	if (cvec.size() == 0)
		return false;
	std::vector<Reference>::iterator iter1;
	std::vector<Constraint>::iterator iter2;
	for (iter1 = rfvec.begin(); iter1 != rfvec.end(); ++iter1)
	{
		if (iter1->pvec_size() == 0)
			return false;
	}
	for (iter2 = cvec.begin(); iter2 != cvec.end(); ++iter2)
	{
		if (iter2->pvec_size() == 0)
			return false;
	}
	return true;
}

std::vector<Requirement> ProblemDiagram::show_rqvec()
{
	return rqvec;
}
