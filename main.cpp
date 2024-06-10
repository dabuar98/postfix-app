/*
Postfix++ Application
Developed by Daniel Bulla SN 220305778 
BSc Computer Science
ADS2 CM2035-01
University of London
*/

#include <iostream>
#include <string>
#include <vector>
#include "postfix.h"
#include "stack.h"
#include "symbolTable.h"
using namespace std;

int main () 
{
    // instantiate postfix object
    Postfix postfix;

    //instantiate symbolTable object
    SymbolTable symbolTable;

    // new stack object
    Stack stack;

    //create global for result
    float result;

    // create global for key
    string key;

    // print intro
    postfix.intro();

    // get input
    string input = postfix.getInput();

    // for each element
    while(true){

        //count the number of operators used
        int operators = 0;

         // checks if result is correct to print
        bool printResult;
        
        for(int i = 0; i < input.size(); i++)
        {

            // convert char into string
            string element = postfix.charToString(input[i]);

            // if element is a key
            if (postfix.isKey(element))
            {
                // update key 
                key = element;

                // if key exists
                if (symbolTable.checkKey(key))
                {
                    // retrieve value and push it to the stack for use
                    float value = symbolTable.search(key);
                    stack.push(value);
                    cout << key << " : " << value << " -> retrieved from the symbol table" << endl;
                } 
                else
                { 
                    cout << "Key: " << key << " created" << endl;
                }
            }

            // if element is a number
            else if (postfix.isNumber(element))
            {
                // parse into float
                float number = stof(element);

                // add element to stack
                stack.push(number);

                cout << "Number: " << element << " pushed to the stack" << endl;
            }
            
            // if element is an operator
            else if (postfix.isOperator(element))
            {
                operators++;

                if (stack.items.size() < operators)
                {
                    cout << "Error: Not enough elements to perform an operation" << endl;
                    // pop last element added to the stack to undo last reading
                    stack.pop();
                    printResult = false;
                    break;
                }

                else
                {
                    // pop stack twice
                    float num1 = stack.pop();
                    float num2 = stack.pop();

                    cout << "Performing " << num1 << " " << element << " " << num2 << "..." << endl; 

                    // create a local result
                    float r = postfix.operate(num1, num2, element);
                    
                    // push local result to the stack
                    stack.push(r);

                    cout << "Number: " << r << " pushed to the stack" << endl;

                    printResult = true;
                } 
                
            }

            // if element is an assignment operator
            else if (element == "=")
            {
                // get index of the last key read
                int index = symbolTable.getIndex(key);
                string option;

                // push stack and store value in values symbol table
                float r = stack.pop();
                symbolTable.insert(r, index);
                cout << key << " : " << r << " -> inserted to the symbol table " << endl;

                // prompt user to print symbol table
                cout << "Do you want to print symbol table? Y/N" << endl;
                cin >> option;
                if (option == "Y") 
                {
                    symbolTable.print();
                    printResult = false;
                }
                printResult = false;

            }

            else
            {
                cout << "Input is not valid." << endl;
                printResult = false;
                break;
            }

        }

        // print result
        if (printResult)
        {
            result = stack.top(); 
            cout << "The result is: " << result << endl;
            cout << "--------------------" << endl;
            cout << "            " << endl;
        }

        // type another input
        input = postfix.getInput();
        
    }

    return 0;
}