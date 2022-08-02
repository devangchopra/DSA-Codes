class Solution {
public:
	bool canReorderDoubled(vector<int>& arr) {

		uordered_map<int, int>m;
		//O(1)
		//Watch

		for (int i = 0; i < arr.size(); i++)
		{
			m[arr[i]]++;
		}

		//Ordered pairs
		sort(arr.begin(), arr.end());

		for (int i = 0; i < arr.size(); i++)
		{
			if (m[arr[i]] != 0 and m[arr[i] * 2] != 0)
			{
				m[arr[i]]--;
				m[arr[i] * 2]--;
			}
		}

		//Check Done
		for (auto p : m)
		{
			if (p.second != 0)
				return false;
		}

		return true;

	}
};