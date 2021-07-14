/*
Diophantine Equations
polynomial equations whose integral soln exists
3x+7y=1 or x^2-y^2=z^3

ax+by=c -> linear diophantine eq {a,b,c  belongs to 1}
soln. of eq exists only if gcd(a,b) divides c

a,b, c given and we have to find integral soln of x,y

property 
ax+by = gcd(a,b)

gcd(a,b) = gcd(b,a%b)
gcd(a,0) = a

when b = 0
ax+0= a->x=1
y=0

x=y1
y=x1-(a/b)*y1
*/

#include <bits/stdc++.h>
using namespace std;

struct triplet
{
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a, int b)
{
    if (b == 0) //base case
    {
        triplet ans; //scope till if only
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns = extendedEuclid(b, a % b); //rec call
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}

int main()
{
    int a;
    int b;
    cin >> a >> b;
    triplet ans = extendedEuclid(a, b);
    cout << ans.gcd << " " << ans.x << " " << ans.y << endl;
    return 0;
}