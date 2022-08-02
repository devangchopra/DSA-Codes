#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int product=1;
	for(int i=0;i<n;i++){
		product=product*arr[i];
	}
	cout<<product<<'\n';
	vector<int>v(n);
	for(int i=0;i<n;i++){
		v[i]=(product/arr[i]);
	}
	for(auto i:v){
		cout<<i<<" ";
	}
	return 0;
}