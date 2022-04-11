#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string validIPAddress(string ip) {
        if(count(ip.begin(),ip.end(),'.')==3){
            if(ip[ip.size()-1]=='.')return "Neither";//last no token present after 3rd '.'
            stringstream ss(ip);//breaking string
            string t;//storing each part a,b, c, d
            while(getline(ss,t,'.')){//'.' is delimeter and stps reading
                
                if(t.length()==0 or t.length()>3)return "Neither";
                //a can be 0 but not be 01
                if(t[0]=='0' and t.size()>1)return "Neither";
                for(char c : t) if(!isdigit(c))return "Neither";
                if(stoi(t)>255)return "Neither";
            }
            return "IPv4";
        }
            
        else if(count(ip.begin(),ip.end(),':')==7){
            if(ip[ip.size()-1]==':')return "Neither";//last no token present after 3rd '.'
            stringstream ss(ip);//breaking string
            string t;//storing each part a,b, c, d
            while(getline(ss,t,':')){//':' is delimeter and stps reading
                
                if(t.length()==0 or t.length()>4)return "Neither";
                //hexadecimal digit or not (0->9 and a->f small and capital)
                for(char c : t) if(!isxdigit(c))return "Neither";
            }
            return "IPv6";
        }
        
        return "Neither";
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
