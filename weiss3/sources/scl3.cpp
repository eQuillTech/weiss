//3-D scalings - P. Ahrenkieltrf3trf3

#include <cstdlib>
#include <math.h>

#include "tlbx.hpp"
#include "arr.hpp"
#include "weiss3.hpp"

//
scl3::scl3(double x):Trf3()
{
	*this=x*Trf3::ident();
}
