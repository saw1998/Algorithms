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
// void show2(const int A[][],int r,int c){
// 	cout<<"\n**************************************\n";
// 	for(int i=0;i<r;i++){
// 		for(int j=0;j<c;j++){
// 			cout<<A[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"\n**************************************\n";
// }


void LCS_2d_array(string a,string b){					//using 2d array
	int dp[a.size()+1][b.size()+1];
	// vector<string> v;
	for(uint i=0;i<=a.size();i++){
		for(uint j=0;j<=b.size();j++){
			if(i==0 || j==0){
				dp[i][j]=0;
				continue;
			}
			if(b[i-1]==a[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
			show2(dp,a.size()+1,b.size()+1);
		}
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

	string a,b;
	cin>>a;    
	cin>>b;
	// vector<string> l;
	LCS_2d_array(a,b);
	// for(uint i=0;i<l.size();i++){
	// 	cout<<l[i]<<endl;
	// }
	// cout<<LCS_lookup(a,b,a.size(),b.size());
}