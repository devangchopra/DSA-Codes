#include<bits/stdc++.h>
using namespace std;
void triplet(std::vector<int> v, int s)
{
	//Already Sorted
	int st=0;
	while(st<v.size())
	{
		int ans=s-v[st];
		int i=st+1;
		int j=v.size()-1;
		int x=0;
		for(int n=i;n<v.size();n++)
		{
			if(v[i]+v[j]==ans)
			{
				x=1;
				break;
			}
			if(v[i]+v[j]>ans)
			{
				j--;
			}
			if(v[i]+v[j]<ans)
			{
				i++;
			}
		}
		
		if(x==1)
		{
			cout<<v[st]<<" "<<v[i]<<" "<<v[j]<<endl;
			
		}
		st++;	
	}

}

int main()
{
	vector<int> arr{1,2,3,4,5,6,7,8,9,15};
	int S=18;

	triplet(arr,S);
	return 0;
}