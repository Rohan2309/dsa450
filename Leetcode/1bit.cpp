/*
191. Number of 1 Bits
Easy

1980

698

Add to List

Share
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /*
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
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n)
        {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}