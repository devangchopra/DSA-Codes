#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char first;
	int second;
	cin>>first>>second;
	int count = 0;
	if (first == 'a' || first == 'h') 
		count++;
	if (second == 1 || second == 8) 
		count++;
	if (count == 0) 
		cout<<8;
	else if (count == 1) 
		cout<<5;
	else if (count == 2) 
		cout<<3;	
	return 0;
}