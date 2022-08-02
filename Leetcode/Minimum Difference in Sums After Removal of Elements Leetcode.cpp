class Solution {
public:
#define ll long long
	long long minimumDifference(vector<int>& nums) {
		ll n = nums.size(), N = n / 3;
		vector<ll>pref(n, INT_MAX), suff(n, INT_MAX);

		priority_queue<ll>q;
		//Max heap

		//Scan from left to right for the prefix
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			q.push(nums[i]);

			//Pop the maximum element
			if (q.size() > N) {
				sum -= q.top();
				q.pop();
			}

			if (q.size() == N) {
				pref[i] = sum;
			}
		}
		sum = 0;
		while (q.empty() == false) {
			q.pop();
		}


		//Now for second half
		//Use min heap
		//Arre simple + -> -
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			q.push(-nums[i]);

			//Pop the maximum element
			if (q.size() > N) {
				sum -= q.top();
				q.pop();
			}

			if (q.size() == N) {
				suff[i] = sum;
			}
		}

		ll ans = INT_MAX;
		for (int i = 0; i < n - 1; i++) {
			if (suff[i+1] != INT_MAX and pref[i] != INT_MAX) {
				ans = min(ans, (pref[i] - suff[i + 1]));
			}
		}
		return ans;

	}
};




class Solution {
public:
 
    // Time Complexity:- O(nlogN)
    // Space Complexity:- O(n)
 
    #define ll long long
    #define inf LONG_LONG_MAX
    long long minimumDifference(vector<int>& nums) {
        // SumFirst - SumSecond --> minimised
        // SumFirst as min as possible
        // SumSecond as max as possible
 
        int n = nums.size(),N = n / 3;
        vector<ll> pref(n,inf),suff(n,inf);
 
        // pref[i] = sum of first N minimum elements from left side
        //suff[i] = sum of first N maximum elements from right side
 
        ll sum = 0;
        priority_queue<ll> q;
 
        for(int i=0;i<n;i++){
            sum += nums[i];
            q.push(nums[i]);
 
            // pop out maximum element
            if((int)q.size()>N){
                sum -= q.top();
                q.pop();
            }
 
            if((int)q.size()==N){
                pref[i] = sum;
            }
        }
 
        sum = 0;
        while(!q.empty()){
            q.pop();
        }
 
        for(int i=n-1;i>=0;i--){
            sum += nums[i];
            q.push(-nums[i]);
 
            // pop out minimum element
            if((int)q.size()>N){
                sum += q.top();
                q.pop();
            }
 
            if((int)q.size()==N){
                suff[i] = sum;
            }
        }
 
        ll ans = inf;
        for(int i=0;i<n-1;i++){
            if(pref[i]!=inf and suff[i+1]!=inf){
                ans = min(ans,pref[i]-suff[i+1]);
            }
        }
 
        return ans;
    }
};