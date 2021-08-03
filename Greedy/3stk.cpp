/*
Find maximum sum possible equal sum of three stacks
Difficulty Level : Easy
Last Updated : 25 Mar, 2021
Given three stacks of the positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. Stacks are represented as an array, and the first index of the array represent the top element of the stack.

Examples: 

Input : stack1[] = { 3, 10}
  stack2[] = { 4, 5 }
  stack3[] = { 2, 1 }
Output : 0
Sum can only be equal after removing all elements 
from all stacks.
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

int main()
{
    int n1, n2, n3, i;
    cin >> n1 >> n2 >> n3;
    int s1[n1], s2[n2], s3[n3];
    fo(i, n1) cin >> s1[i]; //taking input in 3 stacks
    fo(i, n2) cin >> s2[i];
    fo(i, n3) cin >> s3[i];

    int sum1 = 0, sum2 = 0, sum3 = 0; //finding sum of 3 stacks
    fo(i, n1) sum1 += s1[i];
    fo(i, n2) sum2 += s2[i];
    fo(i, n3) sum3 += s3[i];

    int t1 = 0, t2 = 0, t3 = 0; //top as 0 (first element) (iterator)
    int ans = 0;

    while (true)
    {
        if (t1 == n1 or t2 == n2 or t3 == n3)
        {            //base case if any of them reaches end
            ans = 0; //answer can't be formed
            break;
        }
        if (sum1 == sum2 and sum2 == sum3)
        { //base case if sums are equal
            ans = sum1;
            break;
        }
        /*
         we are removing the top element from the stack with biggest sum
        */
        if (sum1 >= sum2 and sum1 >= sum3) //if sum 1 is the largest value

            sum1 -= s1[t1++]; //we will remove top element from stack(sum)

        else if (sum2 >= sum1 and sum2 >= sum3)

            sum2 -= s2[t2++];

        else if (sum3 >= sum2 and sum3 >= sum1)

            sum3 -= s3[t3++];
    }
    cout << ans;

    return 0;
}