#include <iostream>
using namespace std;
void printds(int n)
{
	//Base Case
	if(n==1)
	{
		cout<<1<<" ";
		return;
	}

	//Hypothesis 
	printds(n-1);

	//Induction
	cout<<n<<" ";
}


int main()
{
	int n;
	cin>>n;
	printds(n);
}