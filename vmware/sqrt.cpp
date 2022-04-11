#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long start=0;
        long long end=INT_MAX;
        long ans=0;
        //y<=sqrt(x)
        //y^2<=x
        while(start<=end){
            long long mid = start+(end-start)/2;
            if(mid*mid<=x){//wont stop here
                ans=mid;//prliminary ans
                start=mid+1;//checking next digits
            }
            else{//if false
                end=mid-1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
