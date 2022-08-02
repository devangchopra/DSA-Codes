class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		//find non adjacent
		int x = flowerbed.size(), count = 0, i = 0;
		while (i < x) {
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
			        (i == x - 1 || flowerbed[i + 1] == 0)) {
				flowerbed[i] = 1;
				i++;
				count++;
			}
			if (count >= n) {
				return true;
			}
			i++;
		}

		return false;
	}
};


