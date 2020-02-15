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

void LCP(int **a,int m,int n){
	int i,j;
	dp[0][0]=a[0][0];
	for(i=1;i<m;i++){
		dp[i][0]=a[i][0]+dp[i-1][0];
	}
	for(i=1;i<n;i++){
		dp[0][i]=a[0][i]+dp[0][i-1];
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			dp[i][j]=min(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
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
    int i,j,m,n;
    cin>>m>>n;
    int **a;
    a=new int*[m];
    for(i=0;i<m;i++){
    	a[i]=new int[n];
    	for(j=0;j<n;j++){
    		cin>>a[i][j];
    	}
    }
  	LCP(a,m,n);
  	cout<<dp[m-1][n-1];


    
    

}