// file Question.cpp

#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "Question.h"

using namespace std;

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
    for (int i = 0; i < NUM_ANSWERS; i++)
        answers [i] = ans [i];
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
    for (int i = 0; i < NUM_ANSWERS; i++)
        cout << char ('A' + i) << ". " << answers [i] << endl;
    cout << endl;
}

Question :: Question ()
{
    stem = " ";
    for (int i = 0; i < NUM_ANSWERS; i++)
        answers [i] = " ";
    key = 'X';
}

Question :: Question (string stm, string ans [], char ky)
{
    stem = stm;
    for (int i = 0; i < NUM_ANSWERS; i++)
        answers [i] = ans [i];
    key = ky;
}

