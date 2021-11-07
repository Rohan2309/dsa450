/*

Repeat and Missing Number Array
Medium

127

13

Add to favorites
Asked In:
AMAZON
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

This is one of those problems.

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :

Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

4 3 6 2 1 1
approach -> hashing, number will be in range of 1 to 6 as arr size is 6
create an arr of sz 7, initialized with freq 0
one idx will have freq 0, missing
and one as more than 1 which will be duplicate

another approach -> when adding all squares we need long long data type to store squares
1+2+3+4...+n
S = (n(n+1))/2 is the summation of all the numbers
when S - sum of all the elements present, in the arr
(1+2+3+4+5+6) - (4+3+6+2+1+1)
5 - 1 = 4  (x-y = s) x is missing and y is rep

1^2 + 2^2 + 3^2 + ...n^2 = (n(n+1)(2n+1))/6 = s^2 
(1^2+2^2+3^2+4^2+5^2+6^2) - (4^2+3^2+6^2+2^2+1^2+1^2)
5^2 - 1^2 = 24  (x^2-y^2 = 24) x is missing and y is rep

so 2 eqs are x^2-y^2 = 24 -> (x-y)(x+y) = 24 -> 4(x+y) = 24 -> x+y = 6
and x-y =4
so x+y =6
add 2 eqs
we get 2x = 10 -> x= 5 (missing number)
put val of x in 1st eq to get val of y



OPTIMAL APPROACH

initialize xor as 0
4^3^6^2^1^1 will give value of 3
then 3 ^ (1^2^3^4^5^6) // all the numbers from 1 to n
we get 4 which is x ^ y, x is missing no. and y is rep num

what we are doing
(4^3^6^2^1^1) ^ (1^2^3^4^5^6)
all same numbers are being cancelled, so only n umbers remaining are 1 and 5

x^y = 4
x^y = 100
either of x is 0 or 1
or y is 1 or 0 , either of the bits of x or y must be set that's why it's 1 at the start
rightmost bit was on the 2nd idx -> 1 is at the 2nd idx as 4 = 100


array is 4 3 6 2 1 1
we create 2 buckets
4 can be written in binary as 100
we check 2nd idx is set or not, if set we put it in 1st bucket , otherwise 2nd bucket

so 6 and 4 are in bucket 1 and 1 1 2 3 in bucket 2

then we take array of 1 to n -> 1 2 3 4 5 6
then we classigy again and put numbers in those buckets

now bucket 1 has 6 5 4 6 4 -> xor these numbers and we get 5 (missing number)
bucket 2 has 3 2 1 1 1 2 3 -> xor these numbers and we get 1 (rep number)

then linearly traverse to find the which is the missing and which is the rep no.
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;//iterator
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1); //returns position

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
}

int main(){
    return 0;
}