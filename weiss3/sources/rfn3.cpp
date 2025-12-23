//3-D reflections - P. Ahrenkiel

#include "weiss3.hpp"

rfn3::rfn3(const vtr3 &V):trf3()
{
	*this=-rtn3(V,trg::pi);
}
