#include<iostream>
#include<cmath>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include<queue>
#include <set>
#include <map>
#include<unordered_map>
#include<iomanip>
#define mod 1000000007
using namespace std;
void show(int A[],int n=1){
	int i;
	cout<<"*************************************\n";
	for(i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<"\n";
	cout<<"*************************************\n";
}

vector<pair<int,int> > un_to_di(const vector<vector<int> > &graph,int n,int in){
	vector<pair<int,int> > edges;
	// bool *visited;
	vector<bool> visited(n+1);
	visited[in]=true;
	queue<int> q;
	q.push(in);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto e:graph[v]){
			if(!visited[e]){
				visited[e]=true;
				q.push(e);
				edges.push_back({e,v});
			}
		}
	}
	return(edges);
}

int main(){
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout<<setprecision(10);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    
    int n,f,i,s,d;cin>>n>>f;
    vector< vector<int> > graph(n+1);
    for(i=0;i<n;i++){
    	cin>>s>>d;
    	graph[s].push_back(d);
    	graph[d].push_back(s);
    }

    vector< pair<int,int> > digraph=un_to_di(graph,n+1,f);

    for(i=0;i<digraph.size();i++){
    	cout<<digraph[i].first<<" -> "<<digraph[i].second<<endl;
    }
    

}