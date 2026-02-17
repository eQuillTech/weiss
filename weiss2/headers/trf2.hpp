//2-D transformations - P. Ahrenkiel

#ifndef _TRF2_
#define _TRF2_

#include "dbl2.hpp"

class vtr2;
class pnt2;

class trf2
{
protected:
	union
	{
		struct
		{
			double _00,_01;
			double _10,_11;
		};
		double _p[2][2]; // array representation
	};
	
public:
	trf2();
	trf2(const double p[2][2]);
	trf2(const arr::dbl2 &D);

	vtr2 operator*(const vtr2 &V) const;
	pnt2 operator*(const pnt2 &P) const;

	trf2 operator*(const trf2 &T) const;
	trf2 operator/(const trf2 &T) const;
	trf2 operator*=(const trf2 &T);
	trf2 operator/=(const trf2 &T);

	operator arr::dbl2() const;

	double &operator()(const size_t i,const size_t j);
	double const &operator()(const size_t i,const size_t j) const;

	trf2 T() const;
	trf2 inv() const;

	friend trf2 operator*(double x,const trf2 &T);
	friend trf2 operator/(double x,const trf2 &T);

	static const trf2 ident;
	
	static const trf2 To;

};

#endif

