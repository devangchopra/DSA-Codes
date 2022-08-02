#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<vector<int>>& nums) {
		int n = nums.size();
		unordered_map<int, int>m;
		unordered_set<int>temp;

		for (auto& v : nums) {
			for (auto& i : v) {
				temp.insert(i);
			}
			for (auto& i : temp) {
				m[i]++;
			}
			temp.clear();
		}

		vector<int>ans;
		for (auto& i : m) {
			if (i.second == n) {
				ans.push_back(i.first);
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};

//Without Set Would Also Work

class Solution {
public:
	vector<int> intersection(vector<vector<int>>& nums) {
		int n = nums.size();
		unordered_map<int, int>m;

		for (auto& v : nums) {
			for (auto& i : v) {
				m[i]++;
			}
		}

		vector<int>ans;
		for (auto& i : m) {
			if (i.second == n) {
				ans.push_back(i.first);
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};




//Wrong
//Second Question
//circles = [[2,2,2],[3,4,1]]
class Solution {
public:
	int countLatticePoints(vector<vector<int>>& circles) {
		set<pair<int, int>>points;

		pair<int, int>start;
		pair<int, int>end;

		for (auto& v : circles) {
			//Left Most point = {v[0]-v[2],v[1]};
			//Right Most Point = {v[0]+v[2],v[1]};
			//Bottom Point = {v[0],v[1]-v[2]};
			//Top most point = {v[0],v[1]+v[2]};

			//Iterate and add using euclidean

			//Left to Right
			start = {v[0] - v[2], v[1]};
			end = {v[0] + v[2], v[1]};

			while (start.first <= end.first) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.first++;
			}
			start = {v[0] - v[2], v[1]};
			while (start.second <= end.second) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.second++;
			}

			start = {v[0] - v[2], v[1]};

			while (start.first <= end.first and start.second <= end.second) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.first++;
				start.second++;
			}

			//Bottom To Top
			start = {v[0], v[1] - v[2]};
			end = {v[0], v[1] + v[2]};

			while (start.first <= end.first) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.first++;
			}

			while (start.second <= end.second) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.second++;
			}
		}

		for (auto& i : points) {
			cout << i.first << " " << i.second << endl;
		}
		return points.size();
	}
};



class Solution {
public:
	int countLatticePoints(vector<vector<int>>& circles) {
		set<pair<int, int>>points;

		pair<int, int>start;
		pair<int, int>end;

		for (auto& v : circles) {
			//Left Most point = {v[0]-v[2],v[1]};
			//Right Most Point = {v[0]+v[2],v[1]};
			//Bottom Point = {v[0],v[1]-v[2]};
			//Top most point = {v[0],v[1]+v[2]};

			//Iterate and add using euclidean

			//Left to Right
			start = {v[0] - v[2], v[1]};
			end = {v[0] + v[2], v[1]};

			while (start.first <= end.first) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.first++;
			}
			start = {v[0] - v[2], v[1]};

			while (start.second <= end.second) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.second++;
			}
			start = {v[0] - v[2], v[1]};

			while (start.second <= end.second and start.first <= end.first) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.first++;
				start.second++;
			}



			//Bottom To Top
			start = {v[0], v[1] - v[2]};
			end = {v[0], v[1] + v[2]};

			while (start.first <= end.first) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.first++;
			}
			start = {v[0], v[1] - v[2]};
			while (start.second <= end.second) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.second++;
			}

			start = {v[0], v[1] - v[2]};
			while (start.second <= end.second and start.first <= end.first) {

				//Distance  = sqrt((x1-x2)**2+(y1-y2)**2)
				int a = abs(start.first - v[0]);
				int b = abs(start.second - v[1]);
				a = a * a;
				b = b * b;

				float c = sqrt(a + b);
				cout << start.first << " " << start.second << " " << c << " " << endl;
				if (c <= v[2]) {
					points.insert(start);
				}
				start.first++;
				start.second++;
			}
		}

		// for (auto& i : points) {
		// 	cout << i.first << " " << i.second << endl;
		// }
		return points.size();
	}
};



class Solution {
public:
	int countLatticePoints(vector<vector<int>>& circles) {
		set<pair<int, int>>points;

		pair<int, int>start;
		pair<int, int>end;


		for (auto& v : circles) {
			start = {0, 0};
			end = {v[0] + v[2], v[1]};


		}
		return points.size();
	}
};










int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	Solution obj;


}