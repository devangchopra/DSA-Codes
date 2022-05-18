bool solve(TreeNode<int>*T, TreeNode<int>* S) {
	if (!T and !S) {
		return true;
	}

	if ((!T and S) or (T and !S) or (T->val != S->val)) {
		return false;
	}

	//Now check subtrees are also same or not
	return solve(T->left, S->left) and solve(T->right, S->right);
}

bool isSubtree(TreeNode<int> *T, TreeNode<int> *S) {
	// Write your code here.
	if (!T) {
		return false;
	}

	bool opn1 = solve(T, S);
	//overlap
	bool opn2 = solve(T->left, S);
	bool opn3 = solve(T->right, S);
	//present in either of subtree
	return opn1 or opn2 or opn3;
}