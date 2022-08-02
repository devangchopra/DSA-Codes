class Solution {
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        // Your code here
        sort(arr, arr + n);
        sort(dep, dep + n);
        int i = 1, j = 0;
        //First train already arrived
        int ans = INT_MIN, platform_needed = 1;
        while (i < n and j < n) {
            if (arr[i] <= dep[j]) {
                i++;
                platform_needed++;
            }
            else {
                platform_needed--;
                j++;
            }
            ans = max(ans, platform_needed);
        }
        return ans;
    }
};