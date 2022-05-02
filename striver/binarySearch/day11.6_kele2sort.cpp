/*
K-th element of two sorted Arrays 
Medium Accuracy: 50.09% Submissions: 43307 Points: 4
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
 

Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int kthElement(int a1[], int a2[], int n1, int n2, int k)
    {
        if(n1>n2)return kthElement(a2,a1,n2,n1,k);//a1 will be smaller
        //we need total k eles in left half
        //edge cases for l and h, if a1 has 4 ele and a2 has 6 ele
        //when k is 3, we can't take 4 eles from the a1, l = 0, h = 3
        //when k is 7, we have to take atleast 1 ele from a1, l =1, h=4
        int l=max(0,k-n2);//assuming when k is bhgger than n2, we have to take atlease some else from a1
        int h=min(k,n1);//we can't take all els from a1, when k is smaller
        while(l<=h){
            int c1= (l+h)>>1;//middle ele (/2), for a1
            int c2= k-c1;//remaining eles in a2
            int l1=c1==0?INT_MIN:a1[c1-1];
            int l2=c2==0?INT_MIN:a2[c2-1];
            int r1=c1==n1?INT_MAX:a1[c1];
            int r2=c2==n2?INT_MAX:a2[c2];
            
            //valid case
            if(l1<=r2 and l2<=r1)return max(l1,l2);//k will be largest ele in left side
            //not valid cases
            else if(l1>r2)h=c1-1;
            else l= c1+1;
        }
    }
};
int main()
{
    
    return 0;
}