//2-D coordinates - P. Ahrenkiel

#ifndef _CRD2_
#define _CRD2_

#include "dbl1.hpp"

class crd2
{
protected:
	union
	{
		struct
		{
			double _x,_y;
		};
		double _p[2]; // array representation
	};

	crd2 operator+();
	crd2 operator-();

	crd2 const operator+() const;
	crd2 const operator-() const;
	
	crd2 operator+(const crd2 &c) const;
	crd2 operator-(const crd2 &c) const;
	
	crd2 operator+=(const crd2 &c);
	crd2 operator-=(const crd2 &c);
	crd2 operator*=(double x);
	crd2 operator/=(double x);
	bool operator==(const crd2 &c) const;
	bool operator!=(const crd2 &c) const;

	friend crd2 operator*(double x,const crd2 &c);
	crd2 operator/(double x) const;

	double sqrlen() const;
	double len() const;

public:
	crd2(double x=0.,double y=0.);
	crd2(const double x[2]);
	crd2(const arr::dbl1 &A);
	
	operator arr::dbl1() const;
	double& x();
	double& y();
	
	double const& x() const;
	double const& y() const;
	
	double& operator()(const size_t i0);
	double const& operator()(const size_t i0) const;
	
};

#endif
