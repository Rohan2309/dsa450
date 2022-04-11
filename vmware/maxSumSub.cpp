#include <bits/stdc++.h>
using namespace std;

class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    for(int i=0; i<n;++i)dp[i]=a[i];
	    for(int i=0; i<n;++i){
	        for(int j=0; j<i;++j){
	            if(a[j]<a[i]){
	                dp[i]=max(dp[i], dp[j]+a[i]);
	            }
	        }
	    }
	    int ma=INT_MIN;
	    for(int i=0; i<n;++i){
	        ma=max(ma,dp[i]);
	    }
	    return ma;
	}  
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
