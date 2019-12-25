#pragma once
enum PhysicalProperty
{
	GivenDomain, DesignDomain
};
enum DomainType 
{
	Casual, Biddable, Lexical
};
class Domain
{
public:
	Domain();
	~Domain();
	void set_description(CString str);
	void set_shortname(CString str);
	void set_physicalproperty(int v);
	void set_domaintype(int v);
	CString show_shortname();
	void set_position(int a, int b, int c, int d);
	int show_type();
	int show_property();
	int left_link_point_x();
	int left_link_point_y();
	int right_link_point_x();
	int right_link_point_y();
private:
	CString Description;
	CString ShortName;
	PhysicalProperty pp;
	DomainType dt;
	int x1;
	int y1;
	int x2;
	int y2;
	//int no;

};

