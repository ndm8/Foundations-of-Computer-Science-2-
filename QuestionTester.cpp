// File Name: QuestionTester.cpp
//
// Author: Jill Seaman
// Date: 3/4/2017
// Assignment Number:4
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// Driver to test the Question class.

#include <iostream>
#include <iomanip>
using namespace std;

#include "Question.h"

void Question :: setStem (string sm)
{
    stem = sm;
}

string Question :: getStem () const
{
    return stem;

}

void Question :: setAnswers (string ans [])
{
    for (int i = 0; i < 4; i++)
    {
        answers [i] = ans [i];
    }
 //   answers [] = {ans [0], ans [1], ans [2], ans [3]};
 // why doesn't this work???

}

string Question :: getAnswer (int i) const
{
    return answers [i];
}

void Question :: setKey (char ky)
{
    key = ky;
}

char Question :: getKey () const
{
    return key;

}

void Question :: display () const
{
    cout << stem << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << char ('A' + i) << ". " << answers [i] << endl;
    }
}

Question :: Question ()
{
    stem = " ";
    for (int i = 0; i < 4; i++)
    {
        answers [i] = " ";
    }
//    answers [] = {" ", " ", " ", " "};
//
    key = 'X';
}

Question :: Question (string stm, string ans [], char ky)
{
    stem = stm;
    for (int i = 0; i < 4; i++)
    {
        answers [i] = ans [i];
    }
//    answers [] = {" ", " ", " ", " "};
//
    key = ky;
}


int main()
{
    Question q1;
    q1.setStem("What name is given to half of a Byte (4 bits)?");
    string q1Answers [] = {"Nibble","Ort","Scrap","Snippet"};
    q1.setAnswers(q1Answers);
    q1.setKey('A');

    cout<< "q1 stem: " << q1.getStem() << endl;
    cout<< "q1 first answer: " << q1.getAnswer(0) << endl;
    cout<< "q1 last answer: " << q1.getAnswer(3) << endl;
    cout <<"q1 correct answer: " << q1.getKey() << endl;
    cout << endl;
    string q2Answers [] = {"China","India","Mexico","Australia"};
    Question q2 ("Which country is home to the Kangaroo?",q2Answers,'D');

    q2.display();
    cout << endl;
}

/* Expected output:

 q1 stem: What name is given to half of a Byte (4 bits)?
 q1 first answer: Nibble
 q1 last answer: Snippet
 q1 correct answer: A

 Which country is home to the Kangaroo?
 A. China
 B. India
 C. Mexico
 D. Australia

 */
