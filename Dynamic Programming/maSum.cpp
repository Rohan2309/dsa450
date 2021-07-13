/*
Maximum sum increasing subsequence 
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
*/


#include <bits/stdc++.h>
using namespace std;


class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
        int dp[n];
        for(int i=0; i<n; i++){//filling dp with array elements
            dp[i]= arr[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){//checking elements from start to prev element
                if(arr[j]<arr[i]){ //if prev element is smaller than current element
                    dp[i]=max(dp[i], dp[j]+arr[i]); //storing max till that pos in dp
                }
            }
        }
       int m=0;
       for(int i=0; i<n; i++){
           m = max(m,dp[i]);
       }
       return m; 
	}  
};

int main()
{int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution ob;
    cout << ob.maxSumIS(a, n) << "\n";
    
    return 0;
}