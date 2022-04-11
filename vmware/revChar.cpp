#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0, right = s.size()-1;
        while(left<right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            right--;
            left++;
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
