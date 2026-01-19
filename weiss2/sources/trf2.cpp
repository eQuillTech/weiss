//transformations - P. Ahrenkiel

#include <cstdlib>

#include "dbl2.hpp"
#include "vtr2.hpp"
#include "pnt2.hpp"
#include "trf2.hpp"

const trf2 trf2::To=trf2::ident();

trf2::trf2():_00(0.),_01(0.),_10(0.),_11(0.){}
trf2::trf2(const double x[2][2]):_00(x[0][0]),_01(x[0][1]),_10(x[1][0]),_11(x[1][1]){}

trf2 trf2::operator/(const trf2 &T) const{return T.inv()*(*this);}
trf2 trf2::operator*=(const trf2 &T){return *this=*this*T;}
trf2 trf2::operator/=(const trf2 &T){return *this=*this/T;}

double &trf2::operator()(const size_t i,const size_t j){return _p[i][j];}
double const &trf2::operator()(const size_t i,const size_t j) const{return _p[i][j];}

//static
const trf2 trf2::ident()
{
	const double x[2][2]={{1.,0.},{0.,1.}};
	return trf2(x);
}
	
trf2::trf2(const arr::dbl2 &D)
{
	if((D.size(0)==2)&&(D.size(1)==2))
		for(size_t i=0;i<2;++i)
			for(size_t j=0;j<2;++j)
				_p[i][j]=D(i,j);
	else
		arr::err=-1;
}

trf2::operator arr::dbl2() const
{
	arr::dbl2 A(3,3);
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			A(i,j)=_p[i][j];
	return A;
}

vtr2 trf2::operator*(const vtr2 &V) const
{
	double x[2]={0.,0.};
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			x[i]+=_p[i][j]*V(j);
	return vtr2(x);
}

pnt2 trf2::operator*(const pnt2 &P) const
{
	double x[2]={0.,0.};
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			x[i]+=_p[i][j]*P(j);
	return pnt2(x);
}

trf2 trf2::operator*(const trf2 &T) const
{
	trf2 Tp;
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			for(size_t k=0;k<2;++k)
				Tp._p[i][j]+=_p[i][k]*T._p[k][j];
	return Tp;
}

trf2 trf2::inv() const
{
	return arr::dbl2(*this).inv();
}


//resolve predef
vtr2 vtr2::operator*=(const trf2 &T)
{
	return *this=T*(*this);
}

pnt2 pnt2::operator*=(const trf2 &T)
{
	return *this=T*(*this);
}

trf2 operator*(double x,const trf2 &T)
{
	trf2 Tp;
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			Tp._p[i][j]=x*T._p[i][j];
	return Tp;
}

trf2 operator/(double x,const trf2 &T)
{
	return x*T.inv();
}

