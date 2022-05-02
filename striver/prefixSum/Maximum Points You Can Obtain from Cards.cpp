#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int l = 0;
        int r = n-k;// l and r, sliding window range
        int total = 0;//total points
        total = accumulate(v.begin(), v.end(), total);//sum of numbers not  taken into acc
        int tmp = 0;//we are not taking these eles, just using as a window
        for(int i= l; i<r; ++i)tmp+=v[i];//total sum of current window (1st window)
        int res = total - tmp;//numbers taken into consideration, all from right
        while(r<n){//till right of slide window does not exceeds length
            tmp-=v[l++];//removing first one from window
            tmp+=v[r++];//adding extra when moving right
            res = max(total-tmp,res);//total - temp is what we are taking into consideration
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
