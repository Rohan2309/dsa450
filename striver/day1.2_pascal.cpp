/*
118. Pascal's Triangle
Easy

3946

171

Add to List

Share
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //when we are need are given value of row and col, we have to say value then formula r-1 C c-1
    //for 5c2 = 5x4/2x1
    //for 7c3 = 7x6x5/3x2x1
    //(no of terms in dow = num of terms in up, as 3x2x1 so 7x6x5)
    //nth row print , pascal
    //for a row it will be (i+1) C n (where n will be increased)
    /*
for(int i=0; i<k; ++i){
    res*=(n-1);
    res/=(i+1);
}
    */
    vector<vector<int>> generate(int n) {
        if(n==0){//base case
            return {};
        }
        vector<vector<int>> t(n);
        for(int i=0; i<n; i++){//n rows
            //for every r, the number of c will be same as r
            t[i].resize(i+1);//resizing empty vect to a size i+1
            //(when i will be 0, it will have 1 column)
            //first and last element of each row is 1
            t[i][0]= t[i][i]= 1;
            for(int j=1; j<i; j++){//nth row we have n cols
                
                t[i][j]= t[i-1][j-1]+t[i-1][j];//j-1 col value of prev row, adding to it j val of prev row
            }
        }
        return t;
    }
};


int main(){
    return 0;
}