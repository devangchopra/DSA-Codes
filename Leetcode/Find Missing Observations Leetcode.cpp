#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int x = rolls.size(), y = 0;
		for (auto& i : rolls) {
			y += i;
		}
		int sum = (mean * (x + n) - y);
		std::vector<int> v;
		if (sum % n == 0 and (sum * 1.0) / n <= 6 and ((sum * 1.0) / n ) > 0) {
			for (int i = 0; i < n; i++) {
				v.push_back(sum / n);
			}
			return v;
		}
		else if ((sum * 1.0) / n > 6) {
			return v;
		}
		else if ((sum * 1.0) / n < 0) {
			return v;
		}
		int number = floor((sum * 1.0) / n);
		if (number == 0) {
			return v;
		}
		int proSum = sum - number * n;
		for (int i = 0; i < n; i++) {
			v.push_back(number);
		}
		for (int i = 0; i < n; i++) {
			if (v[i] < 6) {
				while (v[i]<6 and proSum > 0) {
					v[i]++;
					proSum--;
				}
			}
		}
		return v;
	}
};

int main() {
	Solution obj;
	vector<int> rolls = {4, 2, 2, 5, 4, 5, 4, 5, 3, 3, 6, 1, 2, 4, 2, 1, 6, 5, 4, 2, 3, 4, 2, 3, 3, 5, 4, 1, 4, 4, 5, 3, 6, 1, 5, 2, 3, 3, 6, 1, 6, 4, 1, 3};
	int mean = 2, n = 53;
	vector<int>ans = obj.missingRolls(rolls, mean, n);
	for (auto& i : ans) {
		cout << i << " ";
	} cout << endl;
}