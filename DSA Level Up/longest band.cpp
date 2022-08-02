#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr {1,9,3,0,18,5,2,4,10,7,12,6};

	unordered_set<int>s;

	for(auto i:arr)
	{
		s.insert(i);
	}

	int band_length=0;

	for(auto i:arr)
	{
		if(s.count(i-1)>0)
		{
			//do nothing
			continue;
		}
		else
		{
			int temp_length=0;
			int x=i;
			while(s.count(x)>0)
			{
				temp_length++;
				x++;
			}
			band_length=max(band_length,temp_length);
		}
	}
	cout<<band_length<<endl;
}