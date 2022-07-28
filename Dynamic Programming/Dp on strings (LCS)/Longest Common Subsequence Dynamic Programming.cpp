#include <bits/stdc++.h>
#define ll long long int
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int lcs(string s1, string s2, int i, int j) {

	//Base Case

	if (i == s1.size() or j == s2.size() ) {
		return 0;
	}
	if (s1[i] == s2[j]) {
		return 1 + lcs(s1, s2, i + 1, j + 1);
	}

	int choice_1 = lcs(s1, s2, i + 1, j);
	int choice_2 = lcs(s1, s2, i, j + 1);


	return max(choice_1, choice_2);

}

//Top Down
int lcs_td(string s1, string s2, int i, int j, vector<vector<int>>& dp) {

	if (i == s1.size() or j == s2.size() ) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s1[i] == s2[j]) {
		return dp[i][j] = 1 + lcs_td(s1, s2, i + 1, j + 1, dp);
	}

	int choice_1 = lcs_td(s1, s2, i + 1, j, dp);
	int choice_2 = lcs_td(s1, s2, i, j + 1, dp );


	return dp[i][j] = max(choice_1, choice_2);


}


int main() {

	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;

	cout << lcs(s1, s2, 0, 0) << endl;
	//lcs(string s1,string s2, ith index for s1 , jth index for s2)


	int n = s1.size();
	int m = s2.size();

	vector<vector<int>>dp(n, vector<int>(m, -1));
	cout << lcs_td(s1, s2, 0, 0, dp) << endl;
}