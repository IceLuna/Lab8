#include "pch.h"
#include "Triangle.h"


Triangle::Triangle()
{
}

Triangle::Triangle(float a, float b, float c) : a(a),  b(b), c(c)
{
}

Triangle::Triangle(const Triangle & obj) : a(obj.a), b(obj.b), c(obj.c)
{
}

Triangle::Triangle(std::istream & in)
{
	in >> a >> b >> c;
}


Triangle::~Triangle()
{
}

void Triangle::Print() const
{
	std::cout << "Triangle: a = " << a << " b = " << b << " c = " << c << std::endl;
}

float Triangle::Square() const
{
	return a * b / 2;
}

Triangle & Triangle::operator=(const Triangle & other)
{
	a = other.a;
	b = other.b;
	c = other.c;
	return *this;
}

bool Triangle::operator==(const Triangle & other) const
{
	return (fabs(a - other.a) < 1e-6) && (fabs(b - other.b) < 1e-6) && (fabs(c - other.c) < 1e-6);
}

bool Triangle::operator>(const Triangle & other) const
{
	return this->Square() > other.Square();
}

bool Triangle::operator<(const Triangle & other) const
{
	return this->Square() < other.Square();
}

std::istream & operator>>(std::istream & In, Triangle & Obj)
{
	In >> Obj.a >> Obj.b >> Obj.c;
	return In;
}

std::ostream & operator<<(std::ostream & Out, const Triangle & Obj)
{
	Out << Obj.a << " " << Obj.b << " " << Obj.c;
	return Out;
}
