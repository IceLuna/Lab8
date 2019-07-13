#pragma once
#include <iostream>

class Figure
{
public:
	Figure();
	virtual ~Figure();

	virtual void  Print()  const = 0;
	virtual float Square() const = 0;
};

