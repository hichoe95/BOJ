#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	float m = 0.0,score[1001],sum=0.0;
	int n;
	cin >> n;
	for(int i=0 ; i<n ;i++){
		cin >> score[i];
		m = max(m,score[i]);
	}

	for(int i=0 ;i<n;i++) sum += score[i]/m*100;

	printf("%.2f\n",round((sum/n)*100)/100);

	return 0;
}