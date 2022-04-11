#include <iostream>
using namespace std;
 
// A recursive function used by countWays
int countWays(int n)
{
    int res[n + 1];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];
 
    return res[n];
}
 
// Driver program to test above functions
int main()
{
    int n = 4;
    cout << countWays(n);
    return 0;
}