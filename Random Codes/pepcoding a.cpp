#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x, y, z, w;
	cin >> x >> y >> z >> w;

	int hour_ans = 0;
	int minute_ans = 0;

	int h = abs(x - z);
	int m = abs(y - w);

	hour_ans=min(h,24-h);
	minute_ans=min(m,60-m);

	int final_ans = hour_ans+minute_ans;

	cout<<final_ans<<endl;

	return 0;
}