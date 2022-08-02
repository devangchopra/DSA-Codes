vector<int> getTopView(TreeNode<int> *root) {
	
	vector<int>ans;
	if (!root) {
		return ans;
	}
	// Write your code here.
	map<int, int>m;
	queue<pair<TreeNode<int>*, int>>q;
	q.push({root, 0});
	TreeNode<int>* temp;
	int h;
	while (q.empty() == false) {
		temp = q.front().first;
		h = q.front().second;
		if (!m[h]) {
			m[h] = temp->val;
		}
		q.pop();
		if (temp->left) {
			q.push({temp->left, h - 1});
		}
		if (temp->right) {
			q.push({temp->right, h + 1});
		}
	}
	for (auto& i : m) {
		ans.push_back(i.second);
	}
	return ans;
}