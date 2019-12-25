#pragma once
class Requirement
{
public:
	Requirement();
	~Requirement();
	bool isIsolate();
	void set_description(CString str);
	CString show_description();
	void set_position(int a, int b, int c, int d);
	int link_point_x();
	int link_point_y();
private:
	CString Description;
	int x1;
	int y1;
	int x2;
	int y2;
	
};

