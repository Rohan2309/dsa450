/*
Coin game winner where every player has three choices
Last Updated : 30 May, 2021
A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y. In each move a player can pick x or y or 1 coins. A always starts the game. The player who picks the last coin wins the game or the person who is not able to pick any coin loses the game. For a given value of n, find whether A will win the game or not if both are playing optimally.

Examples: 

Input :  n = 5, x = 3, y = 4
Output : A
There are 5 coins, every player can pick 1 or
3 or 4 coins on his/her turn.
A can win by picking 3 coins in first chance.
Now 2 coins will be left so B will pick one 
coin and now A can win by picking the last coin.

Input : 2 3 4
Output : B
*/

#include <bits/stdc++.h>
using namespace std;

bool findWinner(int x, int y, int n)
{
    bool dp[n + 1];
    //false means b and true means a
    dp[0] = false; //a can't pick up
    dp[1] = true;  //only one coin so a will pick up
    for (int i = 2; i <= n; i++)
    {
        if (i - 1 >= 0 and dp[i - 1] == false) //can pick 1 and prev element is picked by B
        {
            dp[i] = true;
        }
        else if (i - x >= 0 and dp[i - 1] == false) //can pick 1 and prev element is picked by B
        {
            dp[i] = true;
        }
        else if (i - y >= 0 and dp[i - 1] == false) //can pick 1 and prev element is picked by B
        {
            dp[i] = true;
        }
        else //prev coin was picked up by a
        {
            dp[i] = false; //so b
        }
    }
    return dp[n];
}
int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';
    return 0;
}