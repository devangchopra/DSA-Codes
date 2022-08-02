#include<iostream>
#include<vetor>
using namespace std;
template <typename T>

class treenode
{
public:
	T data;
	// node contains data and vector of addresses of children
	vector<treenode<T>*> children;
	// vector<treenode *> children ; will also work .... it will assume data type of vector to be T
	// data type of children = data type of parent

	treenode(T data)
	{
		this->data=data;
	}
};