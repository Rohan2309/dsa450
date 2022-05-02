/*
42. Trapping Rain Water
Hard

16458

234

Add to List

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int h1=0;//left max height
        int h2=0;//right max height
        int ans=0;//total water
        int r=n-1;//right pointer
        int l=0;//left pointer
        while(l<=r){//base
            if(h[l]<=h[r]){//when left height is smaller than right height
                if(h[l]>=h1){//if greater than maxleft
                    h1=h[l];//we update
                }
                else{//if smaller, then water will be there
                    ans+=h1-h[l];
                }
                l++;//incre
            }
            else if(h[r]<=h[l]){//for right
                if(h[r]>=h2){
                    h2=h[r];
                }
                else{
                    ans+=h2-h[r];
                }
                r--;
            }
        }
        return ans;
    }
};
int main()
{
    
    return 0;
}