vector <int> zigZagTraversal(Node* root)
{
	// Code here
	stack<Node*>s1;
	stack<Node*>s2;
	s1.push(root);
	vector<int>v;
	while(s1.size()!=0 or s2.size()!=0)
	{
	    while(s1.size()!=0)
	    {
    	    Node* temp=s1.top();
    	    s1.pop();
    	    v.push_back(temp->data);
    	    if(temp->left)
    	    {
    	        s2.push(temp->left);
    	    }
    	    if(temp->right)
    	    {
    	        s2.push(temp->right);
    	    }
	    }
	    while(s2.size()!=0)
	    {
	        Node* temp=s2.top();
    	    s2.pop();
    	    v.push_back(temp->data);
    	    if(temp->right)
    	    {
    	        s1.push(temp->right);
    	    }
    	    if(temp->left)
    	    {
    	        s1.push(temp->left);
    	    }
    	    
	    }

	}
	return v;
}