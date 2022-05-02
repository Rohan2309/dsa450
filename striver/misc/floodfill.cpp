#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &image, int newColor, int n, int m, int oldColor)
    {
        if (i < 0 or j < 0 or i >= n or j >= m)return;
        if (vis[i][j] or image[i][j] != oldColor)return;//vis or not same as old color
        //going to valid pos
        vis[i][j] = 1;          //visited
        image[i][j] = newColor; //update
        //sending to four sides
        dfs(i + 1, j, vis, image, newColor, n, m, oldColor);
        dfs(i - 1, j, vis, image, newColor, n, m, oldColor);
        dfs(i, j + 1, vis, image, newColor, n, m, oldColor);
        dfs(i, j - 1, vis, image, newColor, n, m, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int newColor) {
        int x = image.size();                          //no of rows
        int y = image[0].size();                       //no of columns
        vector<vector<int>> vis(x, vector<int>(y, 0)); //2d visited vec of size x X y and initialized with 0
        int oldColor = image[i][j];
        dfs(i, j, vis, image, newColor, x, y, oldColor);
        return image;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
