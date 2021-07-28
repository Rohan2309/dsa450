/*
Smallest number 
The task is to find the smallest number with given sum of digits as S and number of digits as D.

 

Example 1:

Input:
S = 9 
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.
*/

#include<bits/stdc++.h>
using namespace std;
 
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
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
class Solution{   
public:
    string smallestNumber(int s, int d){
        //s is total and d is length
        // code here 
        if((9*d)<s){
            return "-1"; //we can't form a digit
        }
        string ans = "";
        for(int i=d-1; i>=0; i--){ //we checking ans from the last
           if(s>9){
               ans = '9' +  ans;
               s-=9;
           }
           else{
            if(i==0){ //at first place
               ans = to_string(s) + ans; //if we reach first we directly fill that number
            }
            else{
                ans = to_string(s-1)+ ans; //as we will keep 1 in front (so rest will be there)
                i--;
                while(i>0){//position not at first
                     ans = '0'+ ans;
                     i--;
                }
                //when at first pos
                ans = '1'+ans;
                break;

            }
           }
        }
        return ans;
    }
};
int main()
{
    FIO();
    Solution ob;

    int s,d;
    cin>>s>>d;
    cout <<ob.smallestNumber(s,d)<< endl;
  
    return 0;
}