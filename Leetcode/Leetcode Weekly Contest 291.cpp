//Remove Digit From Number to Maximize Result

class Solution {
public:
	string removeDigit(string number, char digit) {
		vector<string>options;
		vector<int>positions;
		for (int i = 0; i < number.size(); i++) {
			if (number[i] == digit) {
				positions.push_back(i);
			}
		}

		for (auto& i : positions) {
			string temp = "";
			for (int j = 0; j < number.size(); j++) {
				if (j != i) {
					temp.push_back(number[j]);
				}
			}
			options.push_back(temp);
		}
		sort(options.begin(), options.end());
		return options[options.size() - 1];
	}
};


//Minimum Consecutive Cards to Pick Up
//75/78 Test Cases Passed
//because i am just considering 0 and 1 index and not updating
//again and again
class Solution {
public:
	int minimumCardPickup(vector<int>& cards) {
		unordered_map<int, vector<int>>m;
		for (int i = 0; i < cards.size(); i++) {
			m[cards[i]].push_back(i);
		}
		int ans = INT_MAX, temp = 0;
		for (auto &i : m) {
			if (i.second.size() >= 2) {
				temp = abs(i.second[0] - i.second[1]) + 1;
				ans = min(ans, temp);
			}

		}
		if (ans == INT_MAX) {
			return -1;
		}
		return ans;
	}
};

//Correct
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        vector<int> deck(1000007,-1);
        int cnt=INT_MAX;
        for(int i=0; i<cards.size(); i++) {
             if(deck[cards[i]]!=-1) cnt=min(cnt,i-deck[cards[i]]+1);
             deck[cards[i]]=i;
        }
       return cnt == INT_MAX ? -1 : cnt; 
    }
};