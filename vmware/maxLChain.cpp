#include <bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) //storing elements in vector
    {
        v.push_back({p[i].first, p[i].second});
    }
    //sorting with second value
    sort(v.begin(), v.end(), comp);
    int i = 0; //pointing first value
    int j = 1; //pointing second value
    int c = 1; //counter is 1 at initial point
    int sz = v.size();

    while (j < sz) //base case
    {
        if (v[i].second < v[j].first) //second value of first pair is smaller than first value of send pair
        {
            c++;
            i = j;
            j++;
        }
        else //if not less then j is shifted forward and i remains same to compare with next value
        {
            j++;
        }
    }
    return c;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
