class NumArray {
	vector<int>v;
	vector<int>ps;
public:
	vector<int>nums;
	NumArray(vector<int>& nums) {
		v.resize(nums.size());
		for (int i = 0; i < v.size(); i++)
			v[i] = nums[i];
		fun();
		//once only
	}
	void fun()
	{		
		ps.resize(nums.size());
		int prefixSum = v[0];
		ps.push_back(prefixSum);

		for (int i = 1; i < v.size(); i++)
		{
			prefixSum+=v[i];
			ps.push_back(prefixSum);
		}
	}

	int sumRange(int left, int right) {
		return (left==0 ? ps[right] : (ps[right]-ps[left-1]));
	}
};