/*

*/

#include <bits/stdc++.h>
using namespace std;

struct compare //{changing to min heap}
{
    bool operator()(int first, int second)
    {
        return first > second;
    }
};
int kthSmallest(int arr[], int l, int r, int k) //l is initial location of array and r is end
{
    int n = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int, vector<int>, compare> pq; //min heap
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int ans, i = 1; //i is iterator
    while (!pq.empty())
    {
        if (i == k)
        {
            ans = pq.top();
            break;
        }
        i++;
        pq.pop(); //heapify again and next smallest element will come at the top
    }
    return ans;
}
int main()
{
    int arr[] = {10, 1, 7, 2, 35, 11, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; //7 is 3rd smallest element (from example)
    int p = 0, q = n - 1;
    cout << kthSmallest(arr, p, q, k) << endl;

    return 0;
}