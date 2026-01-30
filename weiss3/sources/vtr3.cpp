//3-D vectors - P. Ahrenkiel

#include <cstdlib>

#include "mth.hpp"

#include "dbl1.hpp"

#include "crd3.hpp"
#include "vtr3.hpp"
#include "dir3.hpp"
#include "trf3.hpp"
#include "rtn3.hpp"

const vtr3 vtr3::zero(0.,0.,0.);
const vtr3 vtr3::X(1.,0.,0.);
const vtr3 vtr3::Y(0.,1.,0.);
const vtr3 vtr3::Z(0.,0.,1.);

vtr3::vtr3():crd3(){}
vtr3::vtr3(double x,double y,double z):crd3(x,y,z){}
vtr3::vtr3(const double x[3]):crd3(x){}
vtr3::vtr3(const arr::dbl1 &A):crd3(A){}
vtr3::vtr3(const vtr3 &V):crd3(V){}
vtr3::vtr3(const dir3 &dir)
{
	*this=rtn3(dir)*dir._Vz;
}

vtr3 vtr3::cross(const vtr3 &V) const
{
	vtr3 Vt;
	for(size_t i=0;i<3;++i)
		Vt._p[i]=_p[mth::cyc(i+1,3)]*V._p[mth::cyc(i+2,3)]
			-_p[mth::cyc(i+2,3)]*V._p[mth::cyc(i+1,3)];
	return Vt;
}

bool vtr3::operator==(const vtr3 &V) const
{
	return (_x==V._x)&&(_y==V._y)&&(_z==V._z);
}

bool vtr3::operator!=(const vtr3 &V) const
{
	return !((*this)==V);
}

std::ostream& operator<<(std::ostream &os,const vtr3 &V)
{
	os<<"("<<V.x()<<","<<V.y()<<","<<V.z()<<")";
	return os;
}

vtr3::operator simd::float3()
{
	simd::float3 res={(float)_x,(float)_y,(float)_z};
	return res;
}

vtr3 vtr3::operator/(const trf3 &T)
{
	return T.inv()*(*this);
}

vtr3 vtr3::operator+() const{return *this;}
vtr3 vtr3::operator-() const{return vtr3(-_x,-_y,-_z);}

vtr3 vtr3::operator+(const vtr3 &V) const{return vtr3(_x+V.x(),_y+V.y(),_z+V.z());}
vtr3 vtr3::operator-(const vtr3 &V) const{return vtr3(_x-V.x(),_y-V.y(),_z-V.z());}

vtr3 vtr3::operator+=(const vtr3 &V){return *this=(*this)+V;}
vtr3 vtr3::operator-=(const vtr3 &V){return *this=(*this)-V;}
vtr3 vtr3::operator*=(double x){return *this=x*(*this);}
vtr3 vtr3::operator/=(double x){return *this=(*this)/x;}

double& vtr3::x(){return _x;}
double& vtr3::y(){return _y;}
double& vtr3::z(){return _z;}

double const& vtr3::x() const{return _x;}
double const& vtr3::y() const{return _y;}
double const& vtr3::z() const{return _z;}

double vtr3::dot(const vtr3 &V) const{return _x*V._x+_y*V._y+_z*V._z;}

double vtr3::operator*(const vtr3 &v) const{return dot(v);}
vtr3 vtr3::operator/(double x) const{return arr::dbl1(*this)/x;}

vtr3 vtr3::norm() const{return (*this)/len();}

vtr3 operator*(double x,const vtr3 &V){return vtr3(x*V._x,x*V._y,x*V._z);}
