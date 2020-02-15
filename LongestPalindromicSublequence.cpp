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
/////////  Top Down  /////////


int LPSq(string s,int a,int b,unordered_map<string,int>& lookup){
	string key=a+"|"+b;
	if(a>b){
		return 0;
	}
	if(a==b){
		lookup[key]=1;
		return 1;
	}
	
	if(lookup.find(key)==lookup.end()){
		if(s[a]==s[b]){
			lookup[key]=2+LPSq(s,a+1,b-1,lookup);
		}
		else{
			lookup[key]=max(LPSq(s,a+1,b,lookup),LPSq(s,a,b-1,lookup));
		}
	}
	return(lookup[key]);
}


int main(){
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout<<setprecision(10);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    string s;
    cin>>s;
    unordered_map<string,int> lookup;
    // for(uint i=0;i<s.size()-1;i++){
    // 	string a=i+"|"+i;
    // 	lookup[a]=1;
    // } 
    cout<<LPSq(s,0,s.size()-1,lookup);
    unordered_map<string,int>::iterator itr;
    
    

}