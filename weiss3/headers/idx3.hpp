//indices - P. Ahrenkiel

#ifndef _IDX3_
#define _IDX3_

#include "dbl1.hpp"

class crd3;
class vtr3;

class idx3:public crd3
{
private:
	explicit idx3(const crd3 &C);

public:
	double& h();
	double& k();
	double& l();
	
	double const& h() const;
	double const& k() const;
	double const& l() const;
	
	idx3();
	idx3(const double h,const double k,const double l);
	idx3(const arr::dbl1 &D);

	idx3 round() const;
	idx3 operator+(const idx3 &I) const;
	idx3 operator-(const idx3 &I) const;
	idx3 operator+=(const idx3 &I);
	idx3 operator-=(const idx3 &I);
	bool operator==(const idx3 &I) const;
	bool operator!=(const idx3 &I) const;

	static const idx3 I000;
	static const idx3 I100;
	static const idx3 I010;
	static const idx3 I001;
	static const idx3 I111;
	static const idx3 Imid;

	friend std::ostream& operator<<(std::ostream &os,const idx3 &I);
};

idx3 round(const idx3 &I3);

namespace std
{
template<>
struct hash<idx3> {
	std::size_t operator()(const idx3& I) const noexcept;
};
}

#endif
