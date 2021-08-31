#include <iostream>
#include <stdio.h>

using namespace std;

//______________________Pass/Call by Value Example___________________
// void swap(int x, int y)
// {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }


// int main()
// {
//     int a,b;
//     a = 10;
//     b = 20;
//     swap(a,b);
//     printf("%d %d", a, b);
// }

//_______________________Pass/Call by address(Address of variable is passed in pointers)________________________
// void swap(int *x, int *y)
// {
//     int temp;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int main()
// {
//     int a,b;
//     a = 10;
//     b = 20;
//     swap(&a,&b);
//     printf("%d %d", a, b);
// }

//__Pass/Call by reference(Dont use for complex functions involving multiple looping coz even if the source code is procedural, the machine code is monolithic)_____________________

// Here function modifies the actual parameters (NOTE: References are nicknames, so they are the variable itself)

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a,b;
    a = 10;
    b = 20;
    swap(a,b);
    printf("%d %d", a, b);
}


