#include <iostream>
#include <cctype>
#include <string>
#include "stack.cpp"
using namespace std;

int oprPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isParenthesesValid(string str) {

    Stack<char> stack;

    for (char ch : str) {

        if (ch == '(' || ch == '[' || ch == '{') {

            stack.Push(ch);

        }
        else if (ch == ')' || ch == ']' || ch == '}') {

            if (stack.IsEmpty()) {
                return false;
            }

            char top;

            stack.Pop(top);

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }

        }
    }

    return stack.IsEmpty(); 
}


string convertInfixToPostfix(string infix) {

    Stack<char> stack;

    string postfix;

    for (char ch : infix) {
        if (islower(ch)) {
            ch = toupper(ch); 
        }

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.Push(ch);
        }
        else if (ch == ')') {
            while (!stack.IsEmpty()) {
                char top;
                stack.Pop(top);
                if (top == '(') break;
                postfix += top;
            }
        }
        else {
            while (!stack.IsEmpty() && oprPrecedence(stack.Peek()) >= oprPrecedence(ch)) {
                char top;
                stack.Pop(top);
                postfix += top;
            }
            stack.Push(ch);
        }
    }

    while (!stack.IsEmpty()) {
        char top;
        stack.Pop(top);
        postfix += top;
    }

    return postfix;
}


int EvaluatePostfix(string postfix) {
    Stack<int> stack;

    for (char ch : postfix) {
        if (islower(ch)) {
            ch = toupper(ch); 
        }

        if (isdigit(ch)) {
            stack.Push(ch - '0'); 
        }
   
        else {
            int operand2, operand1;

            stack.Pop(operand2);
            stack.Pop(operand1);

            switch (ch) {

            case '+': {
                stack.Push(operand1 + operand2);
                break;
            }
            case '-': {
                stack.Push(operand1 - operand2);
                break;
            }
            case '*': {
                stack.Push(operand1 * operand2);
                break;
            }
            case '/': {
                stack.Push(operand1 / operand2);
                break;
            }

            }
        }
    }

    int result;

    stack.Pop(result);
    return result;
}

int main() {
    
    Stack<int> IntStack;
    Stack<float> FloatStack;
    int data;
    float val;

    IntStack.Push(35);
    FloatStack.Push(3.1415927);

    IntStack.Pop(data);
    cout << "Popped from Integer Stack: " << data << endl;

    FloatStack.Pop(val);
    cout << "\nPopped from Float Stack: " << val << endl;


    
    string str;

    cout << "\n\n>>Input a parenthesized expression to check its validity: ";
    cin >> str;

    if (isParenthesesValid(str)) {
        cout << "\nValid Parentheses" << endl;
    }
    else {
        cout << "\nInvalid Parentheses" << endl;
    }


    
    string infix;
    cout << "\n>>Input an infix expression to convert to postfix expression: ";
    cin >> infix;

    string postfix = convertInfixToPostfix(infix);
    cout << "\nPostfix stression: " << postfix << endl;

   

    cout << "\n>>Input a postfix expression for evaluation: ";
    cin >> postfix;

    int result = EvaluatePostfix(postfix);
    cout << "\nResult of Postfix Evaluation is: " << result << endl;

    return 0;
}
