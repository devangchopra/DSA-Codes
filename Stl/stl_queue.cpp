#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout<<q.front()<<" "<<q.back()<<endl;
	q.pop();
	cout<<endl<<q.size();
	cout<<endl<<q.front()<<" "<<q.back()<<endl;
	return 0;
}