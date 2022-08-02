class Solution {
	int visit[100006];
	int maximum = INT_MIN;
public:

	void dfs(int index , int total , vector<int>& nums)
	{
		if (visit[index] == 1)
		{
			//Loop is complete
			maximum = max(maximum, total);
			return;
		}

		visit[index] = 1;
		dfs(nums[index], total + 1, nums);
	}


	int arrayNesting(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			if (visit[i] != 1)
			{
				dfs(i, 0, nums);
			}
		}

		return maximum;
	}
};

//To save space we can mark the visited integers in the original array as INT_MX
//bcoz range of integers will not reach int_max so we can do this
//Time complexity would remain same but space complexity would be optimized to O(1)