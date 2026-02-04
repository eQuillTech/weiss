//2-D vectors - P. Ahrenkiel

#ifndef _VTR2_
#define _VTR2_

#include "dbl1.hpp"

#include "crd2.hpp"

class pnt2;
class trf2;
class atr2;

class vtr2:public crd2
{
public:
	vtr2();
	vtr2(double x,double y);
	vtr2(const double x[2]);
	vtr2(const arr::dbl1 &A);
	vtr2(const vtr2 &V);
	
	vtr2 operator+() const;
	vtr2 operator-() const;
	
	vtr2 operator+(const vtr2 &V) const;
	vtr2 operator-(const vtr2 &V) const;

	vtr2 operator+=(const vtr2 &V);
	vtr2 operator-=(const vtr2 &V);
	vtr2 operator*=(double x);
	vtr2 operator/=(double x);

	bool operator==(const vtr2 &V) const;
	bool operator!=(const vtr2 &V) const;

	double dot(const vtr2 &V) const;
	double cross(const vtr2 &V) const;

	double operator*(const vtr2 &v) const;
	vtr2 operator/(double x) const;

	double sqrlen() const;
	double len() const;
	vtr2 norm() const;

	friend std::ostream& operator<<(std::ostream &os,const vtr2 &V);
	friend vtr2 operator*(double x,const vtr2 &v);

	vtr2 operator*=(const trf2 &T);
	vtr2 operator*=(const atr2 &T);

	static const vtr2 zero,X,Y;
};
 
inline double dot(const vtr2 &V1,const vtr2 &V2){return V1.dot(V2);}
inline double cross(const vtr2 &V1,const vtr2 &V2){return V1.cross(V2);}
inline double len(const vtr2 &V){return V.len();}
inline vtr2 norm(const vtr2 &V){return V.norm();}

typedef arr::arr1<vtr2> vtr2_arr1;

#endif
