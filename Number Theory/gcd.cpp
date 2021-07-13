/*

*Euclid's GCD*
GCD - Greatest Common Divisor
gcd(10,15) = 5
10%5=0 and 15%5=0

gcd(a,b) = gcd(b,a%b) -> rec case
gcd(a,0) = a -> base case

if gcd(a,b) [ if a<b]
then it will be gcd(b,a)

gcd(10,14) = gcd(14,10%14) = gcd(14,10) = gcd(10, 14%10) = gcd(10,4) = gcd(4,2) = gcd(2,0) = 2
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b); //ternary operator
    //if b = 0 answer is a (base case)
    //otherwise it will be gcd(b, a%b) (rec case)
}

int lcm(int a, int b, int hcf)
{
    return (a * b) / hcf;
    //formula is gcd * lcm = a * b
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int hcf = gcd(n1, n2);
    cout << hcf << endl;
    cout << lcm(n1, n2, hcf) << endl;
    return 0;
}