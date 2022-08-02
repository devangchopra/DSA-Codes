//Brute but also O(1)
class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		string number = "123456789";
		int n = number.size();
		sttring temp = "";
		vector<int>ans;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				temp += number[i];
				int t = stoi(temp);
				if (t >= low and t <= high) {
					ans.push_back(temp);
				}
			}
			temp = "";
		}

		return ans;
	}
};

//BFS
//Better Solution
//O(1)
class Solution {
public:
	vector<int>ans;
	vector<int> sequentialDigits(int low, int high) {
		queue<int>q;
		for (int i = 1; i < 10; i++)
			q.push(i);
		while (q.size() > 0)
		{
			int curr = q.front(); q.pop();
			if (curr >= low && curr <= high)
				ans.push_back(curr);
			int next = curr * 10 + (curr % 10) + 1;
			if (curr % 10 < 9 && next <= high)
				q.push(next);
		}
		return ans;
	}
};


//Practice
class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int>ans;
		queue<int>q;

		for (int i = 1; i < 10; i++) {
			q.push(i);
		}
		while (q.empty() == false) {
			int curr = q.front();
			q.pop();

			if (curr >= low and curr <= high) {
				ans.push_back(curr);
			}

			int next = curr * 10 + (curr % 10) + 1;
			if (curr % 10 < 9 and next <= high) {
				q.push(next);
			}
		}

		return ans;
	}
};