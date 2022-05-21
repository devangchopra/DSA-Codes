int f(int arr[], int n, int X) {
	int ans = -1;
	int s = 0, e = n-1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (arr[mid] == X) {
			e = mid - 1;
			ans = mid;
			//search space reduced to left halt to  find first occurence
		}
		//Rest same binary search code
		else if (arr[mid] < X) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}

int l(int arr[], int n, int X) {
	int ans = -1;
	int s = 0, e = n-1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (arr[mid] == X) {
			s = mid + 1;
			ans = mid;
			//search space reduced to right half to find the last occurence
		}
		//Rest same binary search code
		else if (arr[mid] < X) {
			s = mid + 1;
		}
		else {
			e = mid -1;
		}
	}
	return ans;
}

int countOccurences(int arr[], int n, int X)
{
	//Write your code here
	//if you are given that then array is sorted then use the binary search obviously
	int first_position = f(arr, n, X);
	int last_position = l(arr, n, X);
	if(first_position==-1 and last_position==-1){
		return 0;
	}
	return last_position - first_position +1;
}