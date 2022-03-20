/*
The Celebrity Problem 
Medium Accuracy: 39.46% Submissions: 100k+ Points: 4
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b]==1)return true;//when a knows b 
        else return false;
    }
    //naive soln
    //celebrity-> row all 0's
    //celebrity-> coll all 1's except diagonal i=j
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //put all eles in stk -> 0 1 2
        //till stck size != 1 ,, take out 2 eles
        //if a knows b ..discard a and push b to stk and vice versa
        //at last there will be single ele in stk, celebrity
        //element left can be a celebrity..so verify
        //check row of celeb all 0's
        //check col of c all 1's except diagonal i==j
        
        stack<int>s;
        //3 eles 1,2,3
        for(int i=0; i<n; ++i)s.push(i);//putting eles in stk
        
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(M,a,b,n))s.push(b);
            else s.push(a);
        }
        int c = s.top();
        //stk will have single ele might be celeb
        int zroCnt=0;//0 count
        for(int i=0; i<n;++i){
            if(M[c][i]==0)zroCnt++;
        }
        //if all zeros
        if(zroCnt!=n)return -1;
        
        int oneCnt=0;//1 count
        for(int i=0; i<n;++i){
            if(M[i][c]==1)oneCnt++;
        }
        //if all one except diagonal element
        if(oneCnt!=n-1)return -1;
        return c;
        
    }
};

int main()
{

    return 0;
}