#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int isOperand(char x)
{
    if(x =='+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int precedence(char x)
{   
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else
        return 0;
}

char* convert(char* infix) 
{
    char* postfix = new char[strlen(infix)+1];
    stack<char> st;
    int i=0,j=0;
    
    while(infix[i] != '\0')
    {
        if(!isOperand(infix[i]))
        {
            if(st.empty())
                st.push(infix[i++]);
            else if(precedence(infix[i]) > precedence(st.top()))
                st.push(infix[i++]);
            else
            {
                postfix[j++] = st.top();
                st.pop();
            }
        }
        else
            postfix[j++] = infix[i++];
    }
    // Emptying remaining elements in stack
    while(!st.empty())
    {
        postfix[j++] = st.top();
        st.pop();
    }    
    postfix[j] = '\0';
    return postfix;  
}

float eval(char* postfix)
{
    stack<float> st;
    for(int i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
            st.push(postfix[i] - '0');
        else
        {
            float x2 = st.top(); st.pop();
            float x1 = st.top(); st.pop();
            switch(postfix[i])
            {
                case '+': 
                    st.push(x1+x2);
                    break;
                case '-': 
                    st.push(x1-x2);
                    break;
                case '*': 
                    st.push(x1*x2);
                    break;
                case '/': 
                    st.push(x1/x2);
                    break; 
            }
        }
    }
    return st.top();
}


int main()
{
    char infix[] = "2+3*4/5-2";
    char* postfix = convert(infix);
    cout << postfix << endl;
    cout << eval(postfix); 
    return 0;
}