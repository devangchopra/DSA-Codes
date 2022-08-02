class Solution {
public:
    int fxn(vector<int>& heights) {
        //If we observe carefully we will know that we have to include atleast one rectangle
        //So calculate ans for each bar :( Right Limit - Left Limit + 1 ) * Height [i];
        int n = heights.size();
        if (n == 1) {
            return heights[0];
        }

        vector<int>left(n);
        vector<int>right(n);

        stack<int>s;
        //Traverse from left to right
        for (int i = 0; i < n; i++) {
            if (s.empty() == true) {
                left[i] = 0;
                //we can go till first element
                s.push(i);
                //this has the potential to become the limit
            }
            else {
                while (s.empty() == false and heights[s.top()] >= heights[i]) {
                    //<= because we are adding 1
                    s.pop();
                }
                left[i] = s.empty() ? 0 : s.top() + 1;
                s.push(i);
            }
        }

        //Clear the stack
        while (s.empty() == false) {
            s.pop();
        }

        //Calculating the right limit i.e. the index upto which we can extend our right
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty() == true) {
                right[i] = n - 1;
                //We can go till lastt
                s.push(i);
            }
            else {
                while (s.empty() == false and heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                right[i] = s.empty() ? n - 1 : s.top() - 1;
                s.push(i);
            }
        }

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            ans = max(ans, (((right[i] - left[i]) + 1) * heights[i]));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        //Convert the char matrix to integer matrix
        int n = matrix.size(), m = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>>v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[i][j] = matrix[i][j] == '1' ? 1 : 0;
            }
        }

        vector<vector<int>>hist(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            bool cnt = true;
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    hist[i][j] = v[i][j];
                }
                else {

                    cnt = false;
                    break;
                }
            }
            if (cnt == false) {
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) {
                    hist[i][j] = 0;
                    continue;
                }
                else {
                    hist[i][j] = 1 + hist[i - 1][j];
                }
            }
        }

        //Select each row and find the maximum area
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            vector<int>temp;
            for (int j = 0; j < m; j++) {
                temp.push_back(hist[i][j]);
            }
            int temp1 = fxn(temp);
            ans = max(ans, temp1);
        }
        return ans;

    }
};