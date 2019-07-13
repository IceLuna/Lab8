#pragma once
#include <iostream>
#include <memory>
#include "RectangleContainerItem.h"

class Rectangle;

//Queue
class RectangleContainer
{
	size_t size = 0;
	std::shared_ptr<RectangleContainerItem> head = nullptr;
	std::shared_ptr<RectangleContainerItem> end  = nullptr;
public:
	RectangleContainer();
	RectangleContainer(const Rectangle& rect);
	RectangleContainer(const RectangleContainer& OtherContainer);
	virtual ~RectangleContainer();

	void Push(const Rectangle& rect);
	Rectangle GetRectangle();
	void Remove();

	bool IsEmpty() const;
	size_t GetSize() const;
	//void Deleter();

	friend std::ostream& operator<< (std::ostream& out, const RectangleContainer& container);
};

