class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream ss(s);
        string curr = "";
        while (ss >> curr) {
            bool ans = true;
            for (auto&i : curr) {
                if (isdigit(i)) {
                    continue;
                }
                else {
                    ans = false;
                }
            }
            if (ans) {
                cout << curr << " ";
            }
        } cout << endl;

        return false;
    }
};

