#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

    int x=0;
	int position=0;
	int temp=n;
	
	while(n>=0)
	{
	    int last_bit=n&1;
	    if(last_bit==1)
	    {
	        position=x;
	        break;
	    }
	    
	    x++;
	    
	    n=n>>1;
	}
	//(N,i)

	cout<<(1<<position)<<endl;
}