// File Name: StringList.cpp
//
// Author: Nick Montana
// Date: 4/6/17
// Assignment Number: 5
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// This program implements an interface that manipulates a list of strings.
// This file contains the class member functions
//

//************************************************************************
// Name: StringList
// Parameters: none
// Function: is the default constructor for the StringList class.
//***********************************************************************

StringList :: StringList()
{
    head = NULL;
}

//************************************************************************
// Name: ~StringList
// Parameters: none
// Function: the destructor function that deallocates all the nodes in
// a list.
//***********************************************************************

StringList :: ~StringList()
{
    StringNode *p;
    StringNode *n;

    p = head;

    while (p)
    {
        n = p -> next;
        delete p;
        p = n;
    }
}

//************************************************************************
// Name: count
// Parameters: none
// Function: counts how many nodes there are in a list.
//***********************************************************************

int StringList :: count()
{
    StringNode *p;
    int counter = 0;

    p = head;

    while (p)
    {
        counter++;
        p = p -> next;
    }

    return counter;
}

//************************************************************************
// Name: add
// Parameters: string  word
// Function: adds a new node to end of a list with data "word" inside of
// it.
//***********************************************************************

void StringList :: add(string word)
{
    if (head)
    {
        StringNode *newNode = new StringNode;
        newNode -> data = word;
        newNode -> next = NULL;

        StringNode *p = head;
        while (p -> next)
        {
            p = p -> next;
        }
        p -> next = newNode;
    }
    else
    {
        StringNode *newNode = new StringNode;
        newNode -> data = word;
        newNode -> next = NULL;
        head = newNode;
    }
}

//************************************************************************
// Name: remove
// Parameters: string word
// Function: removes a node that contains the string word, returns true
//if successful, returns false if string was not in the list.
//***********************************************************************

bool StringList::remove(string word)
{
    StringNode *p = head;
    StringNode *n = NULL;

    if (p -> data == word)
    {
        head = head -> next;
        delete p;
        return true;
    }

    else
    {
        while(p && p -> data != word)
        {
            n = p;
            p = p->next;
        }

        if (p == NULL)
        {
            return false;
        }

        if (p -> data == word)
        {
            n -> next = p -> next;
            delete p;
            return true;
        }
    }
}

//************************************************************************
// Name: display
// Parameters: none
// Function: displays the contents of all the nodes in the list.
//***********************************************************************

void StringList :: display()
{
    StringNode *p = head;

    while (p)
    {
        cout << p -> data << endl;
        p = p -> next;
    }
}

//************************************************************************
// Name: minimum
// Parameters: none
// Function: finds the node with the minimal value in a list and returns
// its value.
//***********************************************************************

string StringList :: minimum()
{
    StringNode *p = head;
    string minimum = p -> data;

    while (p)
    {
        if (p -> data < minimum)
            minimum = p -> data;

        p = p -> next;
    }

    return minimum;
}

//************************************************************************
// Name: sort
// Parameters: none
// Function: sorts the list in alphabetical order.
//***********************************************************************

void StringList :: sort()
{
    //Part 1:
    StringNode *my_node = new StringNode;
    StringNode *new_head = my_node;
    new_head = NULL;

    //Part 2:

    StringNode *p = new_head;

    string temp_min;

    while (count () != 0)
    {

        temp_min = minimum ();

        remove (temp_min);

        if (new_head)
        {
            StringNode *newNode = new StringNode;
            newNode -> data = temp_min;
            newNode -> next = NULL;

            StringNode *p = new_head;

            while (p -> next)
            {
                p = p -> next;
            }
            p -> next = newNode;
        }
        else
        {
            StringNode *newNode = new StringNode;
            newNode -> data = temp_min;
            newNode -> next = NULL;
            new_head = newNode;
        }


    }

    //Part 3
    head = new_head;
}
