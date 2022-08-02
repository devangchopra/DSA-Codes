class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0, temp =0, n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] == 0) {
				count = max(temp, count);
				temp =0;
			}
			else {
				temp++;
			}
		}
        count=max(temp,count);
		return count;
	}
};