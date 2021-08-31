#include <iostream>
#include <stdio.h>

using namespace std;
 
class Node
{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data)
        {
            this->data = data;
            prev = NULL;
            next = NULL;
        }
};

class Stack
{
    private:
        int numNodes;
        Node *mid;
        Node *top;
    public:
        Stack();
        ~Stack();
        void push(int x);
        int pop();
        int findMiddle();
        void deleteMiddle();
};

Stack::Stack()
{
    numNodes = 0;
    mid = NULL;
    top = NULL;
}

Stack::~Stack()
{
    Node* p = top;
    while (top)
    {
        top = top->prev;
        delete p;
        p = top;
    }
}

// Check for mid conditions in the push and pop fucntions and also base conditions !!
void Stack::push(int x)
{
    Node *p = new Node(x);
    if(p==NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        numNodes++;
        if(top==NULL)
            top = mid = p;
        else
        {
            top->next = p;
            p->prev = top;
            top = p;

            if(numNodes%2==0)
                mid = mid->next;
        }
    }
}

int Stack::pop()
{
    int x = -1;
    if(top==NULL)
        cout << "Stack Underflow" << endl;
    else
    {
        numNodes--;
        Node *p = top;
        x = top->data;

        if(top->prev != NULL)
        {
            top = top->prev;
            top->next = NULL;
        }
        if(numNodes%2!=0)
            mid = mid->prev;
        delete p;
    }   
    return x;
}

int Stack::findMiddle()
{
    return mid->data;
}

void Stack::deleteMiddle()
{
    if(mid==NULL)
        cout << "Stack Underflow" << endl;
    else
    {
        Node *p = mid;
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;
        mid = mid->next;
        delete p;
    }
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    Stack s;

    // Populate stack
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        s.push(A[i]);
    
    cout << "Stack Mid " << s.findMiddle() << endl;
    s.pop();
    cout << "Stack Mid " << s.findMiddle() << endl;
    s.push(10);
    s.push(20);
    cout << "Stack Mid " << s.findMiddle() << endl;


}