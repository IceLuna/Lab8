#pragma once
#include "Figure.h"
#include <iostream>
class Triangle : public Figure
{
private:
	float a, b, c;
public:
	Triangle();
	Triangle(float a, float b, float c);
	Triangle(const Triangle& obj);
	Triangle(std::istream& in);
	virtual ~Triangle();

	virtual void Print() const override;
	virtual float Square() const override;

	friend std::istream& operator>> (std::istream& In, Triangle& Obj);
	friend std::ostream& operator<< (std::ostream& Out, const Triangle& Obj);

	Triangle& operator= (const Triangle& other);
	bool operator== (const Triangle& other) const;
	bool operator>  (const Triangle& other) const;
	bool operator<  (const Triangle& other) const;
};

