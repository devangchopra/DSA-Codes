#include <iostream>
using namespace std;
void reverseString(char s[],int n) {
        //Base Case
        if(n == 0)
            return;
        
        //Belief or Hypothesis
        reverseString(s+1,n-1);
        cout<<s[0];
    }
int main()
{
	char s[]={'a','b','c','d','\0'};
	reverseString(s,4);

}