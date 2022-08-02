#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool compareBoxes(vector<int>b1, vector<int>b2) {
	return b1[2] > b2[2];
}

bool canplace(vector<int>b1, vector<int>b2) {
	if (b1[0] > b2[0] and b1[1] > b2[1] and b1[2] > b2[2]) {
		return true;
	}
	return false;
}

int fxn(vector<vector<int>> boxes) {
	int n = boxes.size();

	//1.Sorting
	sort(boxes.begin(), boxes.end(), compareBoxes);

	//2.DP
	vector<int>dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
		dp[i] = boxes[i][2];
	}

	//LIS Logic
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (canplace(boxes[j], boxes[i])) {
				int current_height = boxes[i][2];

				if (dp[j] + current_height > dp[i]) {
					dp[i] = dp[j] + current_height;
				}
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());
	return ans;
}


int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>>boxes = {{2, 1, 2},
		{3, 2, 3},
		{2, 2, 8},
		{2, 3, 4},
		{2, 2, 1},
		{4, 4, 5}
	};


	cout << fxn(boxes);
}