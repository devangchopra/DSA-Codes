#include<bits/stdc++.h>
using namespace std;
int main() {
	int N; cin >> N;
	vector<int> S(N), T(N);
	for (int i = 0; i < N; i++)
		cin >> S[i];

	for (int i = 0; i < N; i++)
		cin >> T[i];

	vector<int> memo = T;

	for (int i = 0; i < N*2; i++)
		memo[(i + 1) % N] = min(memo[(i + 1) % N], memo[i % N] + S[i % N]);

	for (int ans : memo)
		cout << ans << endl;
}