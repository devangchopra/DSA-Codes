class Solution {
public:
    TreeNode* fn(vector<int>& preorder, vector<int>& inorder,int p,int in1,int in2, map<int,int>& m)
    {
        if(p>=preorder.size())
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[p]);
        int in=m[preorder[p]];
        int numleft=in-in1;
        int numright=in2-in;
        if(numleft>=1)
        root->left=fn(preorder,inorder,p+1,in1,in-1,m);
        else
            root->left=NULL;
        if(numright>=1)
            root->right=fn(preorder,inorder,p+numleft+1,in+1,in2,m);
        else
            root->right=NULL;
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        if(inorder.size()==0)
            return NULL;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        return fn(preorder,inorder,0,0,inorder.size()-1,m);
    }
};

