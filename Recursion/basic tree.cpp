#include<iostream>
#include "treenode.cpp"
using namespace std;
int main()
{
	treenode<int>* root = new treenode<int> (1);     // 1-2-3
	treenode<int>* node1 = new treenode<int> (2);
	treenode<int>* node2 = new treenode<int> (3);
	
	// creation of root and children
	//now we have to link

	root->children.push_back(node1); // as children is a vector
	root->children.push_back(node2);
	// as root is a pointer so . == ->

}