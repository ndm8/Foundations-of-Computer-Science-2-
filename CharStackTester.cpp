// File name: CharStackTester.cpp
//
// tests a Char Stack ADT
//

#include <iostream>
#include <cassert>
#include "CharStack.h"

using namespace std;

//*************************************************
// Default Constructor initializes the stackString*
// to an empty space*
//*************************************************

CharStack::CharStack()
{
// ?????????????????????
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




int main () {

    CharStack myStack;

    if (myStack.isEmpty())
        cout << "stack is empty GOOD" << endl;
    else
        cout << "stack is not empty BAD" << endl;

    myStack.push('x');

    if (myStack.isEmpty())
        cout << "stack is empty BAD" << endl;
    else
        cout << "stack is not empty GOOD" << endl;

    if (myStack.isFull())  //this stack is never full
        cout << "stack is full BAD" << endl;
    else
        cout << "stack is NOT full GOOD" << endl;

    CharStack stack;
    char item;
    stack.push('2');
    stack.push('3');
    stack.push('5');
    item = stack.peek(); //item is 5
    cout << "item " << item << " should be 5" << endl;
    stack.pop();

    item = stack.peek(); //item is 3
    cout << "item " << item << " should be 3" << endl;
    stack.pop();
    stack.push('0');
    stack.pop();
    stack.pop();
    if (stack.isEmpty())
        cout << "stack is empty GOOD" << endl;
    else
        cout << "stack is not empty BAD" << endl;

}

/* Expected output:
stack is empty GOOD
stack is not empty GOOD
stack is NOT full GOOD
item 5 should be 5
item 3 should be 3
stack is empty GOOD
*/
