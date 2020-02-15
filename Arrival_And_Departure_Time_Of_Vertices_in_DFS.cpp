#include<iostream>
#include<cmath>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
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

void DFS(vector< vector<int> > &graph,int vertex,int n,vector<bool> &visited,vector<uint> &arrival,vector<uint> &departure,int &time){
	if(visited[vertex]){
		return;
	}
	arrival[vertex]=++time;
	visited[vertex]=true;
	for(auto e:graph[vertex]){
		if(!visited[e]){
			DFS(graph,e,n,visited,arrival,departure,time);
		}
	}
	departure[vertex]=++time;
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout<<setprecision(10);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n,i,j,k;cin>>n;
    vector<vector<int> > graph(n+1);

    for(i=0;i<n;i++){
    	cin>>j>>k;
    	graph[j].push_back(k);
    	// graph[k].push_back(j);
    }
    
    vector<bool> visited(n+1,false);
    vector<uint> arrival(n+1);
    vector<uint> departure(n+1);
    int time=-1;
    for(i=0;i<n;i++){
    	if(!visited[i]){
    		DFS(graph,i,n,visited,arrival,departure,time);
    	}
    }

    for(i=0;i<n;i++){
    	cout<<arrival[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++){
    	cout<<departure[i]<<" ";
    }

}