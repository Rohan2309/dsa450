#include<bits/stdc++.h>
using namespace std;
//shortest path in a directed graph (doesnot work for negative weights)
int main(){
	int n=5,m=6,source=1;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});	
	// Dijkstra's algorithm begins from here
    //min heap pq first is distance and second is node
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
	distTo[source] = 0;//source to source distance is 0
	pq.push(make_pair(0,source));	// (dist,source)
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		for( auto it: g[prev]){//seeing adjacent
			int next = it.second;
			int nextDist = it.first;
            //if shortedt past for adj is greater than new, then update
			if( distTo[next] > dist + nextDist){
				distTo[next] = dist + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
    //print all ans
	cout << "The distances from source " << source << " are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	return 0;
}