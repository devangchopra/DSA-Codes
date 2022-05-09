#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int x = floor(n/2.0);
	unordered_map<int,int>m;
	for(int i=0;i<n;i++){
		m[arr[i]]++;
	}
	int ans=-1;
	for(auto& i:m){
		if(i.second>x){
			ans=i.first;
			break;			
		}
	}
	return ans;
	
}