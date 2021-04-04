#include <iostream>
#include "DynTempQueue.h"
#include <cstdlib>

//************************
// Constructor.          *
//************************
template <class T1>
DynTempQueue<T1>::DynTempQueue()
{
    front = NULL;
    rear = NULL;
}

//************************
// Destructor.           *
//************************
template <class T1>
DynTempQueue<T1>::~DynTempQueue()
{
    clear();
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <class T1>
void DynTempQueue<T1>::enqueue(T1 num)
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
template <class T1>
void DynTempQueue<T1>::dequeue(T1& num)
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

template<class T1>
void DynTempQueue<T1>::displayQueue(QueueNode* ptr)
{
    if (ptr != nullptr)
    {
        std::cout << ptr->value << std::endl;
        displayQueue(ptr->next);
    }
    else
        std::cout << " Reached the end of the queue.." << std::endl;
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <class T1>
bool DynTempQueue<T1>::isEmpty() const
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
template <class T1>
void DynTempQueue<T1>::clear()
{
    T1 value;   // Dummy variable for dequeue

    while (!isEmpty())
        dequeue(value);
}