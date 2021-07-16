/*
Pairs with specific difference 
Given an array of integers arr[] and a number K.You can pair two numbers of the array if the difference between them is strictly less than K. The task is to find the maximum possible sum of such disjoint pairs. The Sum of P pairs is the sum of all 2P numbers of pairs.

 

Example 1:

Input  : 
arr[] = {3, 5, 10, 15, 17, 12, 9}
K = 4
Output : 
62
Explanation :
Then disjoint pairs with difference less
than K are, (3, 5), (10, 12), (15, 17)
max sum which we can get is 
3 + 5 + 10 + 12 + 15 + 17 = 62
Note that an alternate way to form 
disjoint pairs is,(3, 5), (9, 12), (15, 17)
but this pairing produces less sum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here
        sort(arr, arr + N, greater<int>()); //rev sort
        int i = 0;                          //pointer
        int s = 0;                          //sum
        while (i < N - 1)                   //till reaches last
        {
            int x = abs(arr[i] - arr[i + 1]);
            if (x < K)
            {
                s += arr[i];
                s += arr[i + 1]; //adding pairs in sum
                i = i + 2;       //increamenting by 2
            }
            else
            {
                i++; //skipping element
            }
        }
        return s;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Solution ob;
    cout << ob.maxSumPairWithDifferenceLessThanK(arr, n, k) << endl;

    return 0;
}