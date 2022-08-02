//Recursive

class Solution {
public:
	int no_of_steps_to_reach_n(int n) {
		if (n <= 0 or n == 1) {
			return 1;
		}
		return no_of_steps_to_reach_n(n - 1) +
		       no_of_steps_to_reach_n(n - 2);

	}
	int climbStairs(int n) {
		return no_of_steps_to_reach_n(n);
	}
};

//DP

class Solution {
public:
	int no_of_steps_to_reach_n(int n, vector<int>&v) {
		if (v[n] != -1) {
			return v[n];
		}
		if (n <= 0 or n == 1) {
			return 1;
		}
		return v[n] = no_of_steps_to_reach_n(n - 1, v) +
		              no_of_steps_to_reach_n(n - 2, v);

	}
	int climbStairs(int n) {
		vector<int>v(n + 1, -1);
		return no_of_steps_to_reach_n(n,v);
	}
};