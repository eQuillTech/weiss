//indices - P. Ahrenkiel
#include <cstdlib>

#include "mth.hpp"

#include "crd3.hpp"
#include "idx3.hpp"

const idx3 idx3::I000(0.,0.,0.);
const idx3 idx3::I100(1.,0.,0.);
const idx3 idx3::I010(0.,1.,0.);
const idx3 idx3::I001(0.,0.,1.);
const idx3 idx3::I111(1.,1.,1.);
const idx3 idx3::Imid(0.5,0.5,0.5);

idx3::idx3():crd3(){}
idx3::idx3(const double h,const double k,const double l):crd3(h,k,l){}
idx3::idx3(const arr::dbl1 &D):crd3(D){}

idx3 idx3::operator+(const idx3 &I) const{return idx3(crd3::operator+(I));}
idx3 idx3::operator-(const idx3 &I) const{return idx3(crd3::operator-(I));}
idx3 idx3::operator+=(const idx3 &I){return *this=*this+I;}
idx3 idx3::operator-=(const idx3 &I) {return *this=*this-I;}

std::ostream& operator<<(std::ostream &os,const idx3 &I)
{
	os<<"("<<I.h()<<","<<I.k()<<","<<I.l()<<")";
	return os;
}

idx3 idx3::round() const
{
	idx3 I;
	for(size_t i=0;i<3;++i)
		I._p[i]=mth::roundoff(_p[i]);
	return I;
}

idx3 round(const idx3 &I){return I.round();}

bool idx3::operator==(const idx3 &I) const
{
	return (_x==I._x)&&(_y==I._y)&&(_z==I._z);
}

bool idx3::operator!=(const idx3 &I) const
{
	return !((*this)==I);
}

idx3::idx3(const crd3 &C):crd3(C){}

double& idx3::h(){return _x;}
double& idx3::k(){return _y;}
double& idx3::l(){return _z;}

double const& idx3::h() const{return _x;}
double const& idx3::k() const{return _y;}
double const& idx3::l() const{return _z;}

std::size_t std::hash<idx3>::operator()(const idx3& I) const noexcept
{
	return I.hash();
}
