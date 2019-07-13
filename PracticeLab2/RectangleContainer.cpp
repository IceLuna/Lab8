#include "pch.h"
#include "RectangleContainer.h"
#include "Rectangle.h"


RectangleContainer::RectangleContainer()
{
	
}

RectangleContainer::RectangleContainer(const Rectangle & rect)
{
	head = std::make_shared<RectangleContainerItem>(rect);
	end  = head;
	size = 1;
}

RectangleContainer::RectangleContainer(const RectangleContainer & OtherContainer)
{

}


RectangleContainer::~RectangleContainer()
{
	//std::cout << "Deleted... " << this << std::endl;
	//Deleter();
}

void RectangleContainer::Push(const Rectangle& rect)
{
	if (head != nullptr)
	{
		RectangleContainerItem item(rect);
		end->SetNext(item);
		end = end->GetNext();
	}
	else {
		head = std::make_shared<RectangleContainerItem>(rect);
		end = head;
	}
	++size;
}

Rectangle RectangleContainer::GetRectangle()
{
	return head->GetRectangle();
}

void RectangleContainer::Remove()
{	
	if (head != nullptr)
	{
		if (head->GetNext() == nullptr)
		{
			head = end = nullptr;
		}
		else 
		{
			head = head->GetNext();
		}
		--size;
	}
}

bool RectangleContainer::IsEmpty() const
{
	return !size;
}

size_t RectangleContainer::GetSize() const
{
	return size;
}

/*
void RectangleContainer::Deleter()
{
	std::cout << "Deleter\n";
	if (value)
	{
		std::cout << *value << std::endl;
		//delete value;
		value = nullptr;
		//value.reset();
	}
	if (next)
	{
		//delete next;
		//next.reset();
		next = nullptr;
	}
}
*/

std::ostream & operator<<(std::ostream & out, const RectangleContainer & container)
{
	size_t size = container.size;
	if (size)
	{
		std::shared_ptr<const RectangleContainerItem> item = container.head;
		for (size_t i = 0; i < size; ++i)
		{
			out << item->GetRectangle() <<std::endl;
			item = item->GetNext();
		}
	}
	return out;
}
