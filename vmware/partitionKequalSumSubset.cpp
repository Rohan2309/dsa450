#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int>& nums,int n, int k, int currSum,  vector<bool>& vis, int x, int idx){
        if(k==1)return true;
        if(currSum==x)return f(nums,n,k-1,0,vis,x,0);
        for(int i=idx;i<n;++i){
            if(!vis[i] and currSum+nums[i]<=x){
                vis[i]=true;
                if(f(nums,n,k,currSum+nums[i],vis,x,i+1))return true;
                vis[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k>n)return false;
        if(k==1)return true;
        int sum =0;
        //for(int i=0;i<n;++i)sum+=nums[i];
        sum = accumulate(nums.begin(), nums.end(), sum);
        if(sum%k!=0)return false;
        int target= sum/k;
        int curSum=0;
        vector<bool>vis(n,false);//can't take same ele
        return f(nums,n,k,curSum,vis,target,0);
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
