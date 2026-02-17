//2-D augmented transformations - P. Ahrenkiel

#ifndef _ATR2_
#define _ATR2_

#ifndef _TLBX_
#include "tlbx.hpp"
#endif

#include "arr.hpp"

#include "vtr2.hpp"
#include "trf2.hpp"

class atr2
{
protected:
	trf2 _t;
	vtr2 _v;
	
public:
	atr2(const trf2 &T=trf2::To,const vtr2 &V=vtr2::zero);

	vtr2 operator*(const vtr2 &V) const;
	pnt2 operator*(const pnt2 &P) const;

	atr2 operator*(const atr2 &T) const;
	atr2 operator/(const atr2 &T) const;
	atr2 operator*=(const atr2 &T);
	atr2 operator/=(const atr2 &T);

	operator arr::dbl2() const;

	trf2 &A();
	vtr2 &b();
	trf2 const &A() const;
	vtr2 const &b() const;

	atr2 inv() const;
	static const atr2 ident;
};

#endif

