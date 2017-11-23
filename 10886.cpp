#include <iostream>
using namespace std;

int main(){

	int n,ncute=0,cute=0;
	cin >> n;

	for(int i=0 ;i<n ; i++){
		int x;
		cin >> x;
		if(x) cute++;
		else ncute++;
	}

	cout << ((cute>ncute) ? "Junhee is cute!\n" : "Junhee is not cute!\n");


	return 0;
}