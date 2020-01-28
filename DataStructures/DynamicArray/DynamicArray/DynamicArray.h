/*
Dynamic Array Implementation Using Static Arrays
Developed by Fraser Love
Created 24/01/20
Latest Release 26/01/20

Uses C++ Templates and can be used with integers, floats and characters
*/

#pragma once

template <class T>
class DynamicArray {
private:
	T* s_array;
	int len;
	int cap;

	const int GROWTH_FACTOR = 2; // Controls the rate of dynamic resizing (using Push() and Insert()) of the static array, higher value decreases execution time of Pop() and Remove(), lower decreases space used by static array
	const int DECAY_FACTOR = 4; // Controls the rate of dynamic resizing (using Pop() and Remove()) of the static array, higher value decreases execution time of Pop() and Remove(), lower decreases space used by static array
	const int MIN_CAPACITY = 1; // Minimum size of the static array

public:
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(T data[], int size);
	~DynamicArray();

	void Set(int idx, T data); // Sets a specified index in the dynamic array to a specific value
	void Push(T data); // Adds either single data item or multiple data items from a static array to the end of the dynamic array
	void Push(T data[], int size);
	void Insert(int idx, T data); // Adds either a single data item or multiple data items from a static array to a specified index in the dynamic array
	void Insert(int idx, T data[], int size);
	void Clear(); // Overwrites all data in the dynamic array to NULL and resizes array to minimum value
	void Reverse(); // Reverses all elements in the entire dynamic array
	void Show(); // Displays the entire dynamic array
	void ShowAsString(); // Displays the entire dynamic array without any formatting
	void ShowDebug(); // Displays the entire dynamic array, showing the total capacity of the static array and the section currently in use
	
	int Length(); // Returns the length of the dynamic array
	int Find(T data); // Returns the position of the first instance of a specific object in the dynamic array

	bool IsEmpty(); // Checks if the dynamic array is empty
	bool RemoveValue(T data); // Removes a specific value from the dynamic array
	bool Contains(T data); //  Checks if an object is present in the dynamic array

	T Access(int idx); // Returns the value held at a specific index in the dynamic array
	T Pop(); // Removes the last element from the dynamic array and returns its value
	T Remove(int idx); // Removes the element from the specific index specified in the dynamic array and returns its value

	DynamicArray<int>* FindAll(T data); // Returns a new dynamic array of all of the indices where an instance of a specific value was found in the dynamic array
};
