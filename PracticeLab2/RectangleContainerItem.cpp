#include "pch.h"
#include "RectangleContainerItem.h"


RectangleContainerItem::RectangleContainerItem()
{
}

RectangleContainerItem::RectangleContainerItem(const Rectangle & val) : value(val)
{
}


RectangleContainerItem::~RectangleContainerItem()
{
	//std::cout << "Deleted addr " << this << " Val: " << value << "\n";
}

void RectangleContainerItem::SetNext(const RectangleContainerItem & NewNext)
{
	next = std::make_shared<RectangleContainerItem>(NewNext);
}

std::shared_ptr<RectangleContainerItem> RectangleContainerItem::GetNext() const
{
	return next;
}

Rectangle RectangleContainerItem::GetRectangle() const
{
	return value;
}
