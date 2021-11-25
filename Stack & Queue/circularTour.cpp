/*
Circular tour 
Medium Accuracy: 33.91% Submissions: 76983 Points: 4
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
*/

#include <bits/stdc++.h>
using namespace std;

/*
struct Node
{
    int data;
    struct Node *left;  //pointer pointing towards left child
    struct Node *right; //pointer for right child

    Node(int val) //constructor taking data
    {
        data = val;
        left = NULL; //initially
        right = NULL;
    }
};
*/

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    //Your code here
    int start = 0; //will return the answer from which pos it will start
    int extraFuel = 0;
    int requiredFuel = 0;
    int z;
    for (int i = 0; i < n; i++)
    {
        z = p[i].petrol - p[i].distance;
        extraFuel += z; //storing the extra fuel
        if (extraFuel < 0)
        {                              //if ectrafuel becomes negative
            start = i + 1;             //start pos will be next point
            requiredFuel += extraFuel; //will store the required as it will be a shortage later
            extraFuel = 0;             //again start
        }
    }
    if (requiredFuel + extraFuel >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}
int main()
{

    return 0;
}