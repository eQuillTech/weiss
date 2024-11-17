//transformations - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "tlbx.hpp"
#include "arr.hpp"
#include "weiss2.hpp"

using namespace std;

constexpr const Trf2 Trf2::To=Trf2::ident();

//
Trf2::Trf2(const arr::darr2 &D)
{
	if((D.size(0)==2)&&(D.size(1)==2))
		for(size_t i=0;i<2;++i)
			for(size_t j=0;j<2;++j)
				_p[i][j]=D(i,j);
	else
		arr::err=-1;
}

//
Trf2::operator arr::darr2() const
{
	arr::darr2 A(3,3);
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			A(i,j)=_p[i][j];
	return A;
}

//
vtr2 Trf2::operator*(const vtr2 &V) const
{
	double x[2]={0.,0.};
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			x[i]+=_p[i][j]*V(j);
	return vtr2(x);
}

//
pnt2 Trf2::operator*(const pnt2 &P) const
{
	double x[2]={0.,0.};
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			x[i]+=_p[i][j]*P(j);
	return pnt2(x);
}
//
Trf2 Trf2::operator*(const Trf2 &T) const
{
	Trf2 Tp;
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			for(size_t k=0;k<2;++k)
				Tp._p[i][j]+=_p[i][k]*T._p[k][j];
	return Tp;
}

//
Trf2 Trf2::inv() const
{
	return arr::darr2(*this).inv();
}


//resolve predef
vtr2 vtr2::operator*=(const Trf2 &T)
{
	return *this=T*(*this);
}

//resolve predef
pnt2 pnt2::operator*=(const Trf2 &T)
{
	return *this=T*(*this);
}

//
Trf2 operator*(double x,const Trf2 &T)
{
	Trf2 Tp;
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			Tp._p[i][j]=x*T._p[i][j];
	return Tp;
}

//
Trf2 operator/(double x,const Trf2 &T)
{
	return x*T.inv();
}
