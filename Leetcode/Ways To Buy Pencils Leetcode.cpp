class Solution {
public:
	long long waysToBuyPensPencils(int total, int cost1, int cost2) {
		long long ans = 1;
		if (cost2 > total and cost1 > total) {
			return ans;
		}

		if (cost1 > total) {
			ans += floor(total * 1.0 / cost2);
			return ans;
		}

		if (cost2 > total) {
			ans += floor(total * 1.0 / cost1);
			return ans;
		}

		//Negotiate
		int x = total / cost1, temp = 0;
		for (int i = 0; i <= x; i++) {
			temp = total - cost1 * i;
			ans += temp / cost2;
		}

		return ans;

	}
};