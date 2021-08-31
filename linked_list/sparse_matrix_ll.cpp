#include <iostream>
#include <stdio.h>
using namespace std;

class Node 
{
    public:
        int col;
        int data;
        Node *next;    
};

class SparseMatrix
{
    private:
        int m;
        int n;
        Node *A[];

    public:
        SparseMatrix();
        // ~SparseMatrix();
        void display();
        SparseMatrix operator+(SparseMatrix &s); //Write it
};

SparseMatrix::SparseMatrix()
{
    int x, j_count;
    cout << "Please enter the dimensions of the matrix: " << endl;
    cin >> this->m >> this->n;

    Node *p = NULL;
    cout << "Please enter the elements of the matrix: " << endl;
    for(int i=0; i<m; i++)
    {
        j_count=0;
        for(int j=0; j<n; j++)
        {
            cin >> x;
            if(x!=0 && j_count==0)
            {
                j_count=1;
                Node *t = new Node;
                t->col = j;
                t->data = x;
                t->next = NULL;
                A[i] = t;
                p = t;
            }
            else if(x!=0)
            {
                Node *t = new Node;
                t->col = j;
                t->data = x;
                t->next = NULL;
                p->next = t;
                p=p->next;
            }
        }
    }
}

void SparseMatrix::display()
{
    Node *p = NULL;
    for(int i=0; i<m; i++)
    {
        p = A[i];
        for(int j=0; j<n; j++)
        {
            if(p && j==p->col)
            {
                cout <<p->data << " ";
                p=p->next;
            }
            else
                cout << "0 "; 
        }
        cout << endl;
    }   
}


int main()
{
    SparseMatrix s;
    cout << endl;
    s.display();
}