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
		if(root->data<data)
		{
			return hasData(data,root->right);
		}
		if(root->data>data)
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

    private:
    treenode* insertdata(int data,treenode* root)
    {
    	if(root==NULL) 
    	{
    		treenode* n=new treenode(data);
    		return n;
    	}

    	if(data<root->data)
    	{
    		root->left=insertdata(data,root->left);
    	}
    	else
    	{
    		root->right=insertdata(data,root->right);
    	}
    	return root;
    } 

	public:
	void insertdata(int data)
	{
		this->root=insertdata(data,this->root);
		//by "this" we make sure that the data member is accessed
	}

	private:
	treenode* deletedata(int data,treenode* node)
	{
		//Base Case
		if(node==NULL)
		{
			return NULL;
		}

		//Hypothesis and Induction
		if(node->data>data)
		{
			node->left=deletedata(data,node->left);
			return node;
		}
		if(node->data<data)
		{
			node->right=deletedata(data,node->right);
			//case null mei root update
			return node;
		}
		else    //data==node->data
 		{ 
			if(node->left==NULL and node->right==NULL)
			{
				delete node;
				return NULL;
			}

			else if(node->left==NULL)
			{
				treenode* temp=node->right;
				node->right=NULL; //break the connection
				delete node;
				return temp;
			}

			else if(node->right==NULL)
			{
				treenode* temp=node->left;
				node->left=NULL; //break the connection
				delete node;
				return temp;
			}
			else
			{
				//not left null not right null root to be deleted
				treenode* minnode=node->right;
				while(minnode->left!=NULL)
				{
					// minnode->left coz we need to find minimun
					minnode=minnode->left;
				}
				int rightmin=minnode->data;
				node->data=rightmin;
				node->right=deletedata(rightmin,node->right);
				return node;
			}
		}

	}
	public:
	void deletedata(int data)
	{

		this->root=deletedata(data,this->root);
	}
	private:
	void print(treenode* root)
	{
		if(root==NULL) return;
		cout<<root->data<<" ";
		if(root->left)
		{
			cout<<"L "<<" :"<<" "<<root->left->data<<" ";
		}
		if(root->right)
		{
			cout<<"R"<<" :"<<" "<<root->right->data<<" ";
		}
		cout<<endl;
		print(root->left);
		print(root->right);
	}
	public:
	void print()
	{
		print(this->root);
	}



};
int main()
{
	BST obj;
	obj.insertdata(10);
	obj.insertdata(5);
	obj.insertdata(20);
	obj.insertdata(7);
	obj.insertdata(3);
	obj.insertdata(15);
	obj.print();
	obj.deletedata(100);
	obj.deletedata(10);
	obj.print();
}	
