#include <bits/stdc++.h>
using namespace std;

void fun() {
	vector<int>arr(4);
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}
	int count = 0;
	for (auto& i : arr) {
		if (i >= 10) {
			count++;
		}
	}
	cout << count << endl;
}

int main() {
	fun();
	return 0;
}