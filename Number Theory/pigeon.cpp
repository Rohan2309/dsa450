/*
Divisible Sub-arrays
*Pigeonhole Principle*

array containing N elements
we have to find number of good sub arrays
sub array whose sum is divisible by N

n no of holes 4
and n+1 pigeons 3
allocate pigeons in holes
1 hole will have 2 pigeons

cumulative sum array -> will contain sum upto particular index
1, (3, 2,) 6, 4
   a    b  
   total sum upto this point is b
   and total sum upto this point is a
   sum of sub array will be b-a
   (b-a)%N = 0
   b%N = a%N

   1, 3, 2, 6, 4 -> original array
0, 1, 4, 6,12,16 -> sum upto a point

0, 1, 4, 1, 2, 1 -> sum%n (cumulative sum array) 6 diff values after taking mod 5
x % 5 -> max 5 unique values
atleast 2 boxes will have same value

buckets 
0->1
1->3 if we take any two pos we will get the same sum  -> mC2 sub arrays
2->1
3->0
4->1
we will add whereever we have atleast 2 freq
and our ans will be 3c2 as m =3

ans+= fc2
where f>=2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long //constraints are long multiplying 2 numbers which are 10^9

ll a[1000005];   //array
ll pre[1000005]; //frequency array

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(pre, 0, sizeof(pre)); //initializing every bucket with 0

        pre[0] = 1; //freq of 0 will be 1 because of null sub array

        //read input
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];         //input array element
            sum += a[i];         //checking sum till that point
            sum %= n;            //mod with n is cumulative sum
            sum = (sum + n) % n; //for negative case
            pre[sum]++;          //increasing frequency of that number (creating freq array)
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) //going to all positions
        {
            ll m = pre[i];
            ans += (m) * (m - 1) / 2; //nC2
        }
        cout << ans << endl;
    }
    return 0;
}