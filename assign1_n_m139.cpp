// File Name: assign1_n_m139.cpp
//
// Author: Nick Montana
// Date: 1/28/17
// Assignment Number: 1
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// This program stores data about lab rats: the rat's name, the rat's weight in
//ounces, the amount of time in seconds it took the rat to run the maze//.
// The program displays a table of the data to the user, then calculates and
//displays the average weight of all the rats. The program also displays the names
//and times of the fastest and slowest rats.

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int SIZE = 9;

struct Rat
{
    string name;
    double weight;
    int time;
};

double calcAvg (Rat []);

void findExtrema (Rat [], int &, int &);

int main ()
{
    int fastest,
        slowest;

    double average;

    Rat data [SIZE] = {{"Ben", 6.5, 29}, {"Fred", 5.8, 31},
                      {"Splinter", 7.7, 33},{"Lima Bean", 6.5, 27},
                      {"Black Bean", 5.8, 31}, {"Pinto Bean", 7.7, 33},
                      {"Skat", 6.5, 29}, {"Big Pook", 9.8, 34},
                      {"Tiger", 7.7, 33}};

    average = calcAvg (data);

    findExtrema (data, fastest, slowest);

    cout << "Name:      Weight:  Time:" << endl << endl;

    for (int i = 0; i < SIZE; i++)
        cout << left << setw (12) << data [i].name << " " << data [i].weight
             << right << setw (7) << data [i].time << endl;

    cout << endl << "Average weight: " << fixed << setprecision (1) << average
         << endl << "Fastest Rat: " << data [fastest].name << ": "
         << data [fastest].time
         << endl << "Slowest Rat: " << data [slowest].name << ": "
         << data [slowest].time << endl << endl;

    system ("PAUSE > NUL");

    return 0;
}

//*******************************************************
// calcAvg: determines the average weight of the lab rats
//
// data - the array of structures of rat information
// returns - the value of the average weight
//*******************************************************

double calcAvg (Rat data [])
{
    double total = 0;

    for (int i = 0; i < SIZE; i++)
        total += data [i].weight;

    return total / SIZE;
}

//*******************************************************
// fidnExtrema: finds the indices of the Rat structure
// that has the fastest and slowest time
//
// data - the array of structures of rat information
// fastest - the index of the fastest rat's structure
// slowest - the index of the slowest rat's structure
//*******************************************************

void findExtrema (Rat data [], int &fastest, int &slowest)
{
    fastest = 0;

    for (int i = 1; i < SIZE; i++)
        if (data [i].time < data [fastest].time)
            fastest = i;

    slowest = 0;

    for (int i = 1; i < SIZE; i++)
        if (data [i].time > data [slowest].time)
            slowest = i;
}
