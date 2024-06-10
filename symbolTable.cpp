#include <iostream>
#include <vector>
#include <string>
#include "symbolTable.h"
using namespace std;

//get index of the key to edit in the values
int SymbolTable::getIndex(string key)
{
    for (int i = 0; i < keys.size(); i++)
    {
        if (keys[i] == key) return i;
    }  
}

// check if key exists -> Return TRUE if it does FALSE otherwise
bool SymbolTable::checkKey(string key)
{
    int index = getIndex(key);

    if (values[index] != 0) return true;
    return false;
}

// insert -> change the value of the values array
void SymbolTable::insert(float value, int index)
{
    values[index] = value; 
}

// search -> retrieve a value from values array
float SymbolTable::search(string key)
{
    int index = getIndex(key);
    return values[index];
}

// print symbolTable 
void SymbolTable::print()
{
    for (int i = 0; i < keys.size(); i++)
    {
        cout << keys[i] << " : " << values[i] << endl;
    }
}