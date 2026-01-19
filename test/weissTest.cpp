// unit test
#include "unit-test.hpp"

#include "weiss.hpp"

/*
 * arr tests
 */
TEST(weissTest, weiss3)
{
	pnt3 p1(2., 1., 0.);
	pnt3 p2(5., 3., 0.);

	auto v12=p2-p1;

	EXPECT_EQ(v12, vtr3(3., 2., 0.));
}

