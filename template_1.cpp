#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll 					long long int
#define ld 					long double
#define mod 				1e9+7
#define ps(x,y)   			fixed<<setprecision(y)<<x
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>>
#define endl        		"\n"
//Use endl wisely buffer flush
#define ordered_set tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


//int* arr=new int[n]
//cout<<ps(x,y)-->precision upto that decimal places

//cheking integer and fractional part :: double(n)-int(n)
//you can compare int,double ...ll ,int

//GCD
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;

	else return gcd(b, a % b);

}

// 1-2 SEC 10 ^7
//INT LIMIT 10^9
//PRIME NUMBERS USING SEIVE OF ERATOSTHENES

void primecheck() {
	ll x;
	cin >> x;
	std::vector<bool> isthisprime(x + 1, true);
	isthisprime[0] = false;
	isthisprime[1] = false;
	for (int i = 2; i <= x; i++)
	{
		if (isthisprime[i] == true)
		{
			for (int j = i * 2; j <= x; j += i)
			{
				isthisprime[j] = false;
			}
		}
	}
	int y;
	cin >> y;
	cout << isthisprime[y];
}

//---------------------------------------------------------------------------------

void fun() 
{
	//Code
	

}


//----------------------------------------------------------------------------------


int main()
{
	fastio;
#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	while (t--)
	{
		fun();

	}
	return 0;
}