/*
Print all the duplicates in the input string
*/

#include <bits/stdc++.h>
using namespace std;

void duplicate(string s)
{
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    for (auto it : m) //traversing map using for each loop
    {
        if (it.second > 1) //any frequency occurs more than once
        {
            cout << it.first << " "
                 << "count = " << it.second << endl;
        }
    }
}
int main()
{

    string s = "rohan roy";
    duplicate(s);
    return 0;
}