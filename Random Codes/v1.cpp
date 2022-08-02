/*
#include<bits/stdc++.h>
using namespace std;

void printMinDiffPairs(int arr[], int n)
{
    if (n <= 1)
        return;
    sort(arr, arr + n);
    int minDiff = arr[1] - arr[0];
    for (int i = 2 ; i < n ; i++)
        minDiff = min(minDiff, arr[i] - arr[i - 1]);
    for (int i = 1; i < n; i++)
        if ((arr[i] - arr[i - 1]) == minDiff)
            cout << arr[i - 1] << " " << arr[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printMinDiffPairs(arr, n);
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int fun(string str)
{
    int len = str.length();
    if (len % 2)
        return -1;

    stack<char> s;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '}' && !s.empty())
        {
            if (s.top() == '{')
                s.pop();
            else
                s.push(str[i]);
        }
        else
            s.push(str[i]);
    }
    int smallAns = s.size();
    int n = 0;
    while (!s.empty() && s.top() == '{')
    {
        s.pop();
        n++;
    }
    return (smallAns / 2 + n % 2);
}

int main()
{
    string s;
    cin >> s;
    cout << fun(s);
    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;

int isPrime(int);
int isMegaPrime(int);

int main()
{
    int st, sp, sum = 0;
    cin >> st >> sp;
    for (int i = st; i <= sp; i++) {
        if ((i % 2) != 0 && isMegaPrime(i) == 1)
            sum = sum + i;
    }
    cout << sum+2 << endl;
    return 0;
}

int isPrime(int n)
{
    int i = 0, flag = 0;
    if (n == 1)
        return 0;
    else
    {
        int t = sqrt(n);
        for (i = 2; i <= t; i++) {
            if ((n % i) == 0) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        return 0;
    else
        return 1;
}

int isMegaPrime( int n)
{
    int i = 0, flag = 0, temp = 0;
    if (isPrime(n) == 0)
        return 0;
    else {
        while (n != 0) {
            temp = n % 10;
            flag = isPrime(temp);
            if (flag == 0)
                return 0;
            n /= 10;

        }
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}
