//3-D coordinates - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "tlbx.hpp"
#include "weiss3.hpp"

using namespace std;

//
crd3::crd3(const arr::darr1 &A)
{
	if(A.size()==3)
	{
		for(size_t i=0;i<3;++i)
			_p[i]=A(i);
	}
	else
		arr::err=-1;
}

//
crd3::operator arr::darr1() const
{
	arr::darr1 d(3);
	d(0)=_x;d(1)=_y;d(2)=_z;
	return d;
}

//
double& crd3::operator()(const size_t i)
{
	if(i<3)
		return _p[i];
	else
		arr::err=-1;
	return _p[2];
}

//
double const& crd3::operator()(const size_t i) const
{
	if(i<3)
		return _p[i];
	else
		arr::err=-1;
	return _p[2];
}

//friend
ostream& operator<<(ostream &os,const crd3 &C)
{
	os<<"("<<C.x()<<","<<C.y()<<","<<C.z()<<")";
	return os;
}

std::size_t crd3::hash() const
{
	std::size_t h1 = std::hash<double>{}(_x);
	std::size_t h2 = std::hash<double>{}(_y);
	std::size_t h3 = std::hash<double>{}(_z);
	return h1 ^ (h2 << 1) ^ (h3 << 2);
};
