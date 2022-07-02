/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>


vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int>ans;
    if(!root){
        return ans;
    }
    
    queue<BinaryTreeNode<int>*>q;
    q.push(root);

    //BFS
    while(q.empty()==false){
        int x = q.size();
        
        for(int i=0;i<x;i++){
            auto n = q.front();
            q.pop();
            if(i == x-1){
                ans.push_back(n->data);
            }
            if(n->left){q.push(n->left);}
            if(n->right){q.push(n->right);}
        }
    }
    return ans;

}