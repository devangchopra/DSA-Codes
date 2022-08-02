#include <iostream>
using namespace std;
#define ll long long
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        ll D, d, initial_increment_value, value_of_increment_final;
        cin>>D>>d>>initial_increment_value>>value_of_increment_final;
        ll var1;
        ll ans=0;

        var1 = D / d;

        if(var1%2==0)
        {
            ans=ans+d*((var1/(1+1))*(2*initial_increment_value+(var1-1)*value_of_increment_final));
        }
        else
        {
            ans=ans+ d*(var1*(initial_increment_value+((var1-1)/2)*value_of_increment_final));
        }

        ans=ans+(D % d)*(initial_increment_value+(var1)*value_of_increment_final);
        cout<<ans<<endl;
    }
    return 0;
}