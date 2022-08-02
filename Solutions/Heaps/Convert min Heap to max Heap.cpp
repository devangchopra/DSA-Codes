#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int i,int n)
{
	int left_Child=2*i+1;
	int right_Child=2*i+2;

	int largest=i;

	if(left_Child<n and arr[left_Child]>arr[i])
	{
		largest=left_Child;
	}
	if(right_Child<n and arr[right_Child]>arr[largest])
	{
		largest=right_Child;
	}
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,largest,n);
		//toggle
	}
}

void max_heap(vector<int> &arr,int n)
{
	for(int i=(n-2)/2;i>=0;i--)
	{
		heapify(arr,i,n);
	}
}

int main()
{
	vector<int>arr{3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	int n=arr.size();

	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	max_heap(arr,n);

	cout<<"Now"<<endl;

	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}