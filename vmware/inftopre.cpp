#include<bits/stdc++.h>
using namespace std;
 
//Function to return precedence of operators
int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
// The main function to convert infix expression
//to postfix expression
void infixToPrefix(string s) {
    reverse(s.begin(),s.end());//reverse the string for changing to postfix
 
    stack<char> st; //For stack operations, we are using C++ built in stack
    string result;
 
 //swap opening and closing brackets ...we just chance bracket conditions
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == ')')
            st.push(')');
 
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == '(') {
            while(st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            st.pop();//popping (
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());//reverse the string for changing to prefix
 
    cout << result << endl;
}
 
//Driver program to test above functions
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPrefix(exp);
    return 0;
}