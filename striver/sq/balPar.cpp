/*
20. Valid Parentheses
Easy

11497

499

Add to List

Share
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string x)
    {
        int n = x.length();
        stack<char> st;
        char a;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '(' or x[i] == '{' or x[i] == '[')
            {                  // check opening brackets
                st.push(x[i]); // if opening brac then push in stack
                continue;
            }
            if (st.empty())
            { // if only closing brackets
                return false;
            }
            switch (x[i])
            {
            case ')':         // checking closing brackets
                a = st.top(); // assigning a as top
                st.pop();
                if (a == '{' or a == '[')
                { // if different type of bracket
                    return false;
                }
                break;
            case '}':         // checking closing brackets
                a = st.top(); // assigning a as top
                st.pop();
                if (a == '(' or a == '[')
                { // if different type of bracket
                    return false;
                }
                break;
            case ']':         // checking closing brackets
                a = st.top(); // assigning a as top
                st.pop();
                if (a == '{' or a == '(')
                { // if different type of bracket
                    return false;
                }
                break;
            }
        }
        return (st.empty()); // if every element is popped
    }
};

int main()
{

    return 0;
}