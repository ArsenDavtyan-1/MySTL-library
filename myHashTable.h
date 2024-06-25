#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <iostream>
#include "myList.h"

namespace my
{

	class HashTable
	{
	private:
		static const int size = 13;
		List <std::pair<int, std::string>> listArray[size];
		unsigned int HashFunction(int key);


	public:
		HashTable() = default;
		~HashTable() = default;
		void add(int, std::string);
		void printHashTable();
		std::string operator[](int key);
	};

}


unsigned int my::HashTable::HashFunction(int key)
{
	return (key | ((key * 119) <<  7)) % size;
}

void my::HashTable::add(int key, std::string str)
{
	unsigned int index = HashFunction(key);
	std::pair<int, std::string> hashpair(key, str);
	int position = 0;
	for (auto iter = listArray[index].begin(); iter != listArray[index].end(); ++iter)
	{
		if ((*iter).first == hashpair.first)
		{
			listArray[index].remove(position);
			break;
		}
		++position;
	}
	listArray[index].insert(hashpair,position);
	return;
}

std::string my::HashTable::operator[](int key)
{
	unsigned int index = HashFunction(key);
	typedef my::List<std::pair<int, std::string>>::Iterator iter;
	for (iter it = listArray[index].begin(); it != listArray[index].end(); ++it)
	{
		if ((*it).first == key)
			return ((*it).second);
	}
	std::cout << "Invalid key, there are not a value with a key - " << key << std::endl;
	return "";
}




void my::HashTable::printHashTable()
{
	bool empty = true;
	for (int i = 0; i < size; ++i)
	{
		if (listArray[i].isEmpty())
		{
			continue;
		}
		empty = false;
		for (auto it = listArray[i].begin(); it != listArray[i].end(); ++it)
		{
			std::cout << "key - " << (*it).first << ", value - " << (*it).second << "     ";
		}
		std::cout << std::endl;
	}
	if (empty)
		std::cout << "The Hash Table is empty" << std::endl;
	std::cout << std::endl;
	return;
}



#endif // !HASH_TABLE_H_
