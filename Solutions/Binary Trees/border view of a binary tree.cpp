class Solution {
    private:
    
public:
   void left(Node* root , vector<int> &ans)
   {
   		if(root==NULL) return;
   		if(root->left!=NULL)
   		{
   			ans.push_back(root->data);
   			left(root->left,ans);
   		}
   		else if(root->right!=NULL)
   		{
   			ans.push_back(root->data);
   			left(root->right,ans);
   		}
   }

   void Leaf(Node* root , std::vector<int>& ans)
   {
   		if(root==NULL) return;
   		
   		if(root->left==NULL and root->right==NULL)
   		{
   			ans.push_back(root->data);
   		}
   		Leaf(root->left,ans);
   		Leaf(root->right,ans);
   }

   void Right(Node* root, std::vector<int> &ans)
   {
   		if(root==NULL) return;
   		if(root->right)
   		{
   		   Right(root->right,ans);
         //Recursively ulta poora neche jao ten push kro
   			ans.push_back(root->data);
   			
   		}
   		else if(root->left)
   		{
   		    Right(root->left,ans);
   			ans.push_back(root->data);
   			
   		}
   }

    vector <int> printBoundary(Node *root)
    {
       //Left->Leaf->Right
       vector<int>ans;
       ans.push_back(root->data);
       left(root->left,ans);
       //20 8 
       Leaf(root,ans);
       //20 8 4 10 14 25
       Right(root->right,ans);
       // 20 8 4 10 14 25 22
       return ans;
    }
};