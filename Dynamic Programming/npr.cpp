/*
Permutation Coefficient
Difficulty Level : Easy

Permutation refers to the process of arranging all the members of a given set to form a sequence. The number of permutations on a set of n elements is given by n! , where “!” represents factorial. 

The Permutation Coefficient represented by P(n, k) is used to represent the number of ways to obtain an ordered subset having k elements from a set of n elements.
*/

#include <bits/stdc++.h>
using namespace std;

//n!/(n-k)!

int main()
{
    int n, k;
    cin >> n >> k;
    int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
    }
    cout << (fact[n] / fact[n - k]);

    return 0;
}