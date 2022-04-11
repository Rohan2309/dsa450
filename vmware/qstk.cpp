/*
232. Implement Queue using Stacks
Easy
2978
210
Add to List
Share
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]
Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

#include <bits/stdc++.h>
using namespace std;

//2 stack
class MyQueue
{
    stack<int> s1, s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop(); // putting all eles to s2
        }
        s2.push(x); // new ele in s2
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop(); // putting all eles to s1 back
        }
    }

    int pop()
    {
        int ans;
        if (!s1.empty())
        {
            ans = s1.top();
            s1.pop();
            return ans;
        }
        return -1;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{

    return 0;
}