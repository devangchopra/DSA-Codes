class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        
        int n =arr.size();

        vector<int> v;

        for(int i=0;i<n;i++) if(arr[i]) v.push_back(i);

        int cnt = v.size();

    	if(cnt ==0)
    	{
    		return {0,n-1};
    	}
    	if(cnt%3!=0)
    	{
    		return {-1,-1};
    	}
    	int s = v[0];
    	int t = v[(cnt/3)];
    	int u = v[(cnt/3)*2];

    	while(u<n and arr[s]==arr[t] and arr[t]==arr[u])
    	{
    		s++;
    		t++;
    		u++;
    	}

    	if(u==n)
    	{
    		return {s-1,t};
    	}
    	return{-1,-1};
    	
    }
};