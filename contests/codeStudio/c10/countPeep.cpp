/*
Count The People
Difficulty: MEDIUM
Contributed By
Nihal Srivastava
|
Level 5
Avg. time to solve
17 min
Success Rate
82%
Problem Statement
You and your friend recently watched a Mr Beast’s video; now you want to give away food just like him. There are infinite people arranged in a 2-D grid of an infinite length and breadth, each cell having one person. You and your friend are starting at the same cell of the grid. You also have a string ‘S’ of length ‘N’ consisting of the instructions you and your friend have to follow. You will follow the first instruction; your friend will follow the second instruction; you will follow the third instruction, and so on.
The instructions are as follow:
1) ‘U’ means to move one cell UP.
2) ‘D’ means to move one cell DOWN.
3) ‘L’ means to move one cell LEFT.
4) ‘R’ means to move one cell RIGHT.
Once you or your friend reach a cell (including the starting position), the person present in the cell will receive the food. Now you wonder how many distinct people got the food.
For example:
If the instruction is 'RU', you move one cell right and then you friend moves one cell up. Hence, in total 3 cells are visited.
Input Format-
First-line contains ‘T’, denoting the number of Test cases.
For each Test case:
The first line contains an integer, ‘N’, denoting the length of the string ‘S’.
The following contains the string ‘S’ consisting only of the character {‘U’, ‘D’, ‘R’, ‘L’}.
Output Format-
For each test case, you have to print an integer denoting the number of distinct people that got the food.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints -
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10^5 

Note- Sum of ‘N’ over all test cases does not exceed 10^5.

Time Limit: 1 sec
Sample Input-1
2
2
UL
4
ULUL
Sample Output-1
3
5
Explanation For Sample Input 1:
For test case 1:
    You and your friend gave food to the person at the starting position. Then you went up by one cell and gave food to the person in that cell. Your friend went left by one cell and gave food to the person in that cell. Hence a total of three distinct people got the food.   
Sample Input -2
2
4
ULRD
6
DRDRDR
Sample Output -2
5
7

*/

#include <bits/stdc++.h>
using namespace std;

int count(int n, string s)
{
	// Write your code here.
    int x1=0, y1=0;//my coordinates, x is for rows and y is for cols
    int x2=0, y2=0;//friend's coordinates
    unordered_set<int>st;//pos is visited or not
    st.insert(0*1e6+0);//at initial
    for(int i=0; i<n; ++i){
        if(i%2==0){//me taking term
            if(s[i]=='U'){
                x1--;//row number will reduce
            }
            else if(s[i]=='D'){
                x1++;//row number incre
            }
            else if(s[i]=='L'){
                y1--;//col reduces
            }
            else{
                y1++;//col incre
            }
            //at end we will be standing somewhere
            st.insert(x1*1e6+y1);
        }
        else{//friend taking term
            if(s[i]=='U'){
                x2--;//row number will reduce
            }
            else if(s[i]=='D'){
                x2++;//row number incre
            }
            else if(s[i]=='L'){
                y2--;//col reduces
            }
            else{
                y2++;//col incre
            }
            st.insert(x2*1e6+y2);
        }
    }
    int cnt=st.size();
    return cnt;
}
int main() {
	return 0;
}