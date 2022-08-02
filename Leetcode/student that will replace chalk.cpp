#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    	//1. Find Sum
    	long long int sum=0;
    	for(int i=0;i<chalk.size();i++)
    	{
    		sum+=chalk[i];
    	}
    	long long int temp=k/sum;

    	k=k-(temp*sum);

    	int ans=0;

    	//cout<<"Temp"<<" "<<temp<<" "<<"k"<<" "<<k<<endl;

    	for(int i=0;i<chalk.size();i++)
    	{
    		if(chalk[i]>k)
    		{
    			ans=i;
    			break;
    		}
    		else
    		{
    			k=k-chalk[i];
    		}
    	}
    	return ans;
        
    }
};

int main()
{
	Solution obj;
	std::vector<int> chalk{5,1,5};
	int k=22;
	cout<<obj.chalkReplacer(chalk,k);
}
