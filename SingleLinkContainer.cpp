#include <iostream>
#include "SingleLinkContainer.h"

template <typename T>
SingleLinkContainer<T>::SingleLinkContainer()
{
	m_size = 0;
	m_ptrHead = nullptr;
}

template <typename T>
SingleLinkContainer<T>::SingleLinkContainer(const SingleLinkContainer& other)
{
	this->m_size = 0;
	this->m_ptrHead = nullptr;

	Node<T>* ptrTemp = other.m_ptrHead;
	for (int i = 0; i < other.m_size; i++)
	{
		this->push_back(ptrTemp->m_nodeItem);
		ptrTemp = ptrTemp->m_nodePtrNext;
	}
	delete ptrTemp;
}

template <typename T>
SingleLinkContainer<T>& SingleLinkContainer<T>::operator = (const SingleLinkContainer& other)
{
	this->clear();
	this->SingleLinkContainer<T>::SingleLinkContainer(other);
	return *this;
}

template <typename T>
SingleLinkContainer<T>::~SingleLinkContainer()
{
	clear();
}

template <typename T>
T& SingleLinkContainer<T>::operator [] (int index)
{
	int counter = 0;
	Node<T>* ptrCurrent = m_ptrHead;
	while (ptrCurrent != nullptr)
	{
		if (counter == index)
		{
			return ptrCurrent->m_nodeItem;
		}
		ptrCurrent = ptrCurrent->m_nodePtrNext;
		counter++;
	}
}

template <typename T>
SingleLinkContainer<T>::SingleLinkContainer(SingleLinkContainer&& other)
{
	m_size = other.m_size;
	m_ptrHead = other.m_ptrHead;
	other.m_size = 0;
	other.m_ptrHead = nullptr;
}

template <typename T>
SingleLinkContainer<T>& SingleLinkContainer<T>::operator = (SingleLinkContainer&& other)
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		this->clear();
		m_size = other.m_size;
		m_ptrHead = other.m_ptrHead;
		other.m_size = 0;
		other.m_ptrHead = nullptr;
		return *this;
	}
}

template <typename T>
void SingleLinkContainer<T>::content()
{
	std::cout << "Содержимое контейнера: ";

	Node<T>* ptrCurrent = m_ptrHead;
	for (int i = 0; i < m_size; i++)
	{
		std::cout << ptrCurrent->m_nodeItem;
		ptrCurrent = ptrCurrent->m_nodePtrNext;

		if (i < m_size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

template <typename T>
void SingleLinkContainer<T>::push_back(T item)
{
	if (m_ptrHead == nullptr)
	{
		m_ptrHead = new Node<T>(item);
	}
	else
	{
		Node<T>* ptrCurrent = m_ptrHead;
		while (ptrCurrent->m_nodePtrNext != nullptr)
		{
			ptrCurrent = ptrCurrent->m_nodePtrNext;
		}
		ptrCurrent->m_nodePtrNext = new Node<T>(item);
	}
	m_size++;
}

template <typename T>
void SingleLinkContainer<T>::size()
{
	std::cout << "Размер контейнера: " << m_size << std::endl;
}

template <typename T>
void SingleLinkContainer<T>::erase_front()
{
	Node<T>* ptrTemp = m_ptrHead;
	m_ptrHead = m_ptrHead->m_nodePtrNext;
	delete ptrTemp;
	m_size--;
}



template <typename T>
void SingleLinkContainer<T>::clear()
{
	while (m_size != 0)
	{
		erase_front();
	}
}

template <typename T>
void SingleLinkContainer<T>::push_front(T item)
{
	m_ptrHead = new Node<T>(item, m_ptrHead);
	m_size++;
}

template <typename T>
void SingleLinkContainer<T>::insert(T item, int index)
{
	if (index == 0)
	{
		push_front(item);
	}
	else
	{

		Node<T>* ptrPrevious = m_ptrHead;
		for (int i = 0; i < index - 1; i++)
		{
			ptrPrevious = ptrPrevious->m_nodePtrNext;
		}
		Node<T>* ptrInsert = new Node<T>(item, ptrPrevious->m_nodePtrNext);
		ptrPrevious->m_nodePtrNext = ptrInsert;
		m_size++;
	}
}

template <typename T>
void SingleLinkContainer<T>::erase(int index)
{
	if (index == 0)
	{
		erase_front();
	}

	else
	{
		Node<T>* ptrPrevious = m_ptrHead;
		for (int i = 0; i < index - 1; i++)
		{
			ptrPrevious = ptrPrevious->m_nodePtrNext;
		}
		Node<T>* ptrDelete = ptrPrevious->m_nodePtrNext;
		ptrPrevious->m_nodePtrNext = ptrDelete->m_nodePtrNext;
		delete ptrDelete;
		m_size--;
	}
}