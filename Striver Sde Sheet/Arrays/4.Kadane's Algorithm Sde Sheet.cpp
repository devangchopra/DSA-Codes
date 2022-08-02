//1

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = 0, maxi = nums[0];
		for (auto& i : nums) {
			ans += i;
			maxi = max(ans, maxi);
			if (ans < 0) {
				ans = 0;
			}
		}
		return maxi;
	}
};


//2

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int contigious_sum = 0, i, peak = nums[0];
		for (i = 0; i < nums.size(); i++) {
			contigious_sum += nums[i];
			if (contigious_sum > peak) {
				peak = contigious_sum;
				if (contigious_sum < 0) {
					contigious_sum = 0;
				}
			}
			else if (contigious_sum < 0) {
				contigious_sum = 0;
			}
		}
		return peak;
	}
};


//3

//To print the sub array as well

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int>r;
		int ans = 0, maxi = nums[0], s = 0;
		for (int i=0;i<nums.size();i++) {
			ans += nums[i];
			if (ans > maxi) {
				maxi = ans;
                r.clear();
				r.push_back(s);
				r.push_back(i);
			}
			if (ans < 0) {
				r.clear();
				s = i + 1;
				ans = 0;
			}
		}
        
        for(int i=r[0];i<=r[1];i++){
            cout<<nums[i]<<" ";
        }
        
		return maxi;
	}
};
