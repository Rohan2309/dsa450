/*
225. Implement Stack using Queues
Easy

1874

773

Add to List

Share
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {//single queue
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);//inserting in q
        int n;
        n=q.size();
       for(int i=0; i<n-1;++i){//reinsert all elements below that in q
            int x =q.front();
           
            q.pop();
           q.push(x);
        }
    }
    
    int pop() {
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};


class MyStack {//2 queues
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);//inserting in  q2
        while(!q1.empty()){//if we have eles in q1 we insert them in q2
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);//then getting all in q1
    }
    
    int pop() {
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main()
{
    
    return 0;
}