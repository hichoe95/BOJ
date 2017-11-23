//#include <iostream>
#include <cstdio>
//using namespace std;

int set[1000010];

int find(int i){

	if(set[i] == i) return i;
	return set[i] = find(set[i]);
}

void uni(int a, int b){

	int a_p = find(a), b_p = find(b);
	set[a_p] = b_p; 
}

int main(){
	//ios_base::sync_with_stdio(false);

	int n,m,cm,x,y,i;
	scanf("%d %d ",&n,&m);//cin >> n >> m;

	for(i=0 ;i<=n+1;i++) set[i] = i;

	for(i=0 ;i<m ;i++){
		scanf("%d %d %d ",&cm,&x,&y);//cin >> cm >> x >> y;

		if(!cm) uni(x,y);
		else
			if(find(x) == find(y)) printf("YES\n");//cout << "YES\n";
			else printf("NO\n");//cout << "NO\n";

	}


	return 0;
}