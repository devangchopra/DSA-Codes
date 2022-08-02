// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    set<int>p;
    for(int i=0;i<n;i++) 
    {
        p.insert(a1[i]);
    }
    
    int size1=p.size();
    
    for(int i=0;i<m;i++) {
        p.insert(a2[i]);
    }
    int size2=p.size();
    if(size1==size2)
    {
       return "Yes";
    }
    else
    {
        return "No";
    }
    
}