#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int l;
    int b;
};

void initialize(struct Rectangle *r, int l ,int b)
{
    r->l = l;
    r->b = b;
}

int area(struct Rectangle r)
{
    return r.l*r.b;
}

void changelength(struct Rectangle *r, int l)
{
    r->l=l;
}

int main()
{
    struct Rectangle r;
    int a;
    initialize(&r, 10, 5);
    a = area(r);
    changelength(&r, 20);
    printf("%d, %d, %d", r.l, r.b, a);
    return 0;
}