#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

void RemoveWordFromLine(string &line, const string &word)
{
  auto n = line.find(word);
  if (n != string::npos)
  {
    line.erase(n, word.length());
  }
}

string rev(string s)
{
    istringstream ss(s);
    string word;

    ss >> word;
    if (s.compare(word)==0)
        return s + " ";

    word = word + ' ';
    RemoveWordFromLine(s, word);
    return (rev(s)+ word);
}

int main()
{
    string s="cat is running in a circle";
    cout << rev(s);
}