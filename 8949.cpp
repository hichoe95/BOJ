#include <cstdio>
#include <stack>

int main(){

	int a, b;
	std::stack<int> s;
	scanf("%d %d",&a,&b);

	while(a || b){
		s.push(a%10 + b%10);
		a/=10,b/=10;
	}

	while(s.size()){
		printf("%d",s.top());
		s.pop();
	}
	return 0;
}