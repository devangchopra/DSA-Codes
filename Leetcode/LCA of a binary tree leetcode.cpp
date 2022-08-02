//Approach 1  :

class Solution {
public:
    
    bool fxn(TreeNode* root , TreeNode* p,vector<TreeNode*>& v){
        if(root==NULL){
            return false;
            //if no root it means we have no path
        }
        
        v.push_back(root);
        
        if(root == p){
            return true;
        }
        
        bool isInLeft = fxn(root->left,p,v);
        bool isInRight = fxn(root->right,p,v);
        
        if(isInLeft or isInRight){
            return true;
        }
        
        //if not present then pop out this node as well
        v.pop_back();
        return false;
        
    }
    
    //Approach 1 
    //root to node path for p 
    //root to node path for q
    //Two pointer to match those arrays 
    //if doesnot matches return the previous index ans
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>rtp;
        fxn(root,p,rtp);
        vector<TreeNode*>rtq;
        fxn(root,q,rtq);
        
        int i=0,j=0;
        
        while(i<rtp.size() and j<rtq.size()){
            if(rtp[i]->val==rtq[j]->val){
                i++;
                j++;
            }
            else{
                break;
            }
        }
        
        if(i!=0 and j!=0){
            return rtp[i-1];
        }
        
        return NULL;
    }
};

//Approach 2  :

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == p->val or root->val==q->val){
            return root;
        }
        
        TreeNode* isLeftLca = lowestCommonAncestor(root->left,p,q);
        TreeNode* isRightLca = lowestCommonAncestor(root->right,p,q);
        
        if(isLeftLca and isRightLca){
            //it means both nodes are in different subtrees
            return root;
        }
        
        if(isLeftLca == NULL and isRightLca !=NULL){
            return isRightLca;
        }
        
        
        return isLeftLca;
    }
};



