#include <cstdio>

int main(){

	int cnt=0;

	for(int i=1 ; i<=8 ; i++){
		for(int j=1 ; j<=8 ; j++){
			char c;
			scanf("%c ",&c);
			if(i&1 && j&1 && c == 'F') cnt++;
			if(!(i%2) && !(j%2) && c == 'F') cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}