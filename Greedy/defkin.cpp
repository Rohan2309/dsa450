/*
DEFKIN - Defense of a Kingdom

Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.

This position has a penalty of 12.

Help Theodore write a program that calculates the penalty of the given position.

Input
The first line of the input file contains the number of test cases.

Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

Output
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

Example
Input:
1
15 8 3
3 8
11 2
8 6

Output:
12

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
    w(t)
    {
        int w, h, n, i; //n is no of tower
        cin >> w >> h >> n;
        vi a, b; // 1 will store x coordinate and another y
        a.pb(0); //start point will be 0
        b.pb(0);
        fo(i, n) //for 3 crossbows
        {
            int x, y; //we pushing x and y cooordinates
            cin >> x >> y;
            a.pb(x);
            b.pb(y);
        }
        a.pb(w + 1); //pushing last coordinate
        b.pb(h + 1);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int mx = 0, my = 0; //will store max diff

        int sz = a.size() - 1; // will check 2 elements in each turn so we will not go till last
        fo(i, sz)
        {
            mx = max(mx, a[i + 1] - a[i] - 1); //a[i+1] = 3 and a[i]= 0 {as tower is in 3 so diff will be 2 so -1}
            my = max(my, b[i + 1] - b[i] - 1);
        }
        cout << mx * my << endl;
    }

    return 0;
}