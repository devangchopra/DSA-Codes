#include <bits/stdc++.h>
using namespace std;

class meeting 
{
	public:
		
	int start;
	int end;
	int pos;
};

bool comparator(meeting m1, meeting m2)
{
	return (m1.end < m2.end);
}

void maxMeeting(int s[], int f[], int n)
{
	meeting meet[n];
	for (int i = 0; i < n; i++)
	{
		meet[i].start = s[i];
		meet[i].end = f[i];
		meet[i].pos = i + 1;
	}
	sort(meet, meet + n, comparator);

	// Vector for storing selected meeting.
	vector<int> m;

	// Initially select first meeting.
	m.push_back(meet[0].pos);

	// time_limit to check whether new
	// meeting can be conducted or not.
	int time_limit = meet[0].end;

	// Check for all meeting whether it
	// can be selected or not.
	for (int i = 1; i < n; i++) 
	{
		if (meet[i].start >= time_limit)
		{
			// Push selected meeting to vector
			m.push_back(meet[i].pos);
			
			// Update time limit.
			time_limit = meet[i].end;
		}
	}

	for (int i = 0; i < m.size(); i++) 
	{
		cout << m[i] << " ";
	}
}


int main()
{
	int s[] = { 75250, 50074, 43659, 8931, 11273,
27545, 50879, 77924 };
	int f[] = { 112960, 114515, 81825, 93424, 54316,
35533, 73383, 160252 };
	int n = sizeof(s) / sizeof(s[0]);
	maxMeeting(s, f, n);
	return 0;
}
