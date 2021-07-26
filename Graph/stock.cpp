/*
Buy Maximum Stocks if i stocks can be bought on i-th day
In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has an amount of k amount of money initially, find out the maximum number of stocks a customer can buy.
For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.

Examples:

Input : price[] = { 10, 7, 19 }, 
              k = 45.
Output : 4
A customer purchases 1 stock on day 1, 
2 stocks on day 2 and 1 stock on day 3 for 
10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number 
of stocks purchased is 4.

Input  : price[] = { 7, 10, 4 }, 
               k = 100.
Output : 6


*/

#include<bits/stdc++.h>
using namespace std;
 
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ff              first
#define ss              second
#define int             long long
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
 
class Solution{
public:
	int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int> > v;
  
    // Making pair of product cost and number
    // of day.. (amt of stocks we can buy)
    for (int i = 0; i < n; ++i) 
        v.push_back(make_pair(price[i], i + 1));    
  
    // Sorting the vector pair.
    sort(v.begin(), v.end()); //acc. to the price of the stock   
  
    // Calculating the maximum number of stock 
    // count.
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int price = v[i].first;
        int stock = v[i].second;
        if(price*stock<=k){ //lesser than available balance
        	ans+= stock;
        	k-= (price*stock); //updating available balance
        }
        else{ //if not then
            ans+= k/price; //available balance / price retuens integer value like 21/19 = 1
            k-= price*(k/price); //deducting from available balance
        }
    }
  
    return ans;
}
    
};

int32_t main()
{
    FIO();
    Solution ob;
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
  
    cout << ob.buyMaximumProducts(n, k, price) << endl;
  
    return 0;
}