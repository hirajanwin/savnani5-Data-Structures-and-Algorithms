#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first;                        // Global pointer


void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first= new struct Node;
    first->data = A[0];
    first->next = NULL;
    last=first; 

    for(int i=1; i<n; i++)
    {
        t = new struct Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p =p->next;
    }
}

void rdisplay(struct Node *p)
{
    if(p!=NULL)
    {
        cout << p->data;
        rdisplay(p->next);
    }
}

int count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

int add(struct Node *p)
{
    int sum=0;
    while(p!=0)
    {
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}

void insert(struct Node *p, int pos, int x)
{
    if(pos < 0 || pos > count(p))
        return;
    struct Node *t = new Node;
    t->data=x;

    if(pos==0)
    {    
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        for(int i=0; i<pos-1; i++)
        {
            p = p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void insertlast(int x)
{
    struct Node *t = new Node;
    struct Node *last = new Node;
    t->data = x;
    t->next=NULL;
    if(first==NULL)
    {
        first=last=t;
    }
    else
    {
        last->next=t;
        last=t;    
    }
}


struct Node * search(struct Node *p, int key)
{
    // Note : first is a global pointer so no need to take it as argument
    struct Node *q=NULL;
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

void SortedInsert(struct Node *p, int x)
{
    struct Node *t,*q = NULL;
    t = new Node;
    t->data=x;
    t->next=NULL;

    if(first=NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x=-1;

    if(index<1 || index>count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else
    {
        for(int i=0; i<index; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

bool isSorted(struct Node *p)
{
    int x = -99999;
    while(p)
    {
        if(p->data<x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;
}

void Removeduplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;

        }
    }
}

void Reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q=p;
    A = new int[count(p)];
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q=NULL, *r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse3(struct Node *p, struct Node *q=NULL)
{
    if(p)
    {
        Reverse3(p->next,p);
        p->next=q;
    }
    else
        first=q;
}

bool checkloop(){return false;}
void concat(){}
void merge(){}

int main()
{   
    struct Node *temp;
    int A[] = {1,2,3,4,5};
    create(A,5);
    // Removeduplicate(first);
    Reverse3(first);
    // cout << isSorted(first) << endl;
    display(first);
    // cout << add(first) << endl;
    // cout << count(first);
}