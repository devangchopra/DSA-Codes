class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int left = 1;
		int right = INT_MIN;
		for (auto& i : piles) {
			right = max(i, right);
		}
		while (left < right) {
			int mid = (left + right) / 2;
			int hourspent = 0;
			for (auto& i : piles) {
				hourspent += i / mid + (i % mid != 0);
				//for ciel
				//hourspent +=(i*1.0/mid*1.0);
			}
			if (hourspent > h) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return right;
	}
};


