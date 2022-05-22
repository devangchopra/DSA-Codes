#include <bits/stdc++.h>

long long pairsWithGivenSum(int arr[], int n, int sum) {
	// Write your code here
	unordered_map<int, int>m;
	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
	}
	long long count = 0;
	for (int i = 0; i < n; i++) {
	   count+=m[sum-arr[i]];
		if(sum-arr[i]==arr[i]){
			count--;
		}
		// for cases where 6+6=12 or 5+5=10
	}
	return count/2;
	//(a,b) == (b,a)
	
}