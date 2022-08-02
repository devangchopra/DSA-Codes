//Chaining Techinque
class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int count = 0, currChunkEnd = 0;
		for (int i = 0; i < arr.size(); i++) {

			currChunkEnd = max(currChunkEnd, arr[i]);
			if (currChunkEnd == i) {
				count++;
			}
		}

		return count;
	}
};