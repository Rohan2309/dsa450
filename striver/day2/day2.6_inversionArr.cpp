/*
Count Inversions
Difficulty: MEDIUM
Contributed By
Deep Mavani
Avg. time to solve
40 min
Success Rate
55%
Problem Statement
For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Input Format :
The first line of input contains an integer 'N', denoting the size of the array.

The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
Output Format :
Print a single line containing a single integer that denotes the total count of inversions in the input array.
Note:
You are not required to print anything, it has been already taken care of. Just implement the given function.  
Constraints :
1 <= N <= 10^5 
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the array element at 'ith' index.

Time Limit: 1 sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation Of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation Of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).



Brute force
iterator i should be less than itr j
and arr[i] > arr[j]
so i at first then count on right side with cond  arr[i] > arr[j]


merge sort method
 
 in the merge process while merging
 whenever something came from the right in the merging, 
 everything from the right of the left pointere will be contributed and added up  in the
 answer.
*/

#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long *temp, int left,int mid, int right){
    int i, j, k;
    long long inv_cnt = 0;
    i = left; //indexes for left subarray
    j=mid; //idx for right sub array
    k=left; //idx for resultant merged array

    while((i<=mid-1)and(j<=right)){
        if(arr[i]<=arr[j]){ 
            temp[k++] = arr[i++];
        }
        else{
            temp[k++]= arr[j++];
            inv_cnt = inv_cnt + (mid-1);
        }
    }

    while(i<=mid-1) temp[k++] = arr[i++];

    while(j<=right) temp[k++] = arr[j++];

    for(i=left; i<=right; i++) arr[i]= temp[i];
return inv_cnt;
} 

long long _mergeSort(long long arr[], long long *temp, int left, int right){
    long long invCnt=0;
    int mid =0;
    if(right>left){//splitting into 2 halves
        mid = (right+left)/2;
        invCnt += _mergeSort(arr,temp,left,mid);
        invCnt += _mergeSort(arr,temp,mid+1,right);
        invCnt += merge(arr,temp,left,mid+1,right);//after splitting joining them
    }
    return invCnt;

}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n]; //temporary array
    long long ans = _mergeSort(arr, temp, 0, n-1);
    return ans;
}
int main(){
    return 0;
}