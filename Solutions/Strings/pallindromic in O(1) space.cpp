// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <string.h>


 // } Driver Code Ends
//User function Template for C

int isPlaindrome(char S[])
{
    int l=0;
    int h=strlen(S)-1;
    while(l<h)
    {
        if(S[l]!=S[h])
        {
            return 0;
            
        }
        l++;
        h--;
    }
    return 1;
}

// { Driver Code Starts.

int main() 
{
   	int t;
   	scanf("%d", &t);
   	while(t--)
   	{
   		char s[100000];
   		scanf("%s", &s);;


   		printf("%d\n", isPlaindrome(s));
   	}

    return 0;
}  // } Driver Code Ends