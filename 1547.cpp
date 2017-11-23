#include <iostream>
using namespace std;

int main(){

	int m,ball=1;

	cin >> m;

	for(int i=0,x,y;i<m;i++){
		cin >> x >> y;
		if(x==ball) ball = y;
		else if(y==ball) ball = x;
	}
	cout << ball << '\n';
	return 0;
}