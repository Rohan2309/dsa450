// C++ program to check if n is sparse or not
#include<iostream>
using namespace std;
 
// Return true if n is sparse, else false
bool checkSparse(int n)
{
    // n is not sparse if there is set
    // in AND of n and n/2
    if (n & (n>>1))//half of n is not 0
        return false;
 
    return true;
}
 
// Driver program
int main()
{
    cout << checkSparse(72) << endl;
    cout << checkSparse(12) << endl;
    cout << checkSparse(2) << endl;
    cout << checkSparse(3) << endl;
    return 0;
}