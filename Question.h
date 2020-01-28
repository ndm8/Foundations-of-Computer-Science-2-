#include <string>

using namespace std;

const int NUM_ANSWERS = 4;

class Question
{
private:
    string stem;
    string answers [NUM_ANSWERS];
    char key;

public:
    Question ();
    Question (string, string [], char);
    void setStem (string);
    string getStem () const;
    void setAnswers (string []);
    string getAnswer (int) const;
    void setKey (char);
    char getKey () const;
    void display () const;
};
