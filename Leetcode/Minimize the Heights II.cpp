class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        //Current smallest and current largest
        int mini, maxi;

        for (int i = 0; i < n - 1; i++)
        {
            mini = min(smallest, arr[i + 1] - k);
            maxi = max(largest, arr[i] + k);
            if (mini < 0)
                continue;
            ans = min(ans, maxi - mini);
        }

        return ans;


    }
};