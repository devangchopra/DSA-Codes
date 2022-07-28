int longestBitonicSequence(vector<int>& arr, int n) {
    // Write your code here.
    vector<int>dplr(n, 1);
    vector<int>dprl(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] and 1 + dplr[j] > dplr[i]) {
                dplr[i] = 1 + dplr[j];
            }
        }
    }

    //Right to left

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (arr[i] > arr[j] and 1 + dprl[j] > dprl[i]) {
                dprl[i] = 1 + dprl[j];
            }
        }
    }

    vector<int>bitonic(n, 0);

    for (int i = 0; i < n; i++) {
        bitonic[i] = dprl[i] + dplr[i] - 1;
    }

    int ans = INT_MIN;

    for (auto & i : bitonic) {
        ans = max(ans, i);
    }

    return ans;
}

