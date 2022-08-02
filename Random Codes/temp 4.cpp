vector<vector<int>> temp;

bool isLeaf(Node* node) {
	return (node->left == nullptr && node->right == nullptr);
}

void findPath(Node* node, vector<int> &path)
{
	if (node == nullptr) {
		return;
	}

	path.push_back(node->data);

	if (isLeaf(node))
	{
		temp.push_back(path);
	}
	findPath(node->left, path);
	findPath(node->right, path);
	path.pop_back();
}

long long sum_root_to_leaf_numbers(Node* root)
{
	vector<vector<int>> temp;

	vector<int> path;

	bool isLeaf(Node * node) {
		return (node->left == nullptr && node->right == nullptr);
	}

	void findPath(Node * node, vector<int> &path)
	{
		if (node == nullptr) {
			return;
		}

		path.push_back(node->data);

		if (isLeaf(node))
		{
			temp.push_back(path);
		}
		findPath(node->left, path);
		findPath(node->right, path);
		path.pop_back();
	}


	findPath(node, path);

	long long int sum = 0;

	for (auto v : temp)
	{
		long long int m = v.size();
		long long int t = 0;
		for (auto i : v)
		{
			t = t + (i * pow(10, m));
			m--;
		}

		sum = t;
	}

	return sum;
}



void generate_square_array(int *arr, int len)
{
	int* brr = new int[len];

	for (int i = 0; i < len; i++)
	{
		brr[i] = arr[i] * arr[i];
	}

	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - i - 1; j++)
			if (brr[j] > brr[j + 1])
				swap(brr[j], brr[j + 1]);


	for (int i = 0; i < len; i++)
	{
		arr[i] = brr[i];
	}

	return;


}

long long treePathsSumUtil(node *root, long long int val)
{

	if (root == NULL) return 0;

	val = (val * 10 + root->data);
	if (root->left == NULL && root->right == NULL)
		return val;

	return treePathsSumUtil(root->left, val) +
	       treePathsSumUtil(root->right, val);
}

long long sum_root_to_leaf_numbers(Node *root)
{
	return treePathsSumUtil(root, 0);
}



char find_non_repeating(char* arr, int len)
{
	int size = sizeof(arr) / sizeof(arr[0]);
	int freq[27];

	for (int i = 0; i < 27; i++)
	{
		freq[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		freq[arr[i] - 97] += 1;
	}

	int ans = 0;

	for (int i = 0; i < 27; i++)
	{
		if (freq[i] == 1 and ans <= 1)
		{
			ans++;
		}
		else if (freq[i] == 1 and ans == 2)
		{
			result = freq[i] + 97;
		}
	}




	return result;
}





#include <bits/stdc++.h>
using namespace std;
;

char find_non_repeating(char* arr, int len)
{
	const int MAX_CHAR = 256;

	int n = len;

	int count[MAX_CHAR];


	int index[MAX_CHAR];

	for (int i = 0; i < MAX_CHAR; i++)
	{
		count[i] = 0;
		index[i] = n;
	}

	for (int i = 0; i < n; i++)
	{

		char x = str[i];
		++count[x];
		if (count[x] == 1)
			index[x] = i;
		if (count[x] == 2)
			index[x] = n;
	}

	int i, j;
	for (i = 0; i < MAX_CHAR - 1; i++)
		for (j = 0; j < MAX_CHAR - i - 1; j++)
			if (index[j] > index[j + 1])
				swap(index[j], index[j + 1]);

	int ans = index[2 - 1];

	result = ans + 97;

	return result;
}


int main()
{
	string str = "geeksforgeeks";
	int k = 3;
	int res = kthNonRepeating(str, k);
	(res == -1) ? cout << "There are less than k non-"
	                   "repeating characters"
	                   : cout << "k'th non-repeating character"
	                   " is " << str[res];
	return 0;
}


struct ArrWithSize level_wise_ap(struct Node* root)
{
	vector<int> ans;
	queue<Node*>q;
	q.push(root);

	

	while(q.size()!=0)
    {
    	int sum = 0;

        int n=q.size();
        while(n>0)
        {
            Node* temp=q.front();
            q.pop();
            sum+=temp->data;
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            n--;
        }  
        
        ans.push_back(sum);
    }

    int x = sizeof(ans)/sizeof(ans[0]);

    ArrWithSize obj;

    obj.arr = new int [x];
    obj.size = x;

    arr[0]=0;
    arr[1]=0;

    int diff = ans[1]-ans[0];

    for(int i=2;i<x;i++)
    {
    	arr[i]=ans[i]-diff;
    }
    

	return ArrWithSize{};
}


void level_depth(treenode* root)
{  
    queue<treenode*>q;
    q.push(root);
    cout<<root->data<<endl;
    while(q.size()!=0)
    {
        int n=q.size();
        while(n>0)
        {
            treenode* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            n--;
        }
        cout<<endl;      
        
    }
}