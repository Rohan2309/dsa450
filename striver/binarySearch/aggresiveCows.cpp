/*
AGGRCOW - Aggressive cows
#binary-search
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3

*/

#include <bits/stdc++.h>

    using namespace std;
    bool isPossible(int a[], int n, int cows, int minDist) {
        //can we place cows by keeping a distance of minDist
      int cntCows = 1;//init no of cow, atleast 1 cow
      int lastPlacedCow = a[0];//1st cow will be at pos
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows) return true;
      return false;
    }
    int main() {
      int n = 5, cows = 3;
      int a[]={1,2,8,4,9};
      sort(a, a + n);//not in sorted order always

      int low = 1;//smallest min dist can be 1
      int high = a[n - 1] - a[0];//max min dist

      while (low <= high) {
        int mid = (low + high) >> 1;// divided by 2

        if (isPossible(a, n, cows, mid)) {//check
          low = mid + 1;//as we want max of minimums we incre
        } else {//if not possible
          high = mid - 1;//we decree
        }
      }
      cout << "The largest minimum distance is " << high << endl;
//ans will be at high as high low will cross high 
      return 0;
    }