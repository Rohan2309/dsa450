/*
901. Online Stock Span
Medium

2460

201

Add to List

Share
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
*/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    stack<pair<int,int>>s;//stack pair index and value
    int idx;
public:
    //previous greater element
    //maintain stack in decreasing order
    
    StockSpanner() {
        idx=-1;//init
    }
    
    int next(int p) {
        //start fromn 0
        idx+=1;//on every query index will be increase
        //whenever next func is called index will be incre by 1
        
        //elements present in stack and top element's  value is lesser than p
        //we pop element as we maintain it in decreasing order
        while(!s.empty() and s.top().second<=p) s.pop();
        
        //after poping out all smaller elements and if stack empty
        //that means no previous greater element present
        if(s.empty()){
            s.push({idx,p});//push that ele in stack
            return idx+1;//from first to last all will be considered
        }
        
        //if previous greater element is present
        int res = s.top().first; //idx of pge
        s.push({idx,p});//we push in stack
        return idx-res;// current index - pge idx
    }
};

int main()
{

    return 0;
}