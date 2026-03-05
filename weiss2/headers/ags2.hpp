// 2-D axes - P. Ahrenkiel

#ifndef _AGS2_
#define _AGS2_

#include "bas2.hpp"
#include "pnt2.hpp"

class vtr2;
class idx2;
class trf2;
class atr3;

class ags2
{
protected:
	bas2 _b;
	pnt2 _p;

public:
	ags2();
	ags2(const bas2 &b,const pnt2 &p);
	
	bas2 &B();
	bas2 const &B() const;

	pnt2 &p();
	pnt2 const &p() const;

	ags2 &A();
	const ags2 &A() const;			
	operator arr::dbl2() const;

	//idx2 operator*(const pnt2 &P) const;
	ags2 operator/(const trf2 &T) const;
	ags2 operator*=(const atr2 &T);
	ags2 operator/=(const atr2 &T);
	
	atr2 to(const ags2 &A) const;
	atr2 operator/(const ags2 &A) const;

	pnt2 operator*(const idx2 &I) const;
	idx2 operator()(const pnt2 &P) const;
	idx2 dot(const pnt2 &P) const;
	
	friend std::ostream& operator<<(std::ostream &os,const ags2 &A);

	ags2 recip() const;
	   
	bool isIn(const pnt2 &P) const;

	static const ags2 unit;
};

ags2 operator*(double x,const ags2 &A);
	
ags2 recip(ags2 A);

#endif
