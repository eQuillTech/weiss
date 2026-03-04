//indices - P. Ahrenkiel
#include <cstdlib>

#include "mth.hpp"

#include "crd2.hpp"
#include "idx2.hpp"

const idx2 idx2::I00(0.,0.);
const idx2 idx2::I10(1.,0.);
const idx2 idx2::I01(0.,1.);
const idx2 idx2::I11(1.,1.);
const idx2 idx2::Imid(0.5,0.5);

idx2::idx2():crd2(){}
idx2::idx2(const crd2 &C):crd2(C){}
idx2::idx2(const double h,const double k):crd2(h,k){}
idx2::idx2(const arr::dbl1 &D):crd2(D){}

idx2 idx2::operator+(const idx2 &I) const{return idx2(crd2::operator+(I));}
idx2 idx2::operator-(const idx2 &I) const{return idx2(crd2::operator-(I));}
idx2 idx2::operator+=(const idx2 &I){return *this=*this+I;}
idx2 idx2::operator-=(const idx2 &I) {return *this=*this-I;}

std::ostream& operator<<(std::ostream &os,const idx2 &I)
{
	os<<"("<<I.h()<<","<<I.k()<<")";
	return os;
}

idx2 idx2::round() const
{
	idx2 I;
	for(size_t i=0;i<2;++i)
		I._p[i]=mth::roundoff(_p[i]);
	return I;
}

idx2 round(const idx2 &I){return I.round();}

bool idx2::operator==(const idx2 &I) const
{
	return (_x==I._x)&&(_y==I._y);
}

bool idx2::operator!=(const idx2 &I) const
{
	return !((*this)==I);
}

double& idx2::h(){return _x;}
double& idx2::k(){return _y;}

double const& idx2::h() const{return _x;}
double const& idx2::k() const{return _y;}

std::size_t std::hash<idx2>::operator()(const idx2& I) const noexcept
{
	return I.hash();
}
