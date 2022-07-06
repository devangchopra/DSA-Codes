#include <bits/stdc++.h>
using namespace std;

long long countPositiveNegativePairs(int arr[], int n){
    //  Write your code here
    if(n <= 1){
    	return 0;
    }
    unordered_map<int,pair<int,int>>m;
    //Number : Index : Count
    for(int i=0;i<n;i++){
    	if(m.find(arr[i])==m.end()){
    		pair<int,int>p;
    		p.first = i;
    		p.second = 1;
    		m.insert({arr[i],p});
    	}

    	else{
    		m[arr[i]].second++;
    	}

    }
    long long count = 0;
    for(int i=0;i<n;i++){
    	if(m.find(arr[i]*(-1)) != m.end()){
    		if(i!=m[arr[i]*(-1)].first){
    			count += m[arr[i]*(-1)].second;
    		}
    	}
    }

    return count/2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[] = {-2,8,2,5,-2,-5};
	int  n = 6;

	cout<<countPositiveNegativePairs(arr,n);

}