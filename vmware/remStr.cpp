/*
Remove all characters from a string except uppercase letters and digits

*/

#include <bits/stdc++.h>
using namespace std;



int main()
{
    string s = "ROhan2309";
    int n = s.length();
    string res = "";
    for(int i=0; i<n; ++i){
        if(isupper(s[i]) or  isdigit(s[i])){
            res+=s[i];
        }
    }
    cout<<res;
    return 0;
}
