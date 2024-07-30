#include <iostream>
#include "SerialContainer.h"

template <typename T>
SerialContainer<T>::SerialContainer()
{
	m_size = 0;
	m_Fsize = 0;
	m_region = nullptr;
}

template <typename T>
SerialContainer<T>::SerialContainer(const SerialContainer& other)
{
	this->m_size = other.m_size;
	this->m_Fsize = other.m_Fsize;
	this->m_region = new T[other.m_Fsize];
	for (int i = 0; i < other.m_Fsize; i++)
	{
		this->m_region[i] = other.m_region[i];
	}
}

template <typename T>
SerialContainer<T>& SerialContainer<T>::operator = (const SerialContainer& other)
{
	this->m_size = other.m_size;

	if (this->m_region == nullptr)
	{
		this->m_region = new T[other.m_Fsize];
		for (int i = 0; i < other.m_size; i++)
		{
			this->m_region[i] = other.m_region[i];
		}
		this->m_Fsize = other.m_Fsize;
	}
	else
	{
		if (this->m_Fsize >= other.m_size)
		{
			for (int i = 0; i < other.m_size; i++)
			{
				this->m_region[i] = other.m_region[i];
			}
		}
		else
		{
			delete[] this->m_region;
			this->m_region = new T[other.m_Fsize];
			for (int i = 0; i < other.m_size; i++)
			{
				this->m_region[i] = other.m_region[i];
			}
			this->m_Fsize = other.m_Fsize;
		}
	}

	return *this;
}

template <typename T>
SerialContainer<T>::~SerialContainer()
{
	delete[] m_region;
}

template <typename T>
T& SerialContainer<T>::operator [] (int index)
{
	return m_region[index];
}

template <typename T>
SerialContainer<T>::SerialContainer(SerialContainer&& other)
{
	this->m_size = other.m_size;
	this->m_Fsize = other.m_Fsize;
	this->m_region = other.m_region;
	other.m_region = nullptr;
}

template <typename T>
SerialContainer<T>& SerialContainer<T>::operator = (SerialContainer&& other)
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		delete[] m_region;
		m_size = other.m_size;
		m_Fsize = other.m_Fsize;
		m_region = other.m_region;
		other.m_region = nullptr;
		return *this;
	}
}

template <typename T>
void SerialContainer<T>::content()
{
	std::cout << "Содержимое контейнера: ";

	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_region[i];
		if (i < m_size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

template <typename T>
void SerialContainer<T>::size()
{
	std::cout << "Размер контейнера: " << m_size << std::endl;
}

template <typename T>
void SerialContainer<T>::erase(int index)
{
	for (int i = index; i < m_size - 1; i++)
	{
		m_region[i] = m_region[i + 1];
	}
	m_size--;
}
template <typename T>
void SerialContainer<T>::insert(T value, int index)
{
	if (m_size == 0)
	{
		T* newRegion = new T[1];
		newRegion[0] = value;
		m_region = newRegion;
	}
	else
	{
		if (m_Fsize < m_size + 1)
		{
			m_Fsize = m_size * 2;

			T* newRegion = new T[m_Fsize];
			if (index == m_size)
			{
				for (int i = 0; i < m_size; i++)
				{
					newRegion[i] = m_region[i];
				}
				newRegion[index] = value;
				delete[] m_region;
				m_region = newRegion;
			}
			else
			{
				for (int i = 0; i < index; i++)
				{
					newRegion[i] = m_region[i];
				}
				for (int i = index; i < m_size; i++)
				{
					newRegion[i + 1] = m_region[i];
				}
				newRegion[index] = value;
				delete[] m_region;
				m_region = newRegion;
			}
		}
		else
		{
			for (int i = m_size - 1; i >= index; i--)
			{
				m_region[i + 1] = m_region[i];
			}
			m_region[index] = value;
		}
	}
	m_size++;
}

template <typename T>
void SerialContainer<T>::push_back(T value)
{
	if (m_size == 0)
	{
		push_front(value);
	}
	else
	{
		insert(value, m_size);
	}
}

template <typename T>
void SerialContainer<T>::push_front(T value)
{
	insert(value, 0);
}