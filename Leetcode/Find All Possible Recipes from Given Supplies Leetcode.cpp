///**Correect this solution

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		vector<string>ans;
		unordered_set<string>s;
		vector<string>ownsupplies;
		for (auto& i : recipes) {
			s.insert(i);
		}
		for (auto& i : supplies) {
			s.insert(i);
		}
		bool canWe = true;
		for (int i = 0; i < recipes.size(); i++) {
			for (auto& j : ingredients[i]) {
				if (s.find(j) == s.end()) {
					canWe = false;
					break;
				}
			}
			if (canWe) {
				ans.push_back(recipes[i]);
			}
		}

		return ans;

	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<string>recipes = {"bread", "sandwich", "burger"};
	vector<vector<string>>ingredients = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
	vector<string>supplies = {"yeast", "flour", "meat"};
	Solution obj;
	obj.findAllRecipes(recipes, ingredients, supplies);
	// for (auto& i : ans) {
	// 	cout << i << " ";
	// }




	return 0;
}
