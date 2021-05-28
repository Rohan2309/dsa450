/*
Program to Check if a string is a valid shuffle of two distinct strings
*/

#include <bits/stdc++.h>
using namespace std;

bool shuffle(string s1, string s2, string res)
{
    int l1 = s1.length(), l2 = s2.length(), l3 = res.length();
    if ((l1 + l2) != l3)
    {
        return false;
    }
    else
    {
        int i = 0, j = 0, k = 0; //i for s1 pointer , j for s2 pointer  and k for res pointer
        while (k < l3)
        {
            if (i < l1 and s1[i] == res[k])
            {
                i++;
            }
            else if (j < l2 and s2[j] == res[k])
            {
                j++;
            }
            else
            {
                break;
            }
            k++;
        }
        if (i < l1 or j < l2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    string s1 = "ron", s2 = "roy", s3 = "rroony", s4 = "yyyyyy", s5 = "ronroyy";
    cout << shuffle(s1, s2, s3) << endl;
    cout << shuffle(s1, s2, s4) << endl;
    cout << shuffle(s1, s2, s5) << endl;
    return 0;
}