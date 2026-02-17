//3-D transformations - P. Ahrenkiel

#include <cstdlib>

#include "dbl2.hpp"
#include "error.hpp"

#include "vtr3.hpp"
#include "trf3.hpp"
#include "bas3.hpp"

const trf3 trf3::ident({{{1.,0.,0.,},{0.,1.,0.},{0.,0.,1.}}});

trf3::trf3()
{
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			_p[i][j]=0;
}

trf3::trf3(const arr::dbl2 &D)
{
	if((D.size(0)==3)&&(D.size(1)==3))
		for(size_t i=0;i<3;++i)
			for(size_t j=0;j<3;++j)
				_p[i][j]=D(i,j);
	else
		arr::err=-1;
}

trf3 trf3::operator+() const{return *this;}
	
trf3::trf3(const double p[3][3])
{
	memcpy(_p,p,9*sizeof(double));
}

trf3::operator arr::dbl2() const
{
	arr::dbl2 A(3,3);
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			A(i,j)=_p[i][j];
	return A;
}

trf3 trf3::operator+(const trf3 &T) const
{
	trf3 Tp;
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			Tp._p[i][j]=_p[i][j]+T._p[i][j];
	return Tp;
}

trf3 trf3::operator*(const trf3 &T) const
{
	trf3 Tp;
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			for(size_t k=0;k<3;++k)
				Tp._p[i][j]+=_p[i][k]*T._p[k][j];
	return Tp;
}

trf3 trf3::inv() const
{
	return arr::dbl2(*this).inv();
}


vtr3 trf3::operator*(const vtr3 &V) const noexcept
{
	double x[3]={0.,0.,0.};
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			x[i]+=_p[i][j]*V(j);
	return vtr3(x);
}

bas3 trf3::operator*(const bas3 &B) const
{
	return bas3(operator*(B.a()),operator*(B.b()),operator*(B.c()));
}
	
//resolve predef
vtr3 vtr3::operator*=(const trf3 &T)
{
	return *this=T*(*this);
}

trf3 operator*(double x,const trf3 &T)
{
	trf3 Tp;
	for(size_t i=0;i<3;++i)
		for(size_t j=0;j<3;++j)
			Tp._p[i][j]=x*T._p[i][j];
	return Tp;
}

trf3 operator/(double x,const trf3 &T)
{
	return x*T.inv();
}

trf3::operator simd::float3x3()
{
	using simd::float3;
	float3 row0={(float)_p[0][0],(float)_p[0][1],(float)_p[0][2]};
	float3 row1={(float)_p[1][0],(float)_p[1][1],(float)_p[1][2]};
	float3 row2={(float)_p[2][0],(float)_p[2][1],(float)_p[2][2]};
	
	return simd_matrix(row0,row1,row2);
}

trf3 trf3::operator-() const
{
	return -1.*(*this);
}

std::ostream& operator<<(std::ostream &os,const trf3 &T)
{
	for(size_t i=0;i<3;++i)
	{
		os<<"("<<T._p[i][0]<<","<<T._p[i][1]<<","<<T._p[i][2]<<")\n";
	}
	return os;
}

trf3 trf3::operator-(const trf3 &T) const{return -T+(*this);}
trf3 trf3::operator/(const trf3 &T) const{return T.inv()*(*this);}
trf3 trf3::operator+=(const trf3 &T){return *this=*this+T;}
trf3 trf3::operator-=(const trf3 &T){return *this=*this-T;}
trf3 trf3::operator*=(const trf3 &T){return *this=*this*T;}
trf3 trf3::operator/=(const trf3 &T){return *this=*this/T;}

double &trf3::operator()(const size_t i,const size_t j){return _p[i][j];}
double const &trf3::operator()(const size_t i,const size_t j) const{return _p[i][j];}

trf3 trf3::T() const{return *this;}
