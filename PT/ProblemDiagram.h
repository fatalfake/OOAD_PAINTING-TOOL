#pragma once
#include"Constraint.h"
#include"Reference.h"
#include"Requirement.h"
#include<vector>

class ProblemDiagram
{
public:
	ProblemDiagram();
	~ProblemDiagram();
	bool add_requirement(Requirement* rqptr);
	bool add_reference(Reference* rfptr);
	bool add_constraint(Constraint* cptr);
	bool check_pblDgm();
	std::vector<Requirement> show_rqvec();
private:
	
	std::vector<Requirement> rqvec;
	std::vector<Reference> rfvec;
	std::vector<Constraint> cvec;
};

