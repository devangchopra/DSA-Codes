//Accepted :

class Solution {
public:
	int minOperations(vector<int>& nums, vector<int>& numsDivide) {

		//GCD of all numbers in numsDivide
		int gcd_nums = numsDivide[0];

		for (int i = 1; i < numsDivide.size(); i++) {
			gcd_nums = __gcd(gcd_nums, numsDivide[i]);
		}

		priority_queue<int, vector<int>, greater<int>> pq;

		int ans = 0;

		for (auto& i : nums) {
			pq.push(i);
		}

		while (pq.empty() == false) {
			auto t = pq.top();

			//condition : gcd_nums% t==0
			//then this no will divide all nos in numsDivide
			pq.pop();

			if (gcd_nums % t ==0) {
				return ans;
			}

			if (t > gcd_nums) {
				//Cant divide at anyy costt
				return -1;
			}

			ans++;
		}

		return -1;

	}
};





//TLE : 37 tcs passed


class Solution {
public:
	int minOperations(vector<int>& nums, vector<int>& numsDivide) {

		//Min Heap
		priority_queue<int, vector<int>, greater<int>>pq;

		for (auto& i : nums) {
			pq.push(i);
		}

		int ans = -1;
		int n = nums.size();
		bool all_divi = false;

		while (all_divi == false and n >= 0) {
			n--;
			ans++;
			int t = pq.top();

			bool yes = true;

			for (auto& i : numsDivide) {
				if (i % t != 0) {
					yes = false;
					break;
				}
			}

			if (yes) {
				all_divi = true;
				break;
			}
			else {
				pq.pop();
			}
		}

		if (all_divi) {
			return ans;
		}
		return -1;

	}
};




