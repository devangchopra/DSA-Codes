//Naive Solution


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//1 : Left
//0 : Right
//True means iska koi parent nhi hai
class Solution {
public:
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		TreeNode* root = NULL;
		unordered_map<int , pair<TreeNode*, bool>>m;
		for (auto& v : descriptions) {

			TreeNode* n;
			if (m.find(v[0]) == m.end()) {
				n = new TreeNode(v[0]);
				m.insert({v[0], {n, true}});
			}

			else {
				n = m[v[0]].first;
			}


			if (m.find(v[1]) == m.end()) {
				TreeNode* c = new TreeNode(v[1]);
				m.insert({v[1], {c, false}});

				if (v[2] == 0) {
					n->right = c;
				}
				else {
					n->left = c;
				}
			}

			else {
				//cout << "I am here" << " " << v[1] << endl;
				m[v[1]].second = false;
				//Iska parent aa gya hai
				TreeNode* temp = m[v[1]].first;

				if (v[2] == 0) {
					n->right = temp;
				}
				else {
					n->left = temp;
				}
			}

		}

		// for (auto& i : m) {
		// 	cout << i.first << " " << i.second.second << endl;
		// }
		for (auto& i : m) {
			if (i.second.second == true) {
				root = i.second.first;
				break;
			}
		}
		return root;

	}
};