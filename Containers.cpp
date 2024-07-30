#include <iostream>
#include <string>
#include "SerialContainer.h"
#include "SerialContainer.cpp"
#include "SingleLinkContainer.h"
#include "SingleLinkContainer.cpp"
#include "DoubleLinkContainer.h"
#include "DoubleLinkContainer.cpp"

template <typename T, typename U>
T Simple_Demonstration(T container, std::string name, const U& item, int size)
{
	for (int i = 0; i < size; i++)
	{
		container.push_back(item[i]);
	}
	std::cout << std::endl << "ДЕЙСТВИЯ С КОНТЕЙНЕРОМ" << std::endl << std::endl;
	std::cout << name << std::endl << std::endl;
	container.content();
	container.size();
	std::cout << std::endl << "Обращение по индексу" << std::endl;
	std::cout << container[0] << ", ";
	std::cout << container[1] << ", ";
	std::cout << container[2] << std::endl;
	std::cout << std::endl << "Удаление элементов" << std::endl;
	container.erase(2);
	container.erase(3);
	container.erase(4);
	container.content();
	std::cout << std::endl << "Вставка элемента в начало" << std::endl;
	container.push_front(10);
	container.content();
	std::cout << std::endl << "Вставка элемента в середину" << std::endl;
	container.insert(20, 4);
	container.content();
	std::cout << std::endl << "Вставка элемента в конец" << std::endl;
	container.push_back(30);
	container.content();
	std::cout << std::endl << "Присваивание значения" << std::endl;
	container[1] = 100;
	container.content();
	std::cout << std::endl << "Простое копирование" << std::endl;
	T copyContainer = container;
	copyContainer.content();
	std::cout << std::endl;

	return copyContainer;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int numbers[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(numbers) / sizeof(int);

	SerialContainer<int> Serial;
	SingleLinkContainer<int> SingleLink;
	DoubleLinkContainer<int> DoubleLink;

	SerialContainer<int> target_Serial;
	SingleLinkContainer<int> target_SingleLink;
	DoubleLinkContainer<int> target_DoubleLink;

	SerialContainer<int> ref_Serial;
	SingleLinkContainer<int> ref_SingleLink;
	DoubleLinkContainer<int> ref_DoubleLink;

	target_Serial = ref_Serial = Simple_Demonstration(Serial, "<< Последовательный контейнер >>", numbers, size);
	target_SingleLink = ref_SingleLink = Simple_Demonstration(SingleLink, "<< Односвязанный контейнер >>", numbers, size);
	target_DoubleLink = ref_DoubleLink = Simple_Demonstration(DoubleLink, "<< Двусвязанный контейнер >>", numbers, size);

	std::cout << std::endl << "СЕМАНТИКА ПЕРЕМЕЩЕНИЯ (конструктор перемещения, присваивание перемещением)" << std::endl;

	std::cout << std::endl << "Последовательный контейнер" << std::endl;
	target_Serial.content();
	std::cout << std::endl << "Односвязанный контейнер" << std::endl;
	target_SingleLink.content();
	std::cout << std::endl << "Двусвязанный контейнер" << std::endl;
	target_DoubleLink.content();
}


