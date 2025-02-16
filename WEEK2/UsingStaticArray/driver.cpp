#include <iostream>
#include "stack.h"
#include <string>
using namespace std;


void reverseString(const string& str) {

    Stack s;

    for (char ch : str) {

        s.Push(ch);
    }

    cout << "\nReversed String is: ";

    while (!s.IsEmpty()) {
        char ch;
        s.Pop(ch);
        cout << ch;
    }
    cout << endl;
}

int main() {

    Stack s;

    char item;

    
    for (int i = 0; i < 10; i++) {

        s.Push(i + '0'); 

    }

    
    cout << "\nTop Element in result of Peek is: " << s.Peek() << endl;

    
    cout << "\nDisplaying Popped Elements of Stack " << endl;

    cout << endl;

    for (int i = 0; i < 10; i++) {

        s.Pop(item);

        cout << "At position ( "<<(i+1)<<" ) : "<< item << endl;
    }
    cout << endl;

    
    string str = "SANA IS COOL";

    cout << "\n Orignal String is: " << str << endl;
    reverseString(str);

    return 0;
}
