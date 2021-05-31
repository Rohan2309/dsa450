/*
Find maximum area of a rectangle in a histogram.
*/

#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> a)
{
    stack<int> st;
    int n = a.size();
    int ans = 0;
    int i = 0;
    a.push_back(0); //we don't have to handle last element of stack seperately (last bar will be 0)
    while (i < n)
    {
        while (!st.empty() and a[st.top()] > a[i])
        {
            int top = st.top();
            int height = a[top];
            st.pop();
            if (st.empty()) //this will be the smallest height till now
            {
                ans = max(ans, height * i);
            }
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, height * len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{

    vector<int> a = {2, 1, 5, 6, 2, 3};
    cout << getMaxArea(a);
    return 0;
}