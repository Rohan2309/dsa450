/*
Minimum Platforms 
Medium Accuracy: 46.78% Submissions: 94550 Points: 4
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 

 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);//as when any train departs then only another train can arrive
    	
    	int platform_needed=1;//initialy considering 1st train arrive
    	int res=1;//storing maximum
    	int i=1;//first train arrived so pointer at 2nd train
    	int j=0;//dept pointer
    	
    	while(i<n and j<n){//base
    	    if(arr[i]<=dep[j]){//2nd train arrives before departure of first
    	        platform_needed++;//we need extra pointer
    	        i++;//going to next train
    	    }
    	    else if(arr[i]>dep[j]){//cond, (strictly greater), 1st train has already departed then 2nd arrives
    	        platform_needed--;//train escapes from platform
    	        j++;//moving to new dept time
    	    }
    	    res = max(platform_needed, res);//having the max platform 
    	}
    	return res;
    }
};

int main()
{
    
    return 0;
}