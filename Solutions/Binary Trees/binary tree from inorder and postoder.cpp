class Solution{
    public:
    Node* buildTreeHelper(int in[],int pre[],int ins,int ine,int pres,int pree)
    {
    	if(ins>ine) return NULL;
        
    	int root_data=pre[pres];
    	int rootindex=-1;
    	for(int i=ins;i<=ine;i++)
    	{
    		if(in[i]==root_data)
    		{
    			rootindex=i;
    			break;
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

    	Node* root=new Node(root_data);
    	root->left=buildTreeHelper(in,pre,lins,line,lpres,lpree);
    	root->right=buildTreeHelper(in,pre,rins,rine,rpres,rpree);
    	return root;

    } 
    Node* buildTree(int in[],int pre[], int n)
    {
        return buildTreeHelper(in,pre,0,n-1,0,n-1);
    }
};
