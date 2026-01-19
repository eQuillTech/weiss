//scalings - P. Ahrenkieltrf2

#include <cstdlib>

#include "trf2.hpp"
#include "scl2.hpp"

scl2::scl2(double x):trf2()
{
	for(size_t i=0;i<2;i++)
		for(size_t j=0;j<2;j++)
		{
			_p[i][j]=((i==j)?x:0.);
		}
}
