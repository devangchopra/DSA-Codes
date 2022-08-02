pair<int,bool> balanced(Node* root)
{
	//Base Case
	if(root==NULL)
	{
		pair<int,bool>p;
		p.first=0;
		p.second=true;
		return p;
	}

	//Hypothesis 
	//I have these things ...can i make the ans
	pair<int,bool> leftans=balanced(root->left);
	pair<int,bool> rightans=balanced(root->right);

	int leftheight=leftans.first;
	bool isleft=leftans.second;

	int rightheight=rightans.first;
	bool isright=rightans.second;

	//Induction or Small Calculation
	int finalheight=1+max(leftheight,rightheight);
	pair<int,bool>p;
	p.first=finalheight;
	if(isleft and isright)
	{
		if(abs(leftheight-rightheight)<=1)
		{
			p.second=1;
		}
	}
	else{
		p.second=0;
	}
	return p;
}