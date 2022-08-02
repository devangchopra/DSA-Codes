vector<int> bottomView(BinaryTreeNode<int> * root) {
	vector<int>ans;
	if (!root) {
		return ans;
	}
	// Write your code here.
	map<int, int>m;
	queue<pair<BinaryTreeNode<int>*, int>>q;
	q.push({root, 0});
	BinaryTreeNode<int>* temp;
	int h;
	while (q.empty() == false) {
		temp = q.front().first;
		h = q.front().second;
		q.pop();
		m[h] = temp->data;

		if (temp->left) {
			q.push({temp->left, h - 1});
		}
		if (temp->right) {
			q.push({temp->right, h + 1});
		}
	}
	for (auto& x : m) {
		ans.push_back(x.second);
	}
	return x;

}