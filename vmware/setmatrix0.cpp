#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//THIRD APPROACH
    void setZeroes(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        int col = 1; //flag (first it is true)

        //treating first row and first colums as dummy arrays

        for(int i=0; i<r; i++){
            if(m[i][0]==0){//if any of the values in first col is zero
                col=0;//flag is false
                //later if it is 0 the whole 0th col will set to 0
            }
            /*
            reason for this is, if already 1st col is set to 0s,
            then 1st row will be set to 0. (we don't want that)
            */
            for(int j=1; j<c; j++){//we don't check col 1
                if(m[i][j]==0){
                    //filly dummy arrays with 0
                    m[i][0]=m[0][j]=0;//setting leftmost and topmost as 0
                }
            }
        }
        //linearly traverse from backwards
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=1; j--){
                //checking the dummy arrays
                if(m[i][0]==0 or m[0][j]==0){//checking if pos of first row and col is 0
                    m[i][j]=0;//changing to 0
                }
            }
            if(col==0){ //at the last, so it does not hampers the 1st row
                m[i][0]=0;//whole 0th col set to 0
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
