//Maximize Distance to Closest Person

// Brute Force 

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int n = seats.size(), index;
		vector<int>v1;
		vector<int>v2;

		//Left to right
		if (seats[0] == 1) {
			index = 0;
		}
		else {
			index = INT_MAX;
		}
		for (int i = 0; i < n; i++) {
			if (seats[i] == 1) {
				v1.push_back(0);
				index = i;
			}
			else if (index != INT_MAX) {
				v1.push_back(i - index);
			}
			else {
				v1.push_back(INT_MAX);
			}
		}

		//Right to left
		if (seats[n - 1] == 1) {
			index = n - 1;
		}
		else {
			index = INT_MAX;
		}
		for (int i = n - 1; i >= 0; --i) {
			if (seats[i] == 1) {
				v2.push_back(0);
				index = i;
			}
			else if (index != INT_MAX) {
				v2.push_back(index - i);
			}
			else {
				v2.push_back(INT_MAX);
			}
		}

		reverse(v2.begin(), v2.end());

		//Take minimum
		for (int i = 0; i < n; i++) {
			v1[i] = min(v1[i], v2[i]);
		}

		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			ans = max(ans, v1[i]);
		}

		return ans;
	}
};


// Try Two Pointer Approach