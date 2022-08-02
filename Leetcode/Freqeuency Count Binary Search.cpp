#include <bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>& arr, int key) {
	int s = 0, e = arr.size() - 1, ans = 0;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (arr[mid] == key) {
			ans = mid;
			e = mid - 1;
		}
		else if (arr[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int upper_bound(vector<int>& arr, int key) {
	int s = 0, e = arr.size() - 1, ans = 0;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (arr[mid] == key) {
			ans = mid;
			s = mid + 1;
		}
		else if (arr[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int fun(vector<int>& arr, int key) {
	int lower_bound_ans = lower_bound(arr, key);
	int upper_bound_ans = upper_bound(arr, key);
	return (upper_bound_ans - lower_bound_ans) + 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<int>arr = {0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
	int key = 10;
	int ans = fun(arr, key);
	cout << ans << endl;
	return 0;
}