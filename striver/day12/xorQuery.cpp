/*
1707. Maximum XOR With an Element From Array
Hard

437

15

Add to List

Share
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.



Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]

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
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        Trie trie;
        sort(nums.begin(), nums.end()); // array needs to be sorted
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m, -1); // for storing ans
        // making offline query for storing idx
        vector<pair<int, pair<int, int>>> oQ; // first int will keep lim
        for (int i = 0; i < m; i++)
        {
            int lim = queries[i][1]; // keep lim first as we are going to sort on basis of lim
            int num = queries[i][0]; // the number itself
            oQ.push_back({lim, {num, i}});
        }
        sort(oQ.begin(), oQ.end()); // acc to limit of array
        int idx = 0;                // pointer
        for (auto &i : oQ)          // traversing offline query
        {
            int lim = i.first;
            int num = i.second.first;
            int qIdx = i.second.second;
            while (idx < n and nums[idx] <= lim)
            {
                trie.insert(nums[idx]); // inserting till  limit
                idx++;                  // incrementing it
                // so that for next time we get next value
            }
            if(idx!=0){//if idx is not at 0
            
                ans[qIdx]=trie.findMax(num);
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}