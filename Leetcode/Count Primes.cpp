#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int countPrimes(int n) {
    	vector<bool>v(n+1,true);
    	v[0]=false;
    	v[1]=false;
    	for(int i=2;i<=n;i++)
    	{
    		if(v[i]==true)
    		{
    			for(int j=i*2;j<=n;j=j+i)
    			{
    				v[j]=false;
    			}
    		}
    	}
    	int count=0;
    	for(int i=2;i<n;i++)
    	{
    		if(v[i]==true)
    		{
    			count++;
    		}
    	}

    	return count;
    }
};
int main()
{
	Solution obj;
	cout<<obj.countPrimes(10);
	cout<<obj.countPrimes(0);
	cout<<obj.countPrimes(1);

}

