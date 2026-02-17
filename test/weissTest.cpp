// unit test
#include "unit-test.hpp"

#include "weiss.hpp"

/*
 * weiss tests
 */
TEST(weissTest, weiss2)
{
	pnt2 p(2., 1.);
	atr2 T0(rtn2(vtr2::X,vtr2::Y),pnt2::origin);
	atr2 T1(rtn2(vtr2::X,vtr2::Y),p);
	pnt2 p0=T0*p;
	pnt2 p1=T1*p;

	EXPECT_EQ(p0, pnt2(-1.,2.))<< p0 <<", "<< pnt2(-1.,2.);
	EXPECT_EQ(p1, p)<<p1<<", "<<p;
}

TEST(weissTest, weiss3)
{
	atr3 aI= atr3::ident;
	pnt3 p1(2., 1., 0.);
	pnt3 p2(5., 3., 0.);
	
	pnt3 p1p=aI*p1;
	pnt3 p2p=aI*p2;

	auto v12=p2-p1;

	EXPECT_EQ(p1p, p1)<< p1p <<", "<<p1;
	EXPECT_EQ(p2p, p2)<< p2p <<", "<<p2;
}
