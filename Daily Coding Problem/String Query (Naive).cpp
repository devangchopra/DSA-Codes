#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector <string> s {"dog", "deer", "deal"};

	string p ="de";

	vector<string> ans;

	for(auto i : s) 
	{
		auto c=i.find("d");
		auto d=i.find("e");

		int x= d-c;

		if(x==1)
		{
			ans.push_back(i);
		}
	}

	for(auto i:ans)
	{
		cout<<i<<" ";
	}
}