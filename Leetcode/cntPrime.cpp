/*
204. Count Primes
Easy

3769

880

Add to List

Share
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n)
{
    vector<bool> isP(n, true); //array of boolean initialized with true
    for (int i = 2; i * i < n; i++)
    { //logn
        if (!isP[i])
        {             //if already false
            continue; //skip
        }
        for (int j = i * i; j < n; j += i)
        { //for example when i is 2 we will check from 4 and jump to multiples of 2
            isP[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (isP[i])
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}