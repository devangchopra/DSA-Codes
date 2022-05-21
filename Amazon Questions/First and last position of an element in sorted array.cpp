//First and  last position of an element in a sorted array
//O(n) Solution

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	// Write your code here.
	pair<int, int>ans;
	ans.first = -1;
	ans.second = -1;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x and flag == true) {
			ans.first = i;
			flag = false;
			continue;
		}
		if (arr[i] == x) {
			ans.second = i;
		}
	}
	if (ans.second != -1 and ans.first == -1) {
		ans.first = ans.second;
	}
	if (ans.first != -1 and ans.second == -1) {
		ans.second = ans.first;
	}
	return ans;
}


//O(log n) means that we want binary search

int firstOcc(vector<int> &arr, int n, int key) {
	int s = 0, e = n - 1;
	int mid = s + (e - s) / 2;
	int ans = -1;

	while (s <= e) {
		if (arr[mid] == key) {
			ans = mid;
			e = mid - 1;

		}
		else if (key < arr[mid]) {
			e = mid - 1;

		}
		else if (key > arr[mid]) {
			s = mid + 1;

		}
		mid = s + (e - s) / 2;
	}
	return ans;
}

int lastOcc(vector<int> &arr, int n, int key) {
	int s = 0, e = n - 1;
	int mid = s + (e - s) / 2;
	int ans = -1;

	while (s <= e) {
		if (arr[mid] == key) {
			ans = mid;
			s = mid + 1;

		}
		else if (key < arr[mid]) {
			e = mid - 1;

		}
		else if (key > arr[mid]) {
			s = mid + 1;

		}
		mid = s + (e - s) / 2;
	}
	return ans;
}

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	// Write your code here.
	pair <int, int> p;
	p.first = firstOcc(arr, n, x);
	p.second = lastOcc(arr, n, x);

	return p;
}


