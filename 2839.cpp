#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int main(){
    int n;
    int d[5001]={0};
    cin >> n;

    d[3] = d[5] = 1;
    for(int i=6 ;i<=n;i++)
        if(d[i-3] || d[i-5]){
            if(!d[i-5]) d[i] = d[i-3]+1;
            else if(!d[i-3]) d[i] = d[i-5]+1;
            else  d[i] = min(d[i-3],d[i-5])+1;
        }

    if(!d[n]) cout << -1 << endl;
    else cout << d[n] << endl; 

    return 0;
}