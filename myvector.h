#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <exception>
//#include "namespace.h"


namespace my
{
	template <class vector>
	class vectorIterator;

	template <typename T>
	class vector
	{
	private:
		int m_size;
		int m_cap;
		T* m_ptr;
	public:
		using Type = T;
		using Iterator = typename vectorIterator<vector<T>>;

		Iterator begin()
		{
			return Iterator(m_ptr);
		}
		Iterator end()
		{
			return Iterator(m_ptr + m_size);
		}
		vector();
		vector(std::initializer_list<T> init);
		vector(const vector& other);
		vector& operator=(const vector& other);
		vector(vector&&) = delete;
		vector& operator=(vector&& ) = delete;
		int getSize();
		int getCapacity();
		void push_back(T);
		void pop_back();
		void push_front(T);
		void pop_front();
		void insert(T value, int position);
		void remove(size_t position);
		void remove(Iterator& it);
		bool is_empty();
		void print();
		~vector();
		T operator[](int);
		T& at(int);
	};




	template <class vector>
	class vectorIterator
	{
	public:
		using ValueType = typename vector::Type;

		vectorIterator(ValueType* ptr) : m_Ptr(ptr) {}
		ValueType& operator*()
		{
			return *m_Ptr;
		}

		vectorIterator& operator++()
		{
			m_Ptr = ++m_Ptr;
			return *this;
		}

		vectorIterator& operator++(int)
		{
			vectorIterator temp = *this;
			m_Ptr = ++m_Ptr;
			return temp;
		}

		vectorIterator& operator+(size_t n)
		{
			m_Ptr += n;
			return *this;
		}

		vectorIterator& operator-(size_t n)
		{
			m_Ptr -= n;
			return *this;
		}

		bool operator==(const vectorIterator& obj)
		{
			return (obj.m_Ptr == m_Ptr);
		}

		bool operator!=(const vectorIterator& obj)
		{
			return !(obj.m_Ptr == m_Ptr);
		}

		void setIteratorPtr(ValueType* ptr)
		{
			m_Ptr = ptr;
		}
	private:
		ValueType* m_Ptr;
	};
}


template <typename T>
my::vector<T>::vector() : m_ptr(nullptr), m_size(0), m_cap(15)
{
	m_ptr = new T[m_cap];
}

template<typename T>
my::vector<T>::vector(std::initializer_list<T> init)
{
	m_size = init.size();
	m_cap = 15;
	while (m_cap < m_size)
		m_cap *= 2;
	m_ptr = new T[m_cap];
	int i = 0;
	for (const T& elem : init)
		m_ptr[i++] = elem;
}

template <typename T>
my::vector<T>::vector(const vector<T>& other)
{
	m_size = other.m_size;
	m_cap = other.m_cap;
	m_ptr = new T[m_cap];
	for (int i = 0; i < m_size; ++i)
		m_ptr[i] = other.m_ptr[i];
}

template <typename T>
my::vector<T>& my::vector<T>::operator=(const my::vector<T>& other)
{
	if (this != &other)
	{
		delete[] m_ptr;
		m_size = other.m_size;
		m_cap = other.m_cap;
		m_ptr = new T[m_cap];
		for (int i = 0; i < m_size; ++i)
			m_ptr[i] = other.m_ptr[i];
	}
	return* this;
}

template <typename T>
void my::vector<T>::push_back(T a)
{
	if (m_size < m_cap) {
		m_ptr[m_size++] = a;
	}
	else { 
		m_cap *= 2;
		T* tempptr = new T[m_cap];
		for (int i = 0; i < m_size; ++i)
		{
			tempptr[i] = m_ptr[i];
		}
		tempptr[m_size++] = a;
		delete[] m_ptr;
		m_ptr = tempptr;
		tempptr = nullptr;
	}
	return;
}

