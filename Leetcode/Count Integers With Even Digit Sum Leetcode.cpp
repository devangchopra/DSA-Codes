class Solution {
public:
	int sum(int i) {
		int s = 0, x = 0;
		while (i != 0) {
			x = i % 10;
			s += x;
			i = i / 10;
		}
		return s;
	}
	int countEven(int n) {
		int count = 0;
		for (int i = 2; i <= n; i++) {
			if (sum(i) % 2 == 0) {
				count++;
			}
		}
        return count;
	}
};