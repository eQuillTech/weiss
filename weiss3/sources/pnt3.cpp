//3-D points - P. Ahrenkiel

#include <cstdlib>

#include "atr3.hpp"
#include "vtr3.hpp"
#include "pnt3.hpp"

const pnt3 pnt3::origin(0.,0.,0.);

pnt3::pnt3():crd3(){}
pnt3::pnt3(double x,double y,double z):crd3(x,y,z){}
pnt3::pnt3(const arr::dbl1 &A):crd3(A){}

pnt3 pnt3::operator+=(const vtr3 &V)
{
	return *this=(*this)+V;
}

pnt3 pnt3::operator-=(const vtr3 &V)
{
	return *this=(*this)-V;
}

pnt3 pnt3::operator+(const vtr3 &V) const
{
	return 	pnt3(_x+V.x(),_y+V.y(),_z+V.z());
}

pnt3 pnt3::operator-(const vtr3 &V) const
{
	return pnt3(_x-V.x(),_y-V.y(),_z-V.z());
}

vtr3 pnt3::operator-(const pnt3 &P) const
{
	return vtr3(_x-P._x,_y-P._y,_z-P._z);
}

pnt3 pnt3::operator*(const atr3 &T) const
{
	return pnt3::origin+T.A()*(operator-(pnt3::origin))+T.b();
}

pnt3 pnt3::operator/(const atr3 &T) const
{
	return pnt3::origin+T.A().inv()*(operator-(pnt3::origin))+T.b();
}

bool pnt3::operator==(const pnt3 &P) const
{
	return (_x==P._x)&&(_y==P._y)&&(_z==P._z);
}

bool pnt3::operator!=(const pnt3 &P) const
{
	return !((*this)==P);
}

pnt3 pnt3::operator*=(const atr3 &T)
{
	return *this=T*(*this);
}

pnt3 pnt3::operator/=(const atr3 &T)
{
	return *this=T.inv()*(*this);
}

double pnt3::dist() const
{
	return len();
}
	
pnt3::operator simd::float4()
{
	simd::float4 res={(float)_x,(float)_y,(float)_z,1.f};
	return res;
}

pnt3::operator simd::float3()
{
	simd::float3 res={(float)_x,(float)_y,(float)_z};
	return res;
}

double& pnt3::x(){return _x;}
double& pnt3::y(){return _y;}
double& pnt3::z(){return _z;}

double const& pnt3::x() const{return _x;}
double const& pnt3::y() const{return _y;}
double const& pnt3::z() const{return _z;}
