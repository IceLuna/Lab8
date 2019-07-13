#pragma once
#include <memory>
#include <iostream>
#include "FigureContainerItem.h"
#include "ContainerIterator.h"
#include <thread>
#include <future>

template <class T>
class FigureContainer
{
	size_t size = 0;
	std::shared_ptr<FigureContainerItem<T>> head = nullptr;
	std::shared_ptr<FigureContainerItem<T>> endp = nullptr;

	void ParalArraySort(T* Array, int left, int right);
	void ArraySort     (T* Array, int left, int right);

public:
	FigureContainer();
	FigureContainer(const T& rect);
	FigureContainer(const FigureContainer<T>& OtherContainer);
	virtual ~FigureContainer();

	ContainerIterator<T> begin()
	{
		return ContainerIterator<T>(head);
	}
	ContainerIterator<T> end()
	{
		return ContainerIterator<T>();
	}


	void Push(const T& rect);
	T Get();
	void Remove();

	bool IsEmpty() const;
	size_t GetSize() const;
	//void Deleter();

	void Sort(bool DoParallel);

	template <class A>
	friend std::ostream& operator<< (std::ostream& out, const FigureContainer<A>& container);
};



//FigureContainer.cpp
template <class T>
FigureContainer<T>::FigureContainer()
{

}

template <class T>
FigureContainer<T>::FigureContainer(const T & rect)
{
	// head = std::make_shared<FigureContainerItem<T>>(rect);
	head = std::shared_ptr<FigureContainerItem<T>>(new T(rect));
	endp = head;
	size = 1;
}

template <class T>
FigureContainer<T>::FigureContainer(const FigureContainer<T> & OtherContainer)
{
	size_t newsize = OtherContainer.size;
	std::shared_ptr<FigureContainerItem<T>> Next = OtherContainer.head;
	for (size_t i = 0; i < newsize; ++i)
	{
		this->Push(*(Next->GetFigure()));
		Next = Next->GetNext();
	}
}


template <class T>
FigureContainer<T>::~FigureContainer()
{
	//std::cout << "Deleted... " << this << std::endl;
	//Deleter();
}

template<class T>
void FigureContainer<T>::Push(const T& rect)
{
	if (head != nullptr)
	{
		//FigureContainerItem<T> item(rect);
		endp->SetNext(rect);
		endp = endp->GetNext();
	}
	else {
		//head = std::make_shared<FigureContainerItem<T>>(rect);
		FigureContainerItem<T>* item = new FigureContainerItem<T>(rect);
		std::cout << "Used: " << item << std::endl;
		head = std::shared_ptr<FigureContainerItem<T>>(item);
		endp = head;
	}
	++size;
}

template <class T>
T FigureContainer<T>::Get()
{
	return *(head->GetFigure());
}

template <class T>
void FigureContainer<T>::Remove()
{
	if (head != nullptr)
	{
		if (head->GetNext() == nullptr)
		{
			head = endp = nullptr;
		}
		else
		{
			head = head->GetNext();
		}
		--size;
	}
}

template <class T>
bool FigureContainer<T>::IsEmpty() const
{
	return !size;
}

template <class T>
size_t FigureContainer<T>::GetSize() const
{
	return size;
}

template <class A>
std::ostream & operator<<(std::ostream & Out, const FigureContainer<A> & Container)
{
	size_t size = Container.size;
	if (size)
	{
		std::shared_ptr<const FigureContainerItem<A>> item = Container.head;
		for (size_t i = 0; i < size; ++i)
		{
			Out << *(item->GetFigure()) << std::endl;
			item = item->GetNext();
		}
	}
	return Out;
}


template<class T>
void FigureContainer<T>::Sort(bool DoParall)
{
	size_t TempSize = size;
	T* Array = new T[size];
	for (size_t i = 0; !IsEmpty(); ++i)
	{
		Array[i] = Get();
		Remove();
	}

	if (DoParall)
	{
		std::cout << "Paral!\n";
		ParalArraySort(Array, 0, TempSize - 1);
	}
	else
	{
		std::cout << "Single Thread!\n";
		ArraySort(Array, 0, TempSize - 1);
	}

	for (size_t i = 0; i < TempSize; ++i)
	{
		Push(Array[i]);
	}
	delete[] Array;
}

template<class T>
void FigureContainer<T>::ArraySort(T* Array, int left, int right)
{
	int i = left, j = right;
	T Temp;
	T Pivot = Array[(left + right) / 2];

	while (i <= j)
	{
		while (Array[i] < Pivot)
		{
			++i;
		}
		while (Array[j] > Pivot)
		{
			--j;
		}

		if (i <= j)
		{
			Temp = Array[i];
			Array[i] = Array[j];
			Array[j] = Temp;
			++i;
			--j;
		}
	}

	if (left < j)
	{
		ArraySort(Array, left, j);
	}
	if (right > i)
	{
		ArraySort(Array, i, right);
	}
}

template<class T>
void FigureContainer<T>::ParalArraySort(T* Array, int left, int right)
{
	int i = left, j = right;
	T Temp;
	T Pivot = Array[(left + right) / 2];

	while (i <= j)
	{
		while (Array[i] < Pivot)
		{
			++i;
		}
		while (Array[j] > Pivot)
		{
			--j;
		}

		if (i <= j)
		{
			Temp = Array[i];
			Array[i] = Array[j];
			Array[j] = Temp;
			++i;
			--j;
		}
	}
	if (size > 400)
	{
		if (left < j)
		{
			std::async([this, Array, &left, &j]()
			{
				this->ParalArraySort(Array, left, j);
			});
			//std::thread Thread(&FigureContainer<T>::ParalArraySort, this, Array, left, j);
			//Thread.detach();
		}
		if (right > i)
		{
			std::async([this, Array, &i, &right]()
			{
				this->ParalArraySort(Array, i, right);
			});
			//std::thread Thread(&FigureContainer<T>::ParalArraySort, this, Array, i, right);
			//Thread.detach();
		}
	}
	else
	{
		if (left < j)
		{
			this->ParalArraySort(Array, left, j);
		}
		if (right > i)
		{
			this->ParalArraySort(Array, i, right);
		}
	}
	
}