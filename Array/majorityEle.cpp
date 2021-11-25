/*
229. Majority Element II
Medium

3338

239

Add to List

Share
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
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
vector<int> majorityElement(vector<int> &nums)
{
    //boyer moore voting algo
    vector<int> ans;
    int n = nums.size();
    int k = floor(n / 3); //when 8/3 we want ans 2
    int ele1 = -1;        //initial values
    int ele2 = -1;
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (ele1 == nums[i])
        {
            c1++;
        }
        else if (ele2 = nums[i])
        {
            c2++;
        }
        else if (c1 == 0)
        { //when first element
            ele1 = nums[i];
            c1 = 1; //count becomes 1
        }
        else if (c2 == 0)
        {
            ele2 = nums[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    //we got atleast 2 nums now we can check if they are greater than k or not
    c1 = 0;
    c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
        {
            c1++;
        }
        else if (nums[i] == ele2)
        {
            c2++;
        }
    }

    if (c1 > k)
    {
        ans.push_back(ele1);
    }
    if (c2 > k)
    {
        ans.push_back(ele2);
    }
    return ans;
}
int main()
{

    return 0;
}