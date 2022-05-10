#include <bits/stdc++.h>
void deleteMiddle(stack<int>&inputStack, int N) {
	//i have N+1 elements in the stack
	// Write your code here
	stack<int>temp;
	int count = floor(N / 2.0);

	for (int i = 0; i < count; i++) {
		int x = inputStack.top();
		inputStack.pop();
		temp.push(x);
	}
	inputStack.pop();
	while (temp.empty() == false) {
		int x = temp.top();
		temp.pop();
		inputStack.push(x);
	}

}


//Recursive Code

#include <bits/stdc++.h>

void solve(stack<int>& s, int k) {
	if (k == 1) {
		s.pop();
		return;
	}

	int temp = s.top();
	s.pop();
	solve(s, k - 1);

	s.push(temp);
	return;
}
void deleteMiddle(stack<int>&inputStack, int N) {
	int k = N / 2 + 1;
	solve(inputStack, k);
	return;
}