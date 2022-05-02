#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        bool pal[n][n];//for matrix i is st char and j is en char
        //single char is always true, all diagonal eles
        for(int i=0; i<n; ++i) pal[i][i]=true;
        
        for(int len=2; len<=n ;++len){//2 to length of the string
            for(int i=0; i<n-len+1 ;++i){//i represents the start char
                int j = i+len-1;//represents end char
                if(len==2){
                    if(str[i]==str[j])pal[i][j]=true;
                    else pal[i][j]=false;
                }
                //when greater than 2
                else{ //check left bottom diag ele
                    if(str[i]==str[j] and pal[i+1][j-1])pal[i][j]=true;
                    else pal[i][j]=false;
                }
            }
        }
        
        long long int cuts[n];//how many  min cuts are req for 0 to idx i
        for(int i=0; i<n; ++i){
            if(pal[0][i])cuts[i]=0; // if palindrome we don't need to cut
            else{
                cuts[i]= INT_MAX;//we need to find min ans
                for(int j=0; j<i; ++j){//evertime we are checking where to make cut
                //we have to check the next part is palindrome or not
                    if(pal[j+1][i]) cuts[i]= min(cuts[i],cuts[j]+1);//+1 for curr cut
                }
            }
        }
        return cuts[n-1];//last ele of array
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
