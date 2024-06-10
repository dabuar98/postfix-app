#include "stack.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// push
void Stack::push(float number)
{
    items.push_back(number);

}

// top -> returns the last added element
float Stack::top()
{
    try 
    {
        return items[items.size()-1];
    }
    catch (const exception e)
    {
        if(isEmpty()) cout << "The stack is empty" << endl;
    }
}

// pop -> returns element on the top and deletes from stack
float Stack::pop()
{
    float poppedElement = items[items.size()-1];
    items.pop_back();
    return poppedElement;
}

// print stack
void Stack::print()
{
    for (auto item : items)
    {
        cout << item << endl;
    }
}

// returns TRUE if stack is empty, FALSE otherwise
bool Stack::isEmpty()
{
    if (items.size() == 0) return true;
    return false;
}
