#pragma once
#include <vector>
#include <string>
using namespace std;

class Stack
{
    public:
    Stack() = default;

    // push
    void push(float e);

    // top -> returns the last added element
    float top();

    // pop -> returns element Staon the top and deletes from stack
    float pop();

    // print stack
    void print();

    // returns TRUE if stack is empty, FALSE otherwise
    bool isEmpty();

    // holds elements for the stack
    vector<float> items;
};