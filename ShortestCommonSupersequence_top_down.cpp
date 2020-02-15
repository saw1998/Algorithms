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
int ShCSuq(string s1,string s2,int a,int b,unordered_map<string,int>&lookup){
	
	if(a==0 || b==0){
		return(a+b);
	}																///using lookup (top down) Only length
	string key=to_string(a)+"|"+to_string(b);
	
	if(lookup.find(key)==lookup.end()){
		if(s1[a-1]==s2[b-1]){
			lookup[key]=ShCSuq(s1,s2,a-1,b-1,lookup)+1;
		}
		else{
			lookup[key]=min(ShCSuq(s1,s2,a-1,b,lookup)+1 ,ShCSuq(s1,s2,a,b-1,lookup)+1 );
		}
	}
	return(lookup[key]);

}

string ShCSuqString(string s1,string s2,int a,int b,unordered_map<string,string> &lookup){
	if(a==0){
		return(s2.substr(0,b));
	}
	if(b==0){
		return(s1.substr(0,a));									///top down (whole string)
	}
	string key;
	key=to_string(a)+"|"+to_string(b);
	if(lookup.find(key)==lookup.end()){
		if(s1[a-1]==s2[b-1]){
			lookup[key]=ShCSuqString(s1,s2,a-1,b-1,lookup)+s1[a-1];
		}
		else{
			string a1=ShCSuqString(s1,s2,a-1,b,lookup);
			string b1=ShCSuqString(s1,s2,a,b-1,lookup);
			if(a1.length()<b1.length()){
				lookup[key]=a1+s1[a-1];
			}
			else{
				lookup[key]=b1+s2[b-1];
			}
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
    string s1,s2;
    cin>>s1>>s2;
    uint m=s1.size(),n=s2.size();
    // unordered_map<string,int> lookup;
    // int l=ShCSuq(s1,s2,m,n,lookup);
    // cout<<l<<endl;

    unordered_map<string,string> lookup2;
    string a=ShCSuqString(s1,s2,m,n,lookup2);
    cout<<a<<endl;
    // int max=0;
    // // for(pair<string,int> element:lookup){

    // // 	if(max<element.second){
    // // 		max=element.second;
    // // 	}
    // // 	cout<<element.first<<" "<<element.second<<endl;
    // // }
    // // cout<<max<<endl;
    // // for(itr=lookup.begin();itr!=lookup.end();itr++){
    // // 	if(max==element.second){
    // // 		cout<<element.second<<endl;
    // // 	}
    // // }
    // // pair<string,string> element;
    // for(auto element:lookup2){

    // 	if(max<element.second.length()){
    // 		max=element.second.length();
    // 	}
    // 	cout<<element.first<<" "<<element.second<<endl;
    // }
    // cout<<max<<endl;
    // for(auto itr=lookup2.begin();itr!=lookup2.end();itr++){
    // 	if(max==itr->second.length()){
    // 		cout<<itr->second<<endl;
    // 	}
    // }

}