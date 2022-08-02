class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()==0)
            return 0;
        
        vector<int>left;
        vector<int>right;

        int a = height[0];
        for(int i=0;i<height.size();i++)
        {
        	a = max(a,height[i]);
        	left.push_back(a);
        }

        int b = height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--)
        {
        	b = max(b,height[i]);
        	right.push_back(b);
        }
        
        reverse(right.begin(),right.end());

        int ans = 0;
        for(int i=0;i<height.size();i++)
        {
        	ans+=min(left[i],right[i])-height[i];
        }

        return ans;

    }
};