#include <bits/stdc++.h>
using namespace std;
 
// Function to find the word
string mostRepeated(vector<string> seq)
{
 
    // Store all the words with its occurrence
    unordered_map<string, int> mp;
    for (int i = 0; i < seq.size(); i++)
        mp[seq[i]]++;
 
    // find the first largest occurrence
    int first_max = INT_MIN;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > first_max) {
            first_max = it->second;
        }
    }
 
    // Return string with occurrence equals
    // to first_max
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second == first_max)
            return it->first;
}
 
// Driver program
int main()
{
    vector<string> seq = { "ccc", "aaa", "ccc",
                          "ddd", "aaa", "aaa" };
    cout << mostRepeated(seq);
    return 0;
}