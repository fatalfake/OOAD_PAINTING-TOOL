#pragma once
#include<list>
#include<vector>
#include"Machine.h"
#include"Domain.h"
#include"Interface.h"

class ContextDiagram
{
public:
	ContextDiagram();
	~ContextDiagram();
	bool add_machine(Machine* mptr);
	bool add_domain(Domain* dptr);
	bool add_interface(Interface* iptr);
	bool check_conDgm();
	std::list<Machine> show_mlist();
	std::vector<Domain> show_dvec();
private:
	
	std::list<Machine> mlist;
	std::vector<Domain> dvec;
	std::vector<Interface> ilist;
};

