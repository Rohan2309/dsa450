/*
Paranthesis Checker

Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.
Example 3:

Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>                   //max heap
#define pqs priority_queue<int, vi, greater<int>> //min heap
#define setbits(x) __builtin_popcountll(x)        //gives number of setbits
#define zrobits(x) __builtin_ctzll(x)             //gives number of 0 bits
#define mod 1000000007                            // 1e9+7  ans%mod
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n]; //dynamic array
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)                                                      //test case
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //random shuffle

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //policy based ds

class Solution
{
public:
    bool ispar(string x)
    {
        // Your code here
        int n = x.length();
        stack<char> st;
        char a;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '(' or x[i] == '{' or x[i] == '[')
            {                  //check opening brackets
                st.push(x[i]); //if opening brac then push in stack
                continue;
            }
            if (st.empty())
            { //if only closing brackets
                return false;
            }
            switch (x[i])
            {
            case ')':         //checking closing brackets
                a = st.top(); //assigning a as top
                st.pop();
                if (a == '{' or a == '[')
                { //if different type of bracket
                    return false;
                }
                break;
            case '}':         //checking closing brackets
                a = st.top(); //assigning a as top
                st.pop();
                if (a == '(' or a == '[')
                { //if different type of bracket
                    return false;
                }
                break;
            case ']':         //checking closing brackets
                a = st.top(); //assigning a as top
                st.pop();
                if (a == '{' or a == '(')
                { //if different type of bracket
                    return false;
                }
                break;
            }
        }
        return (st.empty()); //if every element is popped
    }
};

void FIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    FIO();

    string a;
    cin >> a;
    Solution ob;
    if (ob.ispar(a))
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "not balanced" << endl;
    }
    // for (auto i : ans) {
    // 	cout << i << " ";
    // }
    // cout << a << "\n";

    return 0;
}