//Probability of choosing a sub array cts whose sum is less than k

#include <bits/stdc++.h>
using namespace std;

long long int countSubarray(long long int arr[], long long int n, long long int k)
{
	long long int count = 0;

	for (long long int i = 0; i < n; i++) {
		long long int sum = 0;
		for (long long int j = i; j < n; j++) {
			if (sum + arr[j] < k) {
				sum = arr[j] + sum;
				count++;
			}
			else {
				break;
			}
		}
	}

	return count;
}

int main()
{
	long long int n;
	long long int k;
	cin >> n >> k;
	long long int arr[n];
	for (long long int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	long long int size = n;
	long long int count = countSubarray(arr, size, k);
	long long int total = (n * (n + 1)) / 2;

	cout << count << " " << total << endl;

	cout << ((count * 1.0) / total) << "\n";
}