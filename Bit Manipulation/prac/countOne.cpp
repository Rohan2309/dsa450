/*
to count no of ones in binary representation of a number

n & n-1 has same bits as n except the rightmost set bit

count = 0
n=19 = 01011
n-1 =18 = 01010
n=n&n-1 = 01010
count =1
n = 18 = 01010
n-1 = 17 = 01001
n=n&n-1 = 01000
count =2
n=16 = 01000
n-1 = 15 = 00111
n = n&n-1 = 00000
count = 3
so 3 set bit present
*/

#include <bits/stdc++.h>
using namespace std;

int noOf1(int n)
{
    int count = 0;
    while (n != 0) //till n is 0
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    cout << noOf1(19) << endl;
    return 0;
}