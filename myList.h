#ifndef MY_LIST_H
#define MY_LIST_H
//#include <stack>


namespace my
{
	template <class List>
	class ListInputIterator
	{
	public:
		using NodePtr  = typename List::Node;
		using DataType = typename List::ValueType;

		ListInputIterator(NodePtr* ptr) : m_ptr(ptr) {}

		DataType& operator*()
		{
			return m_ptr->m_value;
		}

		ListInputIterator& operator++()
		{
			m_ptr = m_ptr->m_next;
			return *this;
		}

		ListInputIterator& operator++(int)
		{
			ListInputIterator temp = *this;
			m_ptr = m_ptr->m_next;
			return temp;
		}

		bool operator==(const ListInputIterator& obj)
		{
			return (m_ptr == obj.m_ptr);
		}

		bool operator!=(const ListInputIterator& obj)
		{
			return !(m_ptr == obj.m_ptr);
		}

	private:
		NodePtr* m_ptr;

	};


	template <typename T>
	class List
	{
	public:
		class Node;
		
		using Iterator = typename ListInputIterator<List<T>>;

	private:
		Node* head;

	public:
		using ValueType = T;

		List();
		List(T value);
		List(const List&);
		List& operator=(const List&);
		Iterator begin()
		{
			return Iterator(head);
		}
		Iterator end()
		{
			return Iterator(nullptr);
		}
		void push_front(T value);
		void pop_front();
		void print();
		void insert(T value, int position);
		void remove(const size_t position);
		void reverse();
		void last_Nth(int position);
		
		~List();


		class Node
		{
		public:
			T m_value;
			Node* m_next;
			Node()
			{
				m_next = nullptr;
			}
			Node(T value) : m_value(value), m_next(nullptr)
			{}
			~Node()
			{
				m_next = nullptr;
			}
		};
	};




}


template <typename T>
my::List<T>::List()
{
	head = nullptr;
}

template <typename T>
my::List<T>::List(T value)
{
	head = new Node(value);
}


template <typename T>
my::List<T>::List(const List& obj)
{
	std::cout << "Called single linked list's copy constructor" << std::endl;

	if (obj.head == nullptr)
	{
		head = nullptr;
		return;
	}

	head = new Node(obj.head->m_value);
	head->m_next = nullptr;
	Node* ptr = head;
	Node* obj_ptr = obj.head->m_next;


	while (obj_ptr != nullptr)
	{
		ptr->m_next = new Node(obj_ptr->m_value);
		ptr = ptr->m_next;	
		
		obj_ptr = obj_ptr->m_next;
	}
	ptr->m_next = nullptr;
}


template <typename T>
my::List<T>& my::List<T>::operator=(const List<T>& obj)
{
	std::cout << "Called single linked list's operator=" << std::endl;

	if (this == &obj)
		return *this;

	Node* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->m_next;
		delete temp;
	}
	head = nullptr;

	if (obj.head == nullptr)
		return *this;

	head = new Node(obj.head->m_value);
	head->m_next = nullptr;
	Node* ptr = head;
	Node* obj_ptr = obj.head->m_next;


	while (obj_ptr != nullptr)
	{
		ptr->m_next = new Node(obj_ptr->m_value);
		ptr = ptr->m_next;

		obj_ptr = obj_ptr->m_next;
	}
	ptr->m_next = nullptr;
	
	return *this;
}


template <typename T>
void my::List<T>::push_front(T value)
{
	Node* temp = new Node(value);
	temp->m_next = head;
	head = temp;
}

template <typename T>
void my::List<T>::pop_front()
{
	if (head == nullptr)
	{
		std::cout << "The list are empty, there are nothing to pop" << std::endl;
		return;
	}
	Node* temp = head;
	head = head->m_next;
	delete temp;
}

template <typename T>
void my::List<T>::print()
{
	if (head == nullptr)
	{
		std::cout << "The list are empty" << std::endl;
		return;
	}
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->m_value << ' ';
		temp = temp->m_next;
	}
	std::cout << std::endl;
}

