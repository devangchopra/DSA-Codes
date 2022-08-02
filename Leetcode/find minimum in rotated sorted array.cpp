class Solution {
public:
	int findMin(vector<int>& nums) {

		int firstElement = nums[0];

		int pointOfInflection = -1;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				pointOfInflection = nums[i + 1];
				break;
			}
		}
		if (pointOfInflection == -1)
			return firstElement;
		return min(firstElement, pointOfInflection);

	}
};


class Solution {
public:
	int findMin(vector<int>& nums) {

		if (nums.size() == 1)
			return nums[0];

		int l = 0;
		int h = nums.size() - 1;

		if (nums[l] < nums[h])
		{
			//Already Sorted
			return nums[l];
		}


		//Else we have to apply modified version of binary search
		//To find point of inflection
		while (l <= h)
		{
			int mid = l + (h - l) / 2;

			//we say ok mid is point of inflection
			if (nums[mid] > nums[mid + 1])
				return nums[mid + 1];

			if (nums[mid - 1] > nums[mid])
				return nums[mid];

			if (nums[mid] > nums[0])
			{
				//Go to right
				l = mid + 1;
			}
			else
			{
				//Go to left
				h = mid - 1;
			}

		}

		return nums[l];
	}
};


-----------------------------
Check this as well

https://leetcode.com/discuss/explore/august-leetcoding-challenge-2021/1437426/find-minimum-in-rotated-sorted-array-all-approaches-c

