#include <iostream>
#include "linkedlist.h"




//
//void Add(int NewData, nodeType NodeBefore, nodeType NodeAfter)
//{
//	nodeType* newNode = new nodeType;
//	nodeType node;
//	
//	newNode = &node;
//	node.info = NewData;
//
//	node.link = &NodeAfter;
//
//	NodeBefore.link = &node;
//
//}

int main()
{
	//nodeType* head = new nodeType;
	//nodeType a, b, c;

	//a.info = 0;
	//b.info = 2;
	//c.info = 4; // setting data to these nodes
	//
	//head = &c; // head will be the current node setting it equal to the address of the first node(last in "first" out)
	// //will allow me to be able to use a while loop to iterate through the list 

	//c.link = &b;//points current node (c) to the address of the data of the next node


	//b.link = &a;
	//a.link = nullptr; // ends the stack with a nullptr
	//Add(6, c, b);
	//while (head != nullptr)
	//{
	//	std::cout << head->info << std::endl; //prints the data of the nodes while the conditions of the while loop is met
	//	head = head->link; //iterates through the list
	//}

	linkedListType<int> list = linkedListType<int>();
	//linkedListType<int> list2 = linkedListType<int>();
	list.insertFirst(4); // last
	list.insertFirst(3);
	list.insertFirst(2);
	list.insertFirst(1); // first

	list.insertLast(5);
	list.insertLast(6);
	//list.search(6);
	//std::cout << list.front();
	//list.destroyList();
	
	list.deleteNode(6);
	//list2 = list;
	list.print();
	//std::cout << list2.back();
	//list2.print();
	system("pause");
	return 0;
}














































