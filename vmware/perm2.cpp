#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    
    void f(vector<int>&a,  int i){
        if(i==a.size()){
            ans.push_back(a);return;
        }
        //when we get a number we will put this in set
        //nexxt time when this number comes we already know its in set
        //and we dont take that
        unordered_set<int>s;
        for(int j=i; j<a.size(); ++j){
            if(s.find(a[j])!=s.end())continue;
            s.insert(a[j]);
            swap(a[i],a[j]);
            f(a,i+1);
            swap(a[i],a[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        
        f(a,0);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
