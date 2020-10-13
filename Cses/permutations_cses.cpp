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
	deque<int>dq={4,2,5,3,1};
	if (n==1)
		cout<<1;
	else if (n==2 or n==3)
		cout<<"NO SOLUTION";

	else if(n==4)
		cout<<2<<" "<<4<<" "<<1<<" "<<3;

	else if(n==5)
		cout<<4<<" "<<2<<" "<<5<<" "<<3<<" "<<1;
	else
	{
		for (ll i=6 ; i<=n ;i++)
		{
			if(i%2==0)
			{
				dq.push_front(i);
			}
			else
			{
				dq.push_back(i);
			}
		}

		for(ll i=0 ;i<dq.size();i++)
			cout<<dq[i]<<" ";
	}
	return 0;
}