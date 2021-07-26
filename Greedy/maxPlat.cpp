/*
Minimum Platforms 
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.


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
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int ans = 1;//count is 1 at start as it will have atleast 1 platform 
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int i=0;//2 pointers  (departure 1)
    	int j=1;//arrival 2
    	while(j<n){
    		if(arr[j]<=dep[i]){ //we have to give new platform as it arrives before train departs
    			ans++;
    		}
    		else{ // if train departs then new depart time
    			i++;
    		}
    		j++; //each and every time new train is arriving
    	}
    	return ans;
    }
    
};

int32_t main()
{
    FIO();
    Solution ob;
    int n,i; cin>>n;
    int arr[n], dep[n];
fo(i,n){
 cin>>arr[i];
}
fo(i,n){
	cin>>dep[i];
}
    cout<<ob.findPlatform(arr, dep, n)<<endl;
    return 0;
}