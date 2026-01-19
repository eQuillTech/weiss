//3-D augmented transformations - P. Ahrenkiel

#ifndef _ATR3_
#define _ATR3_

#include <simd/simd.h>

#include "dbl2.hpp"
#include "vtr3.hpp"
#include "trf3.hpp"

class vtr3;
class ags3;

class atr3
{
protected:
	trf3 _t;
	vtr3 _v;
	
public:
	explicit atr3();
	explicit atr3(const trf3 &T,const vtr3 &V);
	explicit atr3(const trf3 &T);
	explicit atr3(const vtr3 &V);
	explicit atr3(const trf3 &T,const pnt3 &P);

	vtr3 operator*(const vtr3 &V) const noexcept;
	pnt3 operator*(const pnt3 &P) const noexcept;

	atr3 operator*(const atr3 &T) const;
	atr3 operator/(const atr3 &T) const;
	atr3 operator*=(const atr3 &T);
	atr3 operator/=(const atr3 &T);

	operator arr::dbl2() const;
	friend std::ostream& operator<<(std::ostream &os,const atr3 &T);

	trf3 &A();
	vtr3 &b();
	trf3 const &A() const;
	vtr3 const &b() const;

	ags3 operator*(const ags3 &A) const;
	atr3 inv() const;
	static atr3 ident();

	static const atr3 Ato;
	
	operator simd::float4x4();
};

#endif

