/*
172. Factorial Trailing Zeroes
Medium

1659

1563

Add to List

Share
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int trailingZeroes(int n) {
        //the algorithm is, we have to calculate no. of 5s
        //like for 100
        //100/5 = 20 --> in next step 5*5 = 25
        //so 100/25 = 4 --> 25*5 = 125, and 100/125 is not greater than 0
        //so 20+4 = 24 
        int ans = 0;
        int p =5;//power
        while((n/p)>0){
            ans += n/p;
            p*=5;
        }
        return ans;
    }
};

int main()
{

    return 0;
}