class Solution {
public:
	int mostWordsFound(vector<string>& sentences) {
		int ans = INT_MIN;
		for (auto& i : sentences) {
			int count = 0;
			for (auto& j : i) {
				if (j == ' ') {
					count++;
				}
			}
			count++;
			ans=max(count,ans);
		}
		return ans;
	}
};