#ifndef MY_DOUBLE_LIST_H
#define MY_DOUBLE_LIST_H

// The definition of double linked list   


namespace my
{
	template <typename T>
	class doubleList
	{
	public:
		doubleList();
		~doubleList();

		void push_front(T value);
		void pop_front();
		void push_back(T value);
		void pop_back();
		void print();

	private:
		class Node;
		Node* head;
		Node* tail;

		class Node
		{
		public:
			Node* m_next;
			Node* m_prev;
			T m_value;
			Node(T value);

		};
	};


}


template <typename T>
my::doubleList<T>::doubleList()
{
	head = nullptr;
	tail = nullptr;
}


template <typename T>
my::doubleList<T>::~doubleList()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->m_next;
		delete[] temp;
	}
	head = nullptr;
	tail = nullptr;
}


template <typename T>
void my::doubleList<T>::push_front(T value)
{
	if (head == nullptr)
	{
		head = new Node(value);
		tail = head;
		return;
	}
	Node* temp = new Node(value);
	temp->m_next = head;
	temp->m_prev = nullptr;
	head->m_prev = temp;
	head = temp;
	return;
}


template <typename T>
void my::doubleList<T>::pop_front()
{
	if (head == nullptr)
	{
		std::cout << "The double linked list is empty, there are nothing to pop" << std::endl;
		return;
	}
	Node* temp = head;
	head = head->m_next;
	if (head == nullptr)
	{
		delete temp;
		return;
	}
	head->m_prev = nullptr;
	delete temp;
	return;
}


template <typename T>
void my::doubleList<T>::push_back(T value)
{
	if (head == nullptr)
	{
		head = new Node(value);
		tail = head;
		return;
	}
	tail->m_next = new Node(value);
	(tail->m_next)->m_prev = tail;
	tail = tail->m_next;
	tail->m_next = nullptr;
	return;
}


template <typename T>
void my::doubleList<T>::pop_back()
{
	if (tail == nullptr)
	{
		std::cout << "The double linked list is empty, there are nothing to pop" << std::endl;
		return;
	}
	Node* temp = tail;
	tail = tail->m_prev;
	if (tail == nullptr)
	{
		head = nullptr;
		delete temp;
		return;
	}
	tail->m_next = nullptr;
	delete temp;
	return;
}


template <typename T>
void my::doubleList<T>::print()
{
	if (head == nullptr)
	{
		std::cout << "The double linked list is empty" << std::endl;
		return;
	}
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->m_value << ' ';
		temp = temp->m_next;
	}
	std::cout << std::endl;
	return;
}


template <typename T>
my::doubleList<T>::Node::Node(T value)
	: m_value(value), m_next(nullptr), m_prev(nullptr)
{}





#endif // !MY_DOUBLE_LIST_H
