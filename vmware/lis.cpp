#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        //dp arrays ith index will will have the element wich is the last element of potential
        //longest subsequence of length i in dp array
        int dp[n+1];
        //we are filling the dp array with first ele int max and rest int min
        for(int i=1; i<=n;++i)dp[i]=INT_MAX;
        dp[0]=INT_MIN;
        for(int i=0;i<n;++i){
            int idx = upper_bound(dp, dp+n+1, a[i]) -dp;//will give index in dp array
            //upper bound will find next greater ele than a[i] in dp arr
            if(a[i]>dp[idx-1] and a[i]<dp[idx])dp[idx]=a[i];
            //if a[i] is greater than prev ele of idx in dp and
            //a[i] is smaller than current index we update it in dp arr
            
        }
        //iterating through last to find first non index which is not int max
        int ma = 0;
            for(int i=n; i>=0;--i){
                if(dp[i]!=INT_MAX){
                    ma=i;
                    break;
                }
            }
            
        return ma;
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
