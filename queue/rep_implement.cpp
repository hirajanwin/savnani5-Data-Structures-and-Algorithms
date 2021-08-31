#include <iostream>
using namespace std;
 
class Queue
{
    private:
        int size;
        int front;
        int rear;
        int* Q;

    public:
        Queue(int size);
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(int x);
        int dequeue();
        void display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int[size];
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

void Queue::enqueue(int x)
{
    if(Queue::isFull())
        cout << "Queue Overflow" << endl;
    else
    {
        rear = (rear+1) % size;
        Q[rear] = x;
    }
}

int Queue::dequeue() 
{
    int x=-1;
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


int main()
{
    int A[] = {1, 3, 5, 7, 9};
 
    Queue Q(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        Q.enqueue(A[i]);
    }
 
    // Display
    Q.display();
    cout << endl;
 
    // Overflow
    Q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        Q.dequeue();
    }
 
    // Underflow
    Q.dequeue();
 
    return 0;
}