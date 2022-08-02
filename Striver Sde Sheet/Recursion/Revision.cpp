#include<iostream>
#include <vector>
using namespace std;

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

void print(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    print(n-1);
    cout<<n<<" ";
}

void print1(int n){
    if(n<1){
        return;
    }
    print1(n-1);
    cout<<n<<" ";
    return;
}

void print2(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    print2(n-1);    
    return;
}

bool palindromic(string s,int start,int end){
    if(start==end){
        return true;
        //Odd Length
        //Same Char
    }
    if(start>end){
        return false;
    }
    if(s[start]!=s[end]){
        return false;
    }   
    return palindromic(s,start+1,end-1);
}

int sumofdigits(int n){
    if(n<=0){
        return 0;
    }
    int ans = n%10+sumofdigits(n/10);
    return ans;
}

int max_cuts(int n,int a,int b,int c){
    //Defin : for n : maximum cuts
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;
    }

    //Choice Diagram
    int ans = max(max(max_cuts(n-a,a,b,c),max_cuts(n-b,a,b,c)),
                  max_cuts(n-c,a,b,c));
    if(ans==-1){
        return -1;
    } 
    return ans+1;
}

vector<string>ans;

void substrs(string s, string temp,int i,int n){
    if(i==n){
        ans.push_back(temp);
                //Parent should get unaltered String
        return;
    }
    //Include 
    temp.push_back(s[i]);
    substrs(s,temp,i+1,n);
    temp.pop_back();
    //Not Include
    substrs(s,temp,i+1,n);
}

int nthFibonacciNumber(int n){
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int so1=nthFibonacciNumber(n-1);
    int so2=nthFibonacciNumber(n-2);

    return so1+so2;
}

bool isArraySorted(int arr[],int i,int n){
    if(i==n-1){
        return true;
    }
    bool subprob=isArraySorted(arr,i+1,n);
    if(subprob){
        if(arr[i]<arr[i+1]){
            return true;
        }
    }
    return false;
}

int firstIndex(int arr[],int n,int i,int k){
    if(i==n-1){
        return -1;
    }
    if(arr[i]==k){
        return i+1;
    }
    return firstIndex(arr,n,i+1,k);
}



int main(){
    int arr[]={10,20,80,40,50};
    cout<<firstIndex(arr,5,0,80);
}