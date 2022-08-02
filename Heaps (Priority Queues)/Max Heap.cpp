#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr{4, 2, 20, 18, 6 ,14, 11, 9, 4};

	int n=arr.size();
	bool x=true;

	if(n<=1)
	{
		cout<<true<<endl;
	}
	
	else
	{

		int Parent_Index=0;
		int Left_Child_Index=0;
		int Right_Child_Index=0;
		int i=0;

		while(i<=(n-2)/2)
		{
			Left_Child_Index=(2*Parent_Index)+1;

			Right_Child_Index=(2*Parent_Index)+2;

			if((Right_Child_Index<n) and  (arr[Parent_Index]<arr[Left_Child_Index]) or (arr[Parent_Index]<arr[Right_Child_Index]))
			{
				
				x=false;
				break;
			}	

			Parent_Index++;
			i++;

		}

	}
	cout<<x<<endl;
}