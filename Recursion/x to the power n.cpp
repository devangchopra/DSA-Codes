#include <iostream>
using namespace std;

int power(int x,int n){

	//Base Case
	if(n==0){
		return 1;
	}

	//Hypothesis
	int ans=power(x , n-1);

	//Induction
	return x*ans;
}


int main(){
	int x , n;
	cin >>x>>n;

	cout<<power(x,n);
}