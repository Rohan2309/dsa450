/*
Find Missing And Repeating

Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is
 missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

1st possibility check freq -> if freq is 0  or freq is 2 space complexity is o(n)

2nd visited or not

for repeating number
when we get a number we give it a negative sign

array 2 4 1 2 5
idx   1 2 3 4 5 (1 based indexing)

first value of array is 2 -> go to a[2]..it's value is 4
changing it to -4(if not negative already)
take absolute value of(-4)->a[4] is 2 -> not negative make it -2
now 1 -> a[1] is 2 -> make it -2
till now the array is -2 -4 1 -2 5
now -2 -> abs(-2) -> a[2] is -4 which is already negative return 2 (rep element)

now the final array is -2 -4 1 -2 -5
only 1 is possite so 3rd idx is missing
if we getting a number we were going to that pos in arr and making it neg
we didn't get 3 so 3rd pos is +ve

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int *findTwoElement(int *a, int n)
    {
        int A; //rep
        int B; //missing

        for (int i = 0; i < n; i++) //for rep
        {
            if (a[abs(a[i]) - 1] < 0) //a[abs(-2)] = a[2] = 4 (check negative)  (-1 for 0 base idx)
            {
                A = abs(a[i]); //already visited so rep
            }
            else //if not visited change it to negative value
            {
                a[abs(a[i]) - 1] = -a[abs(a[i]) - 1]; //making it visited
            }
        }
        //for missing element
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0) //number is positive (not visited)
            {
                B = i + 1; //+1 for 0 based idx
                break;
            }
        }

        int *v = new int[2]; //dynamically allocated array
        v[0] = A;
        v[1] = B;
        return v;
    }
};

int main()
{
    int a[] = {2, 4, 1, 2, 5};
    int n = 5;
    Solution ob; //object of class solution
    auto ans = ob.findTwoElement(a, n);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}