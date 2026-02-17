//3-D vectors - P. Ahrenkiel

#ifndef _DIR3_
#define _DIR3_

#include "vtr3.hpp"

struct dir3
{
	vtr3 _Vz,_Vx;
	double _theta,_phi,_rho;
	dir3(const vtr3 &Vz=vtr3::Z,const vtr3 &Vx=vtr3::X,const double theta=0.,const double phi=0.,const double rho=0.):
		_Vz(Vz),_Vx(Vx),_theta(theta),_phi(phi),_rho(rho)
	{}
		
	static const dir3 home;
};

#endif
