// File Name: CharStack.cpp
//
// Author: Nick Montana
// Date: 4/18/17
// Assignment Number: 6
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// This program contains the member function
// definitions for the Class "CharStack".
//

#include <iostream>
#include <cassert>

using namespace std;

#include "CharStack.h"

//*************************************************
// Default Constructor does absolutely nothing*
//*************************************************

CharStack::CharStack()
{

}

//*************************************************
// Member function push pushes the argument onto *
// the stack. *
//*************************************************

void CharStack::push(char bracket)
{
    assert (!isFull());

    stackString.resize (stackString.size() + 1);
    stackString [stackString.size () - 1] = bracket;
}

//****************************************************
// Member function pop pops the value at the top *
// of the stack off *
//****************************************************

void CharStack::pop()
{
    assert (!isEmpty());
    stackString.erase (stackString.size () - 1, 1);
}

//****************************************************
// Member function peek returns the value at the top *
// of the stack, and does not remove it *
//****************************************************

char CharStack::peek()
{
    assert (!isEmpty());
    char bracket = stackString [stackString.size () - 1];
    return bracket;
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise. *
//***************************************************

bool CharStack::isFull() const
{
    return (false);
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise. *
//****************************************************

bool CharStack::isEmpty() const
{
    return (stackString.size () == 0);
}
