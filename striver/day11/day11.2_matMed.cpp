/*
Matrix Median

*/

#include <bits/stdc++.h>
using namespace std;
int helper(vector<int>&v, int mid){
    int n = v.size();
    int l=0;
    int h= n-1;
    while(l<=h){
        int md= (h+l)>>1;
        if(v[md]<=mid){
            l=md+1;
        }
        else{
            
            h=md-1;
        }
    }
    return l;
}

int findmedian(vector<vector<int>>&a){
    int low=1;
    int high=1e9;
    int n = a.size();
    int m = a[0].size();
    while(low<=high){
        int mid=(low+high)>>1;// divided by 2
        int cnt=0;//will return no of elements lesser than equal to mid
        for(int i=0; i<n; ++i){//for each row we calculate
            cnt+=helper(a[i],mid);
        }
        //binary search part
        if(cnt<=(n*m)/2)low=mid+1;
        else high=mid-1;
    }
    return low;//will give the median of matrix
}

int main() {
	return 0;
}