#include<bits/stdc++.h>
using namespace std;

int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});

//graph created
    int parent[N]; //will store parent node
      //parent[i] = -1 first, wont have a parent
    int key[N]; //will store min weights
     //key[] = { 0, inf, inf, inf} 
    bool mstSet[N]; //is part of mst or not
     //mSet[] = {false, false, false, false}
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    //min heap
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    //weight, node
    key[0] = 0; //init condition
    parent[0] = -1; 
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int u = pq.top().second;//node with min weight 
        pq.pop(); 
        
        mstSet[u] = true; //node is a part of mst
        
        for (auto it : adj[u]) {//checking neighbours
            int v = it.first; //destination
            int weight = it.second;//weight concerned 
            //if node is not a part of mst and weight is less than key val
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;//parent updated
	            key[v] = weight;//new min weight 
                pq.push({key[v], v});//pushing ele ti pq (weight, node))    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}