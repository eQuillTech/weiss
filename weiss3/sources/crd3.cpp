//3-D coordinates - P. Ahrenkiel

#include <cstdlib>

#include "dbl1.hpp"
#include "crd3.hpp"

crd3::crd3(double x,double y,double z):_x(x),_y(y),_z(z){}
crd3::crd3(const double x[3]):_x(x[0]),_y(x[1]),_z(x[2]){}

crd3::crd3(const arr::dbl1 &A)
{
	for(std::size_t i=0;i<3;++i)
		_p[i]=A(i);
}

crd3::operator arr::dbl1() const
{
	arr::dbl1 d(3);
	d(0)=_x;d(1)=_y;d(2)=_z;
	return d;
}

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
	return _p[2];
}

//friend
std::ostream& operator<<(std::ostream &os,const crd3 &C)
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

crd3 crd3::operator+() const{return *this;}
crd3 crd3::operator-() const{return crd3(-_x,-_y,-_z);}

crd3 crd3::operator+(const crd3 &c) const{return crd3(_x+c._x,_y+c._y,_z+c._z);}
crd3 crd3::operator-(const crd3 &c) const{return crd3(_x-c._x,_y-c._y,_z-c._z);}

crd3 crd3::operator+=(const crd3 &c){return *this=(*this)+c;}
crd3 crd3::operator-=(const crd3 &c){return *this=(*this)-c;}
crd3 crd3::operator*=(double x){return *this=x*(*this);}
crd3 crd3::operator/=(double x){return *this=(*this)/x;}
bool crd3::operator==(const crd3 &c) const{return (_x==c._x)&&(_y==c._y)&&(_z==c._z);}
bool crd3::operator!=(const crd3 &c) const{return !((*this)==c);}

crd3 operator*(double x,const crd3 &c){return crd3(x*c._x,x*c._y,x*c._z);}
crd3 crd3::operator/(double x) const{return crd3(_x/x,_y/x,_z/x);}

double crd3::sqrlen() const{return _x*_x+_y*_y+_z*_z;}
double crd3::len() const{return sqrt(sqrlen());}

double& crd3::x(){return _x;}
double& crd3::y(){return _y;}
double& crd3::z(){return _z;}

double const& crd3::x() const{return _x;}
double const& crd3::y() const{return _y;}
double const& crd3::z() const{return _z;}

