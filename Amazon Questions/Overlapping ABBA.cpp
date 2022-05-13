#include <bits/stdc++.h>

bool findOverlap(string &s) {
	// Write your code here.
	//two no overlapping ab and ba
	int AB = 1, BA = 1;
	queue<char>q;
	for (auto& i : s) {
		q.push(i);
	}
	string temp = "";
	while (q.empty() == false) {
		char c = q.front();
		q.pop();
		temp.push_back(c);
		if(q.empty()){
		    break;
		}
		char d = q.front();
		q.pop();
		temp.push_back(d);
		if (temp == "AB") {
			AB--;
			temp = "";
			continue;
		}
		else if (temp == "BA") {
			BA--;
			temp = "";
			continue;
		}
		temp="";
	}

	if (AB <= 0 and BA <= 0) {
		return true;
	}
	return false;
}