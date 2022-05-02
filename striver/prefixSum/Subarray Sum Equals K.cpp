#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        if(n==0)return 0;
        unordered_map<int,int>mp;//prefix sum with num of occurence
        int curSum = 0;//pre sum
        int i = 0;//itr
        int cnt = 0;
        while(i<n){
            curSum+=a[i];
            if(curSum==k)cnt++;//found a new sub array with sum k
            if(mp.find(curSum-k)!=mp.end())cnt+=mp[curSum-k];
            mp[curSum]++;
            ++i;
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
