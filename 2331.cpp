#include <iostream>
using namespace std;
int vst[1000000];
int a,p;

int POW(int a,int b){
    int r=1;
    while(b){
        if(b&1) r = r*a;
        a*=a;
        b>>=1;
    }
    return r;
}

int compute(int num){
    int sum=0;
    while(num){
        sum+=POW(num%10,p);
        num/=10;
    }
    return sum;
}
int dfs(int a,int cnt){
    if(vst[a]) return vst[a]-1;

    vst[a] = cnt;
    int b = compute(a);
    return dfs(b,cnt+1);
}  
int main(){
    cin >> a >> p;
    cout << dfs(a,1) << endl;
    return 0;
}