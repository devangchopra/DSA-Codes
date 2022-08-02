//Brtue Force

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>ans;
		ans.push_back({1});
		if (numRows == 1) {
			return ans;
		}
		ans.push_back({1, 1});
		if (numRows == 2) {
			return ans;
		}
		for (int i = 3; i <= numRows; i++) {
			vector<int>temp;
			temp.push_back(1);

			int n = ans.size();
			auto h = ans[n - 1];
			for (int i = 0; i <= h.size() - 2; i++) {
				temp.push_back(h[i] + h[i + 1]);
			}


			temp.push_back(1);
			ans.push_back(temp);
		}
		return ans;


	}
};

//Again O(n*2)
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> r(numRows);

		for (int i = 0; i < numRows; i++) {
			r[i].resize(i + 1);
			r[i][0] = r[i][i] = 1;

			for (int j = 1; j < i; j++)
				r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
		}

		return r;
	}
};

