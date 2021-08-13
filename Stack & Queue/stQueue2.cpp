/*
Stack using two queues 
Easy Accuracy: 40.49% Submissions: 69879 Points: 2
Implement a Stack using two queues q1 and q2.

Example 1:

Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  
Example 2:

Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1
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
//using 2 queue
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};
void QueueStack ::push(int x)
{
    // Your Code
    q1.push(x); //pushing element in q1
    while (!q2.empty())
    { //if q2 not empty then pushing elements from q2 to q1
        q1.push(q2.front());
        q2.pop();
    }
    swap(q1, q2); //making q1 again empty
}

//using 1 queue
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};
void QueueStack ::push(int x)
{
    // Your Code
    q1.push(x);             //pushing element in q1
    int sz = q1.size() - 1; //if 2 elements are there we are taking 1 element from the front
    while (sz--)
    {
        q1.push(q1.front());
        q1.pop();
    }
}
//Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // Your Code
    //q2 will have all the elements
    int ans;
    if (q1.empty())
    {
        return -1;
    }
    else
    {
        ans = q1.front();
        q1.pop();
    }
    return ans;
}

int main()
{

    return 0;
}