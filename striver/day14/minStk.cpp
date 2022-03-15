/*
155. Min Stack
Easy

7558

595

Add to List

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include <bits/stdc++.h>
using namespace std;

//naive soln - stack of pairs ,
//when we push, we push value with current minimum element
class MinStack {
    stack<long long> st;
    long long mi;
public:
    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        mi = LLONG_MAX;
        
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){//base case, when stack is empty we directly push and set the minimum
            mi = val;
            st.push(val);
        }
        else{
            if(val<mi){//new min
                st.push(2*val  -mi);//encryption
                mi = val;//updating current minimum
            }
            else{//if greater than current minimum we directly push
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()){//base
            return;
        }
        long long el = st.top();
        st.pop();
        //encrypted value will always be lesser than minimum
        if(el<mi){//if it is an encrypted value
            mi = 2*mi - el;//decryption (old min)
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long el = st.top();
        if(el<mi){//if a modified value
            return mi;//minimum is top
        }
        return el;
    }
    
    int getMin() {
        return mi;
    }
};
int main()
{

    return 0;
}