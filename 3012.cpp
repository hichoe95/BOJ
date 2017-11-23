#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const long long mod = 100000;
string s;
bool over = false;
long long d[200][200];
char open[5] = "({[";
char close[5] = ")}]";
long long go(int i, int j) {
    if (i > j) {
        return 1;
    }
    long long &ans = d[i][j];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    for (int k=i+1; k<=j; k+=2) {
        for (int l=0; l<3; l++) {
            if (s[i] == open[l] || s[i] == '?') {
                if (s[k] == close[l] || s[k] == '?') {
                    long long temp = go(i+1, k-1) * go(k+1, j);
                    if (ans + temp > mod) {
                        over = true;
                    }
                    ans += temp;
                    ans %= mod;
                }
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    cin >> s;
    if(n%2){
      cout << 0 << '\n';
      return 0;
    }
    memset(d,-1,sizeof(d));
    long long ans = go(0, n-1);
    if (over) {
        printf("%05lld\n",ans);
    } else {
        printf("%lld\n",ans);
    }
    return 0;
}
