#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin>>s;
	vector<char>ans;
	for(int i=0;i<s.size()-3;i++){
		if(s[i]='W' and s[i+1]=='U' and s[i+2]=='B'){
			i=i+2;
		}
		else{
			ans.push_back(s[i]);
		}
	}
	for(auto i:ans){
		cout<<i;
	}
	return 0;
}