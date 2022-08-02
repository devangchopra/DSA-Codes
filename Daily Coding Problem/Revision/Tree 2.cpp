#include <bits/stdc++.h>
using namespace std;

class Treenode {
public:

	int data;
	vector<Treenode*>children;

	Treenode(int data) {
		this->data = data;
	}

	~Treenode() {
		for (auto& i : children) {
			delete(i);
		}
	}
};

Treenode* takeinput() {
	int data;
	cin >> data;
	Treenode* root = new Treenode(data);

	queue<Treenode*>q;
	q.push(root);
	Treenode* node;
	while (q.empty() == false) {
		node  = q.front();
		q.pop();

		int cn;
		cin >> cn;

		for (int i = 0; i < cn; i++) {
			int n;
			cin >> n;
			Treenode* child = new Treenode(n);
			node->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}

void printTree(Treenode* root) {
	queue<Treenode*>q;
	q.push(root);
	Treenode* f;
	while (q.empty() == false) {
		f = q.front();
		q.pop();
		cout << f->data << " : ";
		for (auto& i : f->children) {
			cout << i->data << " " << " , " << " ";
			q.push(i);
		}
		cout << endl;
	}
	return;
}

int countnodes(Treenode*root, int x) {
	//Travel the  tree
	if (root == NULL) {
		return 0;
	}
	int ans = 0;
	for (auto& i : root->children) {
		ans += countnodes(i, x);
	}
	if (root->data > x) {
		return ans + 1;
	}
	return ans;

}

// int maxDepth(Node* root) {
// 	if (root == NULL) {
// 		return 0;
// 	}
// 	queue<Node*>q;
// 	int ans = 0;
// 	q.push(root);
// 	Node* f;
// 	while (q.empty() == false) {
// 		ans++;
// 		int x = q.size();
// 		for (int i = 0; i < x; i++) {
// 			f = q.front();
// 			q.pop();
// 			for (auto&i : f->children) {
// 				q.push(i);
// 			}
// 		}

// 	}
// 	return ans;
// }

void printAtLevelK(Treenode* root, int k) {
	queue<Treenode*>q;
	int ans = 0;
	q.push(root);
	Treenode* f;
	while (q.empty() == false) {
		ans++;
		int x = q.size();
		if (ans == k) {
			for (int i = 0; i < x; i++) {
				f = q.front();
				cout << f->data << " ";
				q.pop();
				for (auto&i : f->children) {
					cout << i->data << " ";
				}
			}

		}
		else {
			for (int i = 0; i < x; i++) {
				f = q.front();
				q.pop();
				for (auto&i : f->children) {
					q.push(i);
				}
			}
		}


		if (ans >= k) {
			break;
		}
	}
}

void printAtKRecursive(Treenode* root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data;
	}
	for (auto& i : root->children) {
		printAtKRecursive(i, k - 1);
	}

}

int numberOfLeafNodes(Treenode* root) {
	if (root == NULL) {
		return 0;
	}
	int ans = 0;
	if (root->children.size() == 0) {
		return 1;
	}
	for (auto&i : root->children) {
		ans += numberOfLeafNodes(i);
	}
	return ans;
}

void preorder(Treenode* root) {
	if (!root) {
		return;
	}
	cout << root->data << " ";
	for (auto& i : root->children) {
		preorder(i);
	}
	return;
}

void postorder(Treenode* root) {

	if (!root) {
		return;
	}

	for (auto& i : root->children) {
		postorder(i);
	}
	cout << root->data << " ";
	return;
}


int main() {
	Treenode* root = takeinput();
	//printTree(root);
	cout << " preorder" << endl;
	preorder(root);
	cout << "postorder" << endl;
	postorder(root);
}