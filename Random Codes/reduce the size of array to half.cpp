Ques : Reduce The Array Size To Half

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
    	int n=arr.size();

    	//Frequency ! > n
    	vector<int> v(n+1,0);
    	for(int i=0;i<n;i++)
    	{
    		v[arr[i]]++;
    	}
    	cout<<"This is Vector"<<endl;
    	int x=0;
    	for(auto i:v)
    	{
    		cout<<x<<" "<<i<<endl;
    		x++;
    	}
    	cout<<endl;
    	multimap<int,int,greater<int>>m;
    	pair<int,int>p;
    	for(int i=0;i<n+1;i++)
    	{
    		if(v[i]>0)
    		{
    			p={v[i],i};
    			m.insert(p);
    		}
    	}
    	for(auto p:m)
    	{
    		cout<<p.first<<" "<<p.second<<" "<<endl;
    	}

    	int count=0;
    	int current_size=n;
    	int required_size=(n/2);

    	if(m.count(n)>0)
    	{
    		cout<<"This is it"<<n<<endl;
    		return 1;
    	}

    	for(auto p:m)
    	{
    		
    		if(current_size-p.first<required_size)
    		{
    			continue;
    		}
    		current_size=current_size-p.first;
    		cout<<"This is it"<<" "<<p.second<<endl;
    		count++;
    		if(current_size>required_size)
    		{
    			continue;
    		}
    		else
    		{
    			break;
    		}

    	}

    	cout<<endl<<count<<endl;

    	return count;
        
    }
};

int main()
{
	Solution obj;
	std::vector<int> v{3,3,3,3,5,5,5,2,2,7};
	std::vector<int> v2{7,7,7,7,7,7};
	std::vector<int> v3{1,2,3,4,5,6,7,8,9,10};
	obj.minSetSize(v3);
}
*/

/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
    	int n=arr.size();

    	unordered_map<int,int>temp;

    	for(auto i:arr)
    	{
    		temp[i]++;
    	}

    	multimap<int,int,greater<int>>m;

    	pair<int,int>p;

    	for (auto element:temp)
    	{
    		p={element.second,element.first};
    		m.insert(p);
    	}

    	int count=0;
    	int current_size=n;
    	int required_size=(n/2);
    	

    	if(m.count(n)>0)
    	{
    		count=1;
    	}
    	else
    	{
    		for(auto p:m)
	    	{
	    		
	    		if(current_size-p.first<required_size)
	    		{
	    			continue;
	    		}
	    		current_size=current_size-p.first;
	    		count++;
	    		if(current_size>required_size)
	    		{
	    			continue;
	    		}
	    		else
	    		{
	    			break;
	    		}

	    	}   		
    
    	}
    	return count;     	
       
    }
};

int main()
{
	Solution obj;
	std::vector<int> v{3,3,3,3,5,5,5,2,2,7};
	std::vector<int> v2{7,7,7,7,7,7};
	std::vector<int> v3{1,2,3,4,5,6,7,8,9,10};
	cout<<obj.minSetSize(v)<<endl;
	cout<<obj.minSetSize(v2)<<endl;
	cout<<obj.minSetSize(v3)<<endl;
}
*/

/*
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int c=1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                c++;
            }
            else{
                ans.push_back(c);
                c=1;
            }
        }
        ans.push_back(c);
        c=0;
        sort(ans.begin(),ans.end());
        int count=0;
        for(int i=ans.size()-1;i>=0;i--){
            c+=ans[i];
            count++;
            if(c>=arr.size()/2){
                break;
            }
        }
        return count;
    }
};
*/


