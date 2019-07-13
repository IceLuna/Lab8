// PracticeLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "RectangleContainer.h"
#include "Rectangle.h"
#include "FigureContainer.h"
#include <cstdlib>
#include "Triangle.h"
#include <chrono>

void Print(FigureContainer<Triangle> Container)
{
	std::cout << Container;
	Container.Remove();
	Container.Remove();
}

int main()
{
	FigureContainer<Triangle> Container;
	//Triangle Triangles[5] = { {0.f, 0.f, 0.f}, {1.f, 1.f, 1.f}, {2.f, 2.f, 2.f}, {3.f, 3.f, 3.f}, {4.f, 4.f, 4.f} };
	for (int i = 720; i >= 0; --i)
	{
		Container.Push({i * 1.f, i * 1.f, i * 1.f});
	}
	//Container.Remove();
	std::cin.get();
	std::cout << "BEFORE SORT!!!!\n";
	//for (auto p : Container)
		//std::cout << *p << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	Container.Sort(false);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "AFTER SORT!!!!\n";
	//for (auto p : Container)
		//std::cout << *p << std::endl;
	//Print(Container);
	system("pause");
	std::chrono::duration<float> duration = end - start;
	std::cout << "Time = " << duration.count() * 1000.f << std::endl;
	//Print(Container);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
