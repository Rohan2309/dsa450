#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(vector<string>&ans, vector<string>&t, string&s, int idx){
        if(idx==s.length() and t.size()==4){
            string valid = t[0]+"."+t[1]+"."+t[2]+"."+t[3];
            ans.emplace_back(valid);
            return;
        }
        string tmp="";
        for(int i=idx; i<s.length() and t.size()<4; ++i){
            if(s[i]-'0' > 9)continue;
            tmp+=s[i];
            int x = stoi(tmp);
            if(x>=0 and x<=255){
                t.emplace_back(tmp);
                f(ans,t,s,i+1);
                t.pop_back();//backstracking, popping number out from temporary vect
            }
            if(x<=0 or x>255)break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        vector<string>t;
        f(ans,t,s,0);//start from 0 idx of str
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
