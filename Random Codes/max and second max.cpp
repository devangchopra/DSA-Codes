void fxx(int arr[],int n)
{
	if(n<2)
	{
		cout<<"Invalid";
	}
	int max=0;
	int s_max=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			s_max=max;
			max=arr[i];
		}
		else if(arr[i]>s_max and max!=arr[i])
		{
			s_max=arr[i];
		}
	}
	cout<<max<<" "<<s_max;
}