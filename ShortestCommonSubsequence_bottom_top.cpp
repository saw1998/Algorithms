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
#define MAX 20

int dp[MAX][MAX];

vector<string> SCS_string(string s1,string s2,uint m,uint n){
	if(m==0){
		vector<string> st;
		st.push_back(s2.substr(0,n));
		return(st);
	}
	if(n==0){
		vector<string> st;
		st.push_back(s1.substr(0,m));
		return(st);
	}
	if(s1[m-1]==s2[n-1]){
		vector<string> st;
		st=SCS_string(s1,s2,m-1,n-1);

		for(string& ss:st){
			ss.push_back(s1[m-1]);
		}
		return(st);
	}
	if(dp[m-1][n]<dp[m][n-1]){
		vector<string> st;
		st=SCS_string(s1,s2,m-1,n);

		for(string& ss:st){
			ss.push_back(s1[m-1]);
		}
		return(st);
	}
	if(dp[m][n-1]<dp[m-1][n]){
		vector<string> st;
		st=SCS_string(s1,s2,m,n-1);

		for(string& ss:st){
			ss.push_back(s2[n-1]);
		}
		return(st);
	}
	vector<string> top,left;
	top=SCS_string(s1,s2,m-1,n);

	for(string& ss:top){
		ss.push_back(s1[m-1]);
	}

	left=SCS_string(s1,s2,m,n-1);

	for(string& ss:left){
		ss.push_back(s2[n-1]);
	}

	top.insert(top.end(),left.begin(),left.end());
	return(top);

}


void SCS_Length(string s1,string s2,uint m, uint n){
	uint i,j;
	for(i=0;i<=m;i++){
		dp[i][0]=i;
	}
	for(i=0;i<=n;i++){
		dp[0][i]=i;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
			}
		}
	}
}

set<string> SCS(string s1,string s2){
	uint m=s1.length();
	uint n=s2.length();

	SCS_Length(s1,s2,m,n);

	vector<string> v=SCS_string(s1,s2,m,n);

	set<string> scs(v.begin(),v.end());
	return(scs);
}

int main(){
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout<<setprecision(10);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    string s1,s2;
    cin>>s1>>s2;

    set<string> s=SCS(s1,s2);
    cout<<"All SCS are \n\n";
    for(string a:s){
    	cout<<a<<endl;
    }
    

}