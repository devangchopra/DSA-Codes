#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &output,int i,int n)
{
	int leftchild=2*i+1;
	int rightchild=2*i+2;

	int largest=i;

	//Find the Largest one
	if(leftchild<n and output[leftchild]>output[i])
	{
		largest=leftchild;
	}
	if(rightchild<n and output[rightchild]>output[largest])
	{
		largest=rightchild;
	}
	if(largest!=i)
	{
		swap(output[i],output[largest]);
		heapify(output,largest,n);
	}

}

void build_heap(vector<int> &output,int i,int size)
{
	for(int i=(7-2)/2;i>=0;i--)
	{
		heapify(output,i,size);
	}
}

int main()
{
	vector<int> a{10, 5, 6, 2};
	vector<int> b{12, 7, 9};

	int n=a.size();
	int m=b.size();

	vector<int> output;

	for(int i=0;i<n;i++)
	{
		output.push_back(a[i]);
	}

	for(int i=0;i<m;i++)
	{
		output.push_back(b[i]);
	}

	build_heap(output,0,7);

	for(auto i:output)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}