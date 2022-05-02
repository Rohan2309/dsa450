
#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int B) {
    int n = A.size();
    if (B>n) return {};
    vector<int>ans;
    unordered_map<int,int>m;
    for(int i=0; i<n; ++i){
        m[A[i]]++;
        if(i+1==B)ans.push_back(m.size());
        if(i>=B){
            m[A[i-B]]--;
            if(m[A[i-B]]==0)m.erase(A[i-B]);
            ans.push_back(m.size());
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
