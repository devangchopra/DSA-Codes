#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
	char data;
	TrieNode** children;

	TrieNode(char data)
	{
		this->data=data;
		children=new TrieNode* [26];

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
		root = new TrieNode('\0');

	}

	//Insert : => Helper Function for me
	void insertWord(TrieNode* root,string word)
	{
		//Base Case
		if(word.size()==0)
		{
			return;
		}

		//Small Calculation
		int index=word[0]-'a';
		//Mapping of characters and string
		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			//already exists
			child=root->children[index];
		}
		else
		{
			//We have to make the child
			child = new TrieNode(word[0]);
			//pointer to my node
			root->children[index]=child;
		}

		//Recursive Call
		insertWord(child,word.substr(1));
	}

	void insertWord(string word)
	{
		insertWord(root,word);
	}

	//Search



	bool Search(TrieNode* root,string word)
	{
		//Base Case
		if(word.size()==0)
		{
			//root being a pointer has three members : 1 => data , 2=> children , 3=>isTerminal
			//Therfore will be using ->

			return true;
		}

		//Small Calculation
		int index=word[0]-'a';
		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
			//Basically that will be char only
		}
		else
		{
			return false;
		}

		//Recursive Call
		return Search(child,word.substr(1));
	}

	bool Search(string word)
	{
		//Base Case
		if(word.size()==0)
		{
			return false;
		}

		return Search(root,word);
		//Root is same for all

	}	

};

int main()
{
	Trie t;
	int n;
	cin>>n;

	while(n--)
	{
		string s;
		cin>>s;
		t.insertWord(s);

		string ans=s;
		int index=1;
		while(ans.size()>=0)
		{
			t.insertWord(ans.substr(index));
			index++;
		}
	}

	string s;
	cin>>s;

	cout<<t.Search(s);
}