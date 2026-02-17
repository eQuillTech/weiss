//3-D transformations - P. Ahrenkiel

#ifndef _TRF3_
#define _TRF3_

#include <simd/simd.h>

#include "dbl2.hpp"

class vtr3;
class bas3;
class rtn3;
class scl3;

class trf3
{
protected:
	double _p[3][3];
	
public:
	trf3();
	trf3(const arr::dbl2 &D);
	trf3(const double p[3][3]);

	vtr3 operator*(const vtr3 &V) const noexcept;
	bas3 operator*(const bas3 &B) const;
	
	trf3 operator+(const trf3 &T) const;
	trf3 operator-(const trf3 &T) const;
	trf3 operator*(const trf3 &T) const;
	trf3 operator/(const trf3 &T) const;
	trf3 operator+=(const trf3 &T);
	trf3 operator-=(const trf3 &T);
	trf3 operator*=(const trf3 &T);
	trf3 operator/=(const trf3 &T);

	trf3 operator+() const;
	trf3 operator-() const;

	operator arr::dbl2() const;
	double &operator()(const size_t i,const size_t j);
	double const &operator()(const size_t i,const size_t j) const;

	trf3 T() const;
	trf3 inv() const;

	friend std::ostream& operator<<(std::ostream &os,const trf3 &T);
	friend trf3 operator*(double x,const trf3 &T);
	friend trf3 operator/(double x,const trf3 &T);

	static const trf3 ident;
	operator simd::float3x3();
};

#endif

