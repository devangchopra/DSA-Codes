#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll n ;
	n=t;
	while(n--)
	{
		ll e;
		cin>>e;
		ll arr[e];
		ll sum =0;
		ll cost =0;
		for (ll i=0; i<e; i++)
		{
			cin>>arr[i];
		}

		// got the array

		for (ll i=0;i<e;i++)
		{
			ll j =*min_element(arr+i,arr+e);
			// finding the minimum element
			
			for (ll m =0;m<e;m++)
			{
				if (arr[m]==j)
				{
					j=m;
					break;
				}
			}
			// the index of minimum element

			reverse(arr+i,arr+j);

		    // reversing the array

			/*for (ll i=0; i<e; i++)
			{
				cout<<arr[i];
			}*/

			cost = j-i+1;
			sum = sum+cost;
		}

		cout <<"Case #"<<t-n<<": "<<sum<<endl;
		t=t-1;
	}	
}