#include <cstdio>
#include <algorithm>

int dp[9];
int visited[9];
bool flag;

void comb(int i,int sum,int k){

	if(k==7){
		if(sum == 100){
			flag = true;
			return;
		}
		return;
	}

	for(i=i+1 ;i<9 ; i++){
		if(!visited[i]){
			visited[i] = true;
			comb(i,sum+dp[i],k+1);
			if(flag == true) return;
			visited[i] = false;
		}
	}




}

int main(){
	for(int i=0 , x ; i<9 ; i++)
		scanf("%d",&x),dp[i] = x;
	std::sort(dp,dp+9);

	for(int i=0 ;i<3 ; i++){
		visited[i] = 1;
		comb(i,dp[i],1);
		if(flag) break;
		visited[i] = 0;
	}

	for(int i=0 ;i<9 ;i++) if(visited[i]) printf("%d\n",dp[i]);


	return 0;
}