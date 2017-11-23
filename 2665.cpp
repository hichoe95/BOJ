#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
#define INF 987654321

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){

    int n,r;
    int maze[51][51],cost[51][51];
    priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int > > > q;
    
    cin >> n;

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++){
            scanf("%1d",&r);
            if(!r) maze[i][j] = 1;
            else maze[i][j] = 0;
        }

    for(int i=0 ; i<=n ; i++)
        for(int j=0 ; j<=n ;j++)
            cost[i][j] = INF;
    
    q.push(pair<int,int>(0,0));

    while(q.size()){
        pair<int,int> current = q.top();
        q.pop();
        for(int i=0 ;i<4;i++){
            int x = current.second/n+1,y = current.second%n+1;
            int & c = cost[x+dx[i]][y+dy[i]];

            if(x+dx[i] <= n && y + dy[i]<=n && x+dx[i] >= 1 && y+dy[i] >= 1 && c > current.first + maze[x + dx[i]][y + dy[i]] ){
                c = current.first + maze[x + dx[i]][y + dy[i]];
                q.push(pair<int,int>(c,current.second + dx[i]*n + dy[i]));
            }
        }
    }

    cout << cost[n][n] << "\n";

    return 0;
}