#include<bits/stdc++.h>
vector<pair<int, int>> twoSum(vector<int>& arr, int target, int n) {
	// Write your code here.
	sort(arr.begin(), arr.end());
	int l = 0, h = arr.size() - 1;
	vector<pair<int, int>>ans;
	while (l < h) {
		if (arr[l] + arr[h] == target) {
			pair<int, int>p = {arr[l], arr[h]};
			ans.push_back(p);
			l++;
			h--;
		}
		else if (arr[l] + arr[h] > target) {
			h--;
		}
		else {
			l++;
		}
	}
	if (ans.size() == 0) {
		ans.push_back({ -1, -1});
	}
	return ans;
}
