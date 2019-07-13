#include "pch.h"
#include "Rectangle.h"


Rectangle::Rectangle()
{
}

Rectangle::Rectangle(float a, float b) : a(a), b(b)
{
}

Rectangle::Rectangle(std::istream & in)
{
	in >> a;
	in >> b;
}

Rectangle::Rectangle(const Rectangle & obj)
{
	a = obj.a;
	b = obj.b;
}


Rectangle::~Rectangle()
{
}

void Rectangle::Print() const
{
	std::cout << "Rectangle! A = " << a << " B = " << b << std::endl;
}

float Rectangle::Square() const
{
	return a * b;
}

Rectangle & Rectangle::operator=(const Rectangle & other)
{
	this->a = other.a;
	this->b = other.b;
	return *this;
}

bool Rectangle::operator==(const Rectangle & other)
{
	return (fabs(this->a - other.a) < 1e-6) && (fabs(this->b - other.b) < 1e-6);
}

std::ostream & operator<<(std::ostream & out, const Rectangle & obj)
{
	out << obj.a << " " << obj.b;
	return out;
}

std::istream & operator>>(std::istream & in, Rectangle & obj)
{
	in >> obj.a >> obj.b;
	return in;
}
