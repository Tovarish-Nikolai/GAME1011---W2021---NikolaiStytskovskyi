#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <class T>
class SimpleVector
{
private:
	T* aptr;
	int arraySize;
	void subError() const;
public:
	SimpleVector()
	{
		aptr = 0;
		arraySize = 0;
	}

	SimpleVector(int);

	SimpleVector(const SimpleVector&);

	~SimpleVector();

	int size() const
	{
		return arraySize;
	}

	T& operator[] (int);

	void print() const;

	void push_back(T item)
	{
		for (int i = 0; i < arraySize; i++)
		{
			if (aptr[i] == NULL)
			{
				aptr[i] = item;
				break;
			}
			else if (i == arraySize - 1)
				cout << " The array is full. " << endl;
		}
	}

	void pop_back()
	{
		for (int i = 0; i < arraySize; i++)
		{
			if (aptr[i] == NULL)
			{
				aptr[i - 1] = NULL;
			}
			else if (i == arraySize - 1)
				aptr[arraySize - 1] = NULL;
		}
	}
};
template<class T>
T& SimpleVector<T>::operator[] (int sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

template<class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	aptr = new T[s];

	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = T();
	}
}

template<class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
	arraySize = obj.arraySize;
	aptr = new T[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = obj.aptr[i];
	}
}

template<class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete[] aptr;
}

template<class T>
void SimpleVector<T>::subError() const
{
	cout << " ERROR : Subscript out of range. " << endl;
	exit(0);
}

template<class T>
void SimpleVector<T>::print() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << aptr[i] << " ";
	}
	cout << endl;
}

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
	SearchableVector(int s) : SimpleVector<T>(s) { }

	SearchableVector(const SearchableVector&) { };

	SearchableVector(const SimpleVector<T>& obj) : SimpleVector<T>(obj) { };

	int findItemLinear(T item)
	{
		for (int i = 0; i < this->size(); i++)
		{
			if (this->operator[](i) == item)
			{
				return i;
			}
		}
		return -1;
	}

	void swap(T *a, T *b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	int findItemBinary(T item)
	{
		for (int i = 0; i < this->size() - 1; i++)							//Bubble sorting the array
			for (int j = 0; j < this->size() - i - 1; j++)					//prior to binary searching through it.
				if (this->operator[](j) > this->operator[](j + 1))
					swap(&this->operator[](j), &this->operator[](j + 1));
		
		int first = 0;
		int last = this->size() - 1;
		while (first <= last)
		{
			int middle = first + (last - first) / 2;

			if (this->operator[](middle) == item)
				return middle;

			else if (this->operator[](middle) < item)
				first = middle + 1;
			else
				last = middle - 1;
		}
		return -1;
	}
};

template<class T>
class SortableVector : public SimpleVector<T>
{
public:
	SortableVector(int s) : SimpleVector<T>(s) { }

	SortableVector(const SortableVector&) { };

	SortableVector(const SimpleVector<T>& obj) : SimpleVector<T>(obj) { };

	void swap(T* a, T* b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	void sort()
	{
		for (int i = 0; i < this->size() - 1; i++)							//Bubble sorting the array
			for (int j = 0; j < this->size() - i - 1; j++)					
				if (this->operator[](j) > this->operator[](j + 1))
					swap(&this->operator[](j), &this->operator[](j + 1));
	}
};

int main()
{
	const int SIZE = 10;
	SimpleVector<int> SimpleV(SIZE);
	SearchableVector<int> SearchV(SIZE);
	SortableVector<int> SortV(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		SimpleV[i] = i + 1;

		SearchV[i] = ((i + 1) * 2);

		SortV[i] = (rand() % 100);
	}

	cout << " Simple Vector: ", SimpleV.print();
	cout << "\n Searchable Vector: ", SearchV.print();
	cout << "\n Sortable Vector: ", SortV.print();

	int funnyNumber = 69;
	cout << "\n Pushing 69 to the full Simple Vector.." << endl;
	SimpleV.push_back(funnyNumber);
	
	cout << "\n Popping the back of Simple Vector.." << endl;
	SimpleV.pop_back();
	
	cout << "\n Pushing 69 to Simple Vector.." << endl;
	SimpleV.push_back(funnyNumber);
	
	cout << "\n Simple Vector with 69: ", SimpleV.print();

	cout << "\n Moving on to SearchableVector.." << endl;

	int result;
	cout << " Performing a binary search for 8 in Searchable Vector.." << endl;
	result = SearchV.findItemBinary(8);
	if (result != -1)
		cout << " 8 was found under subscript " << result << endl;
	else
		cout << " 8 wasn't found.." << endl;

	cout << "\n Performing a binary search for 420 in Searchable Vector.." << endl;
	result = SearchV.findItemBinary(420);
	if (result != -1)
		cout << " 420 was found under subscript " << result << endl;
	else 
		cout << " 420 wasn't found.." << endl;

	cout << "\n Moving on to SortableVector.." << endl;
	cout << "\n Let's sort this stuff!" << endl;

	cout << " Before: ", SortV.print();
	SortV.sort();
	cout << " After:  ", SortV.print();
	return 0;
}