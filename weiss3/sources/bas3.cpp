//bases - P. Ahrenkiel

#include <cstdlib>

#include "mth.hpp"
#include "dbl2.hpp"

#include "vtr3.hpp"
#include "trf3.hpp"
#include "idx3.hpp"
#include "bas3.hpp"

const bas3 bas3::Bo(vtr3::Vo,vtr3::Vo,vtr3::Vo);
const bas3 bas3::Bunit(vtr3::Vx,vtr3::Vy,vtr3::Vz);

bas3::bas3(const vtr3 &a,const vtr3 &b,const vtr3 &c){_p[0]=a;_p[1]=b;_p[2]=c;}
bas3::bas3(){_p[0]=_p[1]=_p[2]=vtr3::Vo;}
bas3::bas3(const vtr3 V[]):bas3(V[0],V[1],V[2]){}
bas3::bas3(const arr::dbl2 &D)
{
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			_p[i](j)=D(i,j);
}

vtr3& bas3::a(){return _p[0];}
vtr3& bas3::b(){return _p[1];}
vtr3& bas3::c(){return _p[2];}
	
vtr3 const& bas3::a() const{return _p[0];}
vtr3 const& bas3::b() const{return _p[1];}
vtr3 const& bas3::c() const{return _p[2];}

bas3::operator arr::dbl2() const
{
	arr::dbl2 A=arr::dbl2::ident(3,3);
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			A(i,j)=_p[i](j);
	return A;
}

idx3 bas3::dot(const vtr3 &V) const
{
	return idx3(_p[0].dot(V),_p[1].dot(V),_p[2].dot(V));
}

vtr3 bas3::operator*(const idx3 &I) const
{
	vtr3 V=vtr3::Vo;
	for(size_t i=0;i<3;i++)
		V+=I(i)*_p[i];
	return V;
}

bas3 bas3::recip() const
{
	double v=vol();
	vtr3 V[3];
	for(size_t i=0;i<3;++i)
		V[i]=_p[mth::cyc(i+1,3)].cross(_p[mth::cyc(i+2,3)])/v;
	return bas3(V);
}

double bas3::vol() const
{
	return a().dot(b().cross(c()));
}

std::ostream& operator<<(std::ostream &os,const bas3 &A)
{
	os<<A.a()<<std::endl;
	os<<A.b()<<std::endl;
	os<<A.c()<<std::endl;
	return os;
}

trf3 bas3::dot(const bas3 &B) const
{
	trf3 T;
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			T(i,j)=_p[i].dot(B._p[j]);
	return T;
}

// returns (*this)*B.inv()
trf3 bas3::to(const bas3 &B) const
{
	bas3 Br=B.recip();
	trf3 T;
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
		{
			double x(0.);
			for(size_t k=0;k<3;++k)
				x+=_p[k](i)*Br._p[k](j);
			T(i,j)=x;
		}
	return T;
}

idx3 bas3::operator*(const vtr3 &V) const
{
	return dot(V);
}
	
bas3 bas3::operator/(const trf3 &T) const
{
	return T.inv()*(*this);
}

bas3 bas3::operator*=(const trf3 &T)
{
	return *this=T*(*this);
}

bas3 bas3::operator/=(const trf3 &T)
{
	return *this=(*this)/T;
}

const bas3 &bas3::B() const{return *this;}

vtr3& bas3::operator()(const size_t i){return _p[i];}
vtr3 const& bas3::operator()(const size_t i) const{return _p[i];}

bas3 bas3::operator+() const{return *this;}
bas3 bas3::operator-() const{return bas3(-_p[0],-_p[1],-_p[2]);}

bas3 operator*(double x,const bas3 &A)
{
	return bas3(x*A(0),x*A(1),x*A(2));
}

bas3 recip(bas3 A)
{
	return A.recip();
}

double vol(const bas3 &A)
{
	return A.vol();
}

trf3 bas3::operator*(const bas3 &B) const{return dot(B);}
trf3 bas3::operator/(const bas3 &B) const{return to(B);}

