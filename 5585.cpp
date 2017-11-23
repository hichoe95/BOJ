#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,d[1001]={0},coin[6]={500,100,50,10,5,1};
    cin >> n;
    n=1000-n;
    for(int i=1 ;i<=1000;i++)
        d[i]=999999;
    for(int i=1 ;i<=n;i++)
        for(int k:coin)
            if(i-k>=0) d[i] = min(d[i],d[i-k]+1);

    cout << d[n] << "\n";
    return 0;
}