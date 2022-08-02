#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll number1;
		cin>>number1;

		ll number2;
		cin>>number2;

		ll diff=0;
		ll steps=0;

		if(number2==number1)
		{
			//do nothing
		}
		else
		{
			ll temp_max=max(number1,number2);
			ll temp_min=min(number2,number1);

			diff = temp_max-temp_min;

			if(temp_min%diff==0)
			{
				steps=0;
			}
			else
			{
				//Ratio -> Multiple
				steps = min(diff-temp_min % diff, temp_min%diff);
			}
		}
		cout<<diff<<" "<<steps<<endl;	
		
	}
	return 0;
}