#include<bits/stdc++.h>
using namespace std;
#include "header.h"
class BST
{
	treenode* root;  //Private
	public :

	//Constructor
	BST()
	{
		root=NULL;
	}
	~BST()
	{
		delete root;
	}
private:
	bool hasData(int data,treenode* root)
	{
		if(root==NULL) return false;
		if(root->data==data) return true;
		if(root->data<hasData)
		{
			return hasData(data,root->right);
		}
		if(root->data>hasData)
		{
			return hasData(data,root->left);
		}
		else
		{
			return false;
		}
	}
	public:
		bool hasData(int data)
		{
			//user will access this only
			return hasData(data,root);
 		}

}	
