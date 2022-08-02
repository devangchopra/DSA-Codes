vector<int> find(int arr[], int n , int x )
{
    vector<int>v;
    int stindex=-1;
    int endindex=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            if(stindex==-1)
            {
                stindex=i;
                endindex=i;
            }
            else
            {
                endindex=i;
            }
            
        }
    }
    v.push_back(stindex);
    v.push_back(endindex);
    return v;
    
   
}