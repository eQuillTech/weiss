//axes - P. Ahrenkiel

#ifndef _AGS_
#define _AGS_

#include "bas3.hpp"
#include "pnt3.hpp"

class vtr3;
class idx3;
class trf3;
class atr3;

class ags3
{
protected:
	bas3 _b;
	pnt3 _p;

public:
	ags3();
	ags3(const bas3 &b,const pnt3 &p);
	
	bas3 &B();
	bas3 const &B() const;

	pnt3 &p();
	pnt3 const &p() const;

	ags3 &A();
	const ags3 &A() const;

	operator arr::dbl2() const;

	idx3 dot(const pnt3 &P) const;
	idx3 operator*(const pnt3 &P) const;
	pnt3 operator*(const idx3 &I) const;
	ags3 operator/(const trf3 &T) const;
	ags3 operator*=(const atr3 &T);
	ags3 operator/=(const atr3 &T);
	
	atr3 to(const ags3 &A) const;
	atr3 operator/(const ags3 &A) const;

	idx3 operator()(const pnt3 &P) const;
	friend std::ostream& operator<<(std::ostream &os,const ags3 &A);

	ags3 recip() const;
	   
	bool isIn(const pnt3 &P) const;
	operator simd::float4x4();

	static const ags3 Ao,Axyz;
};

ags3 operator*(double x,const ags3 &A);
	
ags3 recip(ags3 A);

#endif
