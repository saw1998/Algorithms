#include<bits/stdc++.h>
using namespace std;
#define MAX 20;
int dp[MAX][MAX];
vector<string> l;

void find_String(string a,string b,int m,int n){
	vector<string> v(1);
	if(dp[m][n]==0){
		return(v);
	}
	int tm=m,tn=n;
	while(dp[m-1][n]==dp[m][n]){
		m--;
	}
	while(dp[m][n]==dp[m][n-1]){
		n--;
	}
	while(dp[tm][tn]==dp[tm][tn-1]){
		tn--;
	}
	while(dp[tm-1][tn]==dp[tm][tn]){
		tm--;
	}
	// string x;
	if(tm==m){
		for(string & c:l){
			c.push_back(a[tm]);
			c=a[tm]+c;
			find_String(a,b,m-1,n-1);
		}
		
	}
	else{

	}
	
}


void LCS(string a,string b){
	int m=a.size();
	int n=b.size(),i,j;
	for(i=0;i<m+1;i++){
		for(j=0;j<n+1;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
				continue;
			}
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max((dp[i-1][j]),(dp[i][j-1]));
			}

		}
	}
	vector<string> v=find_String(a,b,m,n);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string a,b;
	cin>>a>>b;
	vector<string> v;
	v=LCS(a,b);
	
}

////**********treatment required/******************/////