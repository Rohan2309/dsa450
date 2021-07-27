/*
Shop in Candy Store 
Easy Accuracy: 66.1% Submissions: 7086 Points: 2
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

Example 1:

Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy 
one candy you can take at most two 
more for free. So in the first case, 
you buy the candy which costs 1 and 
takes candies worth 3 and 4 for free, 
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the 
candy which costs 4 and takes candies 
worth 1 and 2 for free, also you need 
to buy candy worth 3 as well. 
So max cost : 3+4 =7.

*/

#include<bits/stdc++.h>
using namespace std;
 
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ff              first
#define ss              second
//#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

 
 
void FIO()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {   //n total no of candies available
    	//candies[] is price array
        // Write Your Code here
        //k is offer if we buy any candy we can get 2 candies free if available
        vector<int>ans; //answer vector

        int ma=0; //max amt in which we can buy all candies
        int mi=0; //min....

//for min part
        sort(candies, candies+n); //sorting in ascending order

        int i=0;  //pointer (purchase from first) as cheap candies are at first
        int j = n-1; //we take free candies from last as they are costly

        while(i<=j){
        	mi += candies[i]; //adding up to the price
        	i++; //incre pointer
        	j=j-k; //we can buy atmost k candies for free
        }
        ans.push_back(mi);
//for max part

        reverse(candies, candies+n); //sort in descending order
         i=0; //pointer purchase from first as costly canties are at first
         j = n-1; //cheap candies for free as they are at the last

         while(i<=j){
         	ma+= candies[i];
         	i++;
         	j = j-k;
         }
        ans.push_back(ma);
        return ans;
    }
};

int32_t main()
{
    FIO();
    Solution ob;

    int n, k, i;
    cin>>n>>k;
    int candies[n];
    fo(i,n){
    	cin>>candies[i];
    }
    vi cost = ob.candyStore(candies, n, k);
    cout << cost[0] <<" "<<cost[1]<< endl;
  
    return 0;
}