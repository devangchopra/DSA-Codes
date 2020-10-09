#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		long long int x;
		cin>>n>>x;

		vector<long long int> v;
		map<long long int , long long int >maps;
		
        
        //cout<<"1 ENTRY";   :::CORRECt

		for (int i=0 ; i<n ; i++)
		{
			long long int a;
			cin>>a;
			v.push_back(a);
		}
		

		/*cout<<endl<<"YOUR INITIAL IS";
		for (int i=0;i<n;i++)
		{
			cout<<v[i]<<" ";
		}*/ // ::CORRECt  

		//cout<<endl<<"KHATAM";   ::CORRECT

        vector<long long int> f;
        long long int m=1;

		for (int i=0;v.empty()!=true;)
		{
			
			if(v[i]<=x)
			{
				
				v.erase(v.begin());
				f.push_back(m);;
				if(m>=n)
				{
					m=1;
				}
				else
				{
					
					m++;
				}
				/*cout<<endl<<"AB YEH POSITION HAI"<<endl;
				for (int i=0;i<v.size();i++)
				{
					
					cout<<v[i]<<" ";
				}
				cout<<endl<<"YEH F HAI"<<endl;
				for (int i=0;i<f.size();i++)
				{
					
					cout<<f[i]<<" ";
				}*/
			}
			else
			{
				//cout<<endl<<"YEH SUTTE GA";
				maps[v[i]-x]=m;
				v.push_back(v[i]-x);
				v.erase(v.begin());
				if(m<n)
					m++;
				
				//cout<<endl<<"AB YEH POSITION HAI SUTNE KE BAAD"<<endl;
				/*for (int i=0;i<v.size();i++)
				{
					
					cout<<v[i]<<" ";
				}*/

			}
			
		}
		for (int i=0;i<n;i++)
		{
			cout<<f[i]<<" ";
		}

	}
}