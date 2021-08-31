// To use header files change c_cpp_properties.json and tasks.json files

#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* lchild;
        Node* rchild;

        Node(int data)
        {
            this->data = data;
            lchild = NULL;
            rchild = NULL;
        } 
};

class Queue
{
    private:
        int size;
        int front;
        int rear;
        Node** Q;

    public:
        Queue(int size);
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(Node* x);
        Node* dequeue();
        void display();
};


class Stack
{
    private:
        int size;
        int top;
        Node** S;
    public:
        Stack(int size);
        ~Stack();
        void push(Node* x);
        Node* pop();
        int isFull();
        int isEmpty();
        void display();
        Node* stackTop();
};


Queue::Queue(int size)
{
    this->size = size;
    front = 0;
    rear = 0;
    Q = new Node*[size];
}

Queue::~Queue()
{
    delete [] Q;
}

bool Queue::isEmpty()
{
    if(front==rear)
        return true;
    return false;
}

bool Queue::isFull()
{
    if((rear+1) % size == front)
        return true;
    return false;
}

void Queue::enqueue(Node* x)
{
    if(Queue::isFull())
        cout << "Queue Overflow" << endl;
    else
    {
        rear = (rear+1) % size;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() 
{
    Node* x=NULL;
    if(Queue::isEmpty())
        cout << "Queue Underflow" << endl;
    else
    {
        front = (front+1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    int i = front + 1;
    do{
        cout << Q[i] << " ";
        i = (i+1) % size;
    }while(i != (rear+1) % size);
}

 
Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new Node*[size];
}
 
Stack::~Stack() {
    delete[] S;
}
 
void Stack::push(Node* x) {
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}
 
Node* Stack::pop() {
    Node* x = NULL;
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
 
void Stack::display() {
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
 
Node* Stack::stackTop() {
    if (isEmpty()){
        return NULL;
    }
    return S[top];
}
 
