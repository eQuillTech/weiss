//3-D reflections - P. Ahrenkiel
#include "trg.hpp"

#include "vtr3.hpp"
#include "trf3.hpp"
#include "rtn3.hpp"
#include "rfn3.hpp"

rfn3::rfn3(const trf3 &T):trf3(T){}

rfn3::rfn3(const vtr3 &V):trf3()
{
	*this=-rtn3(V,trg::pi);
}

trf3 rfn3::operator*(const trf3 &T) const noexcept
{
	return trf3::operator*(T);
}

trf3 rfn3::operator/(const trf3 &T) const noexcept
{
	return trf3::operator/(T);
}
