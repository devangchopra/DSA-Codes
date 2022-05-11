bool isSpecialBinaryTree(BinaryTreeNode<int>* root) {
	// Write your code here.
	//Level order traversal would work i guess
	queue<BinaryTreeNode<int>*>q;
	q.push(root);
	bool isit = true;
	BinaryTreeNode<int>* f;
	while (q.empty() == false) {
		f = q.front();
		int x = 0;
		q.pop();

		if (f->left) {
			q.push(f->left);
			x++;
		}
		if (f->right) {
			q.push(f->right);
			x++;
		}
		if (x == 0 or x == 2) {
			continue;
		}
		else {
			isit = false;
			break;
		}
	}
	return isit;
}