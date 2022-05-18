#include <bits/stdc++.h>
vector<int> chocolateFest(vector<int> choco, int x) {
	// Write your code here
	//1.Minimum Length and contiguous
	//2.Nearby : i am starting from 0
	//3.Sum > x

	//Sliding window + two pointer for pushing into array
	int from = 0;
	int to = 0;
	int min_length = INT_MAX;

	int start = 0, end = 0, sum = 0;

	while (end < choco.size()) {
		sum += choco[end];
		if (sum <= x) {
			end++;
			//basically we want > x
		}
		else {
			//sliding window and updating size
			while (sum > x) {
				int sizeofwindow = end - start + 1;
				if (min_length > sizeofwindow) {
					min_length = sizeofwindow;
					from = start;
					to = end;
				}
				sum -= choco[start];
				start++;
			}
			end++;
		}
	}
	vector<int>ans;
	for (int i = from; i <= to; i++) {
		ans.push_back(choco[i]);
	}
	return ans;
}
