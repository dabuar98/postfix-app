#pragma once
#include <vector>
#include <string>
using namespace std;

class SymbolTable
{
    public:

    //get index of the key to edit in the values
    int getIndex(string key);

    // check if key exists or not
    bool checkKey(string key);

    // insert -> change the value of the values array
    void insert(float value, int index);

    // search -> retrieve value from values array
    float search(string key);

    // print symbolTable 
    void print();

    private:
    vector<string> keys = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Y", "Z"};
    vector<float> values = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};