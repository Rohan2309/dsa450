/*
Find the number of islands 
Medium Accuracy: 38.66% Submissions: 82103 Points: 4
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
 
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

void dfs(int i, int j, vector<vector<char>> &grid, int n, int m)
{
    if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] != '1')
    {
        return;
    }
    grid[i][j] = '2';
    dfs(i + 1, j, grid, n, m);
    dfs(i - 1, j, grid, n, m);
    dfs(i, j + 1, grid, n, m);
    dfs(i, j - 1, grid, n, m);
    dfs(i + 1, j + 1, grid, n, m);
    dfs(i - 1, j - 1, grid, n, m);
    dfs(i + 1, j - 1, grid, n, m);
    dfs(i - 1, j + 1, grid, n, m);
}
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size(); //row
    if (n == 0)
    { //no islands can be formed
        return 0;
    }
    int m = grid[0].size(); //cols
    int c = 0;              //counter

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(i, j, grid, n, m);
                c++;
            }
        }
    }
    return c;
}

int main()
{

    return 0;
}