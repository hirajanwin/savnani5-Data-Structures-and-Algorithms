// A word is considered elfish if it contains the
// letters: e, l, and f in it, in any order. For example, we would say
// that the following words are elfish: whiteleaf, tasteful, unfriendly,
// and waffles, because they each contain those letters.
// • Write a predicate function called elfish? that, given a word,
// tells us if that word is elfish or not.
// • Write a more generalized predicate function called x-ish? that,
// given two words, returns true if all the letters of the first word
// are contained in the second.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

bool xish(string s1, string s2)
{
    if(s1.length()==1)
    {
        if(s2.find(s1)<s2.length())
            return true;
        else
            return false;
    }
    
    string s(1,s1[0]);
    string r=s1.substr(1);
    return (xish(s,s2) && xish(r, s2));

}

int main()
{
    string s1="elf", s2="whiteeaf";
    cout << xish(s1, s2);
}