#pragma once
#include "Figure.h"
#include <iostream>

class Rectangle : public Figure
{
private:
	float a, b;

public:
	Rectangle();
	Rectangle(float a, float b);
	Rectangle(std::istream& in);
	Rectangle(const Rectangle& obj);
	virtual ~Rectangle();
	
	virtual void  Print()  const override;
	virtual float Square() const override;

	friend std::ostream& operator<< (std::ostream& out, const Rectangle& obj);
	friend std::istream& operator>> (std::istream& in,		  Rectangle& obj);

	Rectangle& operator=  (const Rectangle& other);
	bool	   operator== (const Rectangle& other);
};

