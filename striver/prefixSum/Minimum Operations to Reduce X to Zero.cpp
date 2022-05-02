#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        unordered_map<int,int>mp;//prefix sum with index
        mp[0]=0;//avoid index out of bound error
        int n = v.size();
        int sum = 0;//total sum of arr
        for(int i=0; i<n; ++i){
            sum+=v[i];
            mp[sum]=i;
        }
        if(x>sum)return -1;
        int longest = 0;//longest window, that we dont include
        sum = sum-x;//longest windows sum should be this
        int val=0;//we take all the values, will check at any index we have sum val = rest val
        int ans = INT_MIN;
        for(int i=0; i<n; ++i){
            val+=v[i];//keeping track of prefix sum
            if(mp.find(val-sum)!=mp.end()){//if present
                //no elements on left part
                if(val-sum==0)longest=max(longest,i-mp[val-sum]+1);//taking it
                else longest=max(longest,i-mp[val-sum]);//elements in left part
            }
        }
        return longest==0?(sum==0?n:-1):n-longest;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
