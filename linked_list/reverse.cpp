#include <iostream>
#include <stdio.h>
using namespace std;

class Node 
{
    public:
        int data;
        Node *next;    
};

class LinkedList
{
   
    public:
        Node *first;
        Node *last;

        LinkedList()
        {
            first=NULL;
            last=NULL;
        }
        LinkedList(int A[], int n);
        ~LinkedList();    
        void Display();
        int Length();
        void Reverse1();
        void Reverse2();
        void Reverse3(Node *p, Node *q);
        Node* greverse (Node *head, int k);
};

LinkedList::LinkedList(int A[], int n)
{   
    Node *t;
    int i=0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data=A[i];
        t->next= NULL;
        last->next=t;
        last=t;
    }
}   

LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList::Display()
{
    Node *p = first;
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next; 
    }
}

int LinkedList::Length()
{
    Node *p=first;
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

void LinkedList::Reverse1()
{
    Node *p = first, *r = NULL, *q = NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

void LinkedList::Reverse2()
{
    int l = LinkedList::Length();
    int A[l];
    Node *p=first;
    for(int i=0; i<l; i++)
    {
        A[l-i-1] = p->data;
        p = p->next;
    }
    p=first;
    for(int i=0; i<l; i++)
    {
        p->data=A[i];
        p=p->next;
    }
}

void LinkedList::Reverse3(Node *p, Node *q=NULL)
{
    if(p)
    {
        Reverse3(p->next,p);
        p->next=q;
    }
    else
        first=q;
}

Node* LinkedList::greverse (Node *head, int k)
{ 
    Node *curr = head, *prev = NULL, *next = NULL;
    int count = 0;
    
    while(curr != NULL and count < k)
    {
        next = curr->next;       
        curr->next = prev;
        prev = curr; 
        curr = next;
        count++;
    }

    if(next != NULL)
    {
        Node *res_head = greverse(next, k);
        head->next = res_head;
    }
    return prev;
}


int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    int B[6] = {15, 25, 26, 40, 45, 55};
    LinkedList l1(A,5);
    LinkedList l2(B,6);
    l1.Display();
    cout << endl;
    // l1.Reverse3(l1.Getfirst());
    l1.first = l1.greverse(l1.first, 3);
    l1.Display();
}