#include <iostream>
#include "myList.h"
#include "myvector.h"
#include "myDoubleList.h"
#include <initializer_list>
#include <vector>
#include <list>
#include <unordered_map>
#include "myHashTable.h"



int main()
{
	srand(time(nullptr));

	my::vector<int> C = { 4,0,5,-9,2,-99,45,12,84,54,12,5,4,7,-55,9,-9,1,54,0,3,55,8 };
	std::cout << C.at(4) << std::endl;
	std::cout << C.at(0) << std::endl;
	std::cout << C.at(-4) << std::endl;
	std::cout << C.at(0) << std::endl;



}






//my::vector<int> C = { 4,0,5,-9,2,-99,45,12,84,54,12,5,4,7,-55,9,-9,1,54,0,3,55,8 };

	//my::vector<int> A;
	//A.push_back(7);
	//A.print();
	//my::List<int> L;
	//L.push_front(66);
	//L.push_front(-7);
	//L.push_front(0);
	//L.push_front(51);
	//L.print();
	//L.pop_front();
	//L.insert(11, 3);
	//L.insert(1, 5);
	//L.insert(-7, 4);
	//L.push_front(88);
	//L.push_front(-6);
	//L.push_front(-744);
	//L.push_front(171);
	//L.push_front(501);
	//L.print();

	//L.reverse();
	//L.print();
	//L.last_Nth(5);
	//L.push_front(-54);
	//L.push_front(881);
	//L.push_front(3);
	//L.print();
	//L.last_Nth(5);
	//L.last_Nth(0);
	//L.last_Nth(11);
	//L.last_Nth(22);
	//L.last_Nth(12);
	//L.last_Nth(13);
	//L.print();
	//L.reverse();
	//L.print();


	//my::doubleList<int> D;
	//for (int i = 0; i < 5; ++i)
	//{
	//	D.push_front(rand() % 20);
	//}
	//D.print();
	//D.pop_front();
	//D.print();
	//D.pop_front();
	//D.print();
	//D.pop_front();
	//D.pop_front();
	//D.print();
	//D.pop_front();
	//D.print();
	//D.pop_front();
	//D.push_back(12);
	//D.push_front(11);
	//D.push_back(-7);
	//D.push_back(-91);
	//D.push_front(0);
	//D.print();
	//D.pop_back();
	//D.pop_front();
	//D.print();
	//D.pop_back();
	//D.print();
	//D.pop_back();
	//D.print();
	//D.pop_back();
	//D.print();
	//D.pop_back();
	//D.print();


	//my::List<int> test1(11);
	//test1.push_front(-7);
	//test1.push_front(-66);
	//test1.push_front(777);
	//std::cout << "The test 1" << std::endl;
	//test1.print();
	//std::cout << std::endl << std::endl;

	//my::List<int> test2 = test1;
	//test2.push_front(444);
	//std::cout << "The test 2" << std::endl;
	//test2.print();
	//std::cout << std::endl << std::endl;


	//my::List<int> test3;
	//test3 = test2;
	//std::cout << "The test 3" << std::endl;
	//test3.print();
	//std::cout << std::endl << std::endl;

	//return 77;

	//std::vector<int> a = { 65,-8,25,21,99,-3,6,88,-9,-11,2,33 };

	//for (std::vector<int>::iterator i = a.begin(); i < a.end(); ++i)
	//{
	//	std::cout << *i << ' ';
	//}
	//std::cout << '\n';

	/*my::List<int> lst;

	for (int i = 0; i < 20; ++i)
		lst.push_front(rand() % 100);

	lst.print();

	for (auto i = lst.begin(); i != lst.end(); ++i)
		std::cout << (*i) << "  ";
	std::cout << std::endl;

	PrintForwardList(lst);*/



	//my::vector<int> A;;
	//for (int i = 0; i < 27; ++i)
	//{
	//	A.push_back(rand() % 100);
	//}
	//A.print();
	//A.insert(99, 3);
	//A.insert(0, 0);
	//A.insert(1, 1);
	//A.insert(-9, 6);
	//A.insert(11, 24);
	//A.insert(-97, 23);
	//A.print();
	//std::cout << std::endl << std::endl << std::endl;

	//deletingPrimes(A);

	//A.print();


//my::HashTable a;
//a.printHashTable();
//std::cout << std::endl << std::endl << std::endl;
//a.add(444, "sfdsf");
//a.add(154, "fsa");
//a.printHashTable();
//a.add(19687, "sfad");
//a.add(29812, "gerfggfd");
//a.add(12915, "hrye");
//a.add(154, "dgsfg");
//a.add(154, "fsadsafdsa");
//a.add(55, "'sfd'");
//a.printHashTable();
//
//for (int i = 0; i < 20; ++i)
//{
//	a.add(rand(), "sfdf");
//}
//std::cout << a[154] << std::endl << std::endl << std::endl;
//a.printHashTable();


