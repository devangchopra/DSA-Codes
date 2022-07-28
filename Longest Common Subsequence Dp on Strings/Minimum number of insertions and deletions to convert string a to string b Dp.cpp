#include <bits/stdc++.h>
using namespace std;
int lcs(string x, string y, int n, int m) {
    int t[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 or j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i - 1] == y[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return t[n][m];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size(), lcs_ans = lcs(x, y, n, m);
    cout << "Deletions " << " " << abs(n - lcs_ans) << " " << "Insertions " << " " << abs(m - lcs_ans) << endl;

}