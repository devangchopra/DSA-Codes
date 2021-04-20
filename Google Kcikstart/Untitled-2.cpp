#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector <int> v {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	
	cin>>n;
	ll T; 
	T=n; 
	while(n--)
	{
        int z;
        cin>>z;
        int largest=1;
        for (int i=0;i<v.size()-1;i++)
        {
            if(v[i]*v[i+1]<=z)
            {
                largest=v[i]*v[i+1];
            }
            else
            {
                break;
            }
        }
        cout<<"Case #"<<T-n<<":"<<" "<<largest<<endl;


	}
	return 0;
}