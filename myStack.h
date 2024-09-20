#ifndef MY_STACK_H_
#define MY_STACK_H_

#include <iostream>

namespace my
{

	template <typename T>
	class stack
	{
	public:
		stack() : m_size(0), m_capacity(10) { m_ptr = new T[m_capacity]; }
		stack(const stack& other);
		stack& operator=(const stack& other);
		stack& push(T value);
		void pop();
		T& top();
		bool is_empty() { return !m_size; }
	private:
		size_t m_size;
		size_t m_capacity;
		T* m_ptr;
	};
	
}



template <typename T>
my::stack<T>& my::stack<T>::push(T value)
{
	if (m_size == m_capacity)
	{
		m_capacity *= 2;
		T* tempPtr = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i)
			tempPtr[i] = m_ptr[i];
		delete[] m_ptr;
		m_ptr = tempPtr;
	}
	++m_size;
	m_ptr[m_size - 1] = value;
	return *this;
}


template <typename T>
my::stack<T>::stack(const stack<T>& other)
{
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_ptr = new T[m_capacity];
	for (int i = 0; i < m_size; ++i)
		m_ptr[i] = other.m_ptr[i];
}


template <typename T>
my::stack<T>& my::stack<T>::operator=(const stack<T>& other)
{
	if (this != &other)
	{
		delete[] m_ptr;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_ptr = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
			m_ptr[i] = other.m_ptr[i];
	}
	return *this;
}


template <typename T>
T& my::stack<T>::top()
{
	return m_ptr[m_size - 1];
}


// pop doesn't checks, is the stack empty
template <typename T>
void my::stack<T>::pop()
{
	--m_size;
	if (m_size == m_capacity / 2 && m_capacity > 10)
	{
		m_capacity /= 2;
		T* tempPtr = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
			tempPtr[i] = m_ptr[i];
		delete[] m_ptr;
		m_ptr = tempPtr;
	}
}





#endif // ! MY_STACK_H_