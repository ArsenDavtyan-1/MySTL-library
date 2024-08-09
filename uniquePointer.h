#ifndef UNIQUEPOINTER_H_
#define UNIQUEPOINTER_H_


template <typename T>
class uniquePointer
{
private:
	T* m_ptr = nullptr;
public:
	explicit uniquePointer(T* ptr);
	uniquePointer(uniquePointer&&) noexcept;
	uniquePointer& operator=(uniquePointer&&);
	uniquePointer(const uniquePointer&) = delete;
	uniquePointer& operator=(const uniquePointer&) = delete;
	T* operator->()
	{
		return m_ptr;
	}
	T& operator*()
	{
		return *m_ptr;
	}
	~uniquePointer();
};


template <typename T>
uniquePointer<T>::uniquePointer(T* ptr)
{
	std::cout << "Called uniquePointer's constructor for pointer" << std::endl;
	m_ptr = ptr;
}


template <typename T>
uniquePointer<T>::uniquePointer(uniquePointer&& other) noexcept
{
	std::cout << "Called uniquePointer's move constructor" << std::endl;
	m_ptr = other.m_ptr;
	other.m_ptr = nullptr;
}


template <typename T>
uniquePointer<T>& uniquePointer<T>::operator=(uniquePointer&& other)
{
	std::cout << "Called uniquePointer's move assignment operator" << std::endl;
	if (this != &other) {
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	return *this;
}

template <typename T>
uniquePointer<T>::~uniquePointer()
{
	if (m_ptr) {
		std::cout << "deleting uniquePointer's pointer" << std::endl;
		delete m_ptr;
	}
}



// Specialization for arrays

template <typename T>
class uniquePointer<T[]>
{
private:
	T* m_ptr = nullptr;
public:
	explicit uniquePointer(T* ptr)
	{
		std::cout << "Called uniquePointer's constructor for array" << std::endl;
		m_ptr = ptr;
	}
	uniquePointer(uniquePointer&&) noexcept;
	uniquePointer& operator=(uniquePointer&&);
	uniquePointer(const uniquePointer&) = delete;
	uniquePointer& operator=(const uniquePointer&) = delete;
	T& operator[](size_t index)
	{
		return m_ptr[index];
	}
	~uniquePointer()
	{
		if (m_ptr) {
			std::cout << "deleting uniquePointer's array" << std::endl;
			delete[] m_ptr;
		}
	}
};

template <typename T>
uniquePointer<T[]>::uniquePointer(uniquePointer&& other) noexcept
{
	std::cout << "Called uniquePointer's move constructor for array" << std::endl;
	m_ptr = other.m_ptr;
	other.m_ptr = nullptr;
}


template <typename T>
uniquePointer<T[]>& uniquePointer<T[]>::operator=(uniquePointer&& other)
{
	std::cout << "Called uniquePointer's move assignment operator for array" << std::endl;
	if (this != &other) {
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	return *this;
}

#endif // !UNIQUEPOINTER_H_

