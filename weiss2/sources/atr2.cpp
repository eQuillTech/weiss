//augmented transformations - P. Ahrenkiel

#include <cstdlib>

#include "dbl2.hpp"
#include "pnt2.hpp"
#include "atr2.hpp"

const atr2 atr2::ident=atr2();

atr2::operator arr::dbl2() const
{
	auto A=arr::dbl2::ident(3,3);
	A.sub(0,0,2,2)=arr::dbl2(_t);
	A.sub(0,2,2,1)=arr::dbl1(_v);
	return A;
}

atr2::atr2(const trf2 &T,const vtr2 &V){_t=T;_v=V;}

atr2 atr2::operator*=(const atr2 &T){return *this=T*(*this);}

atr2 atr2::operator/=(const atr2 &T){return *this=*this/T;}

trf2 &atr2::A(){return _t;}
vtr2 &atr2::b(){return _v;}
trf2 const &atr2::A() const{return _t;}
vtr2 const &atr2::b() const{return _v;}

vtr2 atr2::operator*(const vtr2 &V) const
{
	return _t*V;
}

pnt2 atr2::operator*(const pnt2 &P) const
{
	return _t*P+_v;
}

//
atr2 atr2::operator*(const atr2 &T) const
{
	return atr2(_t*T._t,_t*T._v+_v);
}

//
atr2 atr2::inv() const
{
	trf2 iT=_t.inv();
	return atr2(iT,iT*(-_v));
}

//resolve predef
vtr2 vtr2::operator*=(const atr2 &T)
{
	return *this=T*(*this);
}

//resolve predef
pnt2 pnt2::operator*=(const atr2 &T)
{
	return *this=T*(*this);
}
