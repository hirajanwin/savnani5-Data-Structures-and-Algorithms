#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
 
class Stack
{
private:
    int size;
    int top;
    int* S;
public:
    Stack(int size);
    ~Stack();
    void push(char x);
    int pop();
    int isFull();
    int isEmpty();
    int stackTop();
};

Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new int[size];
}
 
Stack::~Stack() {
    delete[] S;
}
 
void Stack::push(char x) {
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}
 
int Stack::pop() {
    int x = '\0';
    if (isEmpty()){
        cout << "Stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}

int Stack::isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}

int Stack::isEmpty() {
    if (top == -1){
        return 1;
    }
    return 0;
}

int Stack::stackTop() {
    if (isEmpty()){
        return -1;
    }
    return S[top];
}

// Extend function for different types of brackets
bool isBalanced(char* A)
{
    Stack s(strlen(A)+1);
    for(int i=0; A[i]!='\0'; i++)
    {
        if(A[i]=='(')
            s.push(A[i]);
        else if(A[i]==')')
        {
            if(s.isEmpty())
                return false;
            s.pop();
        }
    }
    if(s.isEmpty())
        return true;
    else
        return false;
}


int main()
{
    char A[] = "((a+b)*(c-d))";
    cout << isBalanced(A); 
    return 0;
}