template <typename T>
void my::vector<T>::pop_back()
{
	if (is_empty())
		return;
	--m_size;
	if (m_size < (m_cap / 2) && m_cap > 15)
	{
		m_cap /= 2;
		T* new_ptr = new T[m_cap];
		for (int i = 0; i < m_size; ++i){
			new_ptr[i] = m_ptr[i];
		}
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	return;
}

template <typename T>
void my::vector<T>::push_front(T value)
{
	if (m_size + 1 >= m_cap){
		T* new_ptr = new T[m_cap * 2];
		new_ptr[0] = value;
		for (int i = 0; i < m_size; ++i)
			new_ptr[i + 1] = m_ptr[i];
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	else {
		for (int i = m_size - 1; i >= 0; --i)
			m_ptr[i + 1] = m_ptr[i];
		m_ptr[0] = value;
	}
	++m_size;
	return;
}

template <typename T>
void my::vector<T>::pop_front()
{
	if (m_size - 1 <= m_cap / 2 && m_cap > 15){
		T* new_ptr = new T[m_cap / 2];
		for (int i = 0; i < m_size - 1; ++i)
			new_ptr[i] = m_ptr[i + 1];
		m_cap /= 2;
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	else {
		for (int i = 0; i < m_size - 1; i++)
			m_ptr[i] = m_ptr[i + 1];
	}
	--m_size;
	return;
}

template <typename T>
void my::vector<T>::insert(T value, int position)
{
	if (position < 0 || position > m_size){
		std::cout << "invalid position for insert" << std::endl;
		return;
	}
	if (m_size + 1 > m_cap)
	{
		m_cap *= 2;
		T* new_ptr = new T[m_cap];
		for (int i = 0; i < position; ++i)
			new_ptr[i] = m_ptr[i];
		new_ptr[position] = value;
		for(int i = position + 1;i < m_size + 1; ++i)
			new_ptr[i] = m_ptr[i - 1];
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	else {
		for (int i = m_size; i > position; --i)
			m_ptr[i] = m_ptr[i - 1];
		m_ptr[position] = value;
	}

	++m_size;
	return;
}


template <typename T>
void my::vector<T>::remove(size_t position)
{
	if (position < 0 || position >= m_size)
	{
		std::cout << "invalid position for remove" << std::endl;
		return;
	}
	if (m_size - 1 < m_cap / 2)
	{
		m_cap /= 2;
		T* new_ptr = new T[m_cap];
		for (int i = 0; i < position; ++i)
			new_ptr[i] = m_ptr[i];
		for (int i = position + 1; i < m_size; ++i)
			new_ptr[i - 1] = m_ptr[i];
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	else
	{
		for (int i = position; i < m_size - 1; ++i)
			m_ptr[i] = m_ptr[i + 1];
	}
	
	--m_size;
	return;
}


template <typename T>
void my::vector<T>::remove(Iterator& it)
{
	size_t position = 0;

	Iterator i = this->begin();
	
	while (i != it)
	{
		++position;
		if (position >= m_size)
		{
			std::cout << "Invalid iterator" << std::endl;
			return;
		}
		++i;
	}
	remove(position);
	it.setIteratorPtr(m_ptr + position);
}


template <typename T>
int my::vector<T>::getSize()
{
	return m_size;
}

template <typename T>
int my::vector<T>::getCapacity()
{
	return m_cap;
}

template <typename T>
my::vector<T>::~vector()
{
	delete[] m_ptr;
}

template<typename T>
T my::vector<T>::operator[](int i)
{
	return m_ptr[i];
}

template<typename T>
inline bool my::vector<T>::is_empty()
{
	return !m_size;
}

template<typename T>
void my::vector<T>::print()
{
	if (m_size) {
		for (int i = 0; i < m_size; ++i)
		{
			std::cout << m_ptr[i] << ' ';
		}
		std::cout << '\n';
	}
	else {
		std::cout << "The container is empty" << std::endl;
	}
}


template <typename T>
T& my::vector<T>::at(int n)
{
	try {
		if (n < 0 || n >= m_size)
		{
			throw std::bad_variant_access();
		}
		return *(m_ptr + n);
	}
	catch (std::bad_variant_access& a){
		std::cout << a.what() << std::endl;
	}
}



bool isPrime(int a)
{
	if (a == 2)
		return true;
	if (a <= 1)
		return false;
	for (int i = 2; i * i <= a; ++i)
		if (a % i == 0)
			return false;
	return true;
}



void deletingPrimes(my::vector<int>& vec)
{
	using iter = typename my::vector<int>::Iterator;

	iter it = vec.begin();

	while (it != vec.end())
	{
		if (isPrime(*it))
			vec.remove(it);
		else
			++it;
	}

	return;
}



#endif // !MY_VECTOR_H
