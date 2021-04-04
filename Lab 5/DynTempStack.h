#include <iostream>
#include <cstdlib>

#pragma once
template <class T>
class DynTempStack
{
private:
    class StackNode
    {
        friend class DynTempStack;
        T value;
        StackNode* next;
        // Constructor
        StackNode(T value1, StackNode* next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode* top;
public:
    DynTempStack() { top = nullptr; }
    void push(T);
    void pop(T&);
    void displayStack(StackNode* ptr);
    bool isEmpty() const;

    StackNode* getTop()
    {
        return top;
    }
};

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
            std::cout << " " << ptr->value << std::endl;
            displayStack(ptr->next);
    }
    else
    {
        if (isEmpty())
            std::cout << " The stack is empty.." << std::endl;
        else
            std::cout << " Reached the end of the stack.." << std::endl;
    }
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