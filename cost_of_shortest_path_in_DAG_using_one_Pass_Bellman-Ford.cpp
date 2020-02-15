#include<iostream>
#include<cmath>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include<climits>
#include <set>
#include <map>
#include<unordered_map>
#include<iomanip>
#define mod 1000000007
using namespace std;
struct node{
	int src,des,wt;
};
void DFS(vector<vector<node>>&graph,int sc,int &time,vector<int>&departure,vector<bool> &visited){
	visited[sc]=true;
	for(auto e:graph[sc]){
		if(!visited[e.des]){
			DFS(graph,e.des,time,departure,visited);
		}
	}
	departure[time]=sc;
	time++;
}

void Find_Shortest_path(vector<vector<node>> &graph,int n,int source){
	int time=0;
	vector<int> departure(n,-1);
	vector<bool> visited(n,false);

	for(int i=0;i<n;i++){
		if(!visited[i]){
			visited[i]=true;
			DFS(graph,i,time,departure,visited);
		}
	}

	vector<int> cost(n,999999);
	cost[source]=0;
	for(int i=n-1;i>=0;i--){
		int v=departure[i];
		for(auto e:graph[v]){
			int s=e.src;
			int d=e.des;
			int w=e.wt;
			if(cost[s]!=999999 && cost[d]>cost[s]+w){
				cost[d]=cost[s]+w;
			}
		}
		
	}
	for(int i=0;i<n;i++){
		cout<<"cost of ("<<source<<"->"<<i<<") = "<<setw(2)<<cost[i]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout<<setprecision(10);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n,source; cin>>n>>source;
    vector<vector<node> > graph(n);
    int i,j,k,l;
    for(i=0;i<n;i++){
    	cin>>j>>k>>l;
    	graph[j].push_back({j,k,l});
    }
    
    Find_Shortest_path(graph,n,source);


}