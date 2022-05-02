/*
Job Sequencing Problem 
Medium Accuracy: 48.94% Submissions: 56722 Points: 4
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
 
*/

#include <bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    static bool comp(Job a, Job b){//desc order acc to profit
        return a.profit> b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n, comp);//sorting in desc ord acc to profit
        
        //finding maximum deadline
        int maxi= arr[0].dead;
        for(int i=0; i<n; ++i){
            maxi=max(maxi,arr[i].dead);
        }
        //creating array of slots acc to max deadline
        int slots[maxi+1];
        
        //initialize slots with -1
        for(int i=1; i<=maxi;++i){
            slots[i]=-1;
        }
        int totProfit=0;
        int jobCnt=0;
        
        //iterate over the job ids
        for(int i=0; i<n; ++i){
            //as late as possible 
            for(int j=arr[i].dead; j>0; --j){//for secondary array (as deadline 2 can also be finished at 1)
                if(slots[j]==-1){//not occupied
                    slots[j]=i;
                    jobCnt++;
                    totProfit +=arr[i].profit;
                    break;
                }
            }
        }
        return {jobCnt,totProfit};
    } 
};


int main()
{
    
    return 0;
}