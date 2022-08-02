class Solution {
public:
	int findClosestNumber(vector<int>& nums) {
		//Number closest to zero would be the smallest number for positive
		//And for negative largest number
		sort(nums.begin(), nums.end());
		if (nums[0] >= 0  ) {
			return nums[0];
		}

		bool areAllNegative = true;

		for (auto&i : nums) {
			if (i > 0) {
				areAllNegative = false;
				break;
			}
		}

		if (areAllNegative) {
			return nums[nums.size() - 1];
		}

		int index = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				index = i;
				break;
			}
		}
		int largestNegative = nums[index - 1];
		int smallestPositive = nums[index];
		if (abs(largestNegative) == abs(smallestPositive)) {
			return smallestPositive;
		}
		else if (abs(largestNegative) < abs(smallestPositive)) {
			return largestNegative;
		}
		return smallestPositive;

	}
};