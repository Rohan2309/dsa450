/*
Minimum number of jumps 
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int a[], int n)
    {
        // Your code here
        int maxR = a[0]; //max reachable point
        int step = a[0];
        int jump = 1; //minimum 1 jump
        if (n == 1)   //base case
        {
            return 0;
        }
        else if (a[0] == 0) //can't jump
        {
            return -1;
        }
        else
        {
            for (int i = 1; i < n; i++) //as for 0 we have already defined above
            {
                if (i == n - 1) //i reached last point
                {
                    return jump;
                }
                maxR = max(maxR, i + a[i]);
                step--;        //step was 1 it is now 0
                if (step == 0) //when 0 we jump
                {
                    jump++;
                    if (i >= maxR)
                    {
                        return -1;
                    }
                    step = maxR - i;
                }
            }
        }
    }
};

int main()
{
    int n, i, j;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    cout << ob.minJumps(arr, n) << endl;

    return 0;
}