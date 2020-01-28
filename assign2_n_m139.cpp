// File Name: assign2_n_m139.cpp
//
// Author: Nick Montana
// Date: 2/14/17
// Assignment Number: 2
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// This program reads data about inventory of items from an input file. Each
//item contains four pieces of information: name, sku, quantity, and price.
//The user then is presented with a menu that allows the user to 1. display the
//inventory, 2. look up an item by sku, 3. look an item by name, or 4. quit the
//program.
//
//***Note to the grader: I had to use the codeblocks IDE due to the Linux
//crashes on campus. Dr. Seaman emailed the class saying this was acceptable.

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Inventory
{
    string name;
    int sku,
        quantity;
    double price;
};

void sortData (Inventory [], int);

void printInventory (Inventory [], int);

int findItemB (Inventory [], int, int);

int findItemL (Inventory [], int, string);

int main ()
{
    int counter =0,
        SIZE =100,
        choice,
        sku_target,
        position;

    string name_target;

    ifstream fin;
    fin.open ("inventory.dat");

    Inventory data [SIZE];

    for (int i = 0; (fin >> data [i].name >> data [i].sku
           >> data [i].quantity >> data [i].price); i++)
       counter ++;

    sortData (data, counter);

    do
    {
        cout << "Manage Inventory Menu" << endl << endl
             << "1. Display inventory sorted by sku" << endl
             << "2. Lookup a product by sku" << endl
             << "3. Lookup a product by name" << endl
             << "4. Quit the Program" << endl << endl
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            printInventory (data, counter);

        else if (choice == 2)
        {
            cout << "Enter sku of product to find: ";
            cin >> sku_target;
            position = findItemB (data, counter, sku_target);
            if (position == -1)
                cout << "No product found with this sku." << endl << endl;
            else
            {
                cout << endl
                     << "product name: " << data [position].name << endl
                     << "sku: " << data [position].sku << endl
                     << "quantity: " << data [position].quantity << endl
                     << "price: " << data [position].price << endl << endl;
            }
        }

        else if (choice == 3)
        {
            cout << "Enter product name of product to find: ";
            cin >> name_target;
            position = findItemL (data, counter, name_target);
            if (position == -1)
                cout << "No product found with this product name."
                     << endl << endl;
            else
            {
                cout << endl
                     << "product name: " << data [position].name << endl
                     << "sku: " << data [position].sku << endl
                     << "quantity: " << data [position].quantity << endl
                     << "price: " << data [position].price << endl << endl;
            }
        }

        else if (choice == 4)
            cout << "Exiting the program.";
        else
            cout << "Incorrect choice";
    } while (choice != 4);

    fin.close ();
    return 0;
}

//***********************************************************
//sortData: sorts the data read in from the file by sku
//
// data - the array of structures that has the inventory data
// SIZE - the amount of items from the file
// returns: nothing
//***********************************************************

void sortData (Inventory data [], int SIZE)
{
    bool swp;
    Inventory temp;

    do
    {
        swp = false;
        for (int i = 0; i < (SIZE-1); i++)
        {
            if (data [i].sku > data [i+1].sku)
            {
                temp = data [i];
                data [i] = data [i+1];
                data [i+1] = temp;
                swp = true;
            }
        }
    } while (swp);
}

//***********************************************************
//printInventory: prints the entire inventory list to the
//console
//
// data - the array of structures that has the inventory data
// SIZE - the amount of items from the file
// returns: nothing
//***********************************************************

void printInventory (Inventory data [], int SIZE)
{
    cout << endl;
    for (int i = 0; i < SIZE; i++)
        cout << fixed << setw (6) << left << data [i].sku << setw (6)
             << data [i].quantity
             << setprecision (2) << setw (10) << data [i].price
             << setw (8) << data [i].name << endl;
    cout << endl;
}

//***********************************************************
//findItemB: finds the item that the user wants by searching
//the array with Binary search
//
// data - the array of structures that has the inventory data
// SIZE - the amount of items from the file
// target - the sku number that the user entered
// returns: the array position of the wanted item
//***********************************************************

int findItemB (Inventory data [], int SIZE, int target)
{
    int first = 0,
        last = SIZE - 1,
        middle,
        position = -1;
    bool found = false;

    while (first <= last && !found)
    {
        middle = (first + last) / 2;

        if (data [middle].sku == target)
        {
            found = true;
            position = middle;
        }
        else if (target < data [middle].sku)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

//***********************************************************
//findItemL: finds the item that the user wants by searching
//the array with Linear search
//
// data - the array of structures that has the inventory data
// SIZE - the amount of items from the file
// target - the name of the product that the user entered
// returns: the array position of the wanted item
//***********************************************************

int findItemL (Inventory data [], int SIZE, string target)
{
    int position = -1;
    bool found = false;

    for (int i = 0; i < SIZE && !found; i++)
    {
        if (data [i].name == target)
        {
            found = true;
            position = i;
        }
    }
    return position;
}
