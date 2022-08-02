#include <string>
#include "TrieNode.h"

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
			root->isTerminal=true;
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

			return root -> isTerminal;
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



	//Remove
	void removeword(TrieNode* root,string word)
	{
		//Base Case
		if(word.size()==0)
		{
			root->isTerminal=false;
			return;
		}

		//Small Calculation
		TrieNode* child;
		int index=word[0]-'a';
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			//Word does not exists
			return; 
		}
		removeword(child,word.substr(1));

		//Remove child node if it is useless
		if(child->isTerminal==false)
		{
			for(int i=0;i<26;i++)
			{
				if(child->children[i]!=NULL)
				{
					return;
				}
			}
			//If we come out of loop -> child is useless uska agge koi connection
			//nhi hai
			delete child;
			root->children[index]=NULL;
		}
	}

	//For User
	void removeword(string word)
	{
		if(word.size()==0)
		{
			return;
		}
		removeword(root,word);	
	}

	

};