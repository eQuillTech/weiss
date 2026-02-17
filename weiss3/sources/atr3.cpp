//3-D augmented transformations - P. Ahrenkiel

#include <cstdlib>

#include "dbl2sub.hpp"

#include "vtr3.hpp"
#include "pnt3.hpp"
#include "idx3.hpp"
#include "ags3.hpp"
#include "atr3.hpp"

const atr3 atr3::ident=atr3();

atr3::atr3():_t(trf3::ident),_v(vtr3::zero){}
atr3::atr3(const trf3 &T,const vtr3 &V):_t(T),_v(V){}
atr3::atr3(const trf3 &T):_t(T),_v(vtr3::zero){}
atr3::atr3(const vtr3 &V):_t(trf3::ident),_v(V){}

atr3::operator arr::dbl2() const
{
	arr::dbl2 A=arr::dbl2::ident(4,4);
	A.sub(0,0,3,3)=arr::dbl2(_t);
	A.sub(0,3,3,1)=arr::dbl1(_v);
	return A;
}

atr3::atr3(const trf3 &T,const pnt3 &P):atr3(T,P-pnt3::origin)
{
}

vtr3 atr3::operator*(const vtr3 &V) const noexcept
{
	return _t*V;
}

pnt3 atr3::operator*(const pnt3 &P) const noexcept
{
	return pnt3::origin+_t*(P-pnt3::origin)+_v;
}

atr3 atr3::operator*(const atr3 &T) const
{
	return atr3(_t*T._t,_t*T._v+_v);
}

atr3 atr3::operator/(const atr3 &T) const
{
	return T.inv()*(*this);
}
	
atr3 atr3::inv() const
{
	trf3 iT=_t.inv();
	return atr3(iT,iT*(-_v));
}

ags3 atr3::operator*(const ags3 &A) const
{
	bas3 Bp=_t*A.B();
	pnt3 Pp=pnt3::origin+_t*(A.p()-pnt3::origin)+_v;
	return ags3(Bp,Pp);
}

atr3::operator simd::float4x4()
{
	using simd::float4;
	return simd_matrix_from_rows
	(
		(float4){	(float)_t(0,0), (float)_t(0,1), (float)_t(0,2), (float)_v.x() },
		(float4){ (float)_t(1,0), (float)_t(1,1), (float)_t(1,2), (float)_v.y() },
		(float4){ (float)_t(2,0), (float)_t(2,1), (float)_t(2,2), (float)_v.z() },
		(float4){ 0.f, 0.f, 0.f, 1.f }
	);
}

std::ostream& operator<<(std::ostream &os,const atr3 &T)
{
	os<<T.A()<<"\n"<<T.b()<<"\n";
	return os;
}


atr3 atr3::operator*=(const atr3 &T){return *this=T*(*this);}
atr3 atr3::operator/=(const atr3 &T){return *this=*this/T;}

trf3 &atr3::A(){return _t;}
vtr3 &atr3::b(){return _v;}
trf3 const &atr3::A() const{return _t;}
vtr3 const &atr3::b() const{return _v;}
