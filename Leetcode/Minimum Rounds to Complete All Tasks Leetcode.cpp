class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		unordered_map<int, int>m;
		for (auto& i : tasks) {
			m[i]++;
		}
		bool canbe = true;
		int ans = 0;
		for (auto& i : m) {
			if (i.second < 2) {
				canbe = false;
				break;
			}
			else {
				ans += i.second / 3;
				int rem = i.second % 3;
				if (rem % 2 == 0) {
					ans += rem / 2;
				}
				else {
					ans += rem % 2;
				}


			}
		}
		if (!canbe) {
			return -1;
		}
		return ans;
	}
};