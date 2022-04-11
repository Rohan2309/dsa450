/*

Sort all even numbers in ascending order and then sort all odd numbers in descending order

*/

// C++ program sort array in even and odd manner.
// The odd numbers are to be sorted in descending
// order and the even numbers in ascending order
#include <bits/stdc++.h>
using namespace std;
 
// To do two way sort. First sort even numbers in
// ascending order, then odd numbers in descending
// order.
void twoWaySort(int arr[], int n)
{
    // Make all odd numbers negative
    for (int i = 0; i < n; i++)
        if (arr[i] & 1) // Check for odd
            arr[i] *= -1;
 
    // Sort all numbers
    sort(arr, arr + n);
 
    // Retaining original array
    for (int i = 0; i < n; i++)
        if (arr[i] & 1)
            arr[i] *= -1;
}
 
// Driver code
int main()
{
    int arr[] = { 1, 3, 2, 7, 5, 4 };
    int n = sizeof(arr) / sizeof(int);
    twoWaySort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}