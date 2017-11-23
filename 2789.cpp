#include <stdio.h>

int main(){
	int a;
	int b;
	int i;
	char c = 8;
	scanf("%d", &a);
	for (i = 0; i < a; i++)
	{
		for (b = i; b < a-1; b++){
				printf(" ");

		}
		for (b = a-i; b <= a; b++)
			printf("*");
		printf("\n");
	}

	return 0;
}
