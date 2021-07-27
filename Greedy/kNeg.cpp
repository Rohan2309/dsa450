/*
Maximize sum after K negations 
Easy Accuracy: 48.5% Submissions: 11069 Points: 2
Given an array of integers of size N and a number K., Your must modify array arr[] exactly K number of times. Here modify array means in each operation you can replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this operation in such a way that after K operations, the sum of the array must be maximum.


Example 1:

Input:
N = 5, K = 1
arr[] = {1, 2, -3, 4, 5}
Output:
15
Explanation:
We have k=1 so we can change -3 to 3 and
sum all the elements to produce 15 as output.
Example 2:

Input:
N = 10, K = 5
arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}
Output:
68
Explanation:
Here  we have k=5 so we turn -2, -4, -12 to
2, 4, and 12 respectively. Since we have
performed 3 operations so k is now 2. To get
maximum sum of array we can turn positive
turned 2 into negative and then positive
again so k is 0. Now sum is
5+5+4+5+12+5+5+5+20+2 = 68
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
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        long long int sum=0;
        sort(a,a+n);
        for(int i=0; i<n; i++){
        	if(a[i]<0 && k>0){ //we can change elements k no of times
        		a[i]=-a[i]; //negative elements will be flipped
        		k--;
        	}
        }
        for(int i=0; i< n; i++){
        	sum+=a[i]; //getting sum
        }
        /* for positive case  */
        //find minimum element in array
        //we will apply remaining k in that
        //if remaining k is even then it will be as it is 
        //odd will change it's sign

        int x = *min_element(a, a+n);
        if(k&1){ //when k is odd as in case of even it will remain as it is 
        	sum= sum - 2*x; //2*x as 1,2,3,4,5  results to 15 but -1,2,3,4,5 results to 13
        }
        return sum;
    }
};
int32_t main()
{
    FIO();
    Solution ob;

    int n, k, i;
    cin>>n>>k;
    long long int a[n+5];
    fo(i,n){
    	cin>>a[i];
    }
    cout <<ob.maximizeSum(a,n,k)<< endl;
  
    return 0;
}