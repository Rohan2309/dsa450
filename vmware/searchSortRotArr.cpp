#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int search(vector<int>& a, int k) {
        //binary search can only be applied in sorted array
        //so we have two sorted arrays 4567 and 123 and k is 6
        int l = 0;//4
        int h = a.size()-1;//3
        while(l<=h){
            int m = (h+l)/2;//middle element //7
            if(a[m]==k){//base case
                return m;//return pos
            }
            else if(a[m]>= a[l]){//when mid is 7 and low is 4 (then mid is in 1st search space)
                if(a[m]>=k and a[l]<=k){//k is 6 , 6 is greater than 4 and smaller than 7
                    h=m-1;//search space changed(now only will search in first search space)
                }
                else{
                    l=m+1;//else will search in 2nd search space
                }
            }
            else{//when middle element is in second search space
                if(a[m]<=k and a[h]>=k){//checking if it lies between mid and high
                    l=m+1;//searching in 
                }
                else{
                    h=m-1;//else searching in the first search space
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}