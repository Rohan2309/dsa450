/*
Bit Difference 

You are given two numbers A and B. The task is to count the number of bits needed to be flipped to
 convert A to B.
Example 1:

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.


approach:
 1. Calculate XOR of A and B.      
        a_xor_b = A ^ B
  2. Count the set bits in the above 
     calculated XOR result.
        countSetBits(a_xor_b)
*/

#include <bits/stdc++.h>
using namespace std;

//counting set bits
int setBit(int n)
{
    int count = 0;
    while (n > 0) //till n = 0
    {
        count++;
        n &= (n - 1); //changing right most set bit to 0
    }
    return count;
}

int countBitsFlip(int a, int b)
{
    //xor of 2 numbers will have set bits only at those places where a differs from b
    return setBit(a ^ b);
}

int main()
{
    int a = 10, b = 20;
    cout << countBitsFlip(a, b) << endl;
    return 0;
}