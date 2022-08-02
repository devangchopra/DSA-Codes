#include<bits/stdc++.h>
using namespace std;
bool sortByVal(const pair<string, int> &a, 
	               const pair<string, int> &b) 
{ 
	return (a.second < b.second); 
}

class Solution {
public:
	//sorting fxn

    string sortSentence(string s) {
    	map<string,int>m;
    	for(int i=0;i<s.length();i++)
    	{
    		string temp="";
    		if(s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9')
    		{
    			m[temp]=stoi(s[i]);
    			temp="";
    		}
    		else
    		{
    			temp=temp+s[i];
    		}
    	}

    	//sorting part
		vector<pair<string, int>> vec;

		map<string, int> :: iterator it2;
		for (it2=m.begin(); it2!=m.end(); it2++) 
		{
		   vec.push_back(make_pair(it2->first, it2->second));
		}

		sort(vec.begin(), vec.end(), sortByVal);

		//vector will contain sorted values
		string d=" ";
		for(int i=0;i<vec.size();i++)
		{
			d=d+vec[i].first;
			d=d+" ";
		}
		return d;

        
    }
};

int main()
{
	Solution obj;
	string s="is2 sentence4 This1 a3";
	string m=obj.sortSentence(s);
	cout<<m;
}