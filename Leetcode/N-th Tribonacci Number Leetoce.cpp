// class Solution {
// public:
// 	int fun(int n) {
// 		if (n == 0) {
// 			return 0;
// 		}
// 		if (n == 1 or n == 2) {
// 			return 1;
// 		}
// 		return fun(n - 1) + fun(n - 2) + fun(n - 3);
// 	}
// 	int tribonacci(int n) {
// 		return fun(n);

// 	}
// };
//The above solution gives TLE
//So let us memooize this recursive solution
class Solution {
public:
	int fun(int n) {
		int a[n + 1];
		a[0] = 0;
		a[1] = 1;
		a[2] = 1;
		for (int i = 3; i < n + 1; i++) {
			a[i] = a[i - 1] + a[i - 2] + a[i - 3];
		}
		return a[n];
	}
	int tribonacci(int n) {
		return fun(n);
	}
};

