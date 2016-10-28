#include <iostream>
// exercise 1
//1. Min
//	DESCRIPTION : Returns the lower of two values.
//	INPUT : Two template arguments(a, b).
//	OUTPUT : The lower of the two values a and b.
template<typename T>
T Min(T a, T b)
{
	return (a < b) ? a : b;
}

//2. Max
//	DESCRIPTION : Returns the higher of two values.
//	INPUT : Two template arguments(a, b).
//	OUTPUT : The higher of the two values a and b.
template<typename T>
T Max(T a, T b)
{
	return (a > b) ? a : b;
}

//3. Clamp
//	DESCRIPTION : Constrains a value within the range of two other values.
//	INPUT : Three template arguments(min, max, val).
//	OUTPUT : The value of the val constrained between min and max.
template<typename T>
T Clamp(T min, T max, T val)
{
	if (val < max && val > min)
		return val;
	else if (val >= max)
		return max;
	else if (val <= min)
		return min;
}

//4.	Min(specialised for char)
//	DESCRIPTION: As above but first checks if a and b represent alphabetical characters.If so,
//	the function will return the value that is alphabetically lower.
//	INPUT : Two template arguments(a, b).
//	OUTPUT : The alphabetically lower of the two values a and b.
char Min(char a, char b)
{
	if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
		return (a < b) ? a : b;
	else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')
		return (a < b) ? a : b;
	else
		return '?'; // No clue
}

//5. Max(specialised for char)
//DESCRIPTION: As above but first checks if a and b represent alphabetical characters.If so,
//	the function will return the value that is alphabetically higher.
//	INPUT : Two template arguments(a, b).
//	OUTPUT : The alphabetically higher of the two values a and b
char Max(char a, char b)
{
	if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
		return (a > b) ? a : b;
	else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')
		return (a > b) ? a : b;
	else
		return '?'; // No clue
}

//exercise 2

//1. Constructor
//	DESCRIPTION : Creates an array on the heap of the specified capacity.The new heap
//	memory should be zeroed using memset.You should store the value of
//	capacity and size for later use(size should start at 0).
//	INPUT : A single integer specifying the capacity for the data array.
//	OUTPUT : N / A.

template<typename T>
class SavedData
{
	int m_size;
	int m_capacity;
	T *m_data;

public:
	SavedData(int capacity)
	{
		m_capacity = capacity;
		m_size = 0;
		m_data = new T[capacity];
		memset(m_size, 0, 1);
	};
	//2. Deconstructor
	//	DESCRIPTION : Deletes the data pointed to on the heap.
	//	INPUT : N / A.
	//	OUTPUT : N / A.

	~SavedData() { delete this->m_capacity; };

	//3. Add
	//DESCRIPTION : Adds an item to the next empty array location(you should be able to use the
	//	size value as an index to the next free location).Before adding the new item
	//	to the array, we should check if there is room and call Expand if not.
	//	INPUT : One template arguments(item).
	//	OUTPUT : None.

	void Add(T item);

	//4. Expand
	//DESCRIPTION : Doubles the capacity of the data array by creating a new array on the heap
	//	with twice the current capacity, and then copying the data from the current
	//	array into the new array using memcpy. (Be sure to delete the old memory!)
	//	INPUT : None.
	//	OUTPUT : None.
	void expand();

	//5. Operator[]
	//DESCRIPTION: Returns an item from the array at a specified index(like a regular subscript).
	//	INPUT : A single integer specifying the array - index of the item to return.
	//	OUTPUT : A copy / reference(your choice) of an item from the data array.
		//T operator[] (int index);

};
// Add function defintion
template<typename T>
void SavedData<T>::Add(T item)
{
	for (int i = 0; i > m_size; i++)
	{

	}
}

template<typename T>
void SavedData<T>::expand()
{

}

template<typename T>
T SavedData<T>::operator[](T index)
{
	Y data;
	return;
}

int main()
{

	system("pause");
}