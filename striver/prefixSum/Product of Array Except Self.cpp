#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        if(n<1)return {};
        vector<int>left;
        int pro=1;
        for(int i=0; i<n; ++i){
            pro*=v[i];
            left.emplace_back(pro);
        }
        //o/p array updated with left cumulative product vals
        pro=1;//real time cumulative product vals from right side
        for(int i=n-1; i>0; --i){//from rev direction
            left[i]=left[i-1]*pro;//i-1 because left of that index will have cm of left
            pro*=v[i];//updating right cm
        }
        left[0]=pro;//no eles in left side so cm of right
        return left;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
