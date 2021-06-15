/*

*/

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string s, char ch[6][6], int size, int idx)
{
    int found = 0;
    if (i >= 0 and j >= 0 and i < 6 and j < 6 and s[idx] == ch[i][j])
    {
        char temp = s[idx]; //storing G
        ch[i][j] = 0;       //if G found 0
        idx++;              //moving towards E
        if (idx == size)
        {
            found = 1;
        }
        else //if not found
        {
            found += solve(i + 1, j, s, ch, size, idx);
            found += solve(i - 1, j, s, ch, size, idx);
            found += solve(i, j + 1, s, ch, size, idx);
            found += solve(i, j - 1, s, ch, size, idx);
        }
        //when found is 1 , S is stored in temp
        ch[i][j] = temp; //backtrack 0->s 0->k....0->g
    }
    return found;
}

int main()
{
    string s = "GEEKS";
    char ch[6][6] = {
        {'D', 'D', 'D', 'G', 'D', 'D'},
        {'B', 'B', 'D', 'E', 'B', 'S'},
        {'B', 'S', 'K', 'E', 'B', 'K'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'G'},

    };
    int ans = 0;
    int n = 5;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            ans += solve(i, j, s, ch, n, 0); //0 is s index
        }
    }
    cout << ans;
    return 0;
}