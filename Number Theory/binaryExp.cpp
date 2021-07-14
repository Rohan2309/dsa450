/*
*Binary Exponentiation*
(a^b)%m sometimes becomes out of range

properties of modulo
(a+b)%m = (a%m) + (b%m)
(a*b)%m = (a%m) * (b%m)
(a-b)%m = (a%m) - (b%m)
(a/b)%m = (a%m) * (b^-1%m)

recursive case
a^n
when n is odd
a^n = a^n/2 * a^n/2 * a

when a is even
a^n = a^n/2 * a^n/2

base case 
n=0 then return 1


iterative
a^45
45 = 1x2^5 + 0x2^4 + 1x2^3 + 1x2^2 + 0x2^1 + 1x2^0
45 = (101101)2
7^45 can be calculated easily
2^3 = 2^2 + 2^2

start with var x = 1
keep multiplying it with itself
when there is 1 in binary rep
multiply it with ans
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;

int power(int a, int n)
{

    if (n == 0)
    {
        return 1;
    }
    int p = (power(a, n / 2) % MOD);

    if (n & 1) //if n is odd
    {
        return (((p * p) % MOD) * a) % MOD;
    }
    else
    {
        return (p * p) % MOD;
    }
}

signed main()
{
    int a, n;
    cin >> a >> n;
    a %= MOD;
    cout << power(a, n) << endl;
    return 0;
}