//Brute Force

class Solution {
public:
	bool validMountainArray(vector<int>& arr) {
		if (arr.size() < 3) {
			return false;
		}
		int n = arr.size(), index = INT_MAX;
		for (int i = 1; i < n; ++i) {
			if (arr[i] > arr[i - 1]) {
				continue;
			}
			else if (arr[i] < arr[i - 1]) {
				index = i;
				break;
			}
			else {
				return false;
			}
		}
		bool ans = true, alld = true;
		for (int i = 1; i < n; i++) {
			if (arr[i] < arr[i - 1]) {
				continue;
			}
			else {
				alld = false;
				break;
			}
		}
		if (alld) {
			return false;
		}
		if (index == INT_MAX) {
			return false;
		}
		else {

			for (int i = index + 1; i < n; i++) {
				if (arr[i] < arr[i - 1]) {
					continue;
				}
				else {
					ans = false;
					break;
				}
			}
		}
		return ans;
	}
};

//Better One Pass
class Solution {
public:
	bool validMountainArray(vector<int>& arr) {
		int i = 0, n = arr.size();
		for (i + 1; i < n; i++) {
			if (arr[i] > arr[i - 1]) {
				continue;
			}
			else {
				break;
			}
		}
		if (i == 0 or i == n - 1) {
			return false;
		}
		for (i + 1; i < n; i++) {
			if (arr[i] < arr[i - 1]) {
				continue;
			}
			else {
				break;
			}
		}
		return i == n - 1;
	}
};