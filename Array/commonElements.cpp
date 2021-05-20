/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
*/

#include <bits/stdc++.h>
using namespace std;

int soln(int a1[], int a2[], int a3[], int n, int m, int o)
{
    int i = 0, j = 0, k = 0;
    vector<int> v;
    while (i < n and j < m and k < o)
    {
        if (a1[i] == a2[j] and a2[j] == a3[k])
        {
            v.push_back(a1[i]);
            i++;
            j++;
            k++;
        }
        else if (a1[i] < a2[j])
        {
            i++;
        }
        else if (a2[j] < a3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
        //unique elements
        int xx = a1[i - 1];
        while (a1[i] == xx)
        {
            i++;
        }
        int yy = a2[j - 1];
        while (a2[j] == yy)
        {
            j++;
        }
        int zz = a3[k - 1];
        while (a3[k] == zz)
        {
            k++;
        }
    }
    if (v.size() == 0)
    {
        return {-1};
    }
    else
    {

        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << ' ';
        }
    }
}

int main()
{
    int n, arr1[10], m, arr2[10], arr3[10], o;
    cout << "enter total no of elements in arr1" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "enter total no of elements in arr2" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << "enter total no of elements in arr3" << endl;
    cin >> o;
    for (int i = 0; i < o; i++)
    {
        cin >> arr3[i];
    }
    int ans = soln(arr1, arr2, arr3, n, m, o);
    cout << ans << endl;
    return 0;
}