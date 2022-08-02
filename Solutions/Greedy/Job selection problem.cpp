/*
struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        
        bool done[n]={0};
        int day=0;
        int profit=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead)-1;j>=0;j--)
            {
                if(done[j]==false)
                {
                    day+=1;
                    profit+=arr[i].profit;
                    done[j]=true;
                    break;
                }
            }
        }
        vector<int>v;
        v.push_back(day);
        v.push_back(profit);
        return v;
    } 
};