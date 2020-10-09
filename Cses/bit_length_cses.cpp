#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n;
	cin>>n;
	n=pow(2,n);
	long long int x =0;
	x = pow(10,9);
	x+=7;
	cout<<n%x;
}