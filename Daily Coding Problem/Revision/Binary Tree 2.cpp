class BinaryTreeNode {

public:

	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
		//By default pointer garbage ko pint krega
	}

	//Because of dynamic allocated memory
	//Deleting is also imp (large programmes)
	~BinaryTreeNode() {
		delete left;
		delete right;
	}

};

pair<int, int> heightDiameter(BinaryTreeNode* root) {
	if (!root) {
		pair<int, int>p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int, int>leftans = heightDiameter(root->left);
	pair<int, int>rightans = heightDiameter(root->right);

	int ld = leftans.second;
	int rd = rightans.second;

	int lh = leftans.first;
	int rh = rightans.first;

	int height = 1 + max(lh, rh);
	int diameter = max(lh + rh, max(ld, rd));
	pair<int, int>p;
	p.first = height;
	p.second = diameter;
	return p;
}

int height(BinaryTreeNode* root) {
	if (!root) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

bool isbalanced(BinaryTreeNode* root) {
	if (!root) {
		return true;
	}

	bool a = isbalanced(root->left);
	bool b = isbalanced(root->right);

	if (!(abs(height(root->left) - height(root->right)) <= 1)) {
		return false;
	}
	else {
		return a and b;
	}

}

//But again this function is having a time complexity of O(h*n)
//i.e. either o(nlogn) or O(n**2)

//So we can again get pair

//In such questions try to reduce the number of calls of a same function
//By doing the maximum calls work in one call

pair<bool, int> balacned(BinaryTreeNode* root) {
	if (!root) {
		pair<bool, int>p;
		p.first = true;
		p.second = 0;
		return p;
	}
	pair<bool, int>leftans = balacned(root->left);
	pair<bool, int>rightans = balacned(root->right);

	bool isleftbalanced = leftans.first;
	bool isrightbalanced = rightans.first;

	int leftheight = leftans.second;
	int rightheight = right.second;

	if (!(abs(leftheight - rightheight) <= 1)) {
		pair<bool, int>p;
		p.first = false;
		p.second = 1 + max(leftheight, rightheight);
		return p;
	}
	else {
		pair<bool, int>p;
		p.first = isleftbalanced and isrightbalanced;
		p.second = 1 + max(leftheight, rightheight);
		return p;
	}
}


BinaryTreeNode* deleteLeafNodes(BinaryTreeNode* root) {
	if (!root) {
		return NULL;
	}
	if (root->left == NULL and root->right == NULL) {
		return NULL;
		//Coz we want to delete
	}
	root->left = delete(root->left);
	root->right = delete(root->right);
	return root;
}

void zigzagtraversal(BinaryTreeNode* root){
	if(!root){
		return;
	}
	Stack<BinaryTreeNode*>s1;
	Stack<BinaryTreeNode*>s2;
	s1.push(root);
	while(s1.empty()==false or s2.empty()==false){

		if(s1.empty()==false){
			BinaryTreeNode* temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				s2.push(temp->left);
			}
			if(temp->right){
				s2.push(temp->right);
			}
		}
		else if(s2.empty()==false){
			cout<<endl;
			//Change of line
			BinaryTreeNode* temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->right){
				s1.push(temp->right);
			}
			if(temp->left){
				s1.push(temp->left);
			}
			
		}
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("1input.txt", "r", stdin);
	freopen("1output.txt", "w", stdout);
#endif

	BinaryTreeNode* root = levelOrderInput();
	cout << "inorder" << endl;
	inorder(root);
	cout << endl << "Postorder" << endl;
	postorder(root);
	cout << endl << "preorder" << endl;
	preorder(root);

}