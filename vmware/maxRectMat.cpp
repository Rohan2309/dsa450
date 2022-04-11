#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
int maxHistogram(vector<int>& heights)
    {
        heights.push_back(0);//overflow error
        int n = heights.size();
        stack<int> st;//store in incre fashion
        int res = 0;
        
        int i = 0;
        while(i < n)
        {
            if(st.empty() or heights[i] >= heights[st.top()])//current ele is greater than top ele of stk
              st.push(i++);
            else//if greater then pop
             {
                 int top = st.top();
                 st.pop();
                //width if smaller ele is not present in array then whole width so i
                //if present then we calculate
                 res = max(res, heights[top] * (st.empty() ? i : i - st.top() - 1));
             }
        }
        
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if(matrix.empty())return 0;//base
        
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        
        vector<int> height(n, 0);//maintaining vect for each row to have max height
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            res = max(res, maxHistogram(height));
        }
        
        return res;
        
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
