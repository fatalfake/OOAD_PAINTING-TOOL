#pragma once
class Machine
{
public:
	Machine();
	~Machine();
	void set_description(CString str);
	void set_shortname(CString str);
	CString show_shortname();
	void set_position(int a, int b, int c, int d);
	int link_point_x();
	int link_point_y();
private:
	CString Description;
	CString ShortName;
	int x1;
	int y1;
	int x2;
	int y2;
};

