#include <iostream>
#include <cstdlib>

#pragma once
template <class T>
class DynTempQueue
{
private:
	class QueueNode
	{
		friend class DynTempQueue;
		T value;
		QueueNode* next;
		QueueNode(T value1, QueueNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	// These track the front and rear of the queue
	QueueNode* front;
	QueueNode* rear;
public:
	// Constructor and Destructor
	DynTempQueue();
	~DynTempQueue();

	// Member functions
	void enqueue(T);
	void dequeue(T&);
	void displayQueue(QueueNode* ptr);
	bool isEmpty() const;
	void clear();


	QueueNode* getFront()
	{
		return front;
	}
};

//************************
// Constructor.          *
//************************
template <class T>
inline DynTempQueue<T>::DynTempQueue()
{
    front = NULL;
    rear = NULL;
}

//************************
// Destructor.           *
//************************
template <class T>
inline DynTempQueue<T>::~DynTempQueue()
{
    clear();
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <class T>
inline void DynTempQueue<T>::enqueue(T num)
{
    if (isEmpty())
    {
        front = new QueueNode(num);
        rear = front;
    }
    else
    {
        rear->next = new QueueNode(num);
        rear = rear->next;
    }
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
template <class T>
inline void DynTempQueue<T>::dequeue(T& num)
{
    QueueNode* temp;
    if (isEmpty())
    {
        std::cout << "The queue is empty.\n";
        exit(1);
    }
    else
    {
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<class T>
inline void DynTempQueue<T>::displayQueue(QueueNode* ptr)
{
    if (ptr != nullptr)
    {
            std::cout << " " <<  ptr->value << std::endl;
            displayQueue(ptr->next);
    }
    else
    {
        if (isEmpty())
            std::cout << " The queue is empty.." << std::endl;
        else
            std::cout << " Reached the end of the queue.." << std::endl;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <class T>
inline bool DynTempQueue<T>::isEmpty() const
{
    if (front == NULL)
        return true;
    else
        return false;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
template <class T>
inline void DynTempQueue<T>::clear()
{
    T value;   // Dummy variable for dequeue

    while (!isEmpty())
        dequeue(value);
}