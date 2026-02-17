//3-D vectors - P. Ahrenkiel

#ifndef _VTR3_
#define _VTR3_

#include <simd/simd.h>

#include "dbl1.hpp"
#include "crd3.hpp"

class pnt3;
class trf3;
class atr3;
class dir3;

class vtr3:public crd3
{
private:
	explicit vtr3(const crd3 &C);
	
public:
	vtr3();
	vtr3(double x,double y,double z);
	vtr3(const double x[3]);
	vtr3(const arr::dbl1 &A);
	vtr3(const vtr3 &V);
	vtr3(const dir3 &dir);
	vtr3 operator+() const;
	vtr3 operator-() const;
	
	vtr3 operator+(const vtr3 &V) const;
	vtr3 operator-(const vtr3 &V) const;

	bool operator==(const vtr3  &V) const;
	bool operator!=(const vtr3  &V) const;

	vtr3 operator+=(const vtr3 &V);
	vtr3 operator-=(const vtr3 &V);
	vtr3 operator*=(double x);
	vtr3 operator/=(double x);

	double& x();
	double& y();
	double& z();
	
	double const& x() const;
	double const& y() const;
	double const& z() const;

	double dot(const vtr3 &V) const;
	vtr3 cross(const vtr3 &V) const;

	double operator*(const vtr3 &v) const;
	vtr3 operator/(double x) const;

	inline double sqrlen() const{return crd3::sqrlen();}
	inline double len() const{return crd3::len();}
	vtr3 norm() const;

	friend std::ostream& operator<<(std::ostream &os,const vtr3 &V);
	friend vtr3 operator*(double x,const vtr3 &V);

	vtr3 operator/(const trf3 &T);

	vtr3 operator*=(const trf3 &T);

	static const vtr3 zero,X,Y,Z;
	
	operator simd::float3();
};
 
inline double dot(const vtr3 &V1,const vtr3 &V2){return V1.dot(V2);}
inline vtr3 cross(const vtr3 &V1,const vtr3 &V2){return V1.cross(V2);}
inline double len(const vtr3 &V){return V.len();}
inline vtr3 norm(const vtr3 &V){return V.norm();}

#endif
