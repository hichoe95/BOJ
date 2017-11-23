#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
vector<int> G[1001];
bool visited[1001];

void dfs(int x){
    visited[x] = true;
    for(int i : G[x])
        if(!visited[i]) dfs(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    int N,M,x,y,cnt=0;
    cin >> N >> M;
    for(int i=0 ;i<M;i++){
        cin >> x >> y;
        G[x].pb(y);G[y].pb(x);
    }

    for(int i=1 ; i<=N ; i++)
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    cout << cnt << '\n';
    return 0;
}