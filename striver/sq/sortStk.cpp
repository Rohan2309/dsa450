/*
Sort a stack 
Easy Accuracy: 50.51% Submissions: 61181 Points: 2
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100

*/

#include <bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void insertAtPos(stack<int>&s, int x){
    if(s.empty() or s.top()<x) s.push(x);//if empty of top is smaller we directly push
    else{
        int a=s.top();//storing in stack frame
        s.pop();
        insertAtPos(s,x);
        s.push(a);//backstrack
    }
}

void rev(stack<int>&s){
    if(!s.empty()){
        int x=s.top();//storing in stack frame
        s.pop();
        rev(s);
        //going till last ele (all eles in stack frame)
        insertAtPos(s,x);
    }
}

void SortedStack :: sort()
{
   //Your code here
   rev(s);
}

int main()
{

    return 0;
}