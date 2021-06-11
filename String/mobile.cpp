/*
Convert a sentence into its equivalent mobile numeric keypad sequence
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    string s;
    cin >> s;
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        { //if space
            ans += '0';
        }
        else
        {
            int j = s[i] - 'A'; //FOR each character substract ascii value of A(obtain pos in arr)
            ans += str[j];
        }
    }
    cout << ans << endl;

    return 0;
}