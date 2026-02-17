//vectors - P. Ahrenkiel

#include <cstdlib>

#include "vtr2.hpp"

const vtr2 vtr2::zero(0.,0.);
const vtr2 vtr2::X(1.,0.);
const vtr2 vtr2::Y(0.,1.);

double vtr2::cross(const vtr2 &V) const
{
	return _x*V._y-_y*V._x;
}

std::ostream& operator<<(std::ostream &os,const vtr2 &V)
{
	os<<"("<<V.x()<<","<<V.y()<<")";
	return os;
}

vtr2::vtr2():crd2(){}
vtr2::vtr2(double x,double y):crd2(x,y){}
vtr2::vtr2(const double x[2]):crd2(x){}
vtr2::vtr2(const arr::dbl1 &A):crd2(A){}
vtr2::vtr2(const vtr2 &V):crd2(V){}

vtr2 vtr2::operator+() const{return *this;}
vtr2 vtr2::operator-() const{return vtr2(-_x,-_y);}

vtr2 vtr2::operator+(const vtr2 &V) const{return vtr2(_x+V.x(),_y+V.y());}
vtr2 vtr2::operator-(const vtr2 &V) const{return vtr2(_x-V.x(),_y-V.y());}

vtr2 vtr2::operator+=(const vtr2 &V){return *this=(*this)+V;}
vtr2 vtr2::operator-=(const vtr2 &V){return *this=(*this)-V;}
vtr2 vtr2::operator*=(double x){return *this=x*(*this);}
vtr2 vtr2::operator/=(double x){return *this=(*this)/x;}

bool vtr2::operator==(const vtr2 &V) const{return crd2::operator==(V);}
bool vtr2::operator!=(const vtr2 &V) const{return !((*this)==V);}

double vtr2::dot(const vtr2 &V) const{return _x*V._x+_y*V._y;}

double vtr2::operator*(const vtr2 &v) const{return dot(v);}
vtr2 vtr2::operator/(double x) const{return arr::dbl1(*this)/x;}

vtr2 vtr2::norm() const{return (*this)/len();}

std::ostream& operator<<(std::ostream &os,const vtr2 &V);
vtr2 operator*(double x,const vtr2 &v){return vtr2(x*v._x,x*v._y);}

double vtr2::sqrlen() const{return crd2::sqrlen();}
double vtr2::len() const{return crd2::len();}

