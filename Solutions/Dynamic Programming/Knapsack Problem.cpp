int t[1005][1005];
class Solution
{
public:
	Solution() {
		memset(t, -1, sizeof(t));
	}
	//Function to return max value that can be put in knapSack of capacity W.
	int knapSack(int W, int wt[], int val[], int n)
	{
		// Your code here
		//Base case
		if (n == 0 or W == 0) {
			return 0;
		}
		if (t[n][W] != -1) {
			return t[n][W];
		}
		if (wt[n - 1] <= W) {
			return t[n][W] = max((val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1)), knapSack(W, wt, val, n - 1)); \

		}
		return t[n][w] = knapSack(W, wt, val, n - 1);
	}
};