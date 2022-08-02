#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int x,y;
		cin>>x>>y;
		char arr[n][m];
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				char c;
				cin>>c;
				arr[i][j]=c;
			}
		}
		
		for (int i=0;i<n;i++)
		{ // every row
			int comp=0;
			int part=0;
			for (int j=0;j<m;j++)
			{	
				
				if(arr[i][j]=='F')
				{
					comp++;
				}
				else if(arr[i][j]=='P')
				{
					part++;
				}
			}
			if(comp==x)
			{
				cout<<"1";
			}
			else if(comp==x-1 and part==y)
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}

		}
		cout<<endl;
		
	}
}

/*3
4 5
3 2
FUFFP
PFPFU
UPFFU
PPPFP
3 4
1 3
PUPP
UUUU
UFUU
1 3
2 2
PPP*/