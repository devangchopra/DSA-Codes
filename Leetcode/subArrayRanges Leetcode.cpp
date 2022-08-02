//This is TLE Solution
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>l;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int>v;
                for (int k = i; k <= j; k++) {
                    v.push_back(nums[k]);
                }
                sort(v.begin(), v.end());
                l.push_back(v);
            }
        }
        int ans = 0;
        for (auto& i : l) {
            for (auto& j : i) {
                cout << j << " ";
            } cout << endl;
            ans += i[i.size() - 1] - i[0];
        }
        return ans;

    }
};


//What if i do inside k loop
//Runtime Error after case 24 / 71 
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mini = INT_MAX; , maxi = INT_MIN;
                for (int k = i; k <= j; ++k) {
                    if(nums[k]>maxi){
                        maxi=nums[k];
                    }
                    if(nums[k]<mini){
                        mini=nums[k];
                    }

                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};