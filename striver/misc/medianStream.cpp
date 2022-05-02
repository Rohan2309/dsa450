#include <bits/stdc++.h>
using namespace std;


class MedianFinder {
public:
    priority_queue<int> maxpq; //maxHeap
    priority_queue<int, vector<int>, greater<int>> minpq; //minHeap
    //smaller half of arr will be in max heap and bigger values in min heap
    void addNum(int num) {
        //if both heaps are empty push to max heap
        //we push nums which are smaller than top ele of max heap
        if(maxpq.empty() or maxpq.top() > num) maxpq.push(num);
        else minpq.push(num);//otherwise we push to min heap
        
        
        //whichever's size diff become greater than 1 we pop
        //ele from that and push to other one
        if(maxpq.size() > minpq.size() + 1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size() + 1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        
    }
    
    double findMedian() {
       if(maxpq.size() == minpq.size()) return (maxpq.top() + minpq.top()) / 2.0; //even elements
        else{ //odd elements, return top ele of heap which is larger iin size
            if(maxpq.size() > minpq.size()) return maxpq.top();
            else return minpq.top();
            
        }
    }
};


int main()
{
    
    return 0;
}