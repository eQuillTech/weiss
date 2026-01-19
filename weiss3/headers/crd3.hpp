//3-D coordinates - P. Ahrenkiel

#ifndef _CRD3_
#define _CRD3_

#include "dbl1.hpp"

class crd3
{
protected:
	union
	{
		struct
		{
			double _x,_y,_z;
		};
		double _p[3]; // array representation
	};

	crd3 operator+() const;
	crd3 operator-() const;
	
	crd3 operator+(const crd3 &c) const;
	crd3 operator-(const crd3 &c) const;
	
	crd3 operator+=(const crd3 &c);
	crd3 operator-=(const crd3 &c);
	crd3 operator*=(double x);
	crd3 operator/=(double x);
	bool operator==(const crd3 &c) const;
	bool operator!=(const crd3 &c) const;

	friend crd3 operator*(double x,const crd3 &c);
	crd3 operator/(double x) const;

	double sqrlen() const;
	double len() const;

	double& x();
	double& y();
	double& z();
	
	double const& x() const;
	double const& y() const;
	double const& z() const;

public:
	crd3(double x=0.,double y=0.,double z=0.);
	crd3(const double x[3]);
	crd3(const arr::dbl1 &A);
	std::size_t hash() const;

	operator arr::dbl1() const;
	
	double& operator()(const size_t i0);
	double const& operator()(const size_t i0) const;
	friend std::ostream& operator<<(std::ostream &os,const crd3 &C);
};

#endif
