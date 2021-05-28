/*
A Program to check if strings are rotations of each other or not
*/

#include <bits/stdc++.h>
using namespace std;

bool rot(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    string temp = s1 + s2;
    return (temp.find(s2) != string::npos); //npos (no position) (true = no matches found)
}

int main()
{
    string s1 = "AACD", s2 = "ACDA";
    if (rot(s1, s2))
    {
        printf("Strings are rotations of each other");
    }
    else
    {
        printf("Strings are not rotations of each other");
    }
    return 0;
}