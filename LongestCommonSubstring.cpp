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

void LCS1(string a,string b){
	uint m=a.size();
	uint n=b.size(),i,j,c=1;
	uint max=1;
	vector<string> v;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j]){
				string temp;
				temp+=a[i];
				c=1;
				while(a[i+c]==b[j+c] && i+c<m && j+c<n){
					temp+=a[i+c];
					c++;
					// max++;
					
				}
				if(max<=c){
					max=c;
					// cout<<max<<endl;
					v.push_back(temp);
				}
			}
		}
	}
	for(i=0;i<v.size();i++){
		if(v[i].size()==max)
		cout<<v[i]<<endl;
	}

}

void LCS2(string a,string b){
	uint m=a.size(),n=b.size(),i,j,c;
	uint dp[m+1][n+1],max=0;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
				continue;
			}
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				if(max<dp[i][j]){
					max=dp[i][j];
				}
			}
			else{
				dp[i][j]=0;
			}

		}
	}
	cout<<"max_length="<<max<<endl;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(dp[i][j]==max){
				string s;
				s=a[i-1];
				c=1;
				while(dp[i-c][j-c]>0){
					s=a[i-1-c]+s;
					c++;
				}
				cout<<s<<endl;
			}
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
    cin>>a>>b;

    LCS1(a,b);
    // LCS2(a,b);
    

}