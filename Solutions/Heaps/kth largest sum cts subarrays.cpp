#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//max heap
	priority_queue<int>pq;

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int temp = arr[i];
		sum += temp;
		pq.push(temp);
		for (int j = i + 1; j < n; j++)
		{
			sum += arr[j];
			pq.push(sum);
		}

		sum = 0;
	}

	int p = 0;
	while (p < k - 1)
	{
		pq.pop();
		p++;
	}

	cout << pq.top();

}