// #include <cstdio>
// #include <vector>
// using namespace std;
// vector<int> v;
// int main(){

// 	int n,a,b,round=1;
// 	scanf("%d %d %d",&n,&a,&b);
// 	for(int i=0 ; i<n ;i++) v.push_back(i+1);

// 	while(1){
// 		for(int i = 0 ; i<v.size() ; i+=2){
// 			if(i+1 == v.size()) continue;
// 			if((v[i]==a && v[i+1] == b) || (v[i] == b && v[i+1] == a)){
// 				printf("%d\n",round);
// 				return 0;
// 			}
// 			if(v[i]==a || v[i] == b) v[i+1] = 0;
// 			else if(v[i+1] == a || v[i+1] == b) v[i] = 0;
// 			else v[i] = 0;

// 		}
// 		for(int i = 0 ; i < v.size() ; i++) if(!v[i]) v.erase(v.begin()+i),i--;
// 		round++;
// 	}

// 	return 0;
// }

#include <cstdio>
int main(){
	int n,a,b,r=0;
	scanf("%d %d %d",&n,&a,&b);
	a--,b--;
	while(a!=b) a/=2,b/=2,r++;
	printf("%d",r);
	return 0;
}