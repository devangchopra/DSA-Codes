class Solution {
public:
	int findMiddleIndex(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return 0;
		vector<int> prefixLeft;
		vector<int> prefixRight;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
			prefixLeft.push_back(sum);
		}
		sum = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			sum += nums[i];
			prefixRight.push_back(sum);
		}
		int index = -1;
        reverse(prefixRight.begin(),prefixRight.end());
		for (int i = 0; i < n; i++)
		{
			if (prefixLeft[i] == prefixRight[i])
			{
				index = i;
				break;
			}
		}

		return index;
	}