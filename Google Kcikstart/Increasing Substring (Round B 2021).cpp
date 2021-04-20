#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
    cin>>n;
	ll T; 
	T=n; 
	//Storing
	while(n--)
	{
        ll size;
        cin>>size;
        string c;
        cin>>c;
        ll count =1;
        vector <ll> v;
        v.push_back(count);
        for (ll i=0;i<size-1;i++)
        {
            if(c[i]<c[i+1])
            {
                count++;
                v.push_back(count);
            }
            else
            {
                count=1;
                v.push_back(count);
            }
        }
        cout<<"Case #"<<T-n<<":"<<" ";
        for (ll i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;



	}
	return 0;
}
