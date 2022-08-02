class Solution {
public:
	int maxPower(string s) {
		int ans = 0, temp = 1;
		char c = s[0];
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == c) {
				temp++;
			}
			else {
				c = s[i];
				ans=max(ans,temp);
				temp=1;

			}
		}
        ans=max(ans,temp);
        if(ans==0){return 1;}
		return ans;
	}
};