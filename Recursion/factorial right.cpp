#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
	if(n==0)
		return 1;
	cout<<n<<endl;
	int ans=factorial(n-1);
	return ans*n;
}
int main()
{
	int n;
	cin>>n;
	cout<<factorial(n);
}