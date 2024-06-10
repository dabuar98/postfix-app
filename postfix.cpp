#include <iostream>
#include <string>
#include <vector>
#include "postfix.h"
using namespace std;

//intro
void Postfix::intro()
{
    cout << "=================================================================" << endl;
    cout << "" << endl;
    cout << "* PostfixMaster *" << endl;
    cout << "" << endl;
    cout << "Instructions:" << endl;
    cout << "" << endl;
    cout << "Read the section 'How to use it?' in README.md in the repository\nand type your first expression below" << endl;
    cout << "" << endl;
    cout << "Developed by Daniel Bulla (C)" << endl;
    cout << "" << endl;
    cout << "=================================================================" << endl;
    cout << "" << endl;
}

// read and process input
string Postfix::getInput()
{
    string input;
    cout << "Type an expression" << endl;
    cin >> input;
    cout <<  "You typed: " << input << endl;
    return input;
}


// convert char to string
string Postfix::charToString(char x)
{
    string s(1, x);
    return s;
}

// function to validate if is a number -> return TRUE
bool Postfix::isNumber(string number)
{
    for (int i = 0; i < Postfix::numbers.size(); i++)
    {
        if (Postfix::numbers[i] == number) return true;
    }
    return false;
}

//function to valdate if is an operator -> return TRUE
bool Postfix::isOperator(string op)
{
    for (int i = 0; i < Postfix::operators.size(); i++)
    {
        if (Postfix::operators[i] == op) return true;
    }
    return false;
}

//function to validate if is a key -> return TRUE
bool Postfix::isKey(string key)
{
    for (int i = 0; i < Postfix::keys.size(); i++)
    {
        if (Postfix::keys[i] == key) return true;
    }
    return false;
}

// perform operations 
float Postfix::operate(float num1, float num2, string op)
{
    float result;

    if (op == "+") result = num1 + num2;
    if (op == "-") result = num1 - num2;
    if (op == "*") result = num1 * num2;
    if (op == "/") result = num1 / num2;

    return result;
}
