#include <iostream>
#include <queue>
using namespace std;

bool prime[10001];

int change(int a, int i, int b){
	int mul = 1;
	if(a/1000==0) return -1;
	for(int k=0 ; k<i;k++) mul*=10;

	int tmp = (a/mul)%10;

	return a - tmp * mul + b * mul;

}

int main(){
	for(int i= 2; i<=10000 ; i++)
		for(int j= i*i ; j<=10000 ; j+=i)
			prime[j] = true;


	int T;

	cin >> T;

	while(T--){
		int x,y;
		int visit[10001] = {0,};
		int d[10001] = {0,};
		cin >> x >> y;
		visit[x] = true;
		queue<int> q;

		q.push(x);

		while(q.size()){
			int cur = q.front();
			q.pop();
			for(int i=0 ; i<4 ; i++){
				for(int j=0 ;j<=9 ; j++){
					int nx = change(cur,i,j);
					if(nx!=-1 && !visit[nx] && !prime[nx]){
						q.push(nx);
						visit[nx] = true;
						d[nx] = d[cur] +1;
					}
				}
			}
		}
		printf("%d\n",d[y]);

	}

	return 0;
}