/*
Minimum Swaps to Sort

Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)
*/

/*

1 5 4 3 2
1 2 3 4 5

1 is in its correct pos
we have to swap 5 (min swap)  -> greedy approach (swap with 2 is benifitial)

1 2 4 3 5
we have to swap 4  (3 will be benefitial)
1 2 3 4 5


approach
pair vector -> number with index
(1,0) (5,1) (4,2) (3,3) (2,4)


we will convert 1 2 3 4 5  to original arr to get no of swaps

sort vector (first parameter)
(1,0) (2,4) (3,3) (4,2) (5,1)

iterate this -> we are already getting their first indexes before sorting

index is equal to second val of vector (check) -> if same then no change in pos

now i++
1==4 ? no
swap (with 4th index)
count++
i--
check 5 is in pos or not ? 1==1
i++
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &v)
    {
        // Code here
        int count = 0;
        int n = v.size();
        vector<pair<int, int>> vect(n);
        for (int i = 0; i < n; i++)
        {
            vect[i] = {v[i], i}; //first element is element and second element is position (make pair)
        }
        sort(vect.begin(), vect.end()); //sorting according to first value
        for (int i = 0; i < n; i++)
        {
            if (vect[i].second == i)
            { //was in same position at first
                continue;
            }
            else
            {
                count++;                             //increasing counter
                swap(vect[i], vect[vect[i].second]); //swapping with element which is at the v.second idx
                i--;                                 //checking back if the swapped element is at correct pos or not
            }
        }
        return count;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        int ans = ob.minSwaps(v);
        cout << ans << endl;
    }

    return 0;
}