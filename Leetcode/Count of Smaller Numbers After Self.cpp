#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll 					long long int
#define ld 					long double
#define mod 				1e9+7
#define ps(x,y)   			fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>> 

#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

    	vector<int> output(nums.size() , 0);

    	ordered_multiset s;

    	int n=nums.size();

    	s.insert(nums[n-1]);

    	for(int i = n-2 ; i >= 0 ; i--){
            
            int cnt = s.order_of_key(nums[i]);
        
            s.insert(nums[i]);

            output[i] = cnt;
            
        }
        
        return output;
        
    }
};