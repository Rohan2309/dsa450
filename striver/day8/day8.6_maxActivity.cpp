/*
Maximum activities
Difficulty: EASY
Contributed By
Anish De
|
Level 1
Avg. time to solve
15 min
Success Rate
85%
Problem Statement
You are given N activities with their start time Start[] and finish time Finish[]. You need to tell the maximum number of activities a single person can perform.
Note:
A person can only work on a single activity at a time. The start time of one activity can coincide with the end time of another.
Input Format:
The first line contains an integer 'T' denoting the number of test cases or queries to be run. 

The first line of each test case or query contains a single integers 'N' denoting the number of activities. 

The second line of each test case contains N single space-separated integers denoting the starting time of N activities respectively.

The third line of each test case contains N single space-separated integers denoting the finishing time of N activities respectively.
Output Format:
For each test case, print the maximum number of activities a single person can perform.
Constraints:
1 <= T <= 5
1 <= N <= (10^5)
0 <= Start[i] < Finish[i] <= (10^9)

Time Limit: 1 sec
Sample Input 1:
2
4
1 6 2 4 
2 7 5 8 
3
1 1 1
4 5 9
Sample Output 1:
3
1
Explanation For Sample Input 1:
For test case 1: 
A person can perform maximum of 3 activities, by performing the activities in the given order 1 - > 3 -> 2.

For test case 2:
As the starting of all the activities is the same, a person can perform a maximum of 1 activity.
Sample Input 2:
2
4
1 3 2 5
2 4 3 6
2
1 2 
6 3 
Sample Output 2:
4 
1
 
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second){//if end time is similar 
        return a.first<b.first;//we compare start time
    }
    return a.second<b.second;//otherwise end time, in ascending order
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    vector<pair<int, int>>v(n);
    for(int i=0; i<n; ++i){
        v[i]={start[i],finish[i]};//pushing start and end in vect pair
    }
    sort(v.begin(), v.end(), comp);//sorting in asc acc to end time
    int curEndTime = v[0].second;//end time of first element
    int ans=1;//first ele is already taken
    for(int i=1; i<n; ++i){//loop from 2nd ele
        if(v[i].first>=curEndTime){//when start time of 2nd ele is greater than end time of 2nd ele
            ans++;//counter incre
            curEndTime=v[i].second;//new end time
        }
    }
    return ans;
}




int main()
{
    
    return 0;
}