// Coin game: Alice and Bob are playing a game
// using a bunch of coins. The players pick several coins out of the
// bunch in turn. Each time a player is allowed to pick 1, 2 or 4 coins,
// and the player that gets the last coin is the winner. Assume that
// both players are very smart and he/she will try his/her best to
// work out a strategy to win the game. For example, if there are 2
// 1
// coins and Alice is the first player to pick, she will definitely pick 2
// coins and win. If there are 3 coins and Alice is still the first player
// to pick, no matter she picks 1 or 2 coins, Bob will get the last coin
// and win the game. Given the number of coins and the order of
// players (which means the first and the second players to pick the
// coins), you are required to write a program to calculate the winner
// of the game, and calculate how many different strategies there are
// for he/she to win the game. You should use recursion to solve
// the problem, and the parameters are read from the command line.
// You can assume that there are no more than 30 coins.
// Here are some sample runs of the program:
// ./pickcoin 1 alice bob
// alice 1
// ./pickcoin 2 bob alice
// bob 1
// ./pickcoin 3 alice bob
// bob 2
// ./pickcoin 10 alice bob
// alice 22
// ./pickcoin 25 alice bob
// alice 3344
// ./pickcoin 30 alice bob
// bob 18272


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

pair<int, string> A[60] = {make_pair(0, "")};

// Winning in least number of moves -- try this variation
pair<int, string> game(int coins, string first, string second)
{
    static int global_strategies=0;
    static string winner;
    int strategies=0;
    string turn = first;
    
    if(coins==1)
    {
        strategies+=1;
        A[1] = make_pair(strategies,"first");
        return make_pair(strategies, first);
    }
    if(coins==2)
    {
        strategies+=1;
        A[2] = make_pair(strategies,"first");
        return make_pair(strategies, first);
    }
    if(coins==3)
    {
        strategies+=2;
        A[3] = make_pair(strategies,"second");
        return make_pair(strategies, second);
    }    
    if(coins==4)
    {
        strategies+=3;
        A[4] = make_pair(strategies,"first");
        return make_pair(strategies, first);
    }
    for(int i=1; i<=4; i++)
    {
        if(i==3)
            continue;

        // Memoization to remember previous states
        // Player picks i coin/coins
        pair<int, string> p;

        if(A[coins-i].first==0)
        {
            // First and second position are switched
            p = game(coins-i,second,first);            
        }
        else
        {
            p.first = A[coins-i].first;
            // First and second position are switched
            if(A[coins-i].second=="first")
                p.second = second;
            else
                p.second = first;
        }
        if(turn==p.second)
        {
            strategies +=p.first;
            winner = p.second;
        }
    }

    // First player tried every combination but he/she cannot win !!
    if(strategies==0)
    {
        for(int i=1; i<=4; i++)
        {
            if(i==3)
                continue;

            // Player picks i coin/coins
            pair<int, string> p;
            if(A[coins-i].first==0)
            {
                // First and second position are switched
                p = game(coins-i,second,first);
            }
            else
            {
                p.first = A[coins-i].first;
                // First and second position are switched
                if(A[coins-i].second=="first")
                    p.second = second;
                else
                    p.second = first;
            }

            strategies +=p.first;
            winner = p.second;
        }
    }

    if(winner==first)
    {
        A[coins] = make_pair(strategies, "first");
    }
    else
    {
        A[coins] = make_pair(strategies, "second");
    }
    return make_pair(strategies, winner);
}

// Input max 30 coins
int main(int argc, char** argv)
{
    int coins = stoi(argv[1],nullptr,0);
    string first=argv[2], second=argv[3];
    pair<int, string> p = game(coins, first, second);
    cout << p.second << " "<< p.first;
    return 0;
}