#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>first;//storing 1st idx of ele
        map<int,int>second;//storing last idx of ele
        map<int,int>cnt;//storing freq of ele
        int n=nums.size();
        for(int i=0; i<n;++i){
            if(!first.count(nums[i]))first[nums[i]]=i;
            second[nums[i]]=i;
            cnt[nums[i]]++;
        }
        int mx=0;
        for(auto i: cnt) mx= max(mx,i.second);
        for(auto i: cnt){
            if(i.second==mx){
                n=min(n,second[i.first]-first[i.first]+1);
            }
        }
        return n;
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
