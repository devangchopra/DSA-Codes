#include <iostream>
using namespace std;
void merge(int a[],int s,int e){

    int mid = (s+e)/2;
    
    int i = s;
    int j = mid+1;
    int k = s;
    
    int temp[100];
    
    while(i<=mid && j<=e){
        if(a[i] < a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k] = a[i];
        k++;
        i++;
    }
    while(j<=e){
        temp[k]  = a[j];
        k++;
        j++;
    }
    
    //We need to copy all element to original arrays
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }
    
    
}
void helper(int arr[],int si,int ei)
{
	//Base Case
	if(si>=ei)
		return;

	//Hypothesis
	int mid=(si+ei)/2;
	helper(arr,si,mid);
	helper(arr,mid+1,ei);

	//Induction
	merge(arr,si,ei);
}
void mergesort(int arr[],int n)
{
	helper(arr,0,n-1);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"This is the array before"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"This is array after"<<endl;
	mergesort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}