class Solution {
public:
	int smallestRepunitDivByK(int k) {
		int unitdigit = k % 10;
		if (unitdigit == 0 or unitdigit == 2 or unitdigit == 4 or unitdigit == 6
		        or unitdigit == 8) {
			return -1;
		}
		int rem = 0;
		for (int i = 1; i <= k; i++) {
			rem = (rem * 10 + 1) % k;
			if (rem == 0) {
				return i;
			}
		}
		return -1;
	}
};