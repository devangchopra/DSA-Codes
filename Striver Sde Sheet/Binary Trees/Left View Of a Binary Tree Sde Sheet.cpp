vector<int> getLeftView(TreeNode<int> *root) {
	//    Write your code here
	vector<int>ans;
	if(!root){
		return ans;
	}
	queue<TreeNode<int>*>q;
	q.push(root);
	TreeNode<int>* temp;
	while (q.empty() == false) {
		int x = q.size();
		temp = q.front();		
		ans.push_back(temp->data);
		for (int i = 0; i < x; i++) {
			temp = q.front();
			q.pop();
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
	return ans;
}