#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int data;
	vector<TreeNode*>children;

	TreeNode(int data) {
		this->data = data;
	}
};

TreeNode* levelOrderInput() {
	int data;
	cout << "Enter Data" << endl;
	cin >> data;

	TreeNode* root = new TreeNode(data);
	queue<TreeNode*>pendingNodes;
	pendingNodes.push(root);

	while (pendingNodes.size() != 0) {
		TreeNode* f = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter Number of children of" << " " << f->data << endl;
		int x;
		cin >> x;

		for (int i = 0; i < x; i++) {
			int c;
			cout << "Enter Child Data" << " " << endl;
			cin >> c;
			TreeNode* child = new TreeNode(c);
			f->children.push_back(child);
			pendingNodes.push(child);
		}

	}
	return root;
}

void levelOrderPrint(TreeNode* root) {
	queue<TreeNode*>pendingNodes;
	pendingNodes.push(root);
	TreeNode* f;
	while (pendingNodes.empty() == false) {
		f = pendingNodes.front();
		pendingNodes.pop();
		cout << f->data << " " << " :" << " ";

		for (auto& i : f->children) {
			cout << i->data << " " << " ," << " ";
			pendingNodes.push(i);
		}
		cout << endl;
	}
	return;
}


TreeNode* takeinput() {
	int data;
	cout << "Enter Data" << endl;
	cin >> data;

	TreeNode* root = new TreeNode(data);

	int n ;
	cout << "Enter Number Of children";
	cin >> n;

	for (int i = 0; i < n; i++) {

		TreeNode* child = takeinput();
		root->children.push_back(child);
	}

	return root;
}

void printTree(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " " << ":";
	for (auto& i : root->children) {
		cout << i->data << " ";
	}
	cout << endl;
	for (auto& i : root->children) {
		printTree(i);
	}

	//Here explicity the for loop was working as a base case
	//but why to take risk
	//that's why we used the root == NULL condition
}

int main() {
	// TreeNode* root = new TreeNode(20);
	// TreeNode* child1 = new TreeNode(30);
	// TreeNode* child2 = new TreeNode(40);

	// root->children.push_back(child1);
	// root->children.push_back(child2);

	// //-> because of dynamic allocation
	// //Pointer name on symbol table which is not stack memory
	//Others are dynamic one which are on heap memory

	// for (auto& i : root->children) {
	// 	cout << i << " ";
	// }

	// cout << endl;

	// for (int i = 0; i < root->children.size(); i++) {
	// 	cout << root->children[i]->data << " ";
	// }

	TreeNode* root = levelOrderInput();
	levelOrderPrint(root);

}