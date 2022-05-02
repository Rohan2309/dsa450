#include <bits/stdc++.h>
using namespace std;

class Solution
{
    
    int f(int n, int k,vector<vector<int>>&dp){
        //n is no of eggs, k is no of floors
        if(n==1)return k; //worst case is number of floors when we have 1 egg
        //we check f1, not break, f2 not break, f3 may or maynot break so worst case will be 3
        if(k==0)return 0; //no floors
        if(~dp[n][k])return dp[n][k];//memoisation
        int ans = 1e9;
        for(int i=1; i<=k; ++i){//running through each floor
            int broken = f(n-1,i-1,dp);//when egg breaks no of eggs will reduce
            //and we will check if the egg can be broken by a floor which is below current floor
            //to find the best possible ans, out of all max we find the min
            int notBroken = f(n,k-i,dp);//no of eggs remain same, and floors are left will be reduced by i
            int maxVal = max(broken,notBroken);//will take the max value out of it
            //finding maximum no of attemps and out of all of them getting the minimum ans
            ans = min(ans, maxVal+1);//adding 1 to maxVal as we are throwing the curr egg
            //optimization
        }
        return dp[n][k] = ans;
    }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(n,k,dp);
    }
};

class Solution {
private:
    int f(int k, int n, vector<vector<int>>&dp){
        if(k==1)return n;//worst case is number of floors when we have 1 egg
        //we check f1, not break, f2 not break, f3 may or maynot break so worst case will be 3
        if(n==0 or n==1)return n;
        if(~dp[k][n])return dp[k][n];
        int ans=1e9;
        int l=1,h=n;//2-ptr to number of floors
        int temp;
        while(l<=h)//iterate through no of floors
        {
            int mid=(l+h)/2;
            int left=f(k-1,mid-1,dp);//egg broken check for down floors of mid
            //when egg breaks no of eggs will reduce
            //and we will check if the egg can be broken by a floor which is below current floor to find the best possible ans, out of all max we find the min
            int right=f(k,n-mid,dp) ;// not broken check for up floors of mid
            //no of eggs remain same
            temp=1+max(left,right);//adding 1 to maxVal as we are throwing the curr egg
            if(left<right) l=mid+1;// so l=mid+1 to gain more temp for worst case : upward
            //since right is more than left and we need more in worst case 
            else h=mid-1;  //left > right so we will go downward 
            ans=min(ans,temp);//store minimum attempts
        }
        return dp[k][n]= ans;
    }
public:
    int superEggDrop(int k, int n) {
        //k is number of eggs, n is no of floors
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return f(k,n,dp);
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
