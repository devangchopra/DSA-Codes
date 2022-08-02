
class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a , Job b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) {
        // your code here
        sort(arr, arr + n, comp);
        //Find the maximum deadline
        int md = INT_MIN;
        for (int i = 0; i < n; i++) {
            md = max(md, arr[i].dead);
        }
        //Initialize the array
        int brr[md+1];
        int ans = 0;
        int count = 0;
        memset(brr,-1,sizeof(brr));
        // for(int i=0;i<md;i++){
        //     cout<<brr[i]<<" ";
        // }cout<<endl;
        for (int i = 0; i < n; i++) {
            int x = arr[i].dead;
            for (int j = x; j > 0; j--) {
                if (brr[j] == -1) {
                    brr[j] = arr[i].profit;
                    ans += arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        vector<int>v;
        v.push_back(count);
        v.push_back(ans);
        return v;
    }
};