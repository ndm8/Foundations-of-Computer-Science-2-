// File Name: QuestionDriver.cpp
//
// Author: Nick Montana
// Date: 3/21/2017
// Assignment Number:4
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// Driver to test the Question class.

#include <iostream>
#include <iomanip>
#include <string>

#include "Question.h"

using namespace std;

int main ()
{
    const int SIZE = 5;

    string q1Stem = "What name is given to half of a Byte (4 bits)?";
    string q1Answers [] = {"Nibble","Ort","Scrap","Snippet"}; //answer A
    string q2Stem = "Which country is home to the Kangaroo?";
    string q2Answers [] = {"China","India","Mexico","Australia"}; //answer D
    string q3Stem = "What do you use to measure an angle?";
    string q3Answers [] = {"Compass","Protractor","Ruler","T-Square"}; //ans B
    string q4Stem =
    "The Great Sphinx has the head of a human and the body of a what?";
    string q4Answers [] = {"Camel","Eagle","Lion","Alligator"}; //answer C
    string q5Stem =
    "What is the flat rubber disc used in a game of ice hockey?";
    string q5Answers [] = {"Birdie","Puck","Dart","Tile"}; //answer B

    Question q1 (q1Stem, q1Answers, 'A');
    Question q2 (q2Stem, q2Answers, 'D');
    Question q3 (q3Stem, q3Answers, 'B');
    Question q4 (q4Stem, q4Answers, 'C');
    Question q5 (q5Stem, q5Answers, 'B');

    Question my_array [SIZE] = {q1, q2, q3, q4, q5};

    for (int i = 0; i < SIZE; i++)
        my_array [i].display();

    cout << "Answers: ";
    for (int i = 0; i < SIZE; i++)
        cout << my_array [i].getKey() << " ";

    cout << endl << endl;

    return 0;
}
