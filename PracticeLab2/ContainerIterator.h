#pragma once
#include <memory>
#include "FigureContainerItem.h"

template <class T>
class ContainerIterator
{
private:
	std::shared_ptr<FigureContainerItem<T>> Ptr = nullptr;
public:
	ContainerIterator(){}
	ContainerIterator(std::shared_ptr<FigureContainerItem<T>> ptr) : Ptr(ptr) {}
	virtual ~ContainerIterator(){}

	std::shared_ptr<T> operator* ()
	{
		return (Ptr->GetFigure());
	}

	std::shared_ptr<T> operator-> ()
	{
		if (Ptr)
			return Ptr->GetFigure();
		else return nullptr;
	}

	ContainerIterator<T>& operator++()
	{
		Ptr = Ptr->GetNext();
		return *this;
	}
	
	bool operator== (const ContainerIterator<T>& Other)
	{
		return Ptr == Other.Ptr;
	}
	bool operator!= (const ContainerIterator<T>& Other)
	{
		return !(this->operator==(Other));
	}
};

