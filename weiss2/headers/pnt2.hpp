//2-D points - P. Ahrenkiel

#ifndef _PNT2_
#define _PNT2_

#include "dbl1.hpp"

#include "crd2.hpp"

class vtr2;
class trf2;
class atr2;

class pnt2:public crd2
{
public:
	pnt2();
	pnt2(double x,double y);
	pnt2(const double x[2]);
	pnt2(const crd2 &C);
	pnt2(const arr::dbl1 &A);

	pnt2 operator+(const vtr2 &V) const;
	pnt2 operator-(const vtr2 &V) const;
	pnt2 operator+=(const vtr2 &V);
	pnt2 operator-=(const vtr2 &V);

	vtr2 operator-(const pnt2 &P) const;
	
	bool operator==(const pnt2 &P) const;
	bool operator!=(const pnt2 &P) const;

	inline double sqrdist() const;
	inline double dist() const;
	
	pnt2 operator*=(const trf2 &T);
	pnt2 operator*=(const atr2 &T);

	pnt2 neg();
	static const pnt2 Po;
};

inline double sqrdist(const pnt2 &p);
inline double dist(const pnt2 &p);
 
typedef std::vector<pnt2> Pnt2Vector;

#endif
