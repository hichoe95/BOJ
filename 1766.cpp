#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
#define SIZE 32001

vector<int> prob[SIZE];
priority_queue<int,vector<int>,greater<int>> q;
int indgr[SIZE];
int N,M;

int main(){
	scanf("%d %d",&N,&M);

	for(int i=0,x,y; i < M ; i++){
		scanf("%d %d",&x,&y);
		prob[x].push_back(y);
		indgr[y]++;
	}

	for(int i=1 ;i <=N ;i++)
		if(!indgr[i])
			q.push(i);

	while(q.size()){
		int cur = q.top();
		q.pop();
		printf("%d ", cur);
		for(int i : prob[cur]){
			if(!--indgr[i])
				q.push(i);
		}
	}

	return 0;
}