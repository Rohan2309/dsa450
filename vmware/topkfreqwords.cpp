#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    static bool cmp(pair<string,int> a, pair<string,int> b)
    {
        //if similar frequency then lexicographical order
        if(a.second>b.second or (a.second==b.second and a.first<b.first))return true;
        return false;
    }
    
    vector<string> topKFrequent(vector<string>& w, int k) {
        unordered_map<string,int> m;
        for(int i=0; i<w.size(); ++i)m[w[i]]++;//freq map
        vector<pair<string,int>> v;
        //copying in vector
        for(auto it=m.begin(); it!=m.end(); ++it)v.push_back({it->first,it->second});
        sort(v.begin(),v.end(),cmp);//sorting vector with freq 
        vector<string> ans;
        for(int i=0; i<k; ++i)ans.push_back(v[i].first);//storing in ans vector
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
