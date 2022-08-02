#include<bits/stdc++.h>
using namespace std;
#include"header.h"

BinaryTreeNode* buildtreehelper(int in[],int pre[],int ins,int ine,int pres , int pree)
{
    if(ins>ine)
    {
        return NULL;
    }

    int rootdata=pre[pres];

    int rootindex=-1;
    for (int i=ins;i<=ine;i++)
    {
        if(in[i]==rootdata)
        {
            rootindex=i;
            break;
            //assuming that i do not have any duplicates in my tree
        }
    }

    int lins=ins;
    int line=rootindex-1;
    int lpres=pres+1;
    int lpree=line-lins+lpres;

    int rpres=lpree+1;
    int rpree=pree;
    int rins=rootindex+1;
    int rine=ine;

    BinaryTreeNode* root=new BinaryTreeNode(rootdata);
    root->left=buildtreehelper(in,pre,lins,line,lpres,lpree);
    root->right=buildtreehelper(in,pre,rins,rine,rpres,rpree);

    return root;
}
BinaryTreeNode* buildtree(int in[],int pre[],int size)
{
    return buildtreehelper(in ,pre ,0,size-1,0,size-1);
}

void printtree(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<" "<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<" "<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
int main()
{
    int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};
    BinaryTreeNode* root= buildtree(in , pre ,9);
    printtree(root);
}
