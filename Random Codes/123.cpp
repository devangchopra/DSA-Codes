
#include <bits/stdc++.h>
using namespace std;


int shopping(int input1, int input2[], int input3[])
{
	int n = input1;

	vector<pair<int, int>>v;

	pair<int, int>p;

	for (int i = 0; i < n; i++)
	{
		p = {input3[i], input2[i]};
		v.push_back(p);
	}

	sort(v.begin(), v.end());

	int count = 0;
	int wt = 0;

	for (auto i : v)
	{
		if (wt <= p.second)
		{
			count++;
			wt += p.first;
		}
	}

	return count;

}




int main()
{
	int input1 = 8;
	int input2[] = {2, 1, 3, 9, 7, 12, 5, 13};
	int input3[] = {1, 3, 6, 9, 2, 3, 1, 3};
	cout << shopping(input1, input2, input3);

}







#include <bits/stdc++.h>
using namespace std;

int burcklenSb(int input1, int input2)
{
    if (input1 < 0) {
        return 0;
    }
 
    if (input1 == 0) {
        return 1;
    }
 
    int count = 0;
    for (int i = 1; i <= input2; i++) {
        count += burcklenSb(input1 - i, input2);
    }
 
    return count;
}
 
int main()
{
    int n = 6, m = 2;
    cout<<burcklenSb(n,m)<<endl;

    return 0;
}




