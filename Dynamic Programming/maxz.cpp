/*
Maximum difference of zeros and ones in binary string 
Given a binary string of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.

Example 1:

Input : S = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, 
there are 7 0s and 1 1s, so number 
of 0s - number of 1s is 6. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubstring(string S)
    {
        // Your code goes here
        int n = S.length();
        int currentSum = 0; //kadane's algo
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int x = (S[i] == '0') ? 1 : -1; //when 0 we change it to 1 and 1 to -1 as we will subtract no of 0s - no of 1s
            currentSum += x;
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution ob;
    cout << ob.maxSubstring(s) << "\n";
    return 0;
}