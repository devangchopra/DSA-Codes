class Solution {
public:
	bool checkValid(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int temp = n;
		for (int i = 0; i < n; i++) {
			unordered_set<int>s;
			for (int j = 0; j < n; j++) {
				s.insert(matrix[i][j]);
			}
			if (s.size() != n) {
				return false;
			}
		}
		for (int i = 0; i < n; i++) {
			unordered_set<int>s;
			for (int j = 0; j < n; j++) {
				s.insert(matrix[j][i]);
			}
			if (s.size() != n) {
				return false;
			}
		}
		return true;
	}
};


//Comments

class Solution {
	public boolean checkValid(int[][] matrix) {
// checking column wise
		for (int i = 0; i < matrix.length; i++) {
			HashSet set = new HashSet<>();
			for (int j = 0; j < matrix[0].length; j++) {
				set.add(matrix[i][j]);
			}
// checking with set size and row size
			if (set.size() != matrix[0].length) {
				return false;
			}
		}
// Checking row wise
		for (int i = 0; i < matrix.length; i++) {
			HashSet set = new HashSet<>();
			for (int j = 0; j < matrix[0].length; j++) {
				set.add(matrix[j][i]);
			}
// check set size and total matrix length
			if (set.size() != matrix.length) {
				return false;
			}
		}
		return true;
	}
}