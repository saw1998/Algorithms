#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout<<setprecision(10);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	cout<<"No. of object :";
	int n; cin>>n; cout<<n;
	int weight[n],profit[n],i;
	for(i=0;i<n;i++) cin>>weight[i];
	for(i=0;i<n;i++) cin>>profit[i];

	double pr_per_wt[n];
	for(i=0;i<n;i++) pr_per_wt[i]=((double)profit[i]/weight[i]);
	
		
	
}