#pragma once
#include <iostream>
#include <cassert>

template<typename Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<typename Type>
class linkedListIterator
{
private:
	nodeType<Type> * current; //pointer to point to the current node in the linked list

public:
	//Default constructor
	//Postcondition: current = NULL
	linkedListIterator() { current = NULL; }

	//Constructor with parameter
	//Postcondition: current = node
	linkedListIterator(nodeType<Type> *node);

	//Function to overlaod the dereferencing operator *
	//Postcondition:Returns the info contained in the node
	Type operator*();

	//Overload the pre-increment operator
	//Postcondition: The iterator is advanced to the next node
	linkedListIterator<Type> operator++();

	//Overlaod the equality operator
	//Postcondition: Returns true if this iterator is equal to the 
	//iterator specified by right otherwise returns false
	bool operator==(linkedListIterator<Type>& list) const;

	//Overlaod the not equal operator
	//Postcondition: Returns true if this iterator is not equal to the 
	//iterator specified by right otherwise returns false
	bool operator!=(linkedListIterator<Type>& list) const;
};

template<typename Type>
class linkedListType
{
protected:
	int count; //variable to store the number of elements in the list
	nodeType<Type> *first; //pointer to the first node of the list
	nodeType<Type> *last; //pointer to the last node of the list

public:
	//Overload the assignment operator
	const linkedListType<Type>& operator= (const linkedListType<Type>& otherList);

	//Initialize the list to an empty state
	//Postcondition: first = NULL, last = NULL, count = 0;
	void initializeList();

	//Function to determine whether the list is empty
	//Postcondition: Returns true if the list is empty otherwise it returns false
	bool isEmptyList() const;

	//Function to output the data contained in each node
	//Postcondition: Node
	void print() const;

	//Function to return the number of nodes in the list
	//Postcondition: The value of count is returned
	int length() const;

	//Function to delete all the nodes from the list
	//Postcondition: first = NULL, last = NULL, count = 0;
	void destroyList();

	//Function to return the first element in the list
	//Precondition: The list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise,
	//the first element of the list is returned
	Type front() const;

	//Function to return the last element in the list
	//Precondition: The list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise,
	//the last element of the list is returned
	Type back() const;

	//Function to determine whether node is in the list
	//Postcondition: Returns true if node is in the list
	//otherwise teh value false is returned
	bool search(const Type& nodeInfo);

	//Function to insert node at the begining of the list
	//Postcondition: first points to the new list, node is inserted 
	//at the beginning of the list, last points to the last node in
	//the list, and count is incremented by 1;
	void insertFirst(const Type& nodeInfo);

	//Function to insert node at the end of the list
	//Postcondition: first points to the new list, node is inserted 
	//at the beginning of the list, last points to the last node in
	//the list, and count is incremented by 1;
	void insertLast(const Type& nodeInfo);

	//Function to delete node from the list
	//Postcondition: If found, the node containing the node is deleted from the list. first points to
	//the first node, last points to the last node of the update list, and count is decremented by 1
	void deleteNode(const Type& nodeInfo);

	//Function to return an iterator at the begining of the linked list
	//Postcondition: Returns an iteratir such that the current is set to first
	linkedListIterator<Type> begin();

	//Funcion to rturn an iterator at the end of the linked list
	//Postcondition: Returns an iterator such that current is set to NULL
	linkedListIterator<Type> end();

	//Default constructor
	//Initializes the list to an empty state
	//Postcondition: first = NULL, last = NULL, count = 0;
	linkedListType();

	//copy constructor
	linkedListType(const linkedListType<Type> &otherList);

	//deconstructor
	//Deletes all the nodes from the list
	//Postcondition: The list object is destroyed
	~linkedListType<Type>() { destroyList(); }

private:
	//Function to make a copy of list
	//Postcondition: A copy of list is created and assigned to this list
	void copyList(const linkedListType<Type>& otherList);
};

template<typename Type>
inline const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	
	copyList(otherList);
	return *this;
}

template<typename Type>
inline void linkedListType<Type>::initializeList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<typename Type>
inline bool linkedListType<Type>::isEmptyList() const
{

	return (first == NULL) ? true : false;
}

