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
        void Merge(Node *second);

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
    Node *slow_p = first, *fast_p = first;

        while (fast_p && fast_p->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if (slow_p == fast_p) {
                return true;
            }
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

// Performed on Sorted Arrays
void LinkedList::Merge(Node *q)
{
    Node *p=first, *r=NULL;
    if(p->data<q->data)
    {
        first=p;
        r=p;
        p=p->next;
    }
    else
    {
        first=q;
        r=q;
        q=q->next; 
    }

    while(p && q)
    {
        if(p->data<q->data)
        {
            r->next=p;
            r=p;
            p=p->next;
        }
        else
        {
            r->next=q;
            r=q;
            q=q->next;
        }
    }
}

int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    int B[6] = {15, 25, 26, 40, 45, 55};
    LinkedList l1(A,5);
    LinkedList l2(B,6);
    l1.Display();
    cout << endl;
    // l1.Reverse();
    l1.Merge(l2.Getfirst());
    l1.Display();
}