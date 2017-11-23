#include <iostream>
using namespace std;

int g[100001];
int v[100001];

int dfs(int x,int y, int z){

    if(v[x]){
        if()
    }

}

int main(){

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        for(int i=0 ;i<n;i++){
            cin >> g[i+1];
            v[i+1] = 0;
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
            if(v[i] == 0)
                ans += dfs(i,1,i);
    }

    return 0;
}