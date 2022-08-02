#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode** children;
    bool isterminal;
    
    TrieNode(char data)
    {
        this->data=data;
        children = new TrieNode*[26];
        isterminal=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};

class Trie
{	
	TrieNode* root;
	public:
	Trie()
	{
		root=new TrieNode('\0');
	}

	void insert(TrieNode* root,string word)
	{
		if(word.size()==0)
		{
			root->isterminal=true;
			return;
		}

		int index=word[0]-'a';
		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->children[index]=child; 
		}
		insert(child,word.substr(1));
	}

	void insert(string word)
	{
		insert(root,word);
	}

	bool search(TrieNode* root,string word)
	{
		if(word.size()==0)
		{
			return root->isterminal;
		}

		int index=word[0]-'a';
		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			return false; 
		}
		return search(child,word.substr(1));

	}

	bool search(string word)
	{
		return search(root,word);
	}

	bool isprefixpresent(TrieNode* root,string word)
	{
		if(word.size()==0)
		{
			return true;
		}

		int index=word[0]-'a';
		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			return false; 
		}
		return isprefixpresent(child,word.substr(1));
	}

	bool isprefixpresent(string word)
	{
		return isprefixpresent(root,word);
	}

	void removeword(TrieNode* root,string word)
	{
		if(word.size()==0)
		{
			root->isterminal=false;
			return;
		}

		int index=word[0]-'a';
		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			return;
		}
		removeword(child,word.substr(1));

		//Delete that word
		//Index = NULL
		//Check whether it is useless

		for(int i=0;i<26;i++)
		{
			if(child->children[index]!=NULL)
			{
				return;
			}
		}

		//It will only come out if all are null
		//that means it is useless
		//therefore delete that
		delete child;
		root->children[index]=NULL;

	}

	void removeword(string word)
	{
		removeword(root,word);
	}


};

int main()
{
	Trie t;
	t.insert("devang");
	t.insert("speaker");
	t.insert("chopra");
	cout<<t.search("speaker")<<endl;
	t.removeword("speaker");
	cout<<t.search("speaker")<<endl;
	cout<<t.isprefixpresent("dev")<<endl;
	cout<<t.search("devang")<<endl;

	return 0;
}