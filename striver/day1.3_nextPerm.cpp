/*
31. Next Permutation
Medium

7550

2491

Add to List

Share
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]

EXPLANATION

for number , 132
perms are ->
123
132
213
231
312
321

so for 132,-> 213 comes next

next_permutation() inbuilt function can be used

Brute force

find all possible combos, then find 132, and for this the next perm will be 213
whenever it is the last of the dictionary, like 321 (ans will be the first one i.e 123)


OPTIMAL APPROACh -> 0(n)

for 1 3 5 4 2
first traverse array from the back,
if a[i] > a[i-1] then index will be i (so index  will be 1)
as 1 is smaller than 3 and 3s pos is 1
again, traverse from back,
find index which is greater than value of curr index (so new idx will be 3)
as 4 is greater than 3 and 4s pos is 3

swap vals of idx1 and idx2
so after swapping 1 4 5 3 2 
reverse everything to the right of idx1 , so 1 4 2 3 5


intuition,
 there is a specific pattern , like 5 is the peak point and befor that it
is rising and after 5 it is falling. so we are finding the breakpoint 
and 1 4 is greater than 1 3 -> greater then reverse them from the right of 4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        if(n==0){ //base case
            return;
        }
        int j = n-1;
        //find the first breakpoint
        int i = n-2;//from 2nd last index
        //a[i] should be smaller than a[i+1]
        //so the first breakpoint can be at the 2nd last index
        //linearly, traversing from the back
        for(i=n-2; i>=0; i--){
            if(a[i]<a[i+1])
            {
                break;
            }
        }
        if(i<0){//if we don't find a breakpoint, we need to reverse the whole
            reverse(a.begin(), a.end());
        }
       
        else{ // finding the second index
            for( j = n-1; j>i; j--){ // traversing from the back and it will be till
            //position of i
                if(a[j]>a[i]){ //if we get a greater value than i
                    break;//that pos will be second index
                }
            }
            swap(a[j],a[i]);//swap them
            //now reverse from the right to idx1 to end
            reverse(a.begin()+i+1 , a.end());
        }
    
    }
};


int main(){
    return 0;
}