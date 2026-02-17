//3-D coordinates - P. Ahrenkiel

#include <cstdlib>

#include "dbl1.hpp"
#include "dbl1.hpp"
#include "error.hpp"

#include "crd2.hpp"

crd2::crd2(double x,double y):_x(x),_y(y){}
crd2::crd2(const double x[2]):_x(x[0]),_y(x[1]){}

crd2::crd2(const arr::dbl1 &A)
{
	for(size_t i=0;i<2;++i)
		_p[i]=A(i);
}

crd2::operator arr::dbl1() const
{
	arr::dbl1 d(2);
	d(0)=_x;d(1)=_y;
	return d;
}

double& crd2::operator()(const size_t i)
{
	if(i<2)
		return _p[i];
	else
		arr::err=-1;
	return _p[1];
}

double const& crd2::operator()(const size_t i) const
{
	if(i<2)
		return _p[i];
	else
		arr::err=-1;
	return _p[1];
}

crd2 crd2::operator+(){return *this;}
crd2 crd2::operator-(){return crd2(-_x,-_y);}

crd2 const crd2::operator+() const{return *this;}
crd2 const crd2::operator-() const{return crd2(-_x,-_y);}

crd2 crd2::operator+(const crd2 &c) const{return crd2(_x+c._x,_y+c._y);}
crd2 crd2::operator-(const crd2 &c) const{return crd2(_x-c._x,_y-c._y);}

crd2 crd2::operator+=(const crd2 &c){return *this=(*this)+c;}
crd2 crd2::operator-=(const crd2 &c){return *this=(*this)-c;}
crd2 crd2::operator*=(double x){return *this=x*(*this);}
crd2 crd2::operator/=(double x){return *this=(*this)/x;}
bool crd2::operator==(const crd2 &c) const{return (_x==c._x)&&(_y==c._y);}
bool crd2::operator!=(const crd2 &c) const{return !((*this)==c);}

crd2 operator*(double x,const crd2 &c){return crd2(x*c._x,x*c._y);}
crd2 crd2::operator/(double x) const{return crd2(_x/x,_y/x);}

double crd2::sqrlen() const{return _x*_x+_y*_y;}
double crd2::len() const{return sqrt(sqrlen());}

double& crd2::x(){return _x;}
double& crd2::y(){return _y;}

double const& crd2::x() const{return _x;}
double const& crd2::y() const{return _y;}

//friend
std::ostream& operator<<(std::ostream &os,const crd2 &C)
{
	os<<"("<<C.x()<<","<<C.y()<<")";
	return os;
}
