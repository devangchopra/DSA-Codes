#include <bits/stdc++.h>

vector<int>dp(4000,-1);
long long int fxn(int n){
	if(n==1 or n==2){
		return n-1;
	}
	if(dp[n]!=-1){
	    return dp[n];
	}
	return dp[n]= (n-1)*(fxn(n-1)+fxn(n-2))%1000000007;
}
long long int countDerangements(int n) {
    // Write your code here.
	long long int ans =fxn(n);
	return ans%1000000007;
}