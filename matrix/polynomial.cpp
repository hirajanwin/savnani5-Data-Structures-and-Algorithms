#include <iostream>
#include <stdio.h>
using namespace std;

class Term
{
    public:
        int coeff;
        int exp; 
};

class Polynomial
{
    private:
        int n;
        Term *terms;

    public:
        Polynomial(int n)
        {
            this->n=n;
            terms = new Term[this->n];
        }
        ~Polynomial()
        {
            delete[] terms;
        }

        Polynomial operator+(Polynomial &s);

        friend istream & operator>>(istream &is,Polynomial &s);
        friend ostream & operator<<(ostream &os,Polynomial &s);
};

istream & operator>>(istream &is,Polynomial &s)
{
    cout << "Enter terms\n";
    for(int i=0; i<s.n; i++)
    {
        cin >> s.terms[i].coeff >> s.terms[i].exp;
    }
    return is;
}

ostream & operator<<(ostream &os,Polynomial &s)
{
    int k=0;
    for(int i=0;i<s.n;i++)
    {
        if(i==s.n-1)
            cout << s.terms[i].coeff << "x" << s.terms[i].exp;
        else
            cout << s.terms[i].coeff << "x" << s.terms[i].exp << "+";
    }
    return os;
}

Polynomial Polynomial::operator+(Polynomial &s)
{
    int i,j,k;
    Polynomial *sum = new Polynomial(n+s.n);
    i=j=k=0;

    while(i<n && j<s.n)
    {
        if(terms[i].exp>s.terms[j].exp)
            sum->terms[k++]=terms[i++];
        else if(terms[i].exp < s.terms[j].exp)
            sum->terms[k++]=s.terms[j++];
        else
        {
            sum->terms[k].exp=terms[i].exp;
            sum->terms[k++].coeff=terms[i++].coeff+s.terms[j++].coeff;
        }
    }
    for(;i<n;i++)sum->terms[k++]=terms[i];
    for(;j<s.n;j++)sum->terms[k++]=s.terms[j];

    sum->n=k;
    return *sum;
}

int main()
{
    Polynomial p1(5);
    Polynomial p2(5);

    cin>>p1;
    cin>>p2;

    Polynomial sum=p1+p2;

    cout<<"First Polynomial"<<endl<<p1 << endl;
    cout<<"Second Polynomial"<<endl<<p2 << endl;
    cout<<"Sum of Polynomials"<<endl<<sum << endl;
    return 0;
}
