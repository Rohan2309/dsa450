/*
Prime Factorisation using Sieve

spf - smallest prime factor of i

while(n!=1){ will divide that number with spf untill it becomes 1
    n = n/spf[n]
}
n = 20, spf of 20 is 2
divide 20 with 2 untill it becomes 1 
20--(20/2)-->10--(10/2)-->5--as 5 is already prime number-->1
prime factors are 2,2 and 5

we will mark numbers which are divisible by 2
these no's spf is 2
similarly for 3,5 and 7
*/

#include <bits/stdc++.h>
using namespace std;

void primeFactor(int n)
{
    int spf[100] = {0};
    for (int i = 2; i <= n; i++) //at first all number's spf will be that number itself
    {
        spf[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i) //it is not marked yet
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j) //it is unmarked
                {
                    spf[j] = i; //assigning spf to each number
                }
            }
        }
    }

    while (n != 1) //till number not becomes 1
    {
        cout << spf[n] << " ";
        n = n / spf[n]; //divide no with spf[n]
    }
}

int main()
{
    int n; //range
    cin >> n;
    primeFactor(n);

    return 0;
}