//Brute Force
//TLE
//O(n**2)
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int>ans;
		int n = nums.size();
		if (k == n) {
			return {*max_element(nums.begin(), nums.end())};
		}
		for (int i = 0; i, n - k; i++) {
			int t = k, m = i, tans = INT_MIN;
			while (t--) {
				tans = max(tans, nums[m]);
				m++;
			}
			ans.push_back(tans);
		}
		return ans;

	}
};




//O(n)
//Monotonic Queue
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int>ans;
		deque<int>dq;

		//We are pushing and palying with indexes

		for (int i = 0; i < n; i++) {

			//Removal from left when the window moves
			if (!dq.empty() and dq.front() == i - k) {
				dq.pop_front();
			}

			while (!dq.empty() and nums[dq.back()] < nums[i]) {
				dq.pop_back();
			}

			dq.push_back(i);

			if (i >= k - 1) {
				ans.push_back(nums[dq.front()]);
			}

			//Pushing value to output after every cycle
		}

		return ans;
	}
};


