class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int k = digits.size() - 1; k >= 0; --k) {
            if (digits[k] < 9) { 
                digits[k]++; 
                return digits; 
            } else {
                digits[k] = 0;
            }
        }
        digits[0] = 1, digits.push_back(0);
        return digits;
    }
};