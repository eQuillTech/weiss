//axes - P. Ahrenkiel

#ifndef _BAS2_
#define _BAS2_

#include "dbl2.hpp"

#include "vtr2.hpp"

class pnt2;
class idx2;
class trf2;

class bas2
{
protected:
	vtr2 _p[2];
	
public:
	bas2();
	bas2(const vtr2 &a,const vtr2 &b);
	bas2(const vtr2 V[]);
	bas2(const arr::dbl2 &D);
	
	vtr2& a();
	vtr2& b();
		
	vtr2 const& a() const;
	vtr2 const& b() const;
	
	bas2 &B();
	const bas2 &B() const;
	
	vtr2& operator()(const size_t i);
	vtr2 const& operator()(const size_t i) const;

	bas2 operator+() const;
	bas2 operator-() const;

	operator arr::dbl2() const;

	idx2 dot(const vtr2 &V) const;
	idx2 operator*(const vtr2 &V) const;
	vtr2 operator*(const idx2 &I) const;
	bas2 operator/(const trf2 &T) const;
	bas2 operator*=(const trf2 &T);
	bas2 operator/=(const trf2 &T);
	trf2 dot(const bas2 &B) const;
	trf2 to(const bas2 &B) const;
	trf2 operator*(const bas2 &B) const;
	trf2 operator/(const bas2 &B) const;

	friend std::ostream& operator<<(std::ostream &os,const bas2 &A);

	bas2 recip() const;
	double vol() const;
	
	static const bas2 unit;
};

bas2 operator*(double x,const bas2 &A);
	
bas2 recip(const bas2& B);
double vol(const bas2 &A);
#endif
