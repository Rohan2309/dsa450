/*
Arithmetic Number
Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' denoting the common difference of an arithmetic sequence and an integer 'B'. you need to tell whether 'B' exists in the arithmetic sequence or not.

Example 1:

Input: A = 1, B = 3, C = 2
Output: 1
Explaination: 3 is the second term of the 
sequence starting with 1 and having a common 
difference 2.
Example 2:

Input: A = 1, B = 2, C = 3
Output: 0
Explaination: 2 is not present in the sequence.
Your Task:
You do not need to read input or print anything. Your task is to complete the function inSequence() which takes A, B and C and returns 1 if B is present in the sequence. Otherwise, returns 0.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/
/*
a=1 c=2 and b =5
AP sequence -> first term is 1 and common difference is 2
1+2 -> 3+2-> 5+2->7
5 is present

time complexity is const

an = a1 + (n-1)d  (an -> nth term  (which is b =5))  (a1 -> 1st term (which is a =1)) and d is c->2
b= a+(n-1)c

n = (b-1)/c  + 1  [n>=1]  {n is number of terms}
if c=0 and a==b then we dont have to go anywhere else(1st element required element)
if c=0 and a!= b then we can't move so ans in 0


if c!=0
then (b-1)/c should be positive ( check b-a % c -> true then 1 should not return fractional value)
if negative then  n<1 which is not true then return 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int inSequence(int a, int b, int c)
    {
        // code here
        if (c == 0)
        { //diff is 0
            if (a == b)
            { //element is present there only
                return 1;
            }
            else
            { //diff is 0 we can't move
                return 0;
            }
        }
        else
        {
            if ((b - a) / c < 0)
            { //if negative then return 0 as it should be positive
                return 0;
            }
            else
            {
                if ((b - a) % c == 0)
                { //not fractional
                    return 1;
                }
                else
                { //fractional
                    return 0;
                }
            }
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        Solution ob;
        int ans = ob.inSequence(A, B, C);
        cout << ans << endl;
    }

    return 0;
}