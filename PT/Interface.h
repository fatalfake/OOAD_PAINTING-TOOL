#pragma once
#include<vector>
#include"Type.h"

class Interface
{
public:
	Interface();
	~Interface();
	int pvec_size();
	void set_position(int a, int b, int c, int d);
	void set_initiator(CString str);
	void set_type(Type i);
	void add_phenomenon(CString p);
	std::vector<CString> show_pvec();
	CString show_initiator();
private:
	CString Initiator;
	CString phenomenon;
	Type t;
	std::vector<CString> pvec;
	int x1;
	int y1;
	int x2;
	int y2;
};

