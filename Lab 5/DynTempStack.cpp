#include <iostream>
#include "DynTempStack.h"
#include <cstdlib>

//**************************************************
// Member function push pushes the argument onto   *
// the stack.                                      *
//**************************************************
template <class T>
void DynTempStack<T>::push(T num)
{
    top = new StackNode(num, top);
}

//*****************************************************
// Member function pop removes the value at the top   *
// of the stack and copies it into the variable       *
// passed as an argument.                             *
//*****************************************************
template <class T>
void DynTempStack<T>::pop(T& num)
{
    StackNode* temp;

    if (isEmpty())
    {
        std::cout << "The stack is empty.\n";
        exit(1);
    }
    else   // Pop value off top of stack
    {
        num = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

template<class T>
void DynTempStack<T>::displayStack(StackNode* ptr)
{
    if (ptr != nullptr)
    {
        std::cout << ptr->value << std::endl;
        displayStack(ptr->next);
    }
    else
        std::cout << " Reached the end of the stack.." << std::endl;
}

//*****************************************************
// Member function isEmpty returns true if the stack  *
// is empty, or false otherwise.                      *
//*****************************************************
template <class T>
bool DynTempStack<T>::isEmpty() const
{
    if (!top)
        return true;
    else
        return false;
}