#include <cstdio>
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y,x%y);
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int a[111];
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) scanf("%d",&a[i]);
        int sum=0;
        for (int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++)
                sum += gcd(a[i],a[j]);
        printf("%d\n",sum);
    }
    return 0;
}
