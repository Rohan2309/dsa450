/*
Allocate Books
Medium

337

2

Add to favorites
Asked In:
GOOGLE
FLIPKART
Given an array of integers A of size N and an integer B.

College library has N bags,the ith book has A[i] number of pages.

You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return that minimum possible number
Constraints

1 <= N <= 10^5
1 <= A[i] <= 10^5
For Example

Input 1:
    A = [12, 34, 67, 90]
    B = 2
Output 1:
    113
Explanation 1:
    There are 2 number of students. Books can be distributed in following fashion : 
        1) [12] and [34, 67, 90]
        Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
        2) [12, 34] and [67, 90]
        Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
        3) [12, 34, 67] and [90]
        Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

        Of the 3 cases, Option 3 has the minimum pages = 113.

Input 2:
    A = [5, 17, 100, 11]
    B = 4
Output 2:
    100

*/
#include <bits/stdc++.h>
using namespace std;

int check(vector<int>&a, int pg, int std){
    //std is no of students
    //pg is max books can be allocated to each students
    int cnt=0;//students needed
    int sumPages=0;//pages alloc to each students

    for(int i=0; i<a.size();++i){
        if(sumPages+a[i]>pg){
            cnt++;//shifting to next students
            sumPages=a[i];//for next student
            if(sumPages>pg)return false;
        }
        else{//valid
            sumPages+=a[i];//allocationg to that student

        }
        
    }
    if(cnt<std)return true;//as we started from 0
    return false;


}
int books(vector<int> &A, int B) {
    if(B>A.size())return -1;//base case
    int n = A.size();
    int sum =0;
    for(int i=0;i<n;++i){
        sum+=A[i];
    }
    int ans =-1;
    int low= A[0];//at min we can allocate the lowest num of book and arr is already sorted
    int high = sum;//at max it can be the sum of all eles

    while(low<=high){
        int mid = (high+low)>>1;
        //valid case when allocation is possible
        //decrease the barrier
        if(check(A,mid,B)){//checks validity
            high=mid-1;
        }
        else{//when not possible incre the barrier
            low=mid+1;
        }

    }
    return low;
}

int main() {
	return 0;
}