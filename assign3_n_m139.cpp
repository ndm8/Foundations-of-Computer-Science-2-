// File Name: assign3_n_m139.cpp
//
// Author: Nick Montana
// Date: 2/28/17
// Assignment Number: 3
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// This program implements and tests four functions that use pointers and
// dynamic memory allocation: isSorted, chain, grow, and subArray

#include <iostream>
#include <iomanip>

using namespace std;

bool isSorted (int *, int);

double chain (int, int *, int *);

int *grow (int [], int);

int *duplicateArray (int *, int);

int *subArray (int *, int, int);

int main ()
{
    const int SIZE = 8;

    int my_array [SIZE] = {1,2,3,4,5,6,7,8};
    int my_array2 [SIZE] = {8,7,6,5,4,3,2,1};
    int my_array3 [SIZE] = {1,2,3,5,4,6,7,8};
    int *ptr = my_array;
    int *ptr2 = my_array2;
    int *ptr3 = my_array3;
    int *feet;
    int *inches;
    int *ptr4;
    int *ptr5;
    int x;
    int y;

    double chainv;

    cout << "testing isSorted:" << endl
         << "test data array 1: ";
    for (int i = 0; i < SIZE; i++)
        cout << my_array [i] << " ";

    cout << endl << "Expected result: true" << endl
         << "Actual result: " << boolalpha << isSorted (ptr, SIZE) << endl;

    cout << "test data array 2: ";
    for (int i = 0; i < SIZE; i++)
        cout << my_array2 [i] << " ";

    cout << endl << "Expected result: false" << endl
         << "Actual result: " << boolalpha << isSorted (ptr2, SIZE) << endl;

    cout << "test data array 3: ";
    for (int i = 0; i < SIZE; i++)
        cout << my_array3 [i] << " ";

    cout << endl << "Expected result: false" << endl
         << "Actual result: " << boolalpha << isSorted (ptr3, SIZE) << endl
         << endl;

    cout << "testing chain for 53 inches:" << endl
         << "Expected result: 15.46  feet: 4  inches: 5" << endl;
    chainv = chain (53, &x, &y);
    cout << "Actual results : " << chainv << "  feet: " << x
         << "  inches: " << y << endl << endl;

    cout << "testing grow:" << endl
         << "test data: ";
    for (int i = 0; i < SIZE; i++)
        cout << my_array [i] << " ";
    cout << endl << "Expected result: 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8"
         << endl << "Actual result:   ";

    ptr4 = grow (my_array, SIZE);

    for (int i = 0; i < 2*SIZE; i++)
        cout << ptr4 [i] << " ";

    cout << endl << endl << "testing subArray:" << endl
         << "test data: ";
    for (int i = 0; i < SIZE; i++)
        cout << my_array [i] << " ";

    cout << endl << "start: 5  length: 3"
         << endl << "Expected result: 6 7 8"
         << endl << "Actual result:   ";

    ptr5 = subArray (my_array, 5, 3);

    for (int i = 0; i < 3; i++)
        cout << ptr5 [i] << " ";
    cout << endl;

    delete [] ptr4;
    delete [] ptr5;

    return 0;
}

//***********************************************************
// isSorted: determines whether or not an array is in
// ascending order.
//
// ptr - a pointer that contains the memory location of the
// first element in an array
// SIZE - the size of the array
//
// returns: the boolean value (true or false) of the test
//***********************************************************


bool isSorted (int *ptr, int SIZE)
{
    bool ascend = false;
    int counter = 0;

    for (int i = 0; i < (SIZE-1); i++)
        if (*(ptr + i) < *(ptr + i + 1))
            counter++;

    if (counter == SIZE - 1)
        ascend = true;

    return ascend;
}

//***********************************************************
// chain: takes in an amount of total inches and calculates
// the number of feet, the left over inches, and then a
// random double calculation.
//
// totalInches - the total number of inches as an integer
// feet - a pointer that refers to a variable in main
// inches - a pointer that refers to a variable in main
//
// returns: this random double
//***********************************************************

double chain (int totalInches, int *feet, int *inches)
{
    *feet = totalInches/12;
    *inches = totalInches%12;
    return (*feet * 3.49) + (*inches * .30);
}

//***********************************************************
// grow: takes an array of integers and its size and creates
// a new array twice its size and copies each element twice.
//
// my_array - an array of integers
// SIZE - the size of the array
//
// returns: a pointer that points to the new array
//***********************************************************


int *grow (int my_array [], int SIZE)
{
    int *new_array;
    new_array = new int [2*SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        new_array [2*i] = my_array [i];
        new_array [(2*i)+1] = my_array [i];
    }

    return new_array;
}

//***********************************************************
// duplicateArray: takes an array and its size and makes a
// copy of it
//
// arr - an array of integers
// SIZE - the size of the array
//
// returns: a pointer that points to the new array
//***********************************************************

int *duplicateArray (int *arr, int SIZE)
{
    int *newArray;
    if (SIZE <= 0)      //size must be positive
        return NULL;    //NULL is 0, an invalid address

    newArray = new int [SIZE];  //allocate new array

    for (int index = 0; index < SIZE; index++)
        newArray[index] = arr[index]; //copy to new array

    return newArray;
}

//***********************************************************
// subArray: takes an array of integers, a starting index, and
// a length and makes a new array that is a copy of the elements
// from the original array starting at the start index and length
// equal to the length argument
//
// my_array - an array of integers
// start - the starting index
// length - the length of the new array
//
// returns: a pointer that points to the new array
//***********************************************************

int *subArray (int *my_array, int start, int length)
{
    int *result = duplicateArray (my_array + start, length);
    return result;
}
