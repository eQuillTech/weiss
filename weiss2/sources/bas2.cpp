//bases - P. Ahrenkiel

#include <cstdlib>

#include "mth.hpp"
#include "dbl2.hpp"

#include "vtr2.hpp"
#include "trf2.hpp"
#include "idx2.hpp"
#include "bas2.hpp"

const bas2 bas2::unit(vtr2(1.,0.),vtr2(0.,1.));

bas2::bas2(const vtr2 &a,const vtr2 &b){_p[0]=a;_p[1]=b;}
bas2::bas2(){_p[0]=_p[1]=vtr2::zero;}
bas2::bas2(const vtr2 V[]):bas2(V[0],V[1]){}
bas2::bas2(const arr::dbl2 &D)
{
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			_p[i](j)=D(i,j);
}

vtr2& bas2::a(){return _p[0];}
vtr2& bas2::b(){return _p[1];}
	
vtr2 const& bas2::a() const{return _p[0];}
vtr2 const& bas2::b() const{return _p[1];}

bas2::operator arr::dbl2() const
{
	arr::dbl2 A=arr::dbl2::ident(2,2);
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			A(i,j)=_p[i](j);
	return A;
}

idx2 bas2::dot(const vtr2 &V) const
{
	return idx2(_p[0].dot(V),_p[1].dot(V));
}

vtr2 bas2::operator*(const idx2 &I) const
{
	vtr2 V=vtr2::zero;
	for(size_t i=0;i<2;i++)
		V+=I(i)*_p[i];
	return V;
}

bas2 bas2::recip() const
{
	double v=vol();
	vtr2 V[2];
	V[0]=vtr2(_p[1].y(),-_p[1].x())/v;
	V[1]=vtr2(-_p[0].x(),_p[0].y())/v;
	return bas2(V);
}

double bas2::vol() const
{
	return _p[0].x()*_p[1].y()-_p[0].y()*_p[1].x();
}

std::ostream& operator<<(std::ostream &os,const bas2 &A)
{
	os<<A.a()<<std::endl;
	os<<A.b()<<std::endl;
	return os;
}

trf2 bas2::dot(const bas2 &B) const
{
	trf2 T;
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
			T(i,j)=_p[i].dot(B._p[j]);
	return T;
}

trf2 bas2::to(const bas2 &B) const
{
	bas2 Br=B.recip();
	trf2 T;
	for(size_t i=0;i<2;++i)
		for(size_t j=0;j<2;++j)
		{
			double x(0.);
			for(size_t k=0;k<2;++k)
				x+=_p[k](i)*Br._p[k](j);
			T(i,j)=x;
		}
	return T;
}

idx2 bas2::operator*(const vtr2 &V) const
{
	return dot(V);
}
	
bas2 bas2::operator/(const trf2 &T) const
{
	return T.inv()*(*this);
}

bas2 bas2::operator*=(const trf2 &T)
{
	return *this=T*(*this);
}

bas2 bas2::operator/=(const trf2 &T)
{
	return *this=(*this)/T;
}

const bas2 &bas2::B() const{return *this;}

vtr2& bas2::operator()(const size_t i){return _p[i];}
vtr2 const& bas2::operator()(const size_t i) const{return _p[i];}

bas2 bas2::operator+() const{return *this;}
bas2 bas2::operator-() const{return bas2(-_p[0],-_p[1]);}
bas2 operator*(double x,const bas2 &A)
{
	return bas2(x*A(0),x*A(1));
}

bas2 recip(const bas2& B)
{
	return B.recip();
}

double vol(const bas2 &A)
{
	return A.vol();
}

trf2 bas2::operator*(const bas2 &B) const{return dot(B);}
trf2 bas2::operator/(const bas2 &B) const{return to(B);}

bool bas2::operator==(const bas2 &B) const
{
	return (a()==B.a())&&(b()==B.b());
}

bool bas2::operator!=(const bas2 &B) const{return !((*this)==B);}
