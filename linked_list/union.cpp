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
    private:
        Node *first;
        Node *last;
    
    public:
        LinkedList()
        {
            first=NULL;
            last=NULL;
        }
        LinkedList(int A[], int n);
        ~LinkedList();
        Node* Getfirst();
        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        int Length();
        Node * Search(int key);
        bool Checkloop();
        void Reverse();

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


Node* LinkedList::Getfirst()
{
    return first;
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

void LinkedList::Insert(int index, int x)
{
    if(index<0 || index > LinkedList::Length())
        return;
    
    Node *p=first;
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if(index==0)
    {
        t->next = first;
        first=t;
    }
    else if(index==LinkedList::Length())
    {
        last->next=t;
    }
    else
    {
        for(int i=1; i<index; i++)
        {
            p=p->next;                                  
        }
        t->next=p->next;
        p->next=t;
    }
}

int LinkedList::Delete(int index)
{
    if(index<0 || index > LinkedList::Length()-1)
        return -1;
    
    int x;
    Node *p=first, *q=NULL;
    if(index==0)
    {
        x=p->data;
        first=p->next;
        delete p;
        return x; 
    }
    else
    {
        for(int i=1; i<=index; i++)
        {
            q=p;
            p=p->next;                                  
        }
        x = p->data;
        q->next=p->next;
        delete p;
        return x;
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

Node * LinkedList::Search(int key)
{ 
    // With Transposition optimization i.e moving the key to the head
    Node *p=first,*q=NULL;
    while(p)
    {
        if(p->data==key)
        {
            q->next = p->next;
            p->next=first;
            first=p;
            return p;
        }
        q = p; 
        p = p->next;
    }
    return NULL;
}

bool LinkedList::Checkloop()
{
    Node *p=first, *q=first;
    while(q!=NULL)
    {
        if(p=q)
            return true; 
        p=p->next;
        q=q->next->next;
    }
    return false;
}

void LinkedList::Reverse()
{
    Node *p=first, *q=NULL, *r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main()
{
    int A[6] = {9,6,4,2,3,8};
    int B[5] = {1,2,8,6,2};
    LinkedList l1(A,6);
    LinkedList l2(B,5);
    
}