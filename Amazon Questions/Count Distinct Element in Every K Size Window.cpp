//TLE
//passes 10/11 test cases

#define pb push_back
#include <bits/stdc++.h>

vector<int> countDistinctElements(vector<int> &arr, int k) {
	vector<int>v;
	list<int>l;
	unordered_set<int>s;
	for (int i = 0; i < k; i++) {
		l.pb(arr[i]);
		s.insert(arr[i]);
	}
	v.pb(s.size());
	for (int i = k; i < arr.size(); i++) {
		s.clear();//O(1)
		l.pop_front();
		l.pb(arr[i]);
		for (auto& i : l) {
			s.insert(i);
		}
		v.pb(s.size());
	}
	return v;
}


//Better Logic 
//O(n)

#define pb push_back
#include <bits/stdc++.h>

vector<int> countDistinctElements(vector<int> &arr, int k) {
	vector<int>v;

	unordered_map<int, int> map;
	for (int i = 0; i < k; i++)
		map[arr[i]] ++ ;

	v.pb(map.size());

	for (int i = k; i < arr.size(); i++) {
		// removing the (i-k)th element

		if (map[arr[i - k]] == 1)
			map.erase(arr[i - k]);
		else
			map[arr[i - k]]--;
		// Adding the nxt value in map

		map[arr[i]]++;

		v.pb(map.size());
	}
	return v;
}
