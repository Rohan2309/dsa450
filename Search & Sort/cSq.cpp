/*
Count Squares 

Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on.
 You are given a number N, you have to output the number of integers less than N in the sample space S.

 

Example 1:

Input :
N = 9
Output:
2
Explanation:
1 and 4 are the only Perfect Squares
less than 9. So, the Output is 2.
Example 2:

Input :
N = 3
Output:
1
Explanation:
1 is the only Perfect Square
less than 3. So, the Output is 1.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function countSquares() 
which takes an Integer N as input and returns the answer.

 

Expected Time Complexity: O(sqrt(N))
Expected Auxiliary Space: O(1)


if number is 9 = n
sqrt of 9 is 3 = a
if 3 x 3 == 9 then 3-1 is the number of perfect squares (2 is ans)
if a x a != N then a is ans 

as 20 is n
sqrt of 20 is 4.something
so ans is 4
*/

#include <bits/stdc++.h>
using namespace std;

int countS(int n)
{
    int a = sqrt(n);
    if (a * a == n)
    {
        return a - 1;
    }
    else
    {
        return a;
    }
}

int main()
{
    int n = 9, N = 20;
    cout << countS(n) << endl;
    cout << countS(N) << endl;
    return 0;
}