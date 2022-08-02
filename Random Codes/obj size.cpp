#include <bits/stdc++.h>
using namespace std;

class hello
{
	int v[100];
public:
	hello()
	{
		for (int i = 0; i < 10; i++)
		{
			v[i] = 5;
		}

	}


};
int main()
{
	hello obj;
	cout << sizeof(obj);
	return 0;
}