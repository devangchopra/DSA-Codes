#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int dp[n + 1];

int main()
{
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1;
		if (i - 2 >= 0)
		{
			dp[i] = dp[i] and dp[i - 2];
		}

		if (i - 3 >= 0)
		{
			dp[i] = dp[i] and dp[i - 3];
		}

		if (i - 4 >= 0)
		{
			dp[i] = dp[i] and dp[i - 4];
		}

		if (i - 5 >= 0)
		{
			dp[i] = dp[i] and dp[i - 5];
		}

		dp[i] = !dp[i];
	}
	cout << dp[n] << endl;
}

