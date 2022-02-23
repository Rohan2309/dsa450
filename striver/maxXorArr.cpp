/*

421. Maximum XOR of Two Numbers in an Array
Medium

3714

313

Add to List

Share
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.



Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        Node *links[2]; // it will have only 1 or 0

        bool containsKey(int idx)
        { // it will tell bit is there or not
            return (links[idx] != NULL);
        }
        Node *get(int idx)
        { // reference node
            return links[idx];
        }
        void put(int idx, Node *node)
        {                      // if bit does not exists
            links[idx] = node; // we need to put it accross
        }
    };
    class Trie
    {
    private:
        Node *root;

    public:
        Trie()
        {
            root = new Node();
        }

    public:
        void insert(int num)
        {
            Node *node = root;
            for (int i = 31; i >= 0; i--)
            {                             // 32 bit number from l to r
                int bit = (num >> i) & 1; // getting ith bit of that number
                if (!node->containsKey(bit))
                {                               // if does not contains
                    node->put(bit, new Node()); // creating reference
                }
                node = node->get(bit); // going to that
            }
        }

    public:
        int findMax(int num)
        {
            Node *node = root;
            int maxNum = 0;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1; // getting bit
                if (node->containsKey(!bit))
                {                               // if it has opposite number
                    maxNum = maxNum | (1 << i); // adding to maximum num
                    node = node->get(!bit);     // going to oppbit
                }
                else
                {                          // if not found
                    node = node->get(bit); // going to that bit
                }
            }
            return maxNum;
        }
    };
    int findMaximumXOR(vector<int> &A)
    {
        Trie trie;
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            trie.insert(A[i]); // inserting all eles of arr ib form of binary in tree
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, trie.findMax(A[i])); // getting maximum with each ele
        }
        return maxi;
    }
};

int main()
{
    return 0;
}