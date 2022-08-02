#include<bits/stdc++.h>
using namespace std;
int anns(vector<int>a)
{
	int n=a.size();
	int largest=0;
	for(int i=1;i<=n-2;)
	{
		if(a[i]>a[i+1] and a[i]>a[i-1])
		{
			int j=i;
			int cnt=1; // coz peak itsslf
			while(j>=1 and a[j]>a[j-1])
			{
				j--;
				cnt++;
			}

			//Forward
			while(i<=n-2 and a[i]>a[i+1])
			{
				i++;
				cnt++;
			}
			largest=max(cnt,largest);
		}
		else
		{
			i++;
		}
	}
	return largest;
}
int main()
{
	vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
	cout<<anns(arr);
}