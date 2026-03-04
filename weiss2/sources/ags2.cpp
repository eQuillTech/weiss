//axes - P. Ahrenkiel

#include <cstdlib>

#include "dbl2.hpp"
#include "dbl2sub.hpp"

#include "vtr2.hpp"
#include "idx2.hpp"
#include "pnt2.hpp"
#include "bas2.hpp"
#include "atr2.hpp"
#include "ags2.hpp"

const ags2 ags2::unit=ags2(bas2(),pnt2::origin);

ags2::ags2():_b(bas2::unit),_p(pnt2::origin){}
ags2::ags2(const bas2 &b,const pnt2 &p):_b(b),_p(p){}
ags2::operator arr::dbl2() const
{
	arr::dbl2 D=arr::dbl2::ident(4,4);
	D.sub(0,0,3,3)=_b;
	D(0,3)=_p(0);
	D(1,3)=_p(1);
	D(2,3)=_p(2);
	return D;
}

pnt2 ags2::operator*(const idx2 &I) const
{
	return _p+_b*I;
}

idx2 ags2::dot(const pnt2 &P) const
{
	return _b*(P-_p);
}

ags2 ags2::recip() const
{
	bas2 iB=_b.recip();
	vtr2 V=_p-pnt2::origin;
	pnt2 iP=pnt2::origin-vtr2(iB.a().dot(V),iB.b().dot(V));
	return ags2(iB,iP);
}

idx2 ags2::operator()(const pnt2 &P) const
{
	auto iA=recip();
	return iA.B()*(P-_p);
}

std::ostream& operator<<(std::ostream &os,const ags2 &A)
{
	os<<A.B()<<"\n"<<A.p()<<"\n";
	return os;
}

atr2 ags2::to(const ags2 &A) const
{

	trf2 T=_b.to(A._b);
	vtr2 V=-T*(A._p-pnt2::origin)+(_p-pnt2::origin);
	return atr2(T,V);
}

atr2 ags2::operator/(const ags2 &A) const
{
	return to(A);
}
	
ags2 operator*(double x,const ags2 &A)
{
	return ags2(x*A.B(),pnt2::origin+x*(A.p()-pnt2::origin));
}

ags2 recip(ags2 A)
{
	return A.recip();
}

bool ags2::isIn(const pnt2 &P) const
{
	idx2 I=(*this)(P);
	double inA=(I.h()>=0.)&&(I.h()<=1.);
	double inB=(I.k()>=0.)&&(I.k()<=1.);
	return inA&&inB;
}

ags2 ags2::operator*=(const atr2 &T)
{
	return *this=T*(*this);
}

bas2 &ags2::B(){return _b;}
bas2 const &ags2::B() const{return _b;}

pnt2 &ags2::p(){return _p;}
pnt2 const &ags2::p() const{return _p;}

ags2 &ags2::A(){return *this;}
const ags2 &ags2::A() const{return *this;}

idx2 ags2::operator*(const pnt2 &P) const{return dot(P);}
