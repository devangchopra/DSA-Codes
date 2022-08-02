class Solution {
public:
    string orderlyQueue(string s, int k)
    {
        if (k == 1)
        {
            auto minchar = min_element(s.begin(), s.end());
            string ans = s;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == *minchar)
                {
                    string suffix = string(s.begin() + i, s.end());
                    string temp = suffix + string(s.begin(), s.begin() + i);
                    ans = min(temp, ans);
                }
            }

            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};