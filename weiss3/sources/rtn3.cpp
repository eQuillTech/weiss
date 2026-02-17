//3-D rotations - P. Ahrenkiel

#include <cstdlib>

#include "trg.hpp"

#include "vtr3.hpp"
#include "trf3.hpp"
#include "rtn3.hpp"
#include "dir3.hpp"

const rtn3 rtn3::Ro(vtr3::Z,0.);

rtn3::rtn3(const trf3 &T):trf3(T){}

rtn3::rtn3(const vtr3 &V0,const vtr3 &V1,const vtr3 &V2):trf3()
{
	vtr3 V[3];
	
	V[0]=(V1.cross(V2)).norm();
	V[1]=(V2.cross(V0)).norm();
	V[2]=(V0.cross(V1)).norm();
	for(size_t i=0;i<3;i++)
		for(size_t j=0;j<3;j++)
			_p[i][j]=V[j](i);
}

rtn3::rtn3(const vtr3 &V,const double angle):trf3()
{
	vtr3 u[3];
	if(V.len()>0.)
	{
		u[2]=V.norm();
		u[1]=u[2].cross(vtr3::X);
		u[0]=u[1].cross(u[2]);
		if((u[1].len()==0.)||(u[0].len()==0.))
		{
			u[0]=vtr3::Y.cross(u[2]);
			u[1]=u[2].cross(u[0]);
		}
		rtn3 R(u[0],u[1],u[2]);
		
		vtr3 up[3];
		up[0]=cos(angle)*vtr3::X+sin(angle)*vtr3::Y;
		up[1]=-sin(angle)*vtr3::X+cos(angle)*vtr3::Y;
		up[2]=vtr3::Z;
		rtn3 Rp(up[0],up[1],up[2]);		
		*this=R*Rp*(R.inv());
	}
	else
	{
		*this=trf3::ident();
	}
}

rtn3::rtn3(const vtr3 &V,const vtr3 &Vp):trf3()
{
	double Lprod=V.len()*Vp.len();
	if(Lprod>0.)
	{
		double angle=trg::acs(V.dot(Vp)/Lprod);
		vtr3 axisV=V.cross(Vp)/Lprod;
		if(axisV.len()>0.)
			*this=rtn3(axisV,angle);
		else
			*this=trf3::ident();
	}
	else
			*this=trf3::ident();
}

rtn3::rtn3(const double theta,const double phi,const double rho):trf3()
{
	*this=rtn3(vtr3::Z,phi)*rtn3(vtr3::Y,theta)*rtn3(vtr3::Z,rho);
}

rtn3::rtn3(const dir3 &dir):trf3()
{
	vtr3 axisY=dir._Vz.cross(dir._Vx);
	rtn3 R_rho(dir._Vz,dir._rho);
	rtn3 R_theta(axisY,dir._theta);
	rtn3 R_phi(dir._Vz,dir._phi);
	*this=R_phi*R_theta*R_rho;
}

rtn3 rtn3::operator*(const rtn3 &R) const noexcept
{
	return trf3::operator*(R);
}

rtn3 rtn3::operator/(const rtn3 &R) const noexcept{return trf3::operator/(R);}
rtn3 rtn3::operator*=(const rtn3 &R) noexcept{return trf3::operator*=(R);}
rtn3 rtn3::operator/=(const rtn3 &R) noexcept{return trf3::operator/=(R);}

rtn3 rtn3::inv() const{return trf3::inv();}

trf3 rtn3::operator*(const trf3 &T) const noexcept{return trf3::operator*(T);}
trf3 rtn3::operator/(const trf3 &T) const noexcept{return trf3::operator/(T);}

vtr3 rtn3::operator*(const vtr3 &V) const{return trf3::operator*(V);}
