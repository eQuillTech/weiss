//3-D rotations - P. Ahrenkiel

#ifndef _RTN3_
#define _RTN3_

class trf3;
class vtr3;
class dir3;

class rtn3:public trf3
{
private:
	rtn3(const trf3 &T);

public:
	rtn3(const vtr3 &V0,const vtr3 &V1,const vtr3 &V2);
	rtn3(const vtr3 &V2,double angle);
	rtn3(const vtr3 &V,const vtr3 &Vp);
	rtn3(const double theta,const double phi,const double rho);
	rtn3(const dir3 &dir);
	//	rtn3(const rtn3 &R) noexcept:trf3(R){}//copy constructor

	rtn3 operator*(const rtn3 &R) const noexcept;
	rtn3 operator/(const rtn3 &R) const noexcept;
	rtn3 operator*=(const rtn3 &R) noexcept;
	rtn3 operator/=(const rtn3 &R) noexcept;
	
	rtn3 inv() const;

	trf3 operator*(const trf3 &T) const noexcept;
	trf3 operator/(const trf3 &T) const noexcept;
	
	vtr3 operator*(const vtr3 &V) const;

	static const rtn3 Ro;
};

#endif

