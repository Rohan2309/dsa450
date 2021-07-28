/*
Check if it is possible to survive on Island
Difficulty Level : Easy
Last Updated : 12 Apr, 2021
You are a poor person in an island. There is only one shop in this island, this shop is open on all days of the week except for Sunday. Consider following constraints: 

N – Maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and you need to survive for the next S days. 
Find the minimum number of days on which you need to buy food from the shop so that you can survive the next S days, or determine that it isn’t possible to survive. 
Examples: 

Input : S = 10 N = 16 M = 2 
Output : Yes 2 
Explanation 1: One possible solution is to buy a box on the first day (Monday), it’s sufficient to eat from this box up to 8th day (Monday) inclusive. Now, on the 9th day (Tuesday), you buy another box and use the chocolates in it to survive the 9th and 10th day.
Input : 10 20 30 
Output : No 
Explanation 2: You can’t survive even if you buy food because the maximum number of units you can buy in one day is less the required food for one day.
*/

#include<bits/stdc++.h>
using namespace std;
 
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ff              first
#define ss              second
//#define int             long long
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> > //min heap
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
void survival(int s, int n, int m){
    //s is no of days more to go
    //n is max unit of food/day we can buy
    //m is min req. unit of food per day
    //start from monday
    //we can't buy on sundays
    int x = s/7; //no. of sundays
    int y = s-x;// we can buy food in these nno. of days
    int food = s*m; //over all we need this unit of food
    int day = food/n; //in how many days we can buy food
    if(food%n!=0){ //not fully divisible 
       day++;//then 1 day xtra
    }
    if(day<=y){ //feasable
        cout<<"Yes "<<day;
    }
    else{ //not feasable
        cout<<"No";
    }
       
    
}
int main()
{
    FIO();
    int S = 10, N = 16, M = 2;
    survival(S, N, M);
  
    return 0;
}