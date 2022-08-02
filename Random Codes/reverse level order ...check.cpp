vector<int> reverselevelorder(Treenode* root)
{
	if(root==NULL)
	{
		vector<int> v;
		return v;
	}
	queue<Treenode*>q;
	q.push(root);
	stack<Treenode*>s;
	v.push_back(root->data);
	while(q.empty()==false)
	{
		int n=q.size()
		while(n--)
		{
			Treenode* front=q.front();
			q.pop();
			s.push(front);
			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
		while(s.empty()==false)
		{
			Treenode* temp=s.top();
			s.pop();
			v.push_back(temp->data);
		}
	}
	return v;
}