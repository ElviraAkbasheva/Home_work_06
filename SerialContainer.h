#pragma once

template <typename T>
class SerialContainer
{
private:
	int m_size;
	int m_Fsize;
	T* m_region;
public:
	SerialContainer();
	~SerialContainer();
	SerialContainer(const SerialContainer&);
	SerialContainer<T>& operator = (const SerialContainer&);
	T& operator [] (int);
	SerialContainer(SerialContainer&&);
	SerialContainer<T>& operator = (SerialContainer&&);
	void content();
	void size();
	void erase(int);
	void insert(T, int);
	void push_back(T);
	void push_front(T);
};


