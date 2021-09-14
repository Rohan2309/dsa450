/*
50. Pow(x, n)
Medium

3010

4259

Add to List

Share
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (nn < 0)
    { //if nn neg changing to positive
        nn *= -1;
    }
    while (nn)
    { //until nnbecomes 0 (we stop when 0)
        if (nn % 2)
        {             //if nn is odd
            ans *= x; //multiply ans with x
            nn -= 1;  //reduced by 1
        }
        else
        {            //if even power
            x *= x;  //(we multiply x * x)
            nn /= 2; //and divide n/2
        }
    }
    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}
int main()
{

    return 0;
}