class Solution {
public:
	long long smallestNumber(long long num) {
		if (num == 0) {
			return 0;
		}
		long long temp = abs(num);
		long long x = 0, size = 0;
		vector<long long>v;
		while (temp != 0) {
			size++;
			x = temp % 10;
			temp = temp / 10;
			v.push_back(x);
		}
		if (num > 0) {
			sort(v.begin(), v.end());
		}
		else {
			sort(v.begin(), v.end(), greater<long long>());
		}

		long long ans = 0;
		size--;

		long long x1 = -1;
		while (v[0] == 0) {
			x1++;
			if (v[x1] == 0) {
				continue;
			}
			swap(v[0], v[x1]);
		}


		for (auto & i : v) {
			ans += pow(10, size) * i;
			size--;
		}

		if (num < 0) {
			ans = -(ans);
		}
		return ans;



	}
};