/*
*Sieve of Eratosthenes*
to get prime numbers in a given range
will find prime numbers by removing all the non prime numbers
will mark all numbers which are divisible by 2, 3, ..
the unmarked numbers are prime numbers left
*/

#include <bits/stdc++.h>
using namespace std;

void primeSieve(int n)
{
    int prime[100] = {0}; //creating array of size 100 , initiating with 0 = unmarked

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0) //if unmarked
        {
            for (int j = i * i; j <= n; j += i) //j will start from i^2 as it is the first number which will be divisible by i
            //j+=i : as we are jumping with value of i to find multiples
            {
                prime[j] = 1; //mark
            }
        }
    }

    //printing all prime numbers

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0) //if unmarked
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n; //range
    cin >> n;
    primeSieve(n);
    return 0;
}