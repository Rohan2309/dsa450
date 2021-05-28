/*
 Reverse String

 Write a function that reverses a string. The input string is given as an array of characters s.
*/

#include <bits/stdc++.h>
using namespace std;

void reverseString(string s)
{
    int leftptr = 0;
    int rightptr = s.size() - 1;
    while (leftptr < rightptr)
    {
        char temp = s[leftptr];
        s[leftptr] = s[rightptr];
        s[rightptr] = temp;
        rightptr--;
        leftptr++;
    }
    cout << s << endl;
}

int main()
{
    string str = "rohan";
    reverseString(str);
    return 0;
}