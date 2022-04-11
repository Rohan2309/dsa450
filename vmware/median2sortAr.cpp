#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        //now nums1 is always smaller
        int n= nums1.size();
        int m= nums2.size();
        int low = 0;//at minimum we can choose 0 elements
        int high = n; //at maximum we can choose n elements, smaller ll
        int len = n+m;//total length of 2 ll
        bool odd = true;
        if(len%2==0)odd=false;
        while(low<=high){
            //cut 1 is for first array (eles we are taking from first array)
            //cut 2 is for second array (from 2nd array)
            int cut1 = (low+ high)>>1;//>>1 is always /2 
            int cut2 = ((n+m+1)>>1)-cut1;//half's length - what we have taken in array 1
            
            int l1 = cut1 == 0? INT_MIN : nums1[cut1-1];//left element to cut1 (when cut reaches 0 we assign min value)
            int l2 = cut2 == 0? INT_MIN : nums2[cut2-1];//that is no elements in left side all elements in right side
            int r1 = cut1 == n? INT_MAX : nums1[cut1];//right ele to c1 (when cut reaches end we assign max value)
            int r2 = cut2 == m? INT_MAX : nums2[cut2];//that is no elements in right side all elements in left side
            
            if(l1<=r2 and l2<=r1){//valid case
                if(!odd){//if total eles are even
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                else{//when odd elements
                    return max(l1,l2);
                }
            }
            //invalid cases
            else if(l1>r2){//we have to shift cut 1 towards left
                high = cut1-1;
            }
            else{//we have to shift cut1 towards right
                low = cut1+1;
            }
        }
        return 0.0;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
