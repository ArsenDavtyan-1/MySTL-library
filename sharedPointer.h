#ifndef SHAREDPOINTER_H_
#define SHAREDPOINTER_H_


template <typename T>
class controlBlock
{
public:
	T* m_ptr = nullptr;
	size_t count;

	controlBlock(T* ptr) : m_ptr(ptr), count(1)
	{}
	~controlBlock()
	{
		delete m_ptr;
	}
};



template <typename T>
class sharedPointer
{
private:
	controlBlock<T>* c_ptr = nullptr;
public:
	explicit sharedPointer(T* ptr) noexcept : c_ptr(new controlBlock<T>(ptr))
	{
		std::cout << "Called sharedPointer's default constructor" << std::endl;
	}
	sharedPointer(const sharedPointer&) noexcept;
	sharedPointer& operator=(const sharedPointer&) noexcept;
	sharedPointer(sharedPointer&&) noexcept;
	sharedPointer& operator=(sharedPointer&&) noexcept;
	T* operator->()
	{
		return c_ptr->m_ptr;
	}
	T& operator*()
	{
		return *(c_ptr->m_ptr);
	}
	~sharedPointer() noexcept;
};


template <typename T>
sharedPointer<T>::sharedPointer(const sharedPointer<T>& other) noexcept
{
	std::cout << "Called sharedPointer's copy constructor" << std::endl;
	c_ptr = other.c_ptr;
	++c_ptr->count;
}

template <typename T>
sharedPointer<T>& sharedPointer<T>::operator=(const sharedPointer<T>& other) noexcept
{
	std::cout << "Called sharedPointer's assignment operator" << std::endl;
	if (this != &other)
	{
		--c_ptr->count;
		if (c_ptr->count == 0)
			delete c_ptr;
		c_ptr = other.c_ptr;
		++c_ptr->count;
	}
	return *this;
}

template <typename T>
sharedPointer<T>::sharedPointer(sharedPointer<T>&& other) noexcept
{
	std::cout << "Called sharedPointer's move copy constructor" << std::endl;
	c_ptr = other.c_ptr;
	other.c_ptr = nullptr;
}

template <typename T>
sharedPointer<T>& sharedPointer<T>::operator=(sharedPointer<T>&& other) noexcept
{
	if (this != &other) {
		std::cout << "Called sharedPointer's move assignment operator" << std::endl;
		if (--(this->c_ptr->count) == 0 && c_ptr != nullptr)
			delete c_ptr;
		c_ptr = other.c_ptr;
		other.c_ptr = nullptr;
	}
	return *this;
}



template <typename T>
sharedPointer<T>::~sharedPointer() noexcept
{
	if (c_ptr != nullptr && --c_ptr->count == 0) {
		std::cout << "Called sharedPointer's destructor" << std::endl;
		delete c_ptr;
	}
}


// Specializations for arrays


template <typename T>
class controlBlock<T[]>
{
public:
	T* m_ptr = nullptr;
	size_t count;

	controlBlock(T* ptr) : m_ptr(ptr), count(1)
	{}
	~controlBlock()
	{
		delete[] m_ptr;
	}
};



template <typename T>
class sharedPointer<T[]>
{
private:
	controlBlock<T[]>* c_ptr = nullptr;
public:
	explicit sharedPointer(T* ptr) noexcept : c_ptr(new controlBlock<T[]>(ptr))
	{
		std::cout << "Called sharedPointer's default constructor for arrays" << std::endl;
	}
	sharedPointer(const sharedPointer&) noexcept;
	sharedPointer& operator=(const sharedPointer&) noexcept;
	sharedPointer(sharedPointer&&) noexcept;
	sharedPointer& operator=(sharedPointer&&) noexcept;
	T& operator[](size_t index)
	{
		return c_ptr->m_ptr[index];
	}
	~sharedPointer() noexcept;
};


template <typename T>
sharedPointer<T[]>::sharedPointer(const sharedPointer<T[]>& other) noexcept
{
	std::cout << "Called sharedPointer's copy constructor for arrays" << std::endl;
	c_ptr = other.c_ptr;
	++c_ptr->count;
}

template <typename T>
sharedPointer<T[]>& sharedPointer<T[]>::operator=(const sharedPointer<T[]>& other) noexcept
{
	std::cout << "Called sharedPointer's assignment operator for arrays" << std::endl;
	if (this != &other)
	{
		--c_ptr->count;
		if (c_ptr->count == 0)
			delete c_ptr;
		c_ptr = other.c_ptr;
		++c_ptr->count;
	}
	return *this;
}

template <typename T>
sharedPointer<T[]>::sharedPointer(sharedPointer<T[]>&& other) noexcept
{
	std::cout << "Called sharedPointer's move copy constructor for arrays" << std::endl;
	c_ptr = other.c_ptr;
	other.c_ptr = nullptr;
}

template <typename T>
sharedPointer<T[]>& sharedPointer<T[]>::operator=(sharedPointer<T[]>&& other) noexcept
{
	if (this != &other) {
		std::cout << "Called sharedPointer's move assignment operator for arrays" << std::endl;
		if (--(this->c_ptr->count) == 0 && c_ptr != nullptr)
			delete c_ptr;
		c_ptr = other.c_ptr;
		other.c_ptr = nullptr;
	}
	return *this;
}


template <typename T>
sharedPointer<T[]>::~sharedPointer() noexcept
{
	if (c_ptr != nullptr && --c_ptr->count == 0) {
		std::cout << "Called sharedPointer's destructor for arrays" << std::endl;
		delete c_ptr;
	}
}


#endif // ! SHAREDPOINTER_H_
