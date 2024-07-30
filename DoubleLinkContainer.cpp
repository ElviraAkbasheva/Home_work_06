#include <iostream>
#include "DoubleLinkContainer.h"

template <typename T>
DoubleLinkContainer<T>::DoubleLinkContainer()
{
	m_size = 0;
	m_ptrHead = nullptr;
	m_ptrTail = nullptr;
}

template <typename T>
DoubleLinkContainer<T>::DoubleLinkContainer(const DoubleLinkContainer& other)
{
	this->m_size = 0;
	this->m_ptrHead = nullptr;
	this->m_ptrTail = nullptr;

	Node<T>* ptrTemp = other.m_ptrHead;
	for (int i = 0; i < other.m_size; i++)
	{
		this->push_back(ptrTemp->m_nodeItem);
		ptrTemp = ptrTemp->m_nodePtrNext;
	}
	delete ptrTemp;
}

template <typename T>
DoubleLinkContainer<T>& DoubleLinkContainer<T>::operator = (const DoubleLinkContainer& other)
{
	this->clear();
	this->DoubleLinkContainer<T>::DoubleLinkContainer(other);
	return *this;
}

template <typename T>
DoubleLinkContainer<T>::~DoubleLinkContainer()
{
	clear();
}

template <typename T>
void DoubleLinkContainer<T>::push_back(T item)
{
	if (m_ptrHead == nullptr)
	{
		m_ptrHead = m_ptrTail = new Node<T>(item);
	}
	else
	{
		Node<T>* ptrNew = new Node<T>(item);
		ptrNew->m_nodePtrPrev = m_ptrTail;
		m_ptrTail->m_nodePtrNext = ptrNew;
		m_ptrTail = ptrNew;
	}
	m_size++;
}

template <typename T>
void DoubleLinkContainer<T>::size()
{
	std::cout << "Размер контейнера: " << m_size << std::endl;
}

template <typename T>
void DoubleLinkContainer<T>::content()
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
T& DoubleLinkContainer<T>::operator [] (int index)
{
	int border = m_size / 2;
	if (index <= border)
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
	else
	{
		int counter = m_size - 1;
		Node<T>* ptrCurrent = m_ptrTail;
		while (ptrCurrent != nullptr)
		{
			if (counter == index)
			{
				return ptrCurrent->m_nodeItem;
			}
			ptrCurrent = ptrCurrent->m_nodePtrPrev;
			counter--;
		}
	}

}

template <typename T>
DoubleLinkContainer<T>::DoubleLinkContainer(DoubleLinkContainer&& other)
{
	m_size = other.m_size;
	m_ptrHead = other.m_ptrHead;
	m_ptrTail = other.m_ptrTail;
	other.m_size = 0;
	other.m_ptrHead = nullptr;
}

template <typename T>
DoubleLinkContainer<T>& DoubleLinkContainer<T>::operator = (DoubleLinkContainer&& other)
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
		m_ptrTail = other.m_ptrTail;
		other.m_size = 0;
		other.m_ptrHead = nullptr;
		return *this;
	}
}

template <typename T>
void DoubleLinkContainer<T>::erase_front()
{
	Node<T>* ptrTemp = m_ptrHead;
	m_ptrHead = m_ptrHead->m_nodePtrNext;
	if (m_size > 1)
	{
		m_ptrHead->m_nodePtrPrev = nullptr;
	}
	delete ptrTemp;
	m_size--;
}

template <typename T>
void DoubleLinkContainer<T>::clear()
{
	while (m_size != 0)
	{
		erase_front();
	}
}

template <typename T>
void DoubleLinkContainer<T>::push_front(T item)
{
	Node<T>* ptrNew = new Node<T>(item);
	m_ptrHead->m_nodePtrPrev = ptrNew;
	ptrNew->m_nodePtrNext = m_ptrHead;
	m_ptrHead = ptrNew;
	m_size++;
}

template <typename T>
void DoubleLinkContainer<T>::insert(T item, int index)
{
	if (index == 0)
	{
		push_front(item);
	}
	else
	{
		int border = m_size / 2;
		if (index <= border)
		{
			Node<T>* ptrPrevious = m_ptrHead;
			for (int i = 0; i < index - 1; i++)
			{
				ptrPrevious = ptrPrevious->m_nodePtrNext;
			}
			Node<T>* ptrInsert = new Node<T>(item);
			ptrInsert->m_nodePtrPrev = ptrPrevious;
			ptrInsert->m_nodePtrNext = ptrPrevious->m_nodePtrNext;
			ptrPrevious->m_nodePtrNext = ptrInsert;
			m_size++;
		}
		else
		{
			Node<T>* ptrPrevious = m_ptrTail;
			for (int i = m_size - 1; i > index - 1; i--)
			{
				ptrPrevious = ptrPrevious->m_nodePtrPrev;
			}
			Node<T>* ptrInsert = new Node<T>(item);
			ptrInsert->m_nodePtrPrev = ptrPrevious;
			ptrInsert->m_nodePtrNext = ptrPrevious->m_nodePtrNext;
			ptrPrevious->m_nodePtrNext = ptrInsert;
			m_size++;
		}
	}
}

template <typename T>
void DoubleLinkContainer<T>::erase(int index)
{
	if (index == 0)
	{
		erase_front();
	}
	else
	{
		int border = m_size / 2;
		if (index <= border)
		{
			Node<T>* ptrPrevious = m_ptrHead;
			for (int i = 0; i < index - 1; i++)
			{
				ptrPrevious = ptrPrevious->m_nodePtrNext;
			}
			Node<T>* ptrDelete = ptrPrevious->m_nodePtrNext;
			ptrPrevious->m_nodePtrNext = ptrDelete->m_nodePtrNext;
			ptrDelete->m_nodePtrNext->m_nodePtrPrev = ptrDelete->m_nodePtrPrev;
			delete ptrDelete;
			m_size--;
		}
		else
		{
			Node<T>* ptrNext = m_ptrTail;
			for (int i = m_size - 1; i > index + 1; i--)
			{
				ptrNext = ptrNext->m_nodePtrPrev;
			}
			Node<T>* ptrDelete = ptrNext->m_nodePtrPrev;
			ptrNext->m_nodePtrPrev = ptrDelete->m_nodePtrPrev;
			ptrDelete->m_nodePtrPrev->m_nodePtrNext = ptrDelete->m_nodePtrNext;
			delete ptrDelete;
			m_size--;
		}
	}
}