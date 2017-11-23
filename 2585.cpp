#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define end pair<int,int>(10000,10000)
#define pii pair<int,int>
#define MAX 987654321
vector<pair<int,int>> co;
bool visited[1001];
int n,k,final = MAX;


int fuel(pii a, pii b){
	int x = a.first,y=a.second, w = b.first,z = b.second;
	return (x-w)*(x-w)+(y-z)*(y-z);
}

bool check(int fu, pii cur, int cnt){

	if(cnt <= k){
		if(fuel(cur,end)<=fu)
			return true;
	}
	if(cnt >= k)
		return false;

	bool flag = false;
	for(int i=0 ; i<=n;i++){
		pii a = co[i];
		if(fuel(cur,a)<=fu && !visited[i]){
			visited[i] = true;
			flag = check(fu,a,cnt+1);
		}
		if(flag)
			break;
	}
	return flag;
}

int main(){

	scanf("%d %d",&n,&k);

	for(int i=0,x,y;i<n;i++){
		scanf("%d %d",&x,&y);
		co.push_back(pii(x,y));
	}
	co.push_back(end);
	int i=fuel(pii(0,0),end)/2,l=0,r=fuel(pii(0,0),end)+1;
	while(l<=r){
		memset(visited,0,sizeof(visited));
		if(check(i,pii(0,0),0)) r = i-1;
		else l = i+1;
		i = (l+r)/2;
	}

	printf("%d\n",(int)ceil(sqrt(i)/10));

	return 0;
}