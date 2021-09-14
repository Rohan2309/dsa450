/*
66. Plus One
Easy

2879

3636

Add to List

Share
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [0]
Output: [1]
Explanation: The array represents the integer 0.
Incrementing by one gives 0 + 1 = 1.
Thus, the result should be [1].
Example 4:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &d)
{
    int n = d.size();
    int idx = n - 1;
    while (idx >= 0)
    {
        if (d[idx] == 9)
        {
            d[idx] = 0;
        }
        else
        {
            d[idx] += 1; //if we get any number lesser than 9 then +1 return
            return d;
        }
        idx--;
    }
    d.insert(d.begin(), 1); //if all are 9 we inser 1 at beginning
    return d;
}

int main()
{

    return 0;
}