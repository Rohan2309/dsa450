/*

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &A)
{
    int r = A.size();
    int c = A[0].size();
    vector<int> ans;
    int Top, Bottom, Left, Right, dir;
    Top = 0;        //first row
    Bottom = r - 1; //last row
    Left = 0;       //first col
    Right = c - 1;  //last col
    dir = 0;        //initial (left to right) (when 1 top to bottom) (when 2 right to left) (3 bottom to top)
    int i;
    while (Top <= Bottom && Left <= Right)
    {
        if (dir == 0)
        {
            for (i = Left; i <= Right; i++) //printing left to right(top most row)
                ans.push_back(A[Top][i]);   //row will be same , col will be changing
            Top++;                          //shifting top 1 pos down as we have already printed first row
        }
        else if (dir == 1) //top to bottom
        {
            for (i = Top; i <= Bottom; i++) //top to bootom
                ans.push_back(A[i][Right]); //column will be static
            Right--;                        //shifting to 2nd last topic
        }
        else if (dir == 2) //right to left
        {
            for (i = Right; i >= Left; i--)
                ans.push_back(A[Bottom][i]); //col will be changing row will be static
            Bottom--;                        //last row printed so it will move up
        }
        else if (dir == 3) //bottom to top
        {
            for (i = Bottom; i >= Top; i--)
                ans.push_back(A[i][Left]); //row changes only col static
            Left++;                        //next col
        }
        dir = (dir + 1) % 4; // when 0 then 1 then 2 then 3 then 4 then 0
    }

    return ans;
}

int main()
{

    return 0;
}