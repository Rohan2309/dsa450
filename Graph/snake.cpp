/*
Snake and Ladder
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l; //ladders
    int s; //snakes
    cin >> l >> s;
    map<int, int> ld; //will store ladder in map to know ladder is present in this pos or not
    map<int, int> sn; //will store snakes in map to know snake is present in this pos or not
    for (int i = 0; i < l; i++)
    {
        int u, v;
        cin >> u >> v;
        ld[u] = v; //we can jump from u to v
    }
    for (int i = 0; i < s; i++)
    {
        int u, v;
        cin >> u >> v;
        sn[u] = v; //we can jump from u to v
    }
    int moves = 0;
    queue<int> q;            //bfs
    q.push(1);               //initial pos will start from first square
    bool found = false;      // flag (haven't got 100th square)
    vector<int> vis(101, 0); //visited array
    vis[1] = true;
    while (!q.empty() and !found) //queue isn't empty and 100th square not found
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                if (t + die == 100)
                {
                    found = true; //we got 100th square
                }
                if (t + die <= 100 and ld[t + die] and !vis[ld[t + die]]) //if ladder present and not visited
                {
                    vis[ld[t + die]] = true;
                    if (ld[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(ld[t + die]);
                }
                else if (t + die <= 100 and sn[t + die] and !vis[sn[t + die]]) //if snake present and not visited
                {
                    vis[sn[t + die]] = true;
                    if (sn[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(sn[t + die]);
                }
                else if (t + die <= 10 and !vis[t + die] and !sn[t + die] and !ld[t + die]) //empty square
                {
                    vis[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }
    if (found)
    {
        cout << moves << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}