#include <bits/stdc++.h>
using namespace std;


class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;//min heap
    int sz;
    KthLargest(int k, vector<int>& a) {
        sz=k;
        int n = a.size();
        //min heap will always have k eles
        //so top of pq is always kth largest
        for(int i=0; i<n;++i){
            pq.push(a[i]);
            if(pq.size()>k)pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>sz)pq.pop();
        return pq.top();
    }
};

int main()
{
    
    return 0;
}