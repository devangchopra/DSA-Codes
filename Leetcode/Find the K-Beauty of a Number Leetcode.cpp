class Solution {
public:
	int divisorSubstrings(int num, int k) {
		string temp = to_string(num);
		list<char>l;
		string curr = "";
		int count = 0;
		for (int i = 0; i < temp.size(); i++) {
			l.push_back(temp[i]);
			if (l.size() == k) {
				for (auto& i : l) {
					curr += i;
				}
				
				l.pop_front();
				int x = stoi(curr);
				if (x != 0 and num % x == 0) {
					count++;
				}
				curr = "";
			}
		}
		return count;

	}
};