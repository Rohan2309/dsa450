#include<bits/stdc++.h>
using namespace std;

class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    for(int i=0; i<n;++i)dp[i]=a[i];//filling dp array with the elements same as array because
	    //the max can be that dp[i] when it is taking only itself
	    for(int i=0; i<n;++i){
	        for(int j=0; j<i;++j){//j is before i
	            if(a[j]<a[i]){//taking when prev element is smaller
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
