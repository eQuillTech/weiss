//3-D points - P. Ahrenkiel

#ifndef _PNT3_
#define _PNT3_

#include <simd/simd.h>

#include "dbl1.hpp"

#include "crd3.hpp"

class vtr3;
class trf3;
class atr3;

class pnt3:public crd3
{
private:

public:
	explicit pnt3(const crd3 &C);
	pnt3();
	pnt3(double x,double y,double z);
	pnt3(const arr::dbl1 &A);

	pnt3 operator+(const vtr3 &V) const;
	pnt3 operator-(const vtr3 &V) const;
	pnt3 operator+=(const vtr3 &V);
	pnt3 operator-=(const vtr3 &V);

	vtr3 operator-(const pnt3 &P) const;
	
	bool operator==(const pnt3 &P) const;
	bool operator!=(const pnt3 &P) const;

	pnt3 operator*(const atr3 &T) const;
	pnt3 operator*=(const atr3 &T);

	pnt3 operator/(const atr3 &T) const;
	pnt3 operator/=(const atr3 &T);

	double dist() const;

	double& x();
	double& y();
	double& z();
	
	double const& x() const;
	double const& y() const;
	double const& z() const;

	static const pnt3 Po;
	operator simd::float4();
	operator simd::float3();
};

//
inline double dist(const pnt3 &p){return p.dist();}
 
typedef std::vector<pnt3> Pnt3Vector;

#endif
