/*
Flood Fill

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &image, int newColor, int n, int m, int oldColor)
    {
        //invalid pos
        if (i < 0 or j < 0 or i >= n or j >= m) //boundary cond.
        {
            return;
        }
        if (vis[i][j] or image[i][j] != oldColor) //visited or not same as old color
        {
            return;
        }
        //going to valid pos
        vis[i][j] = 1;          //visited
        image[i][j] = newColor; //update

        //sending to four sides
        dfs(i + 1, j, vis, image, newColor, n, m, oldColor);
        dfs(i - 1, j, vis, image, newColor, n, m, oldColor);
        dfs(i, j + 1, vis, image, newColor, n, m, oldColor);
        dfs(i, j - 1, vis, image, newColor, n, m, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int i, int j, int newColor)
    {
        int x = image.size();                          //no of rows
        int y = image[0].size();                       //no of columns
        vector<vector<int>> vis(x, vector<int>(y, 0)); //2d visited vec of size x X y and initialized with 0
        int oldColor = image[i][j];
        dfs(i, j, vis, image, newColor, x, y, oldColor);
        return image;
    }
};

int main()
{

    return 0;
}