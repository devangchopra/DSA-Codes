#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int>&nums,int left,int right)
{
	int start=0;
	int end=0;
	int ans=0;

	int window_size=0;

	while(end<nums.size())
	{
		//element within the range
		if(nums[end]>=left and nums[end]<=right)
		window_size=end-start+1;

		//if element not in range
		else if(nums[end]>right)
		{
			window_size=0;
			start=end+1;
		}

		ans=ans+window_size;
		end++;
	}

	return ans;

}