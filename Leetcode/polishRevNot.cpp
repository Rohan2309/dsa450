/*
150. Evaluate Reverse Polish Notation
Medium

2245

570

Add to List

Share
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //12 - 2 + 3
        //12 2 - 3 +
        //10 3 +
        //13
        int n = tokens.size();
        stack<int>s;
        for(int i=0; i<n; i++){
            //if we get numbers, we directly push into the stack
            //if we get operators, we perform operation on the last last 2 inserted members of stk
            if(tokens[i]=="+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(tokens[i]=="-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a); // we have to subtract first number from second number
            }
            else if(tokens[i]=="*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(tokens[i]=="/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a); //same as subtract
            }
            else{
                s.push(stoi(tokens[i])); //conversion, string to integer
            }
        }
        int res = s.top();
        return res;
    }
};

int main()
{
    
    return 0;
}