#pragma once

template <typename T>
class DoubleLinkContainer
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* m_nodePtrPrev;
		Node* m_nodePtrNext;
		T m_nodeItem;

		Node(T item = T(), Node* ptrPrev = nullptr, Node* ptrNext = nullptr)
		{
			m_nodePtrPrev = ptrPrev;
			m_nodePtrNext = ptrNext;
			m_nodeItem = item;
		}
	};

	int m_size;
	Node<T>* m_ptrHead;
	Node<T>* m_ptrTail;

public:
	DoubleLinkContainer();
	DoubleLinkContainer(const DoubleLinkContainer&);
	DoubleLinkContainer<T>& operator = (const DoubleLinkContainer&);
	~DoubleLinkContainer();
	T& operator [] (int);
	DoubleLinkContainer(DoubleLinkContainer&&);
	DoubleLinkContainer<T>& operator = (DoubleLinkContainer&&);
	void push_back(T);
	void content();
	void size();
	void erase_front();
	void clear();
	void push_front(T);
	void insert(T, int);
	void erase(int);
};