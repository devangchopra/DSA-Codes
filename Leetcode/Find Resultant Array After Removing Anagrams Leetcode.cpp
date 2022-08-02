//See other approaches as well

class Solution {
public:
	vector<string> removeAnagrams(vector<string>& words) {
		vector<string>temp = words;
		for (auto& i : words) {
			sort(i.begin(), i.end());
		}
		string curr = words[0];
		vector<int>ind;
		ind.push_back(0);
		for (int i = 1; i < words.size(); i++) {
			//Seen before
			if (words[i] == curr) {
				continue;
			}
			else {
				curr = words[i];
				ind.push_back(i);
			}
		}
		vector<string>ans;
		for (auto& i : ind) {
			ans.push_back(temp[i]);

		}
        return ans;
	}
};