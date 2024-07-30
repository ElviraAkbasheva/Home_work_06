#pragma once

template <typename T>
class SingleLinkContainer
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* m_nodePtrNext;
		T m_nodeItem;

		Node(T item = T(), Node *ptrNext = nullptr)
		{
			m_nodePtrNext = ptrNext;
			m_nodeItem = item;
		}
	};

	int m_size;  
	Node<T>* m_ptrHead;

public:
	SingleLinkContainer();
	SingleLinkContainer(const SingleLinkContainer&);
	SingleLinkContainer<T>& operator = (const SingleLinkContainer&);
	~SingleLinkContainer();
	T& operator [] (int);
	SingleLinkContainer(SingleLinkContainer&&);
	SingleLinkContainer<T>& operator = (SingleLinkContainer&&);
	void content();
	void push_back(T);
	void size();
	void erase_front();
	void clear();
	void push_front(T);
	void insert(T, int);
	void erase(int);
};
