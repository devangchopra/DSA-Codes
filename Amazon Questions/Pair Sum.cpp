#include<bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s) {
	// Write your code here.

	vector<int>res;
	vector< vector<int>>v;
	unordered_map<int, int>m;
	for (int i = 0; i < arr.size(); i++)
	{
		auto it = m.find(s - arr[i]);
		if (it != m.end())
		{
			int temp = it->second;
			while (temp > 0)
			{
				res.push_back(s - arr[i]);
				res.push_back(arr[i]);
				sort(res.begin(), res.end());
				v.push_back(res);
				res.clear();
				temp--;
			}
		}
		m[arr[i]]++;
	}
	sort(v.begin(), v.end());
	return v;
}