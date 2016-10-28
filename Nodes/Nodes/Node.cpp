#include <iostream>

template<typename type>
struct nodeType
{
	int info; // data the nodes
	nodeType* link;// the pointer that ponts to the next node in order for the compiler to know 
				   // where to move from the current node

};

template<typename type>
class LinkedList
{
public:
	
	LinkedList();
	bool Add(const type & num);
	type const front();
protected:
	int count;
	nodeType<type>* First;
	nodeType<type>* Last;
};

int main()
{
	//nodeType<type>* head;
	//nodeType<type> a, b, c;

	//a.info = 0;
	//b.info = 2;
	//c.info = 4; // setting data to these nodes

	//head = &c; // head will be the current node setting it equal to the address of the first node(last in "first" out)
	// will allow me to be able to use a while loop to iterate through the list 

	//c.link = &b; //points current node (c) to the address of the data of the next node
	//b.link = &a;
	//a.link = nullptr; // ends the stack with a nullptr

	//while (head != nullptr)
	//{
	//	std::cout << head->info << std::endl; //prints the data of the nodes while the conditions of the while loop is met
	//	head = head->link; //iterates through the list
	//}
	LinkedList<int> * stuff = new LinkedList<int>;
	stuff->Add(5);
	system("pause");
	return 0;
}

template<typename type>
bool LinkedList<type>::Add(const type & num)
{
	nodeType<type>* newNode = new nodeType<type>;
	//nodeType<type> Node;
	if (First != NULL)
	{
		newNode->link = First;
		newNode->link = Last;
	}
	else
	{
		newNode->info = num;
		First = newNode;
	}
	return true;
}

template<typename type>
LinkedList<type>::LinkedList()
{
	First->info = NULL;
	Last->info = NULL;
	count = 0;
}
