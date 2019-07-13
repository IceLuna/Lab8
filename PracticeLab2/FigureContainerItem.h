#pragma once
#include <memory>
#include "TAllocator.h"
#include <iostream>

template <class T>
class FigureContainerItem
{
private:
	std::shared_ptr<T> value = nullptr;
	std::shared_ptr<FigureContainerItem<T>> next = nullptr;
	static TAllocator Allocator;
public:
	FigureContainerItem();
	FigureContainerItem(const T& val);
	FigureContainerItem(const FigureContainerItem<T>& other);
	virtual ~FigureContainerItem();

	void SetNext(const T& NewNext);
	std::shared_ptr<FigureContainerItem<T>> GetNext() const;
	std::shared_ptr<T> GetFigure() const;

	void* operator new(size_t Size)
	{
		return Allocator.Allocate();
	}
	void  operator delete(void* Pointer)
	{
		Allocator.Deallocate(Pointer);
	}
};

template <class T>
TAllocator FigureContainerItem<T>::Allocator(sizeof(FigureContainerItem<T>), 1001);

//FigureContainerItem.cpp
template <class T>
FigureContainerItem<T>::FigureContainerItem()
{
}

template <class T>
FigureContainerItem<T>::FigureContainerItem(const T & val) : value(new T(val))
{ }

template <class T>
FigureContainerItem<T>::FigureContainerItem(const FigureContainerItem<T>& other)
{
	value = std::shared_ptr<T>(new T(*other.value));

	std::shared_ptr<FigureContainerItem<T>> TempNext = other.next;
	while (TempNext)
	{
		this->SetNext(*TempNext->value);
		TempNext = TempNext->GetNext();
	}
}


template <class T>
FigureContainerItem<T>::~FigureContainerItem()
{
	//std::cout << "Deleted addr " << this << " Val: " << *value << "\n";
}

template <class T>
void FigureContainerItem<T>::SetNext(const T& NewNext)
{
	//next = std::make_shared<FigureContainerItem<T>>(NewNext);
	next = std::shared_ptr<FigureContainerItem<T>>(new FigureContainerItem<T>(NewNext));
}

template<class T>
std::shared_ptr<FigureContainerItem<T>> FigureContainerItem<T>::GetNext() const
{
	return next;
}

template <class T>
std::shared_ptr<T> FigureContainerItem<T>::GetFigure() const
{
	return value;
}


