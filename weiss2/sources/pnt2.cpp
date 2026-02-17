//points - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "crd2.hpp"
#include "pnt2.hpp"
#include "vtr2.hpp"

const pnt2 pnt2::origin(0.,0.);

pnt2::pnt2():crd2(){}
pnt2::pnt2(double x,double y):crd2(x,y){}
pnt2::pnt2(const double x[2]):crd2(x){}
pnt2::pnt2(const crd2 &C):crd2(C){}
pnt2::pnt2(const arr::dbl1 &A):crd2(A){}
	
pnt2 pnt2::operator+=(const vtr2 &V)
{
	return *this=(*this)+V;
}

pnt2 pnt2::operator-=(const vtr2 &V)
{
	return *this=(*this)-V;
}

pnt2 pnt2::operator+(const vtr2 &V) const
{
	return 	pnt2(_x+V.x(),_y+V.y());
}

pnt2 pnt2::operator-(const vtr2 &V) const
{
	return pnt2(_x-V.x(),_y-V.y());
}

vtr2 pnt2::operator-(const pnt2 &P) const
{
	return vtr2(_x-P._x,_y-P._y);
}

bool pnt2::operator==(const pnt2 &P) const
{
	return (_x==P._x)&&(_y==P._y);
}


bool pnt2::operator!=(const pnt2 &P) const
{
	return !((*this)==P);
}

pnt2 pnt2::neg(){return crd2::operator-(*this);}

inline double pnt2::sqrdist() const{return sqrlen();}
inline double pnt2::dist() const{return len();}

inline double sqrdist(const pnt2 &p){return p.sqrdist();}
inline double dist(const pnt2 &p){return p.dist();}

std::ostream& operator<<(std::ostream &os,const pnt2 &P)
{
	os<<crd2(P);
	return os;
}
