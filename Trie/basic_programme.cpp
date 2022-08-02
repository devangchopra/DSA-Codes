#include <iostream>
using namespace std;
#include "Trie.h"

int main()
{
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout<<t.Search("and")<<endl;
	t.removeword("and");
	cout<<t.Search("and")<<endl;
}