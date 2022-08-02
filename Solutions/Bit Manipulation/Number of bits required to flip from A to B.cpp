
//TLE
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int m;
	cin>>m;
	
	int count=0;

	while(n>=0 and m>=0)
	{
		int last_bit_of_n=n&1;
		int last_bit_of_m=m&1;

		if(last_bit_of_m!=last_bit_of_n)
		{
			count++;
		}

		n=n>>1;
		m=m>>1;

	}

	return count;
}

//Real Solution
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        
        int ans=a^b;
        
        int count=0;
        
        while(ans>0)
        {
            count+=ans&1;
            ans=ans>>1;
        }
        
        return count;
    }
};







