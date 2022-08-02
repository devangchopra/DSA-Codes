#include <iostream>
using namespace std;

void bubbleSort(pair<int,int>* v, int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    for (j = 0; j < n-i-1; j++) 
        if (v[j] > v[j+1]) 
            swap(v[j], v[j+1]); 
} 


int shopping(int input1, int input2[], int input3[])
{
	int n = input1;

	pair<int, int>* v;
	v = new pair<int, int> [n];

	pair<int, int>p;

	for (int i = 0; i < n; i++)
	{
		p = {input3[i], input2[i]};
		v[i] = p;
	}

	bubbleSort(v,n);

	int count = 0;
	int wt = 0;

	for (int i = 0; i < n; i++)
	{
		if (wt <= v[i].second)
		{
			count++;
			wt += v[i].first;
		}
	}

	return count;

}
int main()
{
	int input1 = 8;
	int input2[] = {2,1,3,9,7,12,5,13};
	int input3[] = {1,3,6,9,2,3,1,3};
	cout << shopping(input1, input2, input3);

}
