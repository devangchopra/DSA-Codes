#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int color[1001][1001];
void fun() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            color[i][j] == 0;
        }
    }
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            color[i][j] = 1;
            int temp = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 and nx<n and ny >= 0 and ny < m and color[nx][ny] == 1) {
                    temp++;
                }
            }
            score += temp;
        }
    }
    cout << score << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            color[i][j] = 0;
        }
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}