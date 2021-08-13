/*

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

Node *dummy = new Node(-1);
Node *head = dummy;
Node *mid = dummy;
int cnt = 0;

struct Node
{
    int data;
    struct Node *next; //pointer pointing towards left child
    struct Node *prev; //pointer for right child

    Node(int val) //constructor taking data
    {
        data = val;
        prev = NULL; //initially
        next = NULL;
    }
};

void push(int data)
{                               // dummy (h)
    Node *cur = new Node(data); // curr     dummy(h)
    cur->prev = NULL;           // null<-curr
    cur->next = head;           //null<-curr->dummy(h)
    cnt++;
    head->prev = cur; // null<-curr<-dummy(h)
    head = cur;       //null<-curr(h)
    if (cnt == 1)     //if 1 element
    {
        mid = cur;
    }
    else if (cnt % 2 == 0) //if even then mid is prev element
    {
        mid = mid->prev;
    }
}

int pop()
{
    if (cnt == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    Node *temp = head;
    int x = head->data;
    head = head->next; //shifting towards front as we will delete
    if (head != NULL)
    {
        head->prev = NULL;
    }
    cnt--;
    if (cnt & 1) //odd then we will send mid to next
    {
        mid = mid->next;
    }
    free(temp);
    return x;
}

int middle()
{
    if (cnt == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    return mid->data;
}

void printData()
{
    Node *cur = head;
    if (cnt == 0)
    {
        cout << "stack is empty" << endl;
        return;
    }
    for (int i = 0; i < cnt; i++)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printData();
    cout << "Middle is->" << middle() << endl;

    return 0;
}