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
    
    template <class T> 
    void push(T x);

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
 
template <class T>  
void Stack::push(T x) {
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

bool isOperand(char x)
{
    if(x =='+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return false;
    else
        return true;
}

int precedence(char x)
{   
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int generalPrecedenceInStack(char x)
{   
    if(x == '+' || x == '-') 
        return 2;
    else if(x == '*' || x == '/')
        return 4;
    else if(x == '^')
        return 5;
    else if(x == '(')
        return 0;
    else
        return 0;
}

int generalPrecedenceOutStack(char x)
{   
    if(x == '+' || x == '-') 
        return 1;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '^')
        return 6;
    else if(x == '(')
        return 7;
    else
        return 0;
}

// Note: Functions isOperand() and precedence() should be defined/declared before using them in convert function
char* convert(char* infix, Stack &s)
{
    char* postfix = new char[strlen(infix)+2];
    int i=0, j=0; 
    while (infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(precedence(infix[i]) > precedence(s.stackTop()))
                s.push(infix[i++]);
            else
                postfix[j++] = s.pop();
        }   
    }
    while(!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }    
    postfix[j] = '\0';
    return postfix; 
}

char* generalConvert(char* infix, Stack &s)
{
    char* postfix = new char[strlen(infix)+2];
    int i=0, j=0; 
    while (infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(generalPrecedenceOutStack(infix[i]) > generalPrecedenceInStack(s.stackTop()))
                s.push(infix[i++]);
            else
            {
                if(infix[i]==')' && s.stackTop()=='(')
                {
                    s.pop();
                    i++;
                }
                else
                    postfix[j++] = s.pop();
            }
        }   
    }
    while(!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }    
    postfix[j-1] = '\0';
    return postfix; 
}

int evalPostfix(char* postfix)
{
    Stack s(strlen(postfix)+1);
    int x1,x2,r;
    for(int i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            s.push(postfix[i] - '0');  // ASCII code correction (conversion form char to int)
        }
        else
        {
            x2 = s.pop(); 
            x1 = s.pop(); 
            switch(postfix[i])
            {
                case '+': 
                    r = x1+x2; break;
                case '-': 
                    r = x1-x2; break;
                case '*': 
                    r = x1*x2; break;
                case '/': 
                    r = x1/x2; break;
            }
            s.push(r);
        }
    }
    return s.stackTop();
}

int main()
{
    char infix[] = "2+3*4/5-2";
    Stack s(strlen(infix)+1);
    s.push(' ');                                            //To avoid error
    char* postfix = convert(infix, s);
    cout << postfix << endl;
    cout << evalPostfix(postfix); 
    return 0;
}