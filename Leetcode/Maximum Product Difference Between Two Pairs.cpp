class Solution {
public:
	int maxProductDifference(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		int p1 = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 2)
				break;
			else
				p1 = p1 * nums[i];
		}
		int index = 0;
		int p2 = 1;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (index == 2)
				break;
			p2 = p2 * nums[i];
			index++;
		}
		return (p1 - p2);
	}
};