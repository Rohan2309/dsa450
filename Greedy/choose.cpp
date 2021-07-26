/*
Choose and Swap 
You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:

Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose ‘a’ and ‘c’ and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible.


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
    string chooseandswap(string a){
        // Code Here
        set<char>s;
        //everything comes in sorted order in set
        for(int i=0; i< a.length(); i++){
        	s.insert(a[i]);
        }
        for(int i=0; i< a.length(); i++){
        	s.erase(a[i]); // we are erasing that element from set as we can't replace element with same
        	if(s.empty()){ //last point
        		break;
        	}
        	char ch = *s.begin(); //front of set element as it is the smallest
        	if(ch< a[i]){ // if smaller then we will replace
        		int ch2 = a[i];  //acting as temp var
        		for(int j=0; j< a.length(); j++){ //checking whole loop
        		   if(a[j]== ch){ //replacing
        			    a[j]= ch2;
        		    }
        		    else if(a[j]== ch2){
        			    a[j]= ch;
        		    }
        		
        	    }
        	    break; //as we are doing it for max 1 time
        	}
        }
        return a;
    }
    
};

int32_t main()
{
    FIO();
    Solution ob;
    string a;
    cin>>a;
    cout<<ob.chooseandswap(a)<<endl;
    return 0;
}