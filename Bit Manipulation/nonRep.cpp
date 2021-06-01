/*
Non Repeating Numbers 

Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the 
other two number occur exactly once and are distinct. Find the other two numbers.


Example 1:

Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.


x^x = 0
0^y = y

3,4,8,2,1,2,8,3

1: 0001
2: 0010
3: 0011
4: 0100
8: 1000

overall xor can't be zero there will be 1 or more 1's in the result
4^1 = 101 = 5
any set bit (1) -> kth bit (let's take)
partition arr in 2 multisets
kth bit which are 1 will be in set a and 0 in set b
x and y will be in different partitions\
xor in both partitions
*/

#include <bits/stdc++.h>
using namespace std;

void rep(int a[], int n)
{
    int Xor = a[0]; //will hold xor of all elements
    int setBitNo;   //will have right most set bit
    int i;
    int x = 0;
    int y = 0;
    for (i = 1; i < n; i++) //xor of all elementss (from 1 as Xor already has 0)
    {
        Xor = Xor ^ a[i];
    }
    setBitNo = Xor & ~(Xor - 1); //getting rightmost set bit
    for (i = 0; i < n; i++)      //dividing elements in 2 sets by comparing rightmost set bit of Xor with bit at same pos of each element

    {
        if (a[i] & setBitNo) //xor of first set (results to 1)
        {
            x = x ^ a[i]; //gives 1st number
        }
        else
        {
            y = y ^ a[i]; //gives second number
        }
    }
    cout << x << " " << y << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    rep(arr, n);
    return 0;
}