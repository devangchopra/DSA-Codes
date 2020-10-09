#include<bits/stdc++.h> 
using namespace std; 
int check(int a) 
{ 
    long long int result = 0; 
    for (int i =2; i<=sqrt(num); i++) 
    { 
        if (num%i==0) 
        { 

            if (i==(num/i)) 
                result += i; 
            else
                result += (i + num/i); 
        } 
    } 
    if (result == 0)
        return result;
    else
        return (result + 1); 
} 
int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin>>n;
    while(n--)
    {
        long long int a;
        cin>>a;
        long long int s = check(a);
        if (s==a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    } 
} 