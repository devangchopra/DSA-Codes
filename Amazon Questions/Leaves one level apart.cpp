/************************************************************

    Following is the Tree node structure
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
bool isleave(TreeNode<int>* node){
    if(!node){
        return true;
    }

    if(node->left==NULL and node->right==NULL){
        return true;
    }

    return false;
}

bool areLeavesOneLevelApart(TreeNode< int > *root) {
    // Write your code here.
    if(!root){
        return true;
    }
    if(isleave(root)){
        return true;
    }
    unordered_set<int>v;
    int level = -1;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(q.empty()==false){
        int x = q.size();
        level++;
        for(int i=0;i<x;i++){
            auto node = q.front();
            q.pop();
            if(isleave(node)){
                v.insert(level);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    if(v.size()>2){
        return false;
    }
    vector<int>a;
    for(auto &i:v){
        a.push_back(i);
    }
    if(a.size()<=1){
        return true;
    }
    if(abs(a[0]-a[1])<=1){
        return false;
    }
   
    return true;

}