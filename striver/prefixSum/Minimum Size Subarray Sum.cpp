#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int x, vector<int>& v) {
        int n = v.size();
        int mi = INT_MAX;
        int s = 0;//curr subarray
        int i=0, j=0;
        while(j<n){
            s+=v[j];//adding curr ele to sum
            if(s>=x){
                //till its greater than target we try to compress from left side
                while(s>=x){
                    s-=v[i];
                    i++;
                }
                //after we compress, we get curr window >= x
                mi = min(mi,j-i+1+1);//+1 for getting the previous element
            }
            j++;
        }
        return mi==INT_MAX?0:mi;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
