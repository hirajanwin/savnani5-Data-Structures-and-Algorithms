#include <iostream>
#include <stdio.h>
using namespace std;

class Node 
{
    public:
        int data;
        Node *next;    
};

class CircularLinkedList
{
    private:
        Node *first;
    
    public:
        CircularLinkedList()
        {
            first=NULL;
        }
        CircularLinkedList(int A[], int n);
        ~CircularLinkedList();
        Node* Getfirst();
        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        int Length();
};