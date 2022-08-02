#include <iostream>
using namespace std;
bool isSubSequence(char str1[], char str2[], int m, int n)
{
	int j = 0; 
	for (int i = 0; i < n and  j < m; i++)
	{
		if (str1[j] == str2[i])
		{
			j++;
		}
	}
	return (j == m);
}


int main()
{
	char str1[] = "gksrek";
	char str2[] = "geeksforgeeks";
	int m = strlen(str1);	// m is the check string
	int n = strlen(str2);	//n is the main string
	isSubSequence(str1, str2, m, n) ? cout << "Yes "
									: cout << "No";
	return 0;
}





bool isSubSequence(char str1[], char str2[], int m, int n)
{
	int j = 0; 
	for (int i = 0; i < n and  j < m; i++)
	{
		if (str1[j] == str2[i])
		{
			j++;
		}
	}
	return (j == m);
}
char str1[] = "gksrek";
char str2[] = "geeksforgeeks";
int m = strlen(str1);	// m is the check string
int n = strlen(str2);