template<typename Type>
inline void linkedListType<Type>::print() const
{
	nodeType<Type> *currentNode;
	currentNode = first;
	while (currentNode != NULL)
	{
		std::cout << currentNode->info << std::endl; //prints the data of the nodes while the conditions of the while loop is met
		currentNode = currentNode->link; //iterates through the list
	}
}

template<typename Type>
inline int linkedListType<Type>::length() const
{
	return count;
}

template<typename Type>
inline void linkedListType<Type>::destroyList()
{

	nodeType<Type> *currentNode;
	currentNode = first;

	while (currentNode != NULL)
	{
		nodeType<Type>* tmp = NULL;
		currentNode = currentNode->link;
		currentNode = tmp;
		delete tmp;

		first = NULL;
		last = NULL;
		count = 0;
	}
}

template<typename Type>
inline Type linkedListType<Type>::front() const
{
	assert(first != NULL);
	return first->info; 
}

template<typename Type>
inline Type linkedListType<Type>::back() const
{
	assert(first != NULL);
	return last->info;
}

template<typename Type>
inline bool linkedListType<Type>::search(const Type & nodeInfo)
{
	nodeType<Type> *node;
	node = first;
	while (node != NULL)
	{
		
		if (nodeInfo == node->info)
		{
			return true;
		}

		node = node->link;
	}
	return false;
}

template<typename Type>
inline void linkedListType<Type>::insertFirst(const Type & nodeInfo)
{
	nodeType<Type>* node = new nodeType<Type>;
	node->info = nodeInfo;

	if (first != NULL)
	{
		nodeType<Type> *tmp = first;
		first = node;
		first->link = tmp;		
	}
	else
	{
		first = node;
		last = node;
		first->link = NULL;
		last->link = NULL;
	}

	count++;
}

template<typename Type>
inline void linkedListType<Type>::insertLast(const Type & nodeInfo)
{
	nodeType<Type>* node = new nodeType<Type>;
	node->info = nodeInfo;

	if (first != NULL)
	{
		nodeType<Type> *tmp = last;
		last = node;
		tmp->link = last;
		last->link = NULL;

	}
	else
	{
		node = last;
		node = first;
		first->link = NULL;
		last->link = NULL;
	}
	count++;
}


//nodeType<Type>* node;
	//nodeType<Type>* tmp = new nodeType<Type>;
	//
	//node = first;

	//while (node != nullptr)
	//{
	//	node = node->link;

	//	if (node->info == nodeInfo)
	//	{
	//		tmp = node;
	//		node->link != tmp;
	//		delete tmp;
	//	}
	//}



template<typename Type>
inline void linkedListType<Type>::deleteNode(const Type & nodeInfo)
{
	
	nodeType<Type>* node = first;
	if (node->info == nodeInfo)
		{
			nodeType<Type> *tmp = node->info;
			node = node->link;
			delete tmp;
			count--;
		}
	else 
	{
		while (node->link != NULL)
		{
			if (node->link->info == nodeInfo)
			{
				nodeType<Type>* tmp = node->link;
				node->link = node->link->link;
				delete tmp;
				count--;
				break;
			}
			node = node->link;
		}
	}
}

template<typename Type>
inline linkedListIterator<Type> linkedListType<Type>::begin()
{
	return linkedListIterator<Type>(first);
}

template<typename Type>
inline linkedListIterator<Type> linkedListType<Type>::end()
{
	return linkedListIterator<Type>(last);
}

template<typename Type>
inline linkedListType<Type>::linkedListType()
{
	initializeList();
}

template<typename Type>
inline linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	copyList(otherList);
}

template<typename Type>
inline void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	destroyList();

	first = otherList.first;
	last = otherList.last;
	count = otherList.count;
}

template<typename Type>
inline linkedListIterator<Type>::linkedListIterator(nodeType<Type>* node)
{
	current = node;

}

template<typename Type>
inline Type linkedListIterator<Type>::operator*()
{
	if (current == NULL)
	{
		current = NULL;
	}
	return current->info;
}

template<typename Type>
inline linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;
	return *this;

}

template<typename Type>
inline bool linkedListIterator<Type>::operator==(linkedListIterator<Type>& list) const
{
	if (current == list.current)
	{
		return true;
	}
	return false;
}

template<typename Type>
inline bool linkedListIterator<Type>::operator!=(linkedListIterator<Type>& list) const
{
	if (current != list.current)
	{
		return true;
	}
	return false;
}