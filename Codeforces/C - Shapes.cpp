#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;

	char s[n][n],t[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin>>s[i][j];
		}		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin>>t[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<s[i][j];
		}cout<<endl;
	}

	cout<<endl<<"Second Matrix"<<" "<<endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<t[i][j];
		}cout<<endl;
	}



	return 0;
}