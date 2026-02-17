// unit test
#include "unit-test.hpp"

#include "weiss.hpp"

/*
 * weiss tests
 */
TEST(weissTest, weiss2)
{
	pnt2 p(2., 1.);
	atr2 A0(rtn2(vtr2::X,vtr2::Y),pnt2::origin);
	atr2 A1(rtn2(vtr2::X,vtr2::Y),p);
	pnt2 p0=A0*p;
	pnt2 p1=A1*p;

	EXPECT_NEAR((p0-pnt2(-1.,2.)).len(), 0., 1.e-4)<< p0 <<", "<< pnt2(-1.,2.);
	EXPECT_NEAR((p1-p).len(), 0., 1.e-4)<<p1<<", "<<p;
}

TEST(weissTest, weiss3)
{
	pnt3 p(2., 1., 3.);
	atr3 A0(rtn3(vtr3::X,vtr3::Y),pnt3::origin);
	atr3 A1(rtn3(vtr3::X,vtr3::Y),p);
	pnt3 p0=A0*p;
	pnt3 p1=A1*p;

	EXPECT_NEAR((p0-pnt3(-1.,2.,3.)).len(), 0., 1.e-4)<< p0 <<", "<< pnt3(-1.,2.,3.);
	EXPECT_NEAR((p1-p).len(), 0., 1.e-4)<<p1<<", "<<p;
}
