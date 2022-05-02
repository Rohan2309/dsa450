/*
84. Largest Rectangle in Histogram
Hard

9318

138

Add to List

Share
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

//double pass
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int>s;//will store indexes
        int lSmall[n];//array having left smaller element
        int rSmall[n];//array having right smaller element
        
        
        //for left smaller ele array
        for(int i=0; i<n;++i){
            //we store in stack, in increasing order
            while(!s.empty() and h[s.top()]>=h[i]){//elements greater than current ele height
                s.pop();//remove them
            }
            if(s.empty()) lSmall[i]=0;// if no element is smaller than current ele, then left most boundary
            else lSmall[i]=s.top()+1;//otherwise the ele present in stack is prev smaller
            s.push(i);//current index going in stack, in incre order
        }
        
        while(!s.empty())s.pop();//clearing stk for reuse
        
        //for right smaller ele array
        for(int i=n-1; i>=0;--i){//in rev direction
            //we store in stack, in increasing order
            while(!s.empty() and h[s.top()]>=h[i]){//elements greater than current ele height
                s.pop();//remove them
            }
            if(s.empty()) rSmall[i]=n-1;// if no element is smaller than current ele, then rightmost boundary
            else rSmall[i]=s.top()-1;//otherwise the ele present in stack is prev smaller
            s.push(i);//current index going in stack, in incre order
        }
        
        int maxA=0;
        for(int i=0; i<n; ++i){//getting max area
            maxA= max(maxA, h[i]*(rSmall[i]-lSmall[i]+1));
        }
        return maxA;
    }
};

//single pass
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int>s;//will store indexes
        int maxA=0;
        
        //for left smaller ele array
        for(int i=0; i<=n;++i){//will go till 1 extra after n
            //as at the end if there are eles in stack we need to compute for them too
            //we store in stack, in increasing order
            while(!s.empty() and (i==n or h[s.top()]>=h[i])){//if it's the last index (everything left in the stack needed to be computed) or else we operate
                //elements greater than current ele height
                int height = h[s.top()];//getting height
                s.pop();//remove them (greater eles)
                int width;
                if(s.empty())width=i;//does not have a left smaller
                //so width will become entire i, whereever the right smaller ele stands
                
                //if stack is not empty
                else width= i- s.top()-1;//right after that ele in the stack
                maxA= max(maxA,width*height);//getting maximum area
            }
            s.push(i);//pushing ele in stk
        }
        return maxA;
    }
};
int main()
{

    return 0;
}