//indices - P. Ahrenkiel

#ifndef _IDX2_
#define _IDX2_

#include "dbl1.hpp"

#include "crd2.hpp"

class vtr2;

class idx2:public crd2
{
private:
	explicit idx2(const crd2 &C);

public:
	double& h();
	double& k();

	double const& h() const;
	double const& k() const;
	
	idx2();
	idx2(const double h,const double k);
	idx2(const arr::dbl1 &D);

	idx2 round() const;
	idx2 operator+(const idx2 &I) const;
	idx2 operator-(const idx2 &I) const;
	idx2 operator+=(const idx2 &I);
	idx2 operator-=(const idx2 &I);
	bool operator==(const idx2 &I) const;
	bool operator!=(const idx2 &I) const;

	static const idx2 I00;
	static const idx2 I10;
	static const idx2 I01;
	static const idx2 I11;
	static const idx2 Imid;

	friend std::ostream& operator<<(std::ostream &os,const idx2 &I);
};

idx2 round(const idx2 &I2);

namespace std
{
template<>
struct hash<idx2> {
	std::size_t operator()(const idx2& I) const noexcept;
};
}

#endif
