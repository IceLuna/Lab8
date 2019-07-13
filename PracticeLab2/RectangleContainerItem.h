#pragma once
#include <memory>
#include "Rectangle.h"

class RectangleContainerItem
{
private:
	Rectangle value;
	std::shared_ptr<RectangleContainerItem> next = nullptr;
public:
	RectangleContainerItem();
	RectangleContainerItem(const Rectangle& val);
	virtual ~RectangleContainerItem();

	void SetNext(const RectangleContainerItem& NewNext);
	std::shared_ptr<RectangleContainerItem> GetNext() const;
	Rectangle GetRectangle() const;
};

