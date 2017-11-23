#include <cstdio>

int main(){
	int n,cnt=0;
	scanf("%d",&n);

	while(n--){
		char c[101];
		scanf("%s",c);
		bool flag = true, check[27]={0,};

		for(int i=0 ;c[i];i++){
			if(check[c[i]-'a']){
				flag = false;
				break;
			}
			if(c[i] == c[i+1]) continue;
			else check[c[i]-'a'] = true;
		}
		if(flag) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}