#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int N,arr[10001];
	cin >> N;
	for(int i=0 ;i<N; i++) arr[i] = i+1;

	do{
		for(int i=0 ;i<N; i++) cout << arr[i] << ' ';
		cout << '\n';
	}while(next_permutation(arr,arr+N));
		

	return 0;
}