/*
Parenthesis Checker 
Easy Accuracy: 49.12% Submissions: 79505 Points: 2
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
*/

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
// #define int             long long
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

#define deb(x) cout << #x << " " << x << endl; //for debugging
#define fo(i, n) for (i = 0; i < n; i++)
#define fo1(i, n) for (i = 1; i <= n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

#define vi vector<int>
#define vvi vector<vi>

/*
struct Node
{
    int data;
    struct Node *left;  //pointer pointing towards left child
    struct Node *right; //pointer for right child

    Node(int val) //constructor taking data
    {
        data = val;
        left = NULL; //initially
        right = NULL;
    }
};
*/
bool ispar(string x)
{
    // Your code here
    stack<char> st;
    char a;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '(' or x[i] == '{' or x[i] == '[')
        { //if current element is of opening type
            st.push(x[i]);
            continue;
        }
        if (st.empty())
        { //if no opening brackets then stack will be empty
            return false;
        }
        switch (x[i])
        {
        case ')': //case 1
            a = st.top();
            st.pop(); //removing that
            if (a == '{' or a == '[')
            { //other that that paranthesis
                return false;
            }
            break;
        case '}': //case 2
            a = st.top();
            st.pop(); //removing that
            if (a == '(' or a == '[')
            { //other that that paranthesis
                return false;
            }
            break;
        case ']': //case 2
            a = st.top();
            st.pop(); //removing that
            if (a == '(' or a == '{')
            { //other that that paranthesis
                return false;
            }
            break;
        }
    }
    return (st.empty());
}
int main()
{

    return 0;
}