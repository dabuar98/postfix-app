#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Postfix
{
    public:
    Postfix() = default;

    //intro
    void intro();

    // read & process input
    string getInput();

    // convert char to string
    string charToString(char x);
    
    // function to validate if is a number -> return bool
    bool isNumber(string number);

    // function to valdate if is an operator -> return bool
    bool isOperator(string op);

    // function to validate if is a key -> return bool
    bool isKey(string key);

    // perform operations
    float operate(float num1, float num2, string op);

    private:
    vector<string> keys = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Y", "Z"};
    vector<string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> operators = {"+", "-", "*", "/"};
    
};