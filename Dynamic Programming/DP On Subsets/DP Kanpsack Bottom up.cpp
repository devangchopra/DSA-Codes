#include <bits/stdc++.h>
using namespace std;
int t[1005][1005];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 4;
    int n = 4;

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i == 0  or j == 0) {
                t[i][j] = 0;
            }
        }
    }


    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (wt[i - 1] <= j) {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i-1][j]);
                //Included and Not includedd
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }


    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            cout << t[i][j] << " ";
        } cout << endl;
    }
    cout << endl << t[n][W] << endl;
    return 0;
}