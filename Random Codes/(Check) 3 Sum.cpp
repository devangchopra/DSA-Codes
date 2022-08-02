class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>>ans;
        
        //starting pointer
        for(int i=0;i<arr.size()-2;i++)
        {
            if(i==0 or (i>0 and arr[i]!=arr[i-1]))
            {
                int low=i+1 , high=arr.size()-1 , sum=0-arr[i]; //-a --> (b+c)
                
                while(low<high)
                {
                    if(arr[low]+arr[high]==sum)
                    {
                        vector<int>temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[low]);
                        temp.push_back(arr[high]);
                        ans.push_back(temp);
                        
                        while(low<high and arr[low]==arr[low+1])
                        {
                            low++;
                        }
                        while(low<high and arr[high]==arr[high-1])
                        {
                            high--;
                        }
                        
                        low++;
                        high--;
                        
                        //equality both move
                    }
                    
                    else if(arr[low]+arr[high]<sum)
                    {
                        low++;
                    }
                    
                    else
                    {
                        high--;
                    }
                }
                
            }
        }
        return ans;
    }
};