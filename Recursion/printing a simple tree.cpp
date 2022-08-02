#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class treenode
{
public:
	T data;
	vector<treenode<T>* > children;
	// children vector is storing pointers 
	// so accessing data of pointers :: ->
	

	treenode(T data)
	{
		this->data=data;
	}
};

void print_tree(treenode<int>* root)
{
	//IN THIS WE WILL USE RECURSION
	//generally no base case ...... for loop will handle

	if(root==NULL)  //handling the edge case
	{
		return;
	}

	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
		// vector ke andr address hai.... children ke...unka data 
		// root ke childrens 

	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		print_tree(root->children[i]);
		//recursion call
	}
}

int main()
{
	treenode<int>* root=new treenode<int>(1);
	treenode<int>* node1=new treenode<int>(2);
	treenode<int>* node2=new treenode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	print_tree(root);
}