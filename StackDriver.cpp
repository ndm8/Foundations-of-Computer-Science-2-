// File Name: StackDriver.cpp
//
// Author: Nick Montana
// Date: 4/18/17
// Assignment Number: 6
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// This file is the Driver for the file "CharStack.cpp".
// It reads in a file that the user inputs and checks
// the file to ensure it has correctly matched brackets.
// The program will output an appropiate error message
// and then terminate should it find one.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "CharStack.h"

using namespace std;

int main ()
{
    CharStack myStack;

    string file_name;
    char x;
    int num_pairs = 0;

    cout << "Enter the name of a file to check: ";
    cin >> file_name;

    ifstream fin;
    fin.open (file_name.c_str());

    if (!fin)
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        return 1;
    }

    while (fin >> x)
    {
        if (x == '{' || x == '[' || x == '(')
        {
            myStack.push (x);
            num_pairs++;
        }


        else if ((x == '}' || x == ']' || x == ')') && !myStack.isEmpty ())
        {
            char y;
            switch (x)
            {
            case '}':
                if (myStack.peek () != '{')
                    {
                        if (myStack.peek () == '[')
                            y = ']';
                        else
                            y = ')';

                        cout << "Expected '" << y << "' but found '}'" << endl;
                        return 1;
                    }
                else
                    myStack.pop ();

                break;

            case ']':
                if (myStack.peek () != '[')
                    {
                        if (myStack.peek () == '{')
                            y = '}';
                        else
                            y = ')';
                        cout << "Expected '" << y << "' but found ']'" << endl;
                        return 1;
                    }
                else
                    myStack.pop ();

                break;

            case ')':
                if (myStack.peek () != '(')
                    {
                        if (myStack.peek () == '[')
                            y = ']';
                        else
                            y = '}';
                        cout << "Expected '" << y << "' but found ')'" << endl;
                        return 1;
                    }
                else
                    myStack.pop ();

                break;
            }
        }

        else if ((x == '}' || x == ']' || x == ')') && myStack.isEmpty ())
        {
            cout << "Unmatched '" << x << "'." << endl;
            return 1;
        }
    }

    if (!myStack.isEmpty ())
    {
        cout << "There is an opening '" << myStack.peek ()
             << "' that is not matched." << endl;
        return 1;
    }

    else
        cout << num_pairs << " bracket pairs were matched" << endl;

    return 0;
}

