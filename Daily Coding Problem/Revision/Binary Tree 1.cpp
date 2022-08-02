//Binary Trees
// It is a tree in which every node has maximum two chidlren
#include<bits/stdc++.h>
using namespace std;

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

void draft1() {

	BinaryTreeNode* node = new BinaryTreeNode(10);
	BinaryTreeNode* child1 = new BinaryTreeNode(20);
	BinaryTreeNode* child2 = new BinaryTreeNode(30);

	//Class members are obtained via a dot (.) operator
	//But since it is a pointer we will use (->) arrow operator here
	node->left = child1;
	node->right = child2;

	cout << node->data << " " << " : " << " " << node->left->data << " " << " , " << " "
	     << node->right->data << endl;
}

void basicPrint(BinaryTreeNode* root) {

	if (root == NULL) {
		return;
	}
	cout << root->data << endl;
	basicPrint(root->left);
	basicPrint(root->right);
}

void basicPrint1(BinaryTreeNode* root) {
	if (!root) {
		return;
	}
	cout << "Root" << " " << root->data << " ";
	if (root->left) {
		cout << "L" << " " << root->left->data << " ";
	}
	if (root->right) {
		cout << "R" << " " << root->right->data << " ";
	}
	cout << endl;
	basicPrint1(root->left);
	basicPrint1(root->right);
}

BinaryTreeNode* takeinput() {

	//But in this method you have to understand recurison

	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	BinaryTreeNode* root = new BinaryTreeNode(data);

	root->left = takeinput();
	root->right = takeinput();

	return root;
}

BinaryTreeNode* levelOrderInput() {

	int data;
	cin >> data;

	queue<BinaryTreeNode*>q;
	BinaryTreeNode* root = new BinaryTreeNode(data);
	q.push(root);

	BinaryTreeNode* temp = NULL;

	while (q.empty() == false) {
		temp = q.front();
		q.pop();
		int cd;
		cin >> cd;
		if (cd != -1) {
			BinaryTreeNode* leftc = new BinaryTreeNode(cd);
			temp->left = leftc;
			q.push(leftc);
		}
		int cd2;
		cin >> cd2;
		if (cd2 != -1) {
			BinaryTreeNode* rightc = new BinaryTreeNode(cd2);
			temp->right = rightc;
			q.push(rightc);
		}
	}

	return root;
}

void levelOrderPrint(BinaryTreeNode* root) {
	queue<BinaryTreeNode*>q;
	q.push(root);
	BinaryTreeNode* f = NULL;
	while (q.empty() == false) {
		f = q.front();
		q.pop();
		cout << f->data << " ";
		if (f->left) {
			cout << "L" << " " << f->left->data << " ";
			q.push(f->left);
		}
		if (f->right) {
			cout << "R" << " " << f->right->data << " ";
			q.push(f->right);
		}
		cout << endl;
	}
	return;
}

int countNuberOfNodes(BinaryTreeNode* root, int& count) {
	if (!root) {
		return count;
	}
	count++;
	countNuberOfNodes(root->left, count);
	countNuberOfNodes(root->right, count);
	return count;
}

void inorder(BinaryTreeNode* root) {
	if (!root) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(BinaryTreeNode* root) {
	if (!root) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(BinaryTreeNode* root) {
	if (!root) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int height(BinaryTreeNode* root) {
	if (!root) {
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}

int diameterOfBinaryTree(BinaryTreeNode* root) {
	if (!root) {
		return 0;
	}
	int option1 = height(root->left) + height(root->right);
	int option2 = diameterOfBinaryTree(root->left);
	int option3 = diameterOfBinaryTree(root->right);

	return max(option3, max(option2, option1));
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





/*
Remebeer in these kind of data structures you are too much
close to memory because of pointers and NULL
so always handle null properly
ex : if(root->left!=NULL){
	then work etc
}*/