// Specification file for the CharStack class
// Replace with your header.

#include <string>
using namespace std;

class CharStack
{
private:
    string stackString;

public:
    // Constructor
    CharStack();

    // Stack operations
    void push(char);
    void pop();      //removes top character
    char peek();     //returns top character without removing it
    bool isFull() const;
    bool isEmpty() const;
};
