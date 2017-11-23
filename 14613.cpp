#include <iostream>
#include <cmath>
using namespace std;

double w,l,d;
double bronze,silver,gold,platinum,diamond;

long long comb(int n, int r){
	long long a=1,b=1,c=1;
	if(!r || r==n)
		return 1;

	for(int i=1 ;i<=n ; i++)
		a*=i;
	for(int i=1 ; i<=r ;i++)
		b*=i;
	for(int i=1 ; i<=n-r ; i++)
		c*=i;

	a/=b;
	a/=c;
	return a;
}

int main(){

	cin >> w >> l >> d;

	for(int i=0 ;i<=20 ;i++){//이김
		for(int j=0 ;j<=20-i ;j++){//짐
			int score = 2000 + i*50 - j*50,k=20-i-j;
			if(score < 1500)//브론즈
				bronze += comb(20,i)*pow(w,i)*comb(20-i,j)*pow(l,j)*pow(d,k);
			else if(score >=1500 && score <2000)//실버
				silver += comb(20,i)*pow(w,i)*comb(20-i,j)*pow(l,j)*pow(d,k);
			else if(score >=2000 && score < 2500)//골드
				gold += comb(20,i)*pow(w,i)*comb(20-i,j)*pow(l,j)*pow(d,k);
			else if(score >= 2500 && score < 3000)//플래
				platinum += comb(20,i)*pow(w,i)*comb(20-i,j)*pow(l,j)*pow(d,k);
			else//다이아
				diamond += comb(20,i)*pow(w,i)*comb(20-i,j)*pow(l,j)*pow(d,k);
		}
	}

	printf("%.8lf \n%.8lf \n%.8lf \n%.8lf \n%.8lf \n",bronze,silver,gold,platinum,diamond);

	return 0;
}