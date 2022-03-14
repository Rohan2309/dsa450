/*

Nearest Smaller Element
Easy

162

6

Add to favorites
Asked In:
AMAZON
MICROSOFT
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Input Format

The only argument given is integer array A.
Output Format

Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.
For Example

Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
Explaination 1:
    index 1: No element less than 4 in left of 4, G[1] = -1
    index 2: A[1] is only element less than A[2], G[2] = A[1]
    index 3: No element less than 2 in left of 2, G[3] = -1
    index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
    index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
    
Input 2:
    A = [3, 2, 1]
Output 2:
    [-1, -1, -1]
Explaination 2:
    index 1: No element less than 3 in left of 3, G[1] = -1
    index 2: No element less than 2 in left of 2, G[2] = -1
    index 3: No element less than 1 in left of 1, G[3] = -1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int>prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int>ans(n);
    stack<pair<int,int>>s;
    s.push({A[n-1],n-1});//pushing first ele and index in stack
    for(int i=n-2; i>=0;--i){//running loop from 2nd last ele
        while(!s.empty() and s.top().first>A[i]){//if stack not empty and element is greater than next ele
           ans[s.top().second]=A[i];//next smaller element is updated
           //at correct index in ans vector
           s.pop();//now we remove element from stack
        }
        //when stack empty or next smaller is not possible
        s.push({A[i],i});//we insert tat ele with correct position
    }
    //elements still in stack have no nse and will be
    while(!s.empty()){
        ans[s.top().second]=-1;
        s.pop();
    }

    return ans;
}


int main()
{

    return 0;
}