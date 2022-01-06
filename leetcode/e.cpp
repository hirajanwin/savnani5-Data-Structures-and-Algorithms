#include <iostream>
#include <string>
#include <stack>
using namespace std;

float computeLisp(const string lisp_expression) {
    
    char a,b,c,k;
    float res;
    stack<char> s;
    for(int i =0; lisp_expression[i]!= '\0'; i++)
    {
        if(lisp_expression[i] == ')')
        {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            c = s.top(); s.pop();
            s.pop();
            float num1 = a - '0';
            float num2 = b - '0';
            if(c == '+')
            {
                res = num1+num2;
                k = '0' + (char)res;
                s.push(k);
            }
            else if(c == '-')
            {
                res = num1-num2;
                k = '0' + (char)res;
                s.push(k);
            }
            else if(c == '*')
            {
                res = num1*num2;
                k = '0' + (char)res;
                s.push(k);
            }
            else
            {
                res = num1/num2;
                k = '0' + (char)res;
                s.push(k);
            }        
        }
        else if(lisp_expression[i] == ' ')
        {
            continue;
        } 
        else
        {
            s.push(lisp_expression[i]);
        } 
    }
    return res;
}

int main()
{
    string lisp_expression = "( - ( + 3 3 ) 2 )";
    cout << computeLisp(lisp_expression);
}