#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int k;
	scanf("%d",&k);
	while(k!=-1){
		vector<int> v;
		int sum = 0;
		for(int i=1 ; i<k ; i++) if(!(k%i)) v.push_back(i),sum+=i;

		if(sum == k){
			printf("%d = ",k);
			for(int i = 0 ; i<v.size()-1; i++) printf("%d + ",v[i]);
			printf("%d\n",v.back());
		}
		else printf("%d is NOT perfect.\n",k);
		scanf("%d",&k);
	}
	return 0;
}