#include <bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<string,int>m;
	m["abc"]=1;
	m["abc2"]=2;
	m["abc3"]=3;
	m["abc7"]=4;
	m["abc4"]=5;
	m["abc5"]=6;
	m["abc6"]=7;
    m["abc8"]=8;
    unordered_map<string,int> :: iterator it;
    it=m.begin();
    while(it!=m.end())
    {
    	cout<<it->first<<" "<<it->second<<" "<<endl;
    	it++;
    }

    cout<<endl<<"Size :"<<m.size()<<" "<<endl;
    m["abc"]++;


    cout<<endl<<"Count : "<<m.count("abc")<<endl;

    //count only returns 0 or 1
    m["abc"]=5;

    cout<<endl<<"Now Count : "<<m.count("abc")<<endl;


    cout<<"At"<<" "<<m.at("abc")<<endl;

    cout<<"Square Bracket"<<" "<<m["abc"]<<endl;

    cout<<"Erase";
    m.erase(m.begin());

    cout<<endl<<"Now Size"<<" "<<m.size()<<endl;


}