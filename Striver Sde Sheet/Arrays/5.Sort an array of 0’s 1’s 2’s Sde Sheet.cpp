//1
//O(nlogn)
class Solution {
public:
	void sortColors(vector<int>& nums) {
		sort(nums.begin(), nums.end());

	}
};

//2
//O(n) and O(k)
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int r = 0, b = 0, g = 0;
		for (auto& i : nums) {
			if (i == 0) {
				r++;
			}
			else if (i == 1) {
				b++;
			}
			else {
				g++;
			}
		}
		int index = 0;
		while (r--) {
			nums[index] = 0;
			index++;
		}
		while (b--) {
			nums[index] = 1;
			index++;
		}
		while (g--) {
			nums[index] = 2;
			index++;
		}

	}
};

//3

//Dutch National Flag Algorithm
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int low = 0, high = nums.size() - 1, mid = 0;
		while (mid <= high) {
			if (nums[mid] == 0) {
				swap(nums[low], nums[mid]);
				low++;
				mid++;
			}
			else if (nums[mid] == 1) {
				mid++;
			}
			else {
				swap(nums[high], nums[mid]);
				high--;
			}
		}

	}
};