//axes - P. Ahrenkiel

#ifndef _BAS3_
#define _BAS3_

#include "dbl2.hpp"

#include "vtr3.hpp"

class pnt3;
class idx3;
class trf3;

class bas3
{
protected:
	vtr3 _p[3];
	
public:
	bas3();
	bas3(const vtr3 &a,const vtr3 &b,const vtr3 &c);
	bas3(const vtr3 V[]);
	bas3(const arr::dbl2 &D);
	
	vtr3& a();
	vtr3& b();
	vtr3& c();
		
	vtr3 const& a() const;
	vtr3 const& b() const;
	vtr3 const& c() const;
	
	bas3 &B();
	const bas3 &B() const;
	
	vtr3& operator()(const size_t i);
	vtr3 const& operator()(const size_t i) const;

	bas3 operator+() const;
	bas3 operator-() const;

	operator arr::dbl2() const;

	idx3 dot(const vtr3 &V) const;
	idx3 operator*(const vtr3 &V) const;
	vtr3 operator*(const idx3 &I) const;
	bas3 operator/(const trf3 &T) const;
	bas3 operator*=(const trf3 &T);
	bas3 operator/=(const trf3 &T);

	trf3 dot(const bas3 &B) const;
	trf3 to(const bas3 &B) const;
	trf3 operator*(const bas3 &B) const;
	trf3 operator/(const bas3 &B) const;

	friend std::ostream& operator<<(std::ostream &os,const bas3 &A);

	bas3 recip() const;
	double vol() const;
	
	static const bas3 unit;
};

bas3 operator*(double x,const bas3 &A);
	
bas3 recip(bas3 A);
double vol(const bas3 &A);

#endif
