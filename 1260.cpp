#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
vector<vector<int> > G;
bool *vst;

void dfs(int x){
    vst[x] = true;
    cout << x << " ";
    for(int i : G[x])
        if(!vst[i]) dfs(i);
}

void bfs(int x){
    queue<int> q;
    q.push(x);vst[x]=true;
    while(!q.empty()){
        int cur = q.front();q.pop();
        cout << cur << " " ;
        for(int i : G[cur])
            if(!vst[i]){
                q.push(i);
                vst[i] = true;
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int N,M,V,x,y,i;
    cin >> N >> M >> V;
    G.resize(N+1);
    vst = (bool*)malloc(sizeof(bool)*(N+1));

    for(i=0 ;i<M ;i++){
        cin >> x >> y;
        G[x].pb(y);G[y].pb(x);
    }
    for(i=1 ;i <=N;i++) sort(G[i].begin(),G[i].end());
    dfs(V);
    cout << '\n';
    for(i=0 ;i<N+1;i++) vst[i]=false;
    bfs(V);
    cout << '\n';
    free(vst);
    return 0;
}