/*
Product array puzzle 

Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i]
 is equal to the product of all the elements of nums except nums[i].

 Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.


/*
if we are allowed to use division method then
first take prod of all numbers
then divide the product by a[i]


without division

10 3 5 6 2
   l   r

l[0] = 1

1 10 30 150 900

r[n-1] = 1 (iterate from back keep on multiplying)
when itr at 6 -> 1 x 2


180  60  12 2 1
print corresponding products


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> productExceptSelf(vector<long long int> &v, int n)
    {
        //code here
        // vector<long long int> res;
        // long long prod = 1;
        // for (int i = 0; i < n; i++) {
        // 	prod *= v[i];
        // }
        // //storing multiplied value
        // long long count ;
        // for (int i = 0; i < n; i++) {
        // 	count = prod / v[i];
        // 	res.push_back(count);
        // }
        // return res;

        vector<long long int> l(n), r(n);
        l[0] = 1;     //first ele of l ar
        r[n - 1] = 1; //last ele of r ar

        for (int i = 1; i < n; i++)
        {
            l[i] = l[i - 1] * v[i - 1]; //multiplying and storing the current value as prod of prev vals
        }
        for (int i = n - 2; i >= 0; i--)
        {
            r[i] = r[i + 1] * v[i + 1]; //multiplying and storing the current value as prod of prev vals
        }

        for (int i = 0; i < n; i++)
        {
            v[i] = l[i] * r[i]; //multiplying corresponding vals
        }
        return v;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<long long int> vect;
    vect.push_back(10);
    vect.push_back(3);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(2);

    int n = vect.size();
    Solution obj;
    auto vec = obj.productExceptSelf(vect, n);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}