template <typename T>
void my::List<T>::insert(T value, int position)
{
	if (position < 0)
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}
	Node* temp = head;
	for (int i = 0; i < position - 1; ++i)
	{
		temp = temp->m_next;
		if (temp == nullptr )
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}
	}
	Node* obj = new Node(value);
	obj->m_next = temp->m_next;
	temp->m_next = obj;
	return;
}


template <typename T>
void my::List<T>::remove(const size_t position)
{
	if (head == nullptr)
	{
		std::cout << "The single linked list are empty, there are nothing to remove"
				  << std::endl;
		return;
	}
	if (position == 0)
	{
		Node* temp = head;
		head = head->m_next;
		delete temp;
		return;
	}

	int count = 0;
	Node* temp = head;

	while (count + 1 != position)
	{
		if (temp->m_next == nullptr)
		{
			std::cout << position << " is Invalid position" << std::endl;
			return;
		}
		temp = temp->m_next;
		++count;
	}
	if (temp->m_next == nullptr)
	{
		std::cout << position << " is Invalid position" << std::endl;
		return;
	}
	
	Node* rem = temp->m_next;
	temp->m_next = (temp->m_next)->m_next;
	delete rem;
	
	return;
}


template <typename T>
my::List<T>::~List()
{
	Node* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->m_next;
		delete temp;
	}
}


//template <typename T>
//void my::List<T>::reverse()
//{
//	std::stack<T> st;
//	while (head != nullptr)
//	{
//		st.push(head -> m_value);
//		Node<T>* temp = head;
//		head = head->m_next;
//		delete temp;
//	}
//	
//	if (!st.empty())
//	{
//		head = new Node<T>(st.top());
//		st.pop();
//		Node<T>* temp = head;
//		while (!st.empty())
//		{
//			temp -> m_next = new Node<T>(st.top());
//			temp = temp -> m_next;
//			st.pop();
//		}
//		temp -> m_next = nullptr;
//	}
//}

template <typename T>
void my::List<T>::last_Nth(int position)
{
	if (position < 0)
	{
		std::cout << "invalid position" << std::endl;
		return;
	}
	int i = 0;
	Node* temp1 = head;
	Node* temp2 = head;
	while (i < position && temp1 != nullptr)
	{
		temp1 = temp1->m_next;
		++i;
	}
	if (i < (position - 1) || temp1 == nullptr)
	{
		std::cout << "There are not n-th element counted from the last" << std::endl;
		return;
	}

	while (temp1->m_next != nullptr)
	{
		temp1 = temp1->m_next;
		temp2 = temp2->m_next;
	}
	std::cout << "The " << position <<"-th element from the last is - " << temp2->m_value << std::endl;
}


template <typename T>
void my::List<T>::reverse()
{
	if (head == nullptr || head->m_next == nullptr)
		return;
	Node* temp1 = head->m_next->m_next;
	Node* temp2 = head->m_next;
	head->m_next = nullptr;
	temp2->m_next = head;
	while (temp1 != nullptr)
	{
		head = temp2;
		temp2 = temp1;
		temp1 = temp1->m_next;
		temp2->m_next = head;
	}
	temp2->m_next = head;
	head = temp2;

}


template <class T>              
void PrintForwardList(my::List<T>& list)
{
	for (typename my::List<T>::Iterator i = list.begin(); i != list.end(); ++i)
		std::cout << (*i) << "   ";
	std::cout << std::endl;
}


template <class T>
void deletingAvgSmalls(my::List<T>& list)
{
	using iter = typename my::List<T>::Iterator;

	size_t size = 0;
	T average = 0;
	for (iter i = list.begin(); i != list.end(); ++i)
	{
		++size;
		average += (*i);
	}
	if (size == 0)
		return;
	average /= size;


}


#endif // ! MY_LIST_H
