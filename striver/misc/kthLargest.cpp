#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    priority_queue<int,vector<int>,greater<int>>pq;//min heap
    int sz;
public:
    //priority queue will always store k elements
    //top element will be the kth lagest
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sz=k;
        for(int i=0; i<n;++i){
            pq.push(nums[i]);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
