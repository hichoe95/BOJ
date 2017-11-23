#include <iostream>
#include <string>
using namespace std;
bool c[2501][2501];
int d[2501];
int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i=1; i<=n; i++) {
        c[i][i] = true;
    }
    for (int i=1; i<=n-1; i++) {
        if (s[i] == s[i+1]) {
            c[i][i+1] = true;
        }
    }
    for (int k=2; k<n; k++) {
        for (int i=1; i<=n-k; i++) {
            int j = i+k;
            c[i][j] = (s[i] == s[j] && c[i+1][j-1]);
        }
    }
    d[0] = 0;
    for (int i=1; i<=n; i++) {
        d[i] = -1;
        for (int j=1; j<=i; j++) {
            if (c[j][i]) {
                if (d[i] == -1 || d[i] > d[j-1]+1) {
                    d[i] = d[j-1]+1;
                }